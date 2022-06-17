
//#include <mutex>
//#include <memory>
//#include <condition_variable>
//#include <OmniClient.h>
//#include <OmniUsdLive.h>
//#include <pxr/usd/usd/stage.h>
//#include <pxr/usd/usdGeom/mesh.h>
//#include <pxr/usd/usdGeom/metrics.h>
//#include <pxr/base/gf/matrix4f.h>
//#include <pxr/base/gf/vec2f.h>
//#include <pxr/usd/usdUtils/pipeline.h>
//#include <pxr/usd/usdUtils/sparseValueWriter.h>
//#include <pxr/usd/usdShade/material.h>
//#include <pxr/usd/usd/prim.h>
//#include <pxr/usd/usd/primRange.h>
//#include <pxr/usd/usdGeom/primvar.h>
//#include <pxr/usd/usdShade/input.h>
//#include <pxr/usd/usdShade/output.h>
//#include <pxr/usd/usdGeom/xform.h>
//#include <pxr/usd/usdShade/materialBindingAPI.h>
//#include <pxr/usd/usdLux/distantLight.h>
//#include <pxr/usd/usdShade/tokens.h>
//#include <pxr/usd/usdShade/shader.h>
//#include <pxr/usd/usd/modelAPI.h>

#include <xcSceneGraph.h>
#include <xcVector3.h>
#include <xcModel.h>
#include <xcMesh.h>
#include <xcStaticMesh.h>



#include "xcOmvniverse.h"

namespace xcEngineSDK { 

  Mesh createMeshfromGeomMesh(const UsdGeomMesh& geomMesh);

  static void
    createEmptyFolder(const String& emptyFolderPath) {
      {
        std::unique_lock<std::mutex> lk(gLogMutex);
        std::cout << "Waiting to create a new folder: " << emptyFolderPath << " ...";
      }

      OmniClientResult localResult = Count_eOmniClientResult;

      omniClientWait(omniClientCreateFolder(emptyFolderPath.c_str(),
        &localResult,
        [](void* userData,
          OmniClientResult result) noexcept {
            auto returnResult = static_cast<OmniClientResult*>(userData);
            *returnResult = result;
        }));

      {
        std::unique_lock<std::mutex> lk(gLogMutex);
        std::cout << "finished [" << omniClientGetResultString(localResult) << "]\n";
      }
  }

  static void
    failNotify(const char* msg, const char* detail, ...) {
    std::unique_lock<std::mutex> lk(gLogMutex);
    fprintf(stderr, "%s\n", msg);
    if (detail != nullptr) {
      fprintf(stderr, "%s\n", detail);
    }
  }

  static void
    logCallback(const char* threadName,
      const char* component,
      OmniClientLogLevel level,
      const char* message) {
    std::unique_lock<std::mutex> lk(gLogMutex);
    if (gOmniverseLoggingEnabled) {
      puts(message);
    }
  }

  static void
    OmniClientConnectionStatusCallbackImpl(void* userData,
      const char* url,
      OmniClientConnectionStatus status) {
        {
          std::unique_lock<std::mutex> lk(gLogMutex);
          std::cout << "Connection Status: " << omniClientGetConnectionStatusString(status) << "[" << url << "]\n";
        }
        if (status == eOmniClientConnectionStatus_ConnectError) {
          std::cout << "[ERROR] Failed connection, exiting\n";
        }
  }

  // Shut down Omniverse connection
  static
    void shutdownOmniverse()
  {
    // Calling this prior to shutdown ensures that all pending live updates complete.
    omniUsdLiveWaitForPendingUpdates();

    // The stage is a sophisticated object that needs to be destroyed properly.  
    // Since gStage is a smart pointer we can just reset it
    gStage.Reset();

    //omniClientTick(1000);
    omniClientShutdown();
  }

  static void
  printConnectedUsername(const String& stageUrl) {
    // Get the username for the connection
    String userName("_none_");
    omniClientWait(omniClientGetServerInfo(stageUrl.c_str(),
      &userName,
      [](void* userData,
        OmniClientResult result,
        struct OmniClientServerInfo const* info) noexcept {
          String* userName = static_cast<String*>(userData);
          if (userData && userName && info && info->username) {
            userName->assign(info->username);
          }
      }));
    {
      std::unique_lock<std::mutex> lk(gLogMutex);
      std::cout << "Connected username: " << userName << std::endl;
    }
  }

