
#include "xcResource.h"


namespace xcEngineSDK {

  //ResourceModel::ResourceModel(const String& path) {

  //  loadModel(path);
  //}

  //void 
  //ResourceModel::loadModel(const String& path) {

  //  // read file via ASSIMP
  //  Assimp::Importer importer;
  //  const aiScene* scene = importer.ReadFile(path,
  //                            aiProcessPreset_TargetRealtime_MaxQuality |
  //                            aiProcess_ConvertToLeftHanded | 
  //                            aiProcess_Triangulate);

  //  // check for errors
  //  if (!scene ||
  //      scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE ||
  //      !scene->mRootNode) { // if is Not Zero

  //    std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
  //    return;
  //  }
  //  // retrieve the directory path of the filepath
  //  m_directory = path.substr(0, path.find_last_of('/'));

  //  // process ASSIMP's root node recursively
  //  processNode(scene->mRootNode, &scene);
  //  
  //}

  //void 
  //ResourceModel::processNode(void* node, void* scene) {

  //  auto tempNode = reinterpret_cast<aiNode*>(node);
  //  auto tempScene = reinterpret_cast<aiScene*>(scene);

  //  // process each mesh located at the current node
  //  for (uint32 i = 0; i < tempNode->mNumMeshes; ++i) {
  //    // the node object only contains indices to index the actual objects in the scene. 
  //    // the scene contains all the data, node is just to keep stuff organized (like relations between nodes).
  //    aiMesh* mesh = tempScene->mMeshes[tempNode->mMeshes[i]];

  //    m_vModelData.push_back(processMesh(&mesh, scene));
  //  }
 
  //  for (uint32 i = 0; i < tempNode->mNumChildren; ++i) {
  //    processNode(tempNode->mChildren[i], scene);
  //  }

  //}

  //ModelData 
  //ResourceModel::processMesh(void* mesh, void* scene) {

  //  auto& graphicsApi = g_graphicsAPI();
  //  auto tempMesh = reinterpret_cast<aiMesh*>(mesh);
  //  auto tempScene = reinterpret_cast<aiScene*>(scene);

  //  ModelData fullData;

  //  loadVertexData(mesh, fullData);
  //  
  //  //Charge bones

  //  loadAnimationData(mesh, fullData);

  //  // process materials
  //  aiMaterial* material = tempScene->mMaterials[tempMesh->mMaterialIndex];

  //   // 1. diffuse maps
  //  loadMaterialTextures(material,
  //                       TextureType_DIFFUSE, 
  //                       fullData);

  //  //// 2. specular maps
  //  loadMaterialTextures(material,
  //                       TextureType_SPECULAR, 
  //                       fullData);

  //  //// 3. normal maps
  //  loadMaterialTextures(material,
  //                       TextureType_HEIGHT,
  //                       fullData);
  // 
  //  //// 4. height maps
  //  loadMaterialTextures(material, 
  //                       TextureType_AMBIENT, 
  //                       fullData);

  //  fullData.scene = scene;
  //  
  //    

  //  /*SPtr<BONES_INFO> boneVertexData(skeletal);
  //  m_mesh->m_pBonesInfo.reset(skeletal);
  //  m_mesh->m_bonesTransforms.clear();
  //  m_mesh->m_bonesTransforms.resize(skeletal->NumBones);*/

  //  //create sampler

  //  //fullData.samplers.push_back(graphicsApi.createSamplerState(1).get());

  //  return fullData;
  //}

  //void 
  //ResourceModel::loadVertexData(void* mesh, ModelData& data) {

  //  auto tempMesh = reinterpret_cast<aiMesh*>(mesh);


  //  // walk through each of the mesh's vertices
  //  for (uint32 i = 0; i < tempMesh->mNumVertices; ++i) {

  //    BoneVertex meshInfo;
  //    Vector4 vector; 

  //    // positions
  //    vector.x = tempMesh->mVertices[i].x;
  //    vector.y = tempMesh->mVertices[i].y;
  //    vector.z = tempMesh->mVertices[i].z;
  //    vector.w = 1;
  //    meshInfo.vertex = vector;
  //    // normals
  //    if (tempMesh->HasNormals()) {
  //      vector.x = tempMesh->mNormals[i].x;
  //      vector.y = tempMesh->mNormals[i].y;
  //      vector.z = tempMesh->mNormals[i].z;
  //      meshInfo.normal = vector;
  //    }
  //    if (tempMesh->HasTangentsAndBitangents()) {
  //      // tangent
  //      vector.x = tempMesh->mTangents[i].x;
  //      vector.y = tempMesh->mTangents[i].y;
  //      vector.z = tempMesh->mTangents[i].z;
  //      meshInfo.tangent = vector;
  //      // bi tangent
  //      /*vector.x = tempMesh.mBitangents[i].x;
  //      vector.y = tempMesh.mBitangents[i].y;
  //      vector.z = tempMesh.mBitangents[i].z;
  //      modelData. = vector;*/
  //    }
  //    // texture coordinates
  //    if (tempMesh->mTextureCoords[0]) {

