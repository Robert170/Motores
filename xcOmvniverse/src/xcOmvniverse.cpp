
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

#include <xcSceneGraph.h>
#include <xcVector3.h>
#include <xcModel.h>
#include <xcStaticMesh.h>



#include "xcOmvniverse.h"

namespace xcEngineSDK { 

   PXR_NAMESPACE_USING_DIRECTIVE

  // Globals for Omniverse Connection and base Stage
  static UsdStageRefPtr gStage;
  
  // Omniverse logging is noisy, only enable it if verbose mode (-v)
  static bool gOmniverseLoggingEnabled = false;

  // Global for making the logging reasonable
  static std::mutex gLogMutex;

#define HW_ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))


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

  static void 
  failNotify(const char* msg, const char* detail = nullptr, ...) {
    std::unique_lock<std::mutex> lk(gLogMutex);
    
    fprintf(stderr, "%s\n", msg);
    if (detail != nullptr)
    {
        fprintf(stderr, "%s\n", detail);
    }
  }


  double h = 50.0;

  int gBoxVertexIndices[] = { 0, 1, 2, 1, 3, 2, 4, 5, 6, 4, 6, 7, 8, 9, 10, 8, 10, 11, 12, 13, 14, 12, 14, 15, 16, 17, 18, 16, 18, 19, 20, 21, 22, 20, 22, 23 };
  double gBoxNormals[][3] = { {0, 0, -1}, {0, 0, -1}, {0, 0, -1}, {0, 0, -1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, -1, 0}, {0, -1, 0}, {0, -1, 0}, {0, -1, 0}, {1, 0, 0}, {1, 0, 0}, {1, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, 1, 0}, {0, 1, 0}, {0, 1, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0} };
  double gBoxPoints[][3] = { {h, -h, -h}, {-h, -h, -h}, {h, h, -h}, {-h, h, -h}, {h, h, h}, {-h, h, h}, {-h, -h, h}, {h, -h, h}, {h, -h, h}, {-h, -h, h}, {-h, -h, -h}, {h, -h, -h}, {h, h, h}, {h, -h, h}, {h, -h, -h}, {h, h, -h}, {-h, h, h}, {h, h, h}, {h, h, -h}, {-h, h, -h}, {-h, -h, h}, {-h, h, h}, {-h, h, -h}, {-h, -h, -h} };
  float gBoxUV[][2] = { {0, 0}, {0, 1}, {1, 1}, {1, 0}, {0, 0}, {0, 1}, {1, 1}, {1, 0}, {0, 0}, {0, 1}, {1, 1}, {1, 0}, {0, 0}, {0, 1}, {1, 1}, {1, 0}, {0, 0}, {0, 1}, {1, 1}, {1, 0}, {0, 0}, {0, 1}, {1, 1}, {1, 0} };