  static String 
  createOmniverseModel(const std::string& destinationPath,
                       const std::string& fileName) {

    /*if (!startOmniverse(false)) {
      exit(1);
    }*/

    String stageUrl = destinationPath + fileName;
    std::cout << "\nDestination path -> " << stageUrl + "\n";

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


  static void
  createModels(String destinationPath, String existingExample) {
    if (existingExample.empty()) {
      const String stageUrl = createOmniverseModel(destinationPath, "Example.usd");
      printConnectedUsername(stageUrl);
      auto& scene = SceneGraph::instance();
      Vector<SPtr<Model>>sceneModels = scene.getModels();
      int32 modelIndex = 0;
      for (auto& model : sceneModels) {
        int32 meshIndex = 0;
        String modelName("_model" + std::to_string(modelIndex));
        ++modelIndex;
        SdfPath rootPrimPath = SdfPath::AbsoluteRootPath().AppendChild(_tokens->Root);
        SdfPath modelPath = rootPrimPath.AppendChild(TfToken(modelName));
        UsdGeomMesh mesh = UsdGeomMesh::Define(gStage, modelPath);
        if (!mesh) {
          OutputDebugStringA("Couldn't create UsdGeoMesh\n");
          return;
        }
        for (auto& inmesh : model->getMeshes()) {
          String meshName("_mesh" + std::to_string(meshIndex));
          ++meshIndex;
          SdfPath meshPath = modelPath.AppendChild(TfToken(meshName));
          UsdGeomMesh subMesh = UsdGeomMesh::Define(gStage, meshPath);
          if (!subMesh) {
            OutputDebugStringA("Couldn't create a sub UsdGeoMesh.\n");
          }
          subMesh.CreateOrientationAttr(VtValue(UsdGeomTokens->rightHanded));
          Vector<Vector3> tempVertices;
          Vector<uint32> tempIndices;
          Vector<Vector3> tempNormals;
          Vector<Vector2> tempUVs;
          inmesh.getMeshInfo(tempVertices, tempIndices, tempNormals, tempUVs);

          VtArray<GfVec3f> points;
          points.resize(tempVertices.size());
          int32 numVertices = tempVertices.size();
          for (int32 i = 0; i < numVertices; ++i) {
            points[i] = GfVec3f(tempVertices[i].x, tempVertices[i].y, tempVertices[i].z);
          }
          subMesh.CreatePointsAttr(VtValue(points));

          int32 numIndices = tempIndices.size();
          VtArray<int32> vecIndices;
          vecIndices.resize(numIndices);
          for (int32 i = 0; i < numIndices; ++i) {
            vecIndices[i] = tempIndices[i];
          }
          subMesh.CreateFaceVertexIndicesAttr(VtValue(vecIndices));

          VtArray<GfVec3f> meshNormals;
          meshNormals.resize(numVertices);
          for (int32 i = 0; i < numVertices; ++i) {
            meshNormals[i] = GfVec3f(tempNormals[i].x, tempNormals[i].y, tempNormals[i].z);
          }
          subMesh.CreateNormalsAttr(VtValue(meshNormals));

          VtArray<int32> faceVertexCounts;
          faceVertexCounts.resize(numIndices / 3);
          std::fill(faceVertexCounts.begin(), faceVertexCounts.end(), 3);
          subMesh.CreateFaceVertexCountsAttr(VtValue(faceVertexCounts));

          UsdGeomPrimvar attr2 = subMesh.CreatePrimvar(_tokens->st, SdfValueTypeNames->TexCoord2fArray);
          {
            int32 uv_count = tempUVs.size();
            VtVec2fArray valueArray;
            valueArray.resize(uv_count);
            for (int32 i = 0; i < uv_count; ++i) {
              valueArray[i].Set(tempUVs[i].x, tempUVs[i].y);
            }
            bool status = attr2.Set(valueArray);
          }
          attr2.SetInterpolation(UsdGeomTokens->vertex);
        }
      }
      gStage->Save();
      omniUsdLiveProcess();
      shutdownOmniverse();
    }
      //const String stageUrl = createOmniverseModel(destinationPath, "Example.usd");
      //printConnectedUsername(stageUrl);
      //auto& sceneGraph = g_sceneGraph();
      //Vector<SPtr<Model>> models = sceneGraph.getModels();
      //uint32 modelNumber = 0;

      //for (auto& actualModel : models) {
      //  // Keep the model contained inside of "Root", only need to do this once per model
      //  SdfPath rootPrimPath = SdfPath::AbsoluteRootPath().AppendChild(_tokens->Root);
      //  UsdGeomXform::Define(gStage, rootPrimPath);

      //  // Create the geometry inside of "Root"
      //  String modelName("model_");
      //  modelName.append(std::to_string(modelNumber));
      //  SdfPath modelPrimPath = rootPrimPath.AppendChild(TfToken(modelName));//_tokens->box);
      //  UsdGeomMesh model = UsdGeomMesh::Define(gStage, modelPrimPath);

      //  if (!model) {
      //    return;
      //  }
      //  uint32 meshNumber = 0;
      //  Vector<Mesh> meshes = actualModel->getMeshes();

      //  for (auto& meshOfModdel : meshes) {

      //    // Create the geometry inside of "Root"
      //    String meshName("mesh_");
      //    meshName.append(std::to_string(meshNumber));
      //    SdfPath meshPrimPath = rootPrimPath.AppendChild(TfToken(meshName));//_tokens->box);
      //    UsdGeomMesh mesh = UsdGeomMesh::Define(gStage, meshPrimPath);

      //    if (!mesh) {
      //      return;
      //    }
      //mesh.CreateOrientationAttr(VtValue(UsdGeomTokens->rightHanded));


      //    meshNumber++;
      ////// Add all of the vertices
      //Vector<Vector3> vertexes = meshOfModdel.getVertexes();
      //uint32 num_vertices = vertexes.size();
      //VtArray<GfVec3f> points;
      //points.resize(num_vertices);
      //for (uint32 i = 0; i < num_vertices; i++) {
      //    points[i] = GfVec3f(vertexes[i].x,
      //		              vertexes[i].y,
      //		              vertexes[i].z);
      //}
      //mesh.CreatePointsAttr(VtValue(points));

      //// Calculate indices for each triangle
      //Vector<int32> indexes = meshOfModdel.getIndexes();
      //int32 num_indices = indexes.size(); // 2 Triangles per face * 3 Vertices per Triangle * 6 Faces
      //VtArray<int32> vecIndices;
      //vecIndices.resize(num_indices);
      //for (int32 i = 0; i < num_indices; i++) {
      //  vecIndices[i] = indexes[i];

      //}
      //mesh.CreateFaceVertexIndicesAttr(VtValue(vecIndices));

      //// Add vertex normals
      //Vector<Vector3> normals = meshOfModdel.getNormals();
      //uint32 num_normals = normals.size();
      //VtArray<GfVec3f> meshNormals;
      //meshNormals.resize(num_vertices);
      //for (int32 i = 0; i < num_vertices; i++) {
      //  meshNormals[i] = GfVec3f((float)normals[i].x,
      //		                   (float)normals[i].y,
      //		                   (float)normals[i].z);
      //}
      //mesh.CreateNormalsAttr(VtValue(meshNormals));

      //// Add face vertex count
      //VtArray<int> faceVertexCounts;
      //faceVertexCounts.resize(meshOfModdel.getFaceVertexCount()); // 2 Triangles per face * 6 faces
      //std::fill(faceVertexCounts.begin(), faceVertexCounts.end(), 3);
      //mesh.CreateFaceVertexCountsAttr(VtValue(faceVertexCounts));

      //// Set the color on the mesh
      //UsdPrim meshPrim = mesh.GetPrim();
      //UsdAttribute displayColorAttr = mesh.CreateDisplayColorAttr();
      //{
      //  VtVec3fArray valueArray;
      //  GfVec3f rgbFace(0.463f, 0.725f, 0.0f);
      //  valueArray.push_back(rgbFace);
      //  displayColorAttr.Set(valueArray);
      //}

      //// Set the UV (st) values for this mesh
      //UsdGeomPrimvar attr2 = mesh.CreatePrimvar(_tokens->st, SdfValueTypeNames->TexCoord2fArray);
      //{
      //    Vector<Vector2> uv = meshOfModdel.getUV();
      //    uint32 uv_count = uv.size();
      //    VtVec2fArray valueArray;
      //    valueArray.resize(uv_count);
      //    for (int32 i = 0; i < uv_count; ++i) {
      //         valueArray[i].Set(uv[i].x, uv[i].y);
      //      
      //    }
      //      
      //    bool status = attr2.Set(valueArray);
      //}
      //attr2.SetInterpolation(UsdGeomTokens->vertex);

      //// Commit the changes to the USD
      //gStage->Save();
      //omniUsdLiveProcess();
      //  }

      //  modelNumber++;
      //}


  }


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
  bool
  Omvniverse::loadUSD(const String& existingStage) {
      auto& sceneGraph = g_sceneGraph();
      // Open this file from Omniverse
      gStage = UsdStage::Open(existingStage);
      if (!gStage)
      {
          failNotify("Failure to open stage in Omniverse:", existingStage.c_str());
          return false;
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

      auto range = gStage->Traverse();
      for (const auto& node : range) {

        if (node.IsA<UsdGeomMesh>()) {
          UsdPrim parent = node.GetParent();
          if ("Root" == parent.GetName()) {
            SPtr<Model> tempModel = std::make_shared<Model>();

            std::unique_lock<std::mutex> lk(gLogMutex);
            std::cout << "Found UsdGeoMesh " << node.GetName() << ".\n";

            UsdGeomMesh geoMesh(node);

            /*tempModel->m_textureSampler = g_graphicsAPI().createSamplerState(
              FILTER_LEVEL::FILTER_LINEAR,
              FILTER_LEVEL::FILTER_LINEAR,
              FILTER_LEVEL::FILTER_LINEAR,
              false,
              0,
              WRAPPING::WRAP,
              COMPARISON::NEVER);*/

            //GeomMesh is container and has children
            if (!node.GetAllChildren().empty()) {
              for (const auto& childNode : node.GetAllChildren()) {
                if (childNode.IsA<UsdGeomMesh>()) {
                  UsdGeomMesh childGM(childNode);
                  tempModel->m_vMeshes.push_back(createMeshfromGeomMesh(childGM));
                }
              }
            }
            //GeomMesh is single and contains the mesh info
            else {
              tempModel->m_vMeshes.push_back(createMeshfromGeomMesh(geoMesh));
            }

            //SPtr<Model> exampleModelUsd(new Model());
            //exampleModelUsd->setData(modelData, modelIndex);
            SPtr<Component> testComponent(new StaticMesh(tempModel));
            SPtr<Actor> testActor(new Actor(node.GetName().GetString()));
            testActor->addComponent(testComponent);
            testActor->m_omniPath = node.GetPath().GetString();
            sceneGraph.addActor(testActor, SPtr<SceneNode>(nullptr));

          }
        }
        


      }
      return true;
          
      

  }
  
  // Create a new connection for this model in Omniverse, 
  //returns the created stage URL

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

  

  Omvniverse::~Omvniverse() {

    shutdownOmniverse();
  }

  void
  Omvniverse::init() {

    // Startup Omniverse with the default login
    //m_doLiveEdit = false;
    if (!startOmniverse(false)) {
      exit(1);
    }

    String path ="omniverse://localhost/Users/xc170";
    String name = "Vela2.usd";
    //createModels(m_destinationPath, m_existingExample);


  }

  void
  Omvniverse::update() {

    if (m_doLiveEdit) {
      liveEdit();
    }
  }

  void 
  Omvniverse::createUSD(String& destinationPath, 
                        String& file) {
    //bool doLiveEdit = false;
    String existingStage;
    UsdGeomMesh model;
  

    

    if (existingStage.empty()) { 
      createOmniverseModel(destinationPath, file);

      // Create geometry in the model
      //model = 
      createModels(m_destinationPath, m_existingExample);
      //createBox();
      String pathUSD = "Models/Cube2.usd";
      pathUSD = "http://localhost:8080/omniverse://127.0.0.1/Users/xc170/Vela.usd";
      //loadUSD(pathUSD);

    }

    // All done, shut down our connection to Omniverse
    shutdownOmniverse();

  }

  bool 
  Omvniverse::connectFromOmni(const String& fileName) {
    m_doLiveEdit = true;
    omniUsdLiveSetDefaultEnabled(m_doLiveEdit);
    return loadUSD(fileName);
  }

  bool 
  Omvniverse::connectToOmni(const String& fileName) {
    m_doLiveEdit = true;
    omniUsdLiveSetDefaultEnabled(m_doLiveEdit);
    if (m_existingExample.empty()) {
      if (0 != SceneGraph::instance().getNumActors()) {
        createEmptyUSD(fileName);
        createModels(m_destinationPath, m_existingExample);
        return true;
      }
      else {
        createEmptyUSD(fileName);
        createOmniverseModel(m_destinationPath, fileName);
        return true;
      }
    }
    return false;
  }

  void 
  Omvniverse::createEmptyUSD(const String projectName) {
    createEmptyFolder(m_destinationPath + projectName);
    m_existingExample = m_destinationPath + projectName;
    m_destinationPath = m_existingExample;
  }

  void 
  Omvniverse::liveEdit() {
    omniUsdLiveWaitForPendingUpdates();
    auto& sgraph = SceneGraph::instance();
    for (auto& node : sgraph.getRoot()->m_pChild) {
      if (nullptr != node->m_pActor) {
        if (!node->m_pActor->m_omniPath.empty()) {
          SdfPath path(node->m_pActor->m_omniPath);
          UsdGeomMesh geomMesh(gStage->GetPrimAtPath(path));
          UsdGeomXformable xForm = geomMesh;

          UsdGeomXformOp translateOp;
          UsdGeomXformOp rotateOp;
          UsdGeomXformOp scaleOp;

          GfVec3d position(0);
          GfVec3f rotZYX(0);
          GfVec3f scale(1);

          bool resetXformStack = false;
          Vector<UsdGeomXformOp> xFormOps = xForm.GetOrderedXformOps(&resetXformStack);
          for (SIZE_T i = 0; i < xFormOps.size(); ++i) {
            switch (xFormOps[i].GetOpType()) {
            case UsdGeomXformOp::TypeTranslate: {
              translateOp = xFormOps[i];
              translateOp.Get(&position);
              break;
            }
            case UsdGeomXformOp::TypeRotateZYX: {
              rotateOp = xFormOps[i];
              translateOp.Get(&rotZYX);
              break;
            }
            case UsdGeomXformOp::TypeScale: {
              scaleOp = xFormOps[i];
              scaleOp.Get(&scale);
              break;
            }
            }
          }
          node->m_pActor->m_actorPosition = { (float)position.GetArray()[0],
                                              (float)position.GetArray()[1],
                                              (float)position.GetArray()[2] };
          

          node->m_pActor->m_actorScale = { (float)scale.GetArray()[0],
                                           (float)scale.GetArray()[1],
                                           (float)scale.GetArray()[2] };

       
        }
      }
    }
  }

  void 
  Omvniverse::setTransformOp(Vector3 data, 
                             OMNI_OP::E operation, 
                             OMNI_PRECISION::E precision, 
                             String omniPath) {
  }

  bool 
  Omvniverse::getLiveEdit() {
    return m_doLiveEdit;
  }

  Mesh
  createMeshfromGeomMesh(const UsdGeomMesh& geomMesh) {
    auto& graphicsApi = g_graphicsAPI();
    VtArray<GfVec3f> points;
    VtArray<GfVec3f> normals;
    VtVec2fArray uvs;
    VtArray<int32> indices;

    UsdAttribute meshPointAttrib = geomMesh.GetPointsAttr();
    meshPointAttrib.Get(&points);

    UsdAttribute meshIndexAttrib = geomMesh.GetFaceVertexIndicesAttr();
    meshIndexAttrib.Get(&indices);

    UsdAttribute meshNormalAttrib = geomMesh.GetNormalsAttr();
    meshNormalAttrib.Get(&normals);

    //UsdGeomPrimvarsAPI primApi = UsdGeomPrimvarsAPI(gStage->GetPrimAtPath(geomMesh.GetPath()));
    ////UsdGeomPrimvar meshUVAttrib = primApi.GetPrimvar(_tokens->st);
    //bool check = primApi.HasPrimvar(_tokens->st);
    //check = geomMesh.HasPrimvar(_tokens->st);
    //Vector<UsdGeomPrimvar> primVars = geomMesh.GetPrimvars();
    //UsdGeomPrimvar meshUVAttrib = geomMesh.GetPrimvar(_tokens->st);
    //meshUVAttrib.Get(&uvs);

    uint32 numPoints = points.size();
    uint32 numIndices = indices.size();
    int32 numNormal = 0;
    Vector<BoneVertex> modelData;
    Vector<Vector3> modelVertex;
    Vector<Vector3> modelNormals;
    Vector<int32> modelIndex;

    Vector<BoneVertex> meshVertices;
    Vector<int32> meshIndices;

    for (int32 i = 0; i < numPoints; ++i) {
      BoneVertex v;
      v.vertex = Vector3(points[i].data()[0], points[i].data()[1], points[i].data()[2]);
      v.normal = Vector3(normals[i].data()[0], normals[i].data()[1], normals[i].data()[2]);
      v.tangent = Vector3(1.0f, 1.0f, 1.0f);
      v.biTangent = Vector3(1.0f, 1.0f, 1.0f);
      v.texCoords = Vector2(0.f, 0.f);
      meshVertices.push_back(v);
    }

    for (int32 i = 0; i < numIndices; ++i) {
      meshIndices.push_back(indices[i]);
    }

    Vector<Texture*> emptytextures;

    MeshTexture mTexture;
    mTexture.TextureMesh = g_graphicsAPI().textureFromFile("Models/Bea/bea_tex.png");

    emptytextures.push_back(mTexture.TextureMesh);
    emptytextures.push_back(mTexture.TextureMesh);
    emptytextures.push_back(mTexture.TextureMesh);
    emptytextures.push_back(mTexture.TextureMesh);

    SPtr<SamplerState> Samplers = graphicsApi.createSamplerState();

    return Mesh(meshVertices, meshIndices, emptytextures, Samplers);
  }


  
}
