#include "xcModel.h"
#include <xcShaderProgram.h>
#include <xcGraphiAPI.h>
namespace xcEngineSDK {

  Model::Model(String const& path, 
               GraphiAPI* API, 
               bool gamma) {

    gammaCorrection = gamma;

    //create sampler
    

    loadModel(path,
              API);

    m_sampler = API->createSamplerState(1);

    m_vSamplers.push_back(m_sampler);
  }

  void 
  Model::draw(ShaderProgram& shader,
              GraphiAPI* API) {
    for (uint32 i = 0; i < m_vMeshes.size(); i++) {

      m_vMeshes[i].draw(shader, 
                        m_vSamplers,
                        API);
    }
  }

  void 
  Model::update(float delta) {

    Vector<Matrix4x4> Transform;

    for (uint32 i = 0; i < m_vMeshes.size(); i++) {

      m_vMeshes[i].boneTrasnform(delta, Transform, m_scene);
    }
  }

  void 
  Model::loadModel(String const& path,
                   GraphiAPI* API) {
    /*XC_UNREFERENCED_PARAMETER(API);
    XC_UNREFERENCED_PARAMETER(path);*/
    // read file via ASSIMP
    Assimp::Importer importer;
    m_scene = importer.ReadFile(path,
                                aiProcess_Triangulate |
                                aiProcess_GenSmoothNormals |
                                aiProcess_FlipUVs |
                                aiProcess_CalcTangentSpace);
   

    // check for errors
    if (!m_scene ||
        m_scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE ||
        !m_scene->mRootNode) { // if is Not Zero

      std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
      return;
    }
    // retrieve the directory path of the filepath
    m_directory = path.substr(0, path.find_last_of('/'));

    // process ASSIMP's root node recursively
    processNode(m_scene->mRootNode,
                m_scene,
                API);
  }

  void 
  Model::processNode(aiNode* node,
                     const aiScene* scene,
                     GraphiAPI* API) {
    // process each mesh located at the current node
    for (uint32 i = 0; i < node->mNumMeshes; ++i)
    {
      // the node object only contains indices to index the actual objects in the scene. 
      // the scene contains all the data, node is just to keep stuff organized (like relations between nodes).
      aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
      
      m_vMeshes.push_back(processMesh(mesh, scene, API));
    }
    // after we've processed all of the meshes (if any) we then recursively process each of the children nodes
    for (uint32 i = 0; i < node->mNumChildren; ++i)
    {
      processNode(node->mChildren[i], scene, API);
    }
  }

  Mesh
  Model::processMesh(aiMesh* mesh,
                     const aiScene* scene,
                     GraphiAPI* API) {
    // data to fill
    Vector<BoneVertex> vertices;
    Vector<uint32> indices;
    Vector<Texture> Textures;
    BoneVertex* structVertex = new BoneVertex[mesh->mNumVertices];
    // walk through each of the mesh's vertices
    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        Vector3 vector; 

        // positions
        vector.m_x = mesh->mVertices[i].x;
        vector.m_y = mesh->mVertices[i].y;
        vector.m_z = mesh->mVertices[i].z;
        structVertex[i].Position = vector;
        // normals
        if (mesh->HasNormals())
        {
            /*vector.m_x = mesh->mNormals[i].x;
            vector.m_y = mesh->mNormals[i].y;
            vector.m_z = mesh->mNormals[i].z;
            Vertex.Normal = vector;*/
        }
        // texture coordinates
        if (mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
        {
            Vector2 vec;
            // a vertex can contain up to 8 different texture coordinates. 
            //We thus make the assumption that we won't 
            // use models where a vertex can have multiple texture coordinates so we always
            //take the first set (0).
            /*vec.m_x = mesh->mTextureCoords[0][i].x;
            vec.m_y = mesh->mTextureCoords[0][i].y;
            Vertex.TexCoords = vec;*/
            // tangent
            /*vector.m_x = mesh->mTangents[i].x;
            vector.m_y = mesh->mTangents[i].y;
            vector.m_z = mesh->mTangents[i].z;
            Vertex.Tangent = vector;*/
            // bitangent
            /*vector.m_x = mesh->mBitangents[i].x;
            vector.m_y = mesh->mBitangents[i].y;
            vector.m_z = mesh->mBitangents[i].z;
            Vertex.Bitangent = vector;*/
        }
        else
        {
           // Vertex.Tex = Vector2(0.f,0.f);
        }

        vertices.push_back(structVertex[i]);
    }
    // now weak through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        // retrieve all indices of the face and store them in the indices vector
        for (unsigned int j = 0; j < face.mNumIndices; j++)
        {
            indices.push_back(face.mIndices[j]);
        }
    }