  static UsdGeomMesh createBox(int boxNumber = 0)
  {

      auto& sceneGraph = g_sceneGraph();
      Vector<SPtr<Model>> models = sceneGraph.getModels();
      // Keep the model contained inside of "Root", only need to do this once per model
      SdfPath rootPrimPath = SdfPath::AbsoluteRootPath().AppendChild(_tokens->Root);
      UsdGeomXform::Define(gStage, rootPrimPath);

      // Create the geometry inside of "Root"
      std::string boxName("box_");
      boxName.append(std::to_string(boxNumber));
      SdfPath boxPrimPath = rootPrimPath.AppendChild(TfToken(boxName));//_tokens->box);
      UsdGeomMesh mesh = UsdGeomMesh::Define(gStage, boxPrimPath);

      if (!mesh)
          return mesh;

      // Set orientation
      mesh.CreateOrientationAttr(VtValue(UsdGeomTokens->rightHanded));

     uint32 i = 0;
      //// Add all of the vertices
      Vector<Vector3> vertexes = models[i]->getVertexes();
      uint32 num_vertices = vertexes.size();
      VtArray<GfVec3f> points;
      points.resize(num_vertices);
      for (uint32 i = 0; i < num_vertices; i++)
      {
          points[i] = GfVec3f(vertexes[i].x,
                              vertexes[i].y,
                              vertexes[i].z);
      }
      mesh.CreatePointsAttr(VtValue(points));

      // Calculate indices for each triangle
      Vector<int32> indexes = models[i]->getIndexes();
      int32 num_indices = indexes.size(); // 2 Triangles per face * 3 Vertices per Triangle * 6 Faces
      //int num_indices = HW_ARRAY_COUNT(gBoxVertexIndices); // 2 Triangles per face * 3 Vertices per Triangle * 6 Faces
      VtArray<int32> vecIndices;
      vecIndices.resize(num_indices);
      for (int32 i = 0; i < num_indices; i++)
      {
          //vecIndices[i] = gBoxVertexIndices[i];
          vecIndices[i] = indexes[i];

      }
      mesh.CreateFaceVertexIndicesAttr(VtValue(vecIndices));

      // Add vertex normals
      Vector<Vector3> normals = models[i]->getNormals();
      uint32 num_normals = normals.size();
      //int num_normals = HW_ARRAY_COUNT(gBoxNormals);
      VtArray<GfVec3f> meshNormals;
      meshNormals.resize(num_vertices);
      for (int32 i = 0; i < num_vertices; i++)
      {
          //meshNormals[i] = GfVec3f((float)gBoxNormals[i][0], (float)gBoxNormals[i][1], (float)gBoxNormals[i][2]);
          meshNormals[i] = GfVec3f((float)normals[i].x,
                                   (float)normals[i].y,
                                   (float)normals[i].z);
      }
      mesh.CreateNormalsAttr(VtValue(meshNormals));

      // Add face vertex count
      VtArray<int> faceVertexCounts;
      //faceVertexCounts.resize(12); // 2 Triangles per face * 6 faces
      faceVertexCounts.resize(models[i]->getFaceVertexCount()); // 2 Triangles per face * 6 faces
      std::fill(faceVertexCounts.begin(), faceVertexCounts.end(), 3);
      mesh.CreateFaceVertexCountsAttr(VtValue(faceVertexCounts));

      // Set the color on the mesh
      UsdPrim meshPrim = mesh.GetPrim();
      UsdAttribute displayColorAttr = mesh.CreateDisplayColorAttr();
      {
          VtVec3fArray valueArray;
          GfVec3f rgbFace(0.463f, 0.725f, 0.0f);
          valueArray.push_back(rgbFace);
          displayColorAttr.Set(valueArray);
      }

      // Set the UV (st) values for this mesh
      UsdGeomPrimvar attr2 = mesh.CreatePrimvar(_tokens->st, SdfValueTypeNames->TexCoord2fArray);
      {
          Vector<Vector2> uv = models[i]->getUV();
          uint32 uv_count = uv.size();
          //int uv_count = HW_ARRAY_COUNT(gBoxUV);
          VtVec2fArray valueArray;
          valueArray.resize(uv_count);
          for (int32 i = 0; i < uv_count; ++i)
          {
              //valueArray[i].Set(gBoxUV[i]);
              valueArray[i].Set(uv[i].x, uv[i].y);

          }

          bool status = attr2.Set(valueArray);
      }
      attr2.SetInterpolation(UsdGeomTokens->vertex);

      // Commit the changes to the USD
      gStage->Save();
      omniUsdLiveProcess();

      return mesh;
  }

  // Opens an existing stage and finds the first UsdGeomMesh
  static UsdGeomMesh findGeomMesh(const String& existingStage)
  {
	  auto& sceneGraph = g_sceneGraph();
      // Open this file from Omniverse
      gStage = UsdStage::Open(existingStage);
      if (!gStage)
      {
          failNotify("Failure to open stage in Omniverse:", existingStage.c_str());
          return UsdGeomMesh();
      }

      {
          std::unique_lock<std::mutex> lk(gLogMutex);
          std::cout << "Existing stage opened: " << existingStage << std::endl;
      }

      if (UsdGeomTokens->y != UsdGeomGetStageUpAxis(gStage))
      {
          std::unique_lock<std::mutex> lk(gLogMutex);
          std::cout << "Stage is not Y-up so live xform edits will be incorrect.  Stage is " << UsdGeomGetStageUpAxis(gStage) << "-up" << std::endl;
      }

      // Traverse the stage and return the first UsdGeomMesh we find
      UsdGeomMesh mesh;
      auto range = gStage->Traverse();
      for (const auto& node : range)
      {
          if (node.IsA<UsdGeomMesh>())
          {
              {
                  std::unique_lock<std::mutex> lk(gLogMutex);
                  std::cout << "Found UsdGeomMesh: " << node.GetName() << std::endl;
              }
              mesh = UsdGeomMesh(node);
          }
      }

      uint32 numVertex = 0;
      int32 numNormal = 0;
      Vector<BoneVertex> modelData;
      Vector<Vector3> modelVertex;
      Vector<Vector3> modelNormals;
      Vector<int32> modelIndex;


      //indices
      {
          UsdAttribute indexes = mesh.GetFaceVertexIndicesAttr();
          VtArray<int32> points;
          indexes.Get(&points);

          uint32 size = points.size();


          for (uint32 i = 0; i < size; ++i) {

              modelIndex.push_back(points[i]);

          }
      }

      //vertices
      {
          UsdAttribute vertexes = mesh.GetPointsAttr();
          VtArray<GfVec3f> points;
          vertexes.Get(&points);

          uint32 size = points.size();
          numVertex = size;

          for (uint32 i = 0; i < size; ++i) {


              modelVertex.push_back(Vector3(points[i].GetArray()[0],
                                            points[i].GetArray()[1],
                                            points[i].GetArray()[2]));

          }
      }
      
      
      //Normals
      {
        UsdAttribute normals = mesh.GetNormalsAttr();
        VtArray<GfVec3f> points;
        normals.Get(&points);

        uint32 size = points.size();
        numNormal = size;

        for (uint32 i = 0; i < size; ++i) {

            modelNormals.push_back(Vector3(points[i].GetArray()[0],
                                           points[i].GetArray()[1],
                                           points[i].GetArray()[2]));

        }
      }

      //UV
      mesh.GetPrim();
      //modelData.reserve(numVertex);
      for (uint32 i = 0; i < numVertex; ++i) {
        BoneVertex temp;
        temp.vertex = modelVertex[i];
		temp.normal = modelNormals[i];
        temp.texCoords = Vector2::ZERO;

        modelData.push_back(temp);
      }
          
      SPtr<Model> exampleModelUsd (new Model());
      exampleModelUsd->setData(modelData, modelIndex);
	  SPtr<Component> testComponent(new StaticMesh(exampleModelUsd));
	  SPtr<Actor> testActor(new Actor("testUsd"));
	  testActor->addComponent(testComponent);

	  sceneGraph.addActor(testActor, SPtr<SceneNode>(nullptr));


      // No UsdGeomMesh found in stage (what kind of stage is this anyway!?)
      std::cout << "ERROR: No UsdGeomMesh found in stage: " << existingStage << std::endl;
      return UsdGeomMesh();
  }


