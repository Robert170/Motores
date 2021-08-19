#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>
#include "xcModel.h"

namespace xcEngineSDK {


  Model::Model(const String& path) {

    loadFromFile(path);

  }

  void
  processMeshData(aiMesh* pMesh, Mesh& myMesh) {

    // walk through each of the mesh's vertices
    for (uint32 i = 0; i < pMesh->mNumVertices; ++i) {

      BoneVertex meshInfo;
      Vector4 vector;
      Vector3 bitan;

      if (pMesh->HasPositions()) {
        // positions
        vector.x = pMesh->mVertices[i].x;
        vector.y = pMesh->mVertices[i].y;
        vector.z = pMesh->mVertices[i].z;
        vector.w = 1;
        meshInfo.vertex = vector;
      }
      
      // normals
      if (pMesh->HasNormals()) {
        vector.x = pMesh->mNormals[i].x;
        vector.y = pMesh->mNormals[i].y;
        vector.z = pMesh->mNormals[i].z;
        meshInfo.normal = vector;
      }
      if (pMesh->HasTangentsAndBitangents()) {
        // tangent
        vector.x = pMesh->mTangents[i].x;
        vector.y = pMesh->mTangents[i].y;
        vector.z = pMesh->mTangents[i].z;
        meshInfo.tangent = vector;

        // bi tangent
        bitan.x = pMesh->mBitangents[i].x;
        bitan.y = pMesh->mBitangents[i].y;
        bitan.z = pMesh->mBitangents[i].z;
        meshInfo.biTangent = bitan;
      }
      // texture coordinates
      if (pMesh->mTextureCoords[0]) {

        Vector2 vec;
        vec.x = pMesh->mTextureCoords[0][i].x;
        vec.y = pMesh->mTextureCoords[0][i].y;
        meshInfo.texCoords = vec;
      }
      else {
        meshInfo.texCoords = Vector2::ZERO;
      }
      myMesh.m_Vertices.push_back(meshInfo);
      //data.meshData.push_back(meshInfo);
    }

    //Charge index
    for (uint32 i = 0; i < pMesh->mNumFaces; ++i) {
      aiFace face = pMesh->mFaces[i];

      for (uint32 j = 0; j < face.mNumIndices; ++j) {
        myMesh.m_Indices.push_back(face.mIndices[j]);
      }
    }
  }
    
  void
  processMeeshAnimation(aiMesh* pMesh, Mesh& myMesh) {

    BONES_INFO* skeletal = new BONES_INFO();

    if (pMesh->mNumBones != 0) {

      for (uint32 i = 0; i < pMesh->mNumBones; ++i) {

        uint32 boneIndex = 0;
        String boneName(pMesh->mBones[i]->mName.data);

        if (skeletal->BonesMap.find(boneName) == skeletal->BonesMap.end()) {
          boneIndex = skeletal->NumBones;
          skeletal->NumBones++;
          BONES bi;
          skeletal->VecSkeletal.push_back(bi);
        }
        else {
          boneIndex = skeletal->BonesMap[boneName];
        }

        skeletal->BonesMap[boneName] = boneIndex;

        std::memcpy(&skeletal->VecSkeletal[boneIndex].Offset,
                    &pMesh->mBones[i]->mOffsetMatrix,
                    sizeof(Matrix4x4));

        for (uint32 j = 0; j < pMesh->mBones[i]->mNumWeights; ++j) {

          uint32 temp = pMesh->mBones[i]->mWeights[j].mVertexId;
          float temp2 = pMesh->mBones[i]->mWeights[j].mWeight;

          for (uint32 k = 0; k < 4; k++) {


            if (myMesh.m_Vertices[temp].bonesWeight[k] == 0) {

              myMesh.m_Vertices[temp].id_Bones[k] = boneIndex;
              myMesh.m_Vertices[temp].bonesWeight[k] = temp2;
              break;
            }

          }
        }
      }
    }
    else {
      for (uint32 i = 0; i < pMesh->mNumVertices; i++) {
        for (uint32 j = 0; j < 4; j++) {

          myMesh.m_Vertices[i].bonesWeight[j] = 1;
        }
      }
    }

    SPtr<BONES_INFO> boneVertexData(skeletal);
    myMesh.m_pBonesInfo.reset(skeletal);
    myMesh.m_bonesTransforms.clear();
    myMesh.m_bonesTransforms.resize(skeletal->NumBones);
  }

  String
  getTexturePath(String file) {

    size_t realPos = 0;
    size_t posInvSlash = file.rfind('\\');
    size_t posSlash = file.rfind('/');

    if (posInvSlash == String::npos) {
      if (posSlash != String::npos) {
        realPos = posSlash;
      }
    }
    else {
      realPos = posInvSlash;
      if (!posSlash == String::npos) {
        if (posSlash > realPos) {
          posSlash = realPos;
        }
      }

    }
    return file.substr(realPos, file.length() - realPos);
  }

