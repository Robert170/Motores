#include "xcResourceModel.h"



namespace xcEngineSDK {

  ResourceModel::ResourceModel(const String& path) {

    auto& graphicsApi = g_graphicsAPI();

    loadModel(path);

    //create sampler

    m_sampler = graphicsApi.createSamplerState(1);

    m_vSamplers.push_back(m_sampler.get());
  }
  void 
  ResourceModel::render() {
    uint32 numMeshes = m_vMeshes.size();


    for (uint32 i = 0; i < numMeshes; i++) {

      m_vMeshes[i].render();
    }
  }

  void 
  ResourceModel::update(float deltaTime) {
    uint32 numMeshes = m_vMeshes.size();

    for (uint32 i = 0; i < numMeshes; ++i) {
      m_vMeshes[i].update(deltaTime);
    }
  }

  void 
  ResourceModel::loadModel(const String& path) {

    m_scene = m_importer.ReadFile(path,
                                  aiProcessPreset_TargetRealtime_MaxQuality |
                                  aiProcess_ConvertToLeftHanded | 
                                  aiProcess_Triangulate);
    // check for errors
    if (!m_scene ||
        m_scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE ||
        !m_scene->mRootNode) { // if is Not Zero

      std::cout << "ERROR::ASSIMP:: " << m_importer.GetErrorString() << std::endl;
      return;
    }

    // retrieve the directory path of the filepath
    m_directory = path.substr(0, path.find_last_of('/'));

    // process ASSIMP's root node recursively
    processNode(m_scene->mRootNode,
                m_scene);
  }

  void 
  ResourceModel::processNode(aiNode* node, const aiScene* scene) {

    for (uint32 i = 0; i < node->mNumMeshes; ++i) {
      
      aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];

      m_vMeshes.push_back(processMesh(mesh, scene));
    }
    
    for (uint32 i = 0; i < node->mNumChildren; ++i) {
      processNode(node->mChildren[i], scene);
    }

  }

  Mesh 
  ResourceModel::processMesh(aiMesh* mesh, const aiScene* scene) {
    // data to fill
    Vector<BoneVertex> vertices;
    Vector<uint32> indices;
    //Vector<Texture> Textures;
    BoneVertex* structVertex = new BoneVertex[mesh->mNumVertices];
    // walk through each of the mesh's vertices
    for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
        Vector4 vector; 

        // positions
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        vector.w = 1;
        structVertex[i].Position = vector;
        // normals
        if (mesh->HasNormals()) {
          /*vector.x = mesh->mNormals[i].x;
          vector.y = mesh->mNormals[i].y;
          vector.z = mesh->mNormals[i].z;
          structVertex[i].normal = vector;*/
        }
        if (mesh->HasTangentsAndBitangents()) {
          // tangent
            /*vector.x = mesh->mTangents[i].x;
            vector.y = mesh->mTangents[i].y;
            vector.z = mesh->mTangents[i].z;
            structVertex[i].tangent = vector;*/
            // bi tangent
            /*vector.x = mesh->mBitangents[i].x;
            vector.y = mesh->mBitangents[i].y;
            vector.z = mesh->mBitangents[i].z;
            Vertex.Bitangent = vector;*/
        }
        // texture coordinates
        if (mesh->mTextureCoords[0]) {
            Vector2 vec;
            
            vec.x = mesh->mTextureCoords[0][i].x;
            vec.y = mesh->mTextureCoords[0][i].y;
            structVertex[i].TexCoords = vec;
        }
        else {
          structVertex[i].TexCoords = Vector2(0.f,0.f);
        }

        vertices.push_back(structVertex[i]);
    }

    for (unsigned int i = 0; i < mesh->mNumFaces; ++i) {
        aiFace face = mesh->mFaces[i];
        // retrieve all indices of the face and store them in the indices vector
        for (unsigned int j = 0; j < face.mNumIndices; ++j) {
            indices.push_back(face.mIndices[j]);
        }
    }


    //Charge bones
    BONES_INFO* skeletal = new BONES_INFO(); 
    loadAnimation(mesh, vertices, skeletal);
  
    // process materials
    aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

    // 1. diffuse maps
    loadMaterialTextures(material,
                         aiTextureType_DIFFUSE);

    //// 2. specular maps
    //loadMaterialTextures(material,
    //                     aiTextureType_SPECULAR);

    //// 3. normal maps
    //loadMaterialTextures(material,
    //                     aiTextureType_HEIGHT);
    
    //// 4. height maps
    //loadMaterialTextures(material, 
    //                     aiTextureType_AMBIENT);

    // return a mesh object created from the extracted mesh data
    return Mesh(vertices,
                indices,
                m_texturesloaded,
                m_vSamplers,
                m_scene);
  }

  void 
  ResourceModel::loadAnimation(aiMesh* mesh,
                               Vector<BoneVertex>& vertex, 
                               BONES_INFO* skeletal) {
    if (mesh->mNumBones != 0) {

      uint32 numBones = mesh->mNumBones;

      for (uint32 i = 0; i < numBones; ++i) {

        auto bone = mesh->mBones[i];
        uint32 boneIndex = 0;
        String boneName(bone->mName.data);

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
                    &bone->mOffsetMatrix,
                    sizeof(Matrix4x4));

        uint32 numWeights = bone->mNumWeights;

        for (uint32 j = 0; j < numWeights; ++j) {

          uint32 temp = bone->mWeights[j].mVertexId;
          float temp2 = bone->mWeights[j].mWeight;

          for (uint32 k = 0; k < 4; k++) {


            if (vertex[temp].bonesWeight[k] == 0) {

              vertex[temp].id_Bones[k] = boneIndex;
              vertex[temp].bonesWeight[k] = temp2;
              break;
            }

          }
        }
      }
    }
    else {
      for (uint32 i = 0; i < mesh->mNumVertices; ++i) {
        for (uint32 j = 0; j < 4; ++j) {

          vertex[i].bonesWeight[j] = 1;
        }
      }
    }

    SPtr<BONES_INFO> boneVertexData(skeletal);
    m_mesh->m_pBonesInfo.reset(skeletal);
    m_mesh->m_bonesTransforms.clear();
    m_mesh->m_bonesTransforms.resize(skeletal->NumBones);
  }

  void 
  ResourceModel::loadMaterialTextures(aiMaterial* mat, 
                                      aiTextureType type) {

    auto graphicsApi = g_graphicsAPI().instancePtr();
    Vector<Texture*> Textures;
    for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
      aiString str;
      mat->GetTexture(type, i, &str);

      String filename = str.C_Str();
      filename = m_directory + getTexturePath(filename);
      //check if texture was loaded before and if so, continue to next iteration: 
      //skip loading a new texture
      bool skip = false;
      for (unsigned int j = 0; j < m_texturesloaded.size(); j++)
      {
        //TODO MeshTexture

        if (m_texturesloaded[j] != nullptr)
        {
          Textures.push_back(m_texturesloaded[j]);
          skip = true; // a texture with the same filepath has already been loaded, 
          break;
        }

      }
      if (!skip) {   // if texture hasn't been loaded already, load it


        m_texturesloaded.push_back(graphicsApi->textureFromFile(filename));
      }

    }
    return;

  }

  String 
  ResourceModel::getTexturePath(String file) {
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
}