  static UsdGeomMesh createModel(uint32 ModelNumber = 0) {

    auto& sceneGraph = g_sceneGraph();
    Vector<SPtr<Model>> models = sceneGraph.getModels();

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

    uint32 numModels = models.size();

    //for (uint32 i = 0; i < numModels; ++i) {
    uint32 i = 0;
      //// Add all of the vertices
      Vector<Vector3> vertexes = models[i]->getVertexes();
      uint32 num_vertices = vertexes.size();
      VtArray<GfVec3f> points;
      points.resize(num_vertices);
      for (uint32 j = 0; j < num_vertices; ++j) {

        points[j] = GfVec3f(vertexes[j].x,
                            vertexes[j].y,
                            vertexes[j].z);

      }
      mesh.CreatePointsAttr(VtValue(points));

      // Calculate indices for each triangle
      Vector<int32> indexes = models[i]->getIndexes();
      uint32 num_indices = indexes.size(); // 2 Triangles per face * 3 Vertices per Triangle * 6 Faces
      VtArray<uint32> vecIndices;
      vecIndices.resize(num_indices);
      for (uint32 k = 0; k < num_indices; ++k)
      {
        vecIndices[i] = indexes[i];
      }
      mesh.CreateFaceVertexIndicesAttr(VtValue(vecIndices));

      // Add vertex normals
      Vector<Vector3> normals = models[i]->getNormals();
      uint32 num_normals = normals.size();
      VtArray<GfVec3f> meshNormals;
      meshNormals.resize(num_vertices);
      for (uint32 l = 0; l < num_vertices; ++l)
      {
          meshNormals[l] = GfVec3f((float)normals[l].x,
                                   (float)normals[l].y,
                                   (float)normals[l].z);
          
      }           
      mesh.CreateNormalsAttr(VtValue(meshNormals));

      // Add face vertex count
      VtArray<uint32> faceVertexCounts;
      faceVertexCounts.resize(models[i]->getFaceVertexCount()); // 2 Triangles per face * 6 faces
      std::fill(faceVertexCounts.begin(), faceVertexCounts.end(), 3);
      mesh.CreateFaceVertexCountsAttr(VtValue(faceVertexCounts));

      // Set the color on the mesh
      UsdPrim meshPrim = mesh.GetPrim();
      UsdAttribute displayColorAttr = mesh.CreateDisplayColorAttr();
      {
          VtVec3fArray valueArray;
          GfVec3f rgbFace(0.463f, 0.725f, 0.0f);
          valueArray.push_back(rgbFace);
          displayColorAttr.Set(valueArray);
      }

      // Set the UV (st) values for this mesh
      UsdGeomPrimvar attr2 = mesh.CreatePrimvar(_tokens->st, 
                                                SdfValueTypeNames->TexCoord2fArray);
      {
        Vector<Vector2> uv = models[i]->getUV();
        uint32 uv_count = uv.size();
        VtVec2fArray valueArray;
        valueArray.resize(uv_count);

        for (uint32 m = 0; m < uv_count; ++m) {
            valueArray[m].Set(uv[m].x, uv[m].y);

        }

        bool status = attr2.Set(valueArray);
      }
      attr2.SetInterpolation(UsdGeomTokens->vertex);

      // Commit the changes to the USD
      gStage->Save();
      omniUsdLiveProcess();

      return mesh;

    //}

    
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

  

  // Create a new connection for this model in Omniverse, 
  //returns the created stage URL
  static String createOmniverseModel(const std::string& destinationPath,
                                          const std::string& fileName)
  {
      String stageUrl = destinationPath + "/" + fileName;

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
    String name = "Cube2.usd";
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
      //model = 
      //createModel();
      createBox();
      String pathUSD = "Models/Cube2.usd";

       findGeomMesh(pathUSD);

    }

    // All done, shut down our connection to Omniverse
    shutdownOmniverse();

  }
}
