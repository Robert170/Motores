
#include <mutex>
#include <memory>
#include <condition_variable>
#include <OmniClient.h>
#include <OmniUsdLive.h>
#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usdGeom/mesh.h>
#include <pxr/usd/usdGeom/metrics.h>
#include <pxr/base/gf/matrix4f.h>
#include <pxr/base/gf/vec2f.h>
#include <pxr/usd/usdUtils/pipeline.h>
#include <pxr/usd/usdUtils/sparseValueWriter.h>
#include <pxr/usd/usdShade/material.h>
#include <pxr/usd/usd/prim.h>
#include <pxr/usd/usd/primRange.h>
#include <pxr/usd/usdGeom/primvar.h>
#include <pxr/usd/usdShade/input.h>
#include <pxr/usd/usdShade/output.h>
#include <pxr/usd/usdGeom/xform.h>
#include <pxr/usd/usdShade/materialBindingAPI.h>
#include <pxr/usd/usdLux/distantLight.h>
#include <pxr/usd/usdShade/tokens.h>
#include <pxr/usd/usdShade/shader.h>
#include <pxr/usd/usd/modelAPI.h>

#include "xcOmvniverse.h"

namespace xcEngineSDK { 

   PXR_NAMESPACE_USING_DIRECTIVE

  // Globals for Omniverse Connection and base Stage
  static UsdStageRefPtr gStage;
  
  // Omniverse logging is noisy, only enable it if verbose mode (-v)
  static bool gOmniverseLoggingEnabled = false;

  // Global for making the logging reasonable
  static std::mutex gLogMutex;

  TF_DEFINE_PRIVATE_TOKENS(
	  _tokens,
	  (box)
	  (Light)
	  (Looks)
	  (Root)
	  (Shader)
	  (st)

	  // These tokens will be reworked or replaced by the official MDL schema for USD.
	  // https://developer.nvidia.com/usd/MDLschema
	  (Material)
	  ((_module, "module"))
	  (name)
	  (out)
	  ((shaderId, "mdlMaterial"))
	  (mdl)

	  // Tokens used for USD Preview Surface
	  (diffuseColor)
	  (normal)
	  (file)
	  (result)
	  (varname)
	  (rgb)
	  (RAW)
	  (sRGB)
	  (surface)
	  (PrimST)
	  (UsdPreviewSurface)
	  ((UsdShaderId, "UsdPreviewSurface"))
	  ((PrimStShaderId, "UsdPrimvarReader_float2"))
	  (UsdUVTexture)
  );

  static UsdGeomMesh createModel(int ModelNumber = 0) {
    // Keep the model contained inside of "Root", only need to do this once per model
    SdfPath rootPrimPath = SdfPath::AbsoluteRootPath().AppendChild(_tokens->Root);
    UsdGeomXform::Define(gStage, rootPrimPath);

	// Create the geometry inside of "Root"
	String boxName("Model");
	boxName.append(std::to_string(ModelNumber));
	SdfPath boxPrimPath = rootPrimPath.AppendChild(TfToken(boxName));
	UsdGeomMesh mesh = UsdGeomMesh::Define(gStage, boxPrimPath);

    if (!mesh) {
		return mesh;
    }

	// Set orientation
    mesh.CreateOrientationAttr(VtValue(UsdGeomTokens->rightHanded));


  }

  static void OmniClientConnectionStatusCallbackImpl(void* userData, 
                                                     const char* url, 
                                                     OmniClientConnectionStatus 
                                                     status) noexcept {
    // Let's just print this regardless
    {
        std::unique_lock<std::mutex> lk(gLogMutex);
        std::cout << "Connection Status: " << 
        omniClientGetConnectionStatusString(status) << " [" << url << "]" << std::endl;
    }
    if (status == eOmniClientConnectionStatus_ConnectError) {
        // We shouldn't just exit here - we should clean up a bit, but we're going to do it anyway
        std::cout << "[ERROR] Failed connection, exiting." << std::endl;
        exit(-1);
    }
  }