  void 
  loadMaterialTextures(aiMaterial* mat, 
                       aiTextureType type,
                       Mesh& myMesh,
                       String& directory) {

 
   
    auto& graphicsApi = g_graphicsAPI();
    Vector<Texture*> Texturesload;
    for (uint32 i = 0; i < 
         mat->GetTextureCount(static_cast<aiTextureType>(type)); ++i) {

      aiString str;
      mat->GetTexture(static_cast<aiTextureType>(type), i, &str);

      String filename = str.C_Str();
      filename = directory + getTexturePath(filename);
      //check if texture was loaded before and if so, continue to next iteration: 
      //skip loading a new texture
      bool skip = false;
      uint32 it = 0;
      for (auto& phats : myMesh.m_vPhats) {
        //TODO MeshTexture
        
        if (strcmp(phats.data(), filename.data()) ==  0) {
          Texturesload.push_back(myMesh.m_vTextures[it]);
          skip = true; // a texture with the same filepath has already been loaded, 
          break;
        }

      }
      if (!skip) {   // if texture hasn't been loaded already, load it
        
        myMesh.m_vTextures.push_back(graphicsApi.textureFromFile(filename));
        myMesh.m_vPhats.push_back(filename);
      }
      ++it;

    }

    

    return;

  }

  void
  processMeeshTexture(const aiScene* pScene, 
                      aiMesh* pMesh, 
                      Mesh& myMesh, 
                      String& directory) {

      // process materials
    aiMaterial* material = pScene->mMaterials[pMesh->mMaterialIndex];

     // 1. diffuse maps
    loadMaterialTextures(material,
                         aiTextureType_DIFFUSE, 
                         myMesh,
                         directory);

    //// 2. normal maps
    loadMaterialTextures(material,
                         aiTextureType_NORMALS, 
                         myMesh, 
                         directory);

    //// 3. metallic maps
    loadMaterialTextures(material,
                         aiTextureType_SPECULAR,
                         myMesh, 
                         directory);
   
    //// 4. Roughness  maps
    loadMaterialTextures(material, 
                         aiTextureType_SHININESS, 
                         myMesh,
                         directory);
  }

  void 
  addMeshNode(Model* pModel, const aiScene* pScene, const aiNode* parentNode) {

    if (!pScene->HasMeshes()) {
      return;
    }

    pModel->m_vMeshes.resize(pScene->mNumMeshes);



    for (uint32 i = 0; i < pScene->mNumMeshes; ++i) {
      auto assipMesh = pScene->mMeshes[i];
      auto& myMesh = pModel->m_vMeshes[i];
      processMeshData(assipMesh, myMesh);
      //processMeeshAnimation(assipMesh, myMesh);
      processMeeshTexture(pScene, assipMesh, myMesh, pModel->m_directory);
    }




 }

  bool 
  Model::loadFromFile(const String& filePath) {

    // read file via ASSIMP
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(filePath,
                              aiProcessPreset_TargetRealtime_MaxQuality |
                              aiProcess_ConvertToLeftHanded | 
                              aiProcess_Triangulate);

    // check for errors
    if (!scene ||
        scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE ||
        !scene->mRootNode) { // if is Not Zero

      std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
      return false;
    }
    // retrieve the directory path of the filepath
    m_directory = filePath.substr(0, filePath.find_last_of('/'));

    // process ASSIMP's root node recursively
    addMeshNode(this, scene, scene->mRootNode);

    auto& graphicsApi = g_graphicsAPI();

    SPtr<SamplerState> Samplers = graphicsApi.createSamplerState();

    for (uint32 i = 0; i < m_vMeshes.size(); ++i) {
      m_vMeshes[i].m_vSamplers.push_back(Samplers);
      m_vMeshes[i].setUpGPUMesh();
    }
    
    return true;
  }

  bool 
  Model::loadFromMemory(const char* pData, size_t sizeOfData) {
    return false;
  }

  void 
  Model::unload() {
  }

  void 
  Model::saveToFile(const String& filePath) {
  }


  void 
  Model::update(float delta) {

    uint32 numMeshes = m_vMeshes.size();

    for (uint32 i = 0; i < numMeshes; ++i) {
      m_vMeshes[i].update(delta);
    }
  }

  void 
  Model::render() {

    uint32 numMeshes = m_vMeshes.size();

    for (uint32 i = 0; i < numMeshes; ++i) {
      m_vMeshes[i].render();
    }
  }
}