  //      Vector2 vec;
  //      vec.x = tempMesh->mTextureCoords[0][i].x;
  //      vec.y = tempMesh->mTextureCoords[0][i].y;
  //      meshInfo.texCoords = vec;
  //    }
  //    else
  //    {
  //      meshInfo.texCoords = Vector2::ZERO;
  //    }
  //    
  //    data.meshData.push_back(meshInfo);
  //  }

  //  //Charge index
  //  for (uint32 i = 0; i < tempMesh->mNumFaces; ++i) {
  //    aiFace face = tempMesh->mFaces[i];

  //    for (uint32 j = 0; j < face.mNumIndices; ++j) {
  //      data.index.push_back(face.mIndices[j]);
  //    }
  //  }
  //}

  //void 
  //ResourceModel::loadAnimationData(void* mesh, ModelData& data) {

  //  auto tempMesh = reinterpret_cast<aiMesh*>(mesh);

  //  BONES_INFO* skeletal = new BONES_INFO();

  //  if (tempMesh->mNumBones != 0) {

  //    for (uint32 i = 0; i < tempMesh->mNumBones; ++i) {

  //      uint32 boneIndex = 0;
  //      String boneName(tempMesh->mBones[i]->mName.data);

  //      if (skeletal->BonesMap.find(boneName) == skeletal->BonesMap.end()) {
  //        boneIndex = skeletal->NumBones;
  //        skeletal->NumBones++;
  //        BONES bi;
  //        skeletal->VecSkeletal.push_back(bi);
  //      }
  //      else {
  //        boneIndex = skeletal->BonesMap[boneName];
  //      }

  //      skeletal->BonesMap[boneName] = boneIndex;

  //      std::memcpy(&skeletal->VecSkeletal[boneIndex].Offset,
  //        &tempMesh->mBones[i]->mOffsetMatrix,
  //        sizeof(Matrix4x4));

  //      for (uint32 j = 0; j < tempMesh->mBones[i]->mNumWeights; ++j) {

  //        uint32 temp = tempMesh->mBones[i]->mWeights[j].mVertexId;
  //        float temp2 = tempMesh->mBones[i]->mWeights[j].mWeight;

  //        for (uint32 k = 0; k < 4; k++) {


  //          if (data.meshData[temp].bonesWeight[k] == 0) {

  //            data.meshData[temp].id_Bones[k] = boneIndex;
  //            data.meshData[temp].bonesWeight[k] = temp2;
  //            break;
  //          }

  //        }
  //      }
  //    }
  //  }
  //  else {
  //    for (uint32 i = 0; i < tempMesh->mNumVertices; i++) {
  //      for (uint32 j = 0; j < 4; j++) {

  //        data.meshData[i].bonesWeight[j] = 1;
  //      }
  //    }
  //  }

  //  data.skeletal = skeletal;
  //}

  //void 
  //ResourceModel::loadMaterialTextures(void* mat,
  //                                    TEXTURE_TYPE type,
  //                                    ModelData& data) {

  //  auto tempMaterial = reinterpret_cast<aiMaterial*>(mat);
  // 
  //  auto& graphicsApi = g_graphicsAPI();
  //  Vector<Texture*> Texturesload;
  //  Vector<Texture*> TexturesToload;
  //  for (unsigned int i = 0; i < 
  //    tempMaterial->GetTextureCount(static_cast<aiTextureType>(type)); ++i) {

  //    aiString str;
  //    tempMaterial->GetTexture(static_cast<aiTextureType>(type), i, &str);

  //    String filename = str.C_Str();
  //    filename = m_directory + getTexturePath(filename);
  //    //check if texture was loaded before and if so, continue to next iteration: 
  //    //skip loading a new texture
  //    bool skip = false;
  //    for (unsigned int j = 0; j < data.modelTextures.size(); j++)
  //    {
  //      //TODO MeshTexture

  //      if (data.modelTextures[j] != nullptr)
  //      {
  //        Texturesload.push_back(data.modelTextures[j]);
  //        skip = true; // a texture with the same filepath has already been loaded, 
  //        break;
  //      }

  //    }
  //    if (!skip) {   // if texture hasn't been loaded already, load it
  //      
  //      data.modelTextures.push_back(graphicsApi.textureFromFile(filename));
  //    }

  //  }

  //  

  //  return;

  //}

  //String 
  //ResourceModel::getTexturePath(String file) {

  //  size_t realPos = 0;
  //  size_t posInvSlash = file.rfind('\\');
  //  size_t posSlash = file.rfind('/');

  //  if (posInvSlash == String::npos) {
  //    if (posSlash != String::npos) {
  //      realPos = posSlash;
  //    }
  //  }
  //  else {
  //    realPos = posInvSlash;
  //    if (!posSlash == String::npos) {
  //      if (posSlash > realPos) {
  //        posSlash = realPos;
  //      }
  //    }

  //  }
  //  return file.substr(realPos, file.length() - realPos);
  //}
  
}