  static void 
  failNotify(const char* msg, const char* detail = nullptr, ...) {
      std::unique_lock<std::mutex> lk(gLogMutex);

      fprintf(stderr, "%s\n", msg);
      if (detail != nullptr)
      {
          fprintf(stderr, "%s\n", detail);
      }
  }

  // Create a new connection for this model in Omniverse, 
  //returns the created stage URL
  static std::string createOmniverseModel(const std::string& destinationPath,
                                          const std::string& fileName)
  {
      std::string stageUrl = destinationPath + "/" + fileName;

      // Delete the old version of this file on Omniverse and wait for the operation to complete
      {
          std::unique_lock<std::mutex> lk(gLogMutex);
          std::cout << "Waiting for " << stageUrl << " to delete... " << std::endl;
      }
      omniClientWait(omniClientDelete(stageUrl.c_str(), nullptr, nullptr));
      {
          std::unique_lock<std::mutex> lk(gLogMutex);
          std::cout << "finished" << std::endl;
      }
      
      // Create this file in Omniverse cleanly
      gStage = UsdStage::CreateNew(stageUrl);
      if (!gStage)
      {
          failNotify("Failure to create model in Omniverse", stageUrl.c_str());
          return std::string();
      }

      {
          std::unique_lock<std::mutex> lk(gLogMutex);
          std::cout << "New stage created: " << stageUrl << std::endl;
      }

      // Always a good idea to declare your up-ness
      UsdGeomSetStageUpAxis(gStage, UsdGeomTokens->y);

      return stageUrl;
  }


  // Shut down Omniverse connection
  static void shutdownOmniverse()
  {
      // Calling this prior to shutdown ensures that all pending live updates complete.
      omniUsdLiveWaitForPendingUpdates();

      // The stage is a sophisticated object that needs to be destroyed properly.  
      // Since gStage is a smart pointer we can just reset it
      gStage.Reset();

      //omniClientTick(1000);
      omniClientShutdown();
  }



  // Omniverse Log callback
  static void logCallback(const char* threadName, 
                          const char* component, 
                          OmniClientLogLevel level, 
                          const char* message) noexcept {
      std::unique_lock<std::mutex> lk(gLogMutex);
      if (gOmniverseLoggingEnabled)
      {
          puts(message);
      }
  }

  // Startup Omniverse 
  static bool startOmniverse(bool doLiveEdit)
  {
    // Register a function to be called whenever the library wants to print something to a log
    omniClientSetLogCallback(logCallback);

    // The default log level is "Info", set it to "Debug" to see all messages
    omniClientSetLogLevel(eOmniClientLogLevel_Debug);

    // Initialize the library and pass it the version constant defined in OmniClient.h
    // This allows the library to verify it was built with a compatible version. It will
    // return false if there is a version mismatch.
    if (!omniClientInitialize(kOmniClientVersion))
    {
        return false;
    }

    omniClientRegisterConnectionStatusCallback(nullptr,
                                               OmniClientConnectionStatusCallbackImpl);

    // Enable live updates
    omniUsdLiveSetDefaultEnabled(doLiveEdit);
    
    return true;
  }

  void 
  Omvniverse::init() {

    String path ="omniverse://localhost/Users/testHomework";
    String name = "Prueba2.usd";
    createUSD(path, name);


  }

  void
  Omvniverse::update() {
  }

  void 
  Omvniverse::createUSD(String& destinationPath, 
                        String& file) {
    bool doLiveEdit = false;
    String existingStage;
    UsdGeomMesh model;
  

    // Startup Omniverse with the default login
    if (!startOmniverse(doLiveEdit)) {
        exit(1);
    }

    if (existingStage.empty()) { 
      createOmniverseModel(destinationPath, file);

      // Create geometry in the model
      model = createModel();

    }

    // All done, shut down our connection to Omniverse
    shutdownOmniverse();

  }
}