    //Charge bones
    BONES_INFO* skeletal = new BONES_INFO(); 

    if (mesh->mNumBones != 0) {

      for (uint32 i = 0; i < mesh->mNumBones; i++) {

        uint32 boneIndex = 0;
        String boneName(mesh->mBones[i]->mName.data);

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
                    &mesh->mBones[i]->mOffsetMatrix, 
                    sizeof(Matrix4x4));

        for (uint32 j = 0; j < mesh->mBones[i]->mNumWeights; j++) {
         
          uint32 temp = mesh->mBones[i]->mWeights[j].mVertexId;
          float temp2 = mesh->mBones[i]->mWeights[j].mWeight;

          for (uint32 k = 0; k < 4; k++) {


            if (structVertex[temp].bonesWeight == 0) {

              structVertex[temp].id_Bones[k] = boneIndex;
              structVertex[temp].bonesWeight = temp2;
              break;
            }

          }
        }
      }
    }
    else {
      for (uint32 i = 0; i < mesh->mNumVertices; i++) {
        for (uint32 j = 0; j < 4; j++) {

          structVertex[i].bonesWeight = 1;
        }
      }
    }

    //m_mesh = new Mesh();

    //m_mesh->m_pBonesInfo.reset(skeletal);
    //m_mesh->m_pBoneVertex.reset(structVertex);
    ///*m_mesh->m_Vertices = vertices;
    //m_mesh->m_Indices = indices;*/
    //m_mesh->m_bonesTransforms.clear();
    //m_mesh->m_bonesTransforms.resize(skeletal->NumBones);


    // process materials
    aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

    // 1. diffuse maps
    loadMaterialTextures(material,
                         aiTextureType_DIFFUSE, 
                         "texture_diffuse", 
                         API);
   /*Textures.insert(Textures.end(),
                    diffuseMaps.begin(), 
                    diffuseMaps.end());*/
    // 2. specular maps
    loadMaterialTextures(material,
                         aiTextureType_SPECULAR, 
                         "texture_specular", 
                         API);
    /*Textures.insert(Textures.end(),
                            specularMaps.begin(), 
                            specularMaps.end());*/
    // 3. normal maps
    loadMaterialTextures(material,
                         aiTextureType_HEIGHT,
                         "texture_normal", 
                         API);
    /*Textures.insert(Textures.end(),
                            normalMaps.begin(), 
                            normalMaps.end());*/
    // 4. height maps
    loadMaterialTextures(material, 
                         aiTextureType_AMBIENT, 
                         "texture_height", 
                         API);
   /* Textures.insert(Textures.end(),
                            heightMaps.begin(), 
                            heightMaps.end());*/

    // return a mesh object created from the extracted mesh data
    return Mesh(vertices,
                indices,
                m_texturesloaded,
                m_vSamplers,
                skeletal,
                structVertex,
                skeletal->NumBones,
                API);

    
  }

  void 
  Model::loadMaterialTextures(aiMaterial* mat, 
                              aiTextureType type, 
                              String typeName,
                              GraphiAPI* API) {
    Vector<TextureB*> Textures;
    for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
      aiString str;
      mat->GetTexture(type, i, &str);

      String filename = str.C_Str();
      filename = m_directory + "/" + getTexturePath(filename);
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
          //continue to next one. (optimization)
          break;
        }
        if (!skip) {   // if texture hasn't been loaded already, load it
        
       
          m_texturesloaded.push_back(API->textureFromFile(filename,
                                                          this->m_directory, 
                                                          API));
        }
      }
      
    }
    return;
  }

  String
  Model::getTexturePath(String file) {
    size_t realPos = 0;
	  size_t posInvSlash = file.rfind('\\');
	  size_t posSlash = file.rfind('/');

	  if (posInvSlash == std::string::npos) {
	  	if (posSlash != std::string::npos) {
	  		realPos = posSlash;
	  	}
	  }
	  else {
	  	realPos = posInvSlash;
	  	if (!posSlash == std::string::npos) {
	  		if (posSlash > realPos) {
	  			posSlash = realPos;
	  		}
	  	}

	  }
	  return file.substr(realPos, file.length() - realPos);
  }
  
}