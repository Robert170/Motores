#include "xcModel.h"
namespace xcEngineSDK {
  Model::Model() {
    gammaCorrection = false;
  }

  Model::~Model() {
  }

  void 
  Model::init(std::string const& path,
              GraphiAPI* API,
              InputLayout_Desc InpLayDesc,
              bool gamma) {
    XC_UNREFERENCED_PARAMETER(gamma);
    m_inpLayDesc = InpLayDesc;
    loadModel(path,
              API);
  }

  void 
  Model::draw(ShaderProgram& shader,
              GraphiAPI* API) {
    for (uint32 i = 0; i < meshes.size(); ++i) {
      meshes[i].draw(shader,
                     API);
    }
  }

  void 
  Model::loadModel(std::string const& path,
                    GraphiAPI* API) {
    XC_UNREFERENCED_PARAMETER(API);
    XC_UNREFERENCED_PARAMETER(path);
    //// read file via ASSIMP
    //Assimp::Importer importer;
    //const aiScene* scene = importer.ReadFile(path,
    //                                         aiProcess_Triangulate |
    //                                         aiProcess_GenSmoothNormals |
    //                                         aiProcess_FlipUVs |
    //                                         aiProcess_CalcTangentSpace);
    //// check for errors
    //if (!scene || 
    //    scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || 
    //    !scene->mRootNode) { // if is Not Zero

    //  std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
    //  return;
    //}
    //// retrieve the directory path of the filepath
    //directory = path.substr(0, path.find_last_of('/'));

    //// process ASSIMP's root node recursively
    //processNode(scene->mRootNode,
    //            scene,
    //            API);
  }

  //void 
  //Model::processNode(aiNode* node,
  //                   const aiScene* scene,
  //                   GraphiAPI* API) {
  //  // process each mesh located at the current node
  //  for (uint32 i = 0; i < node->mNumMeshes; )
  //  {
  //    // the node object only contains indices to index the actual objects in the scene. 
  //    // the scene contains all the data, node is just to keep stuff organized (like relations between nodes).
  //    aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
  //    meshes.push_back(processMesh(mesh, scene, API));
  //  }
  //  // after we've processed all of the meshes (if any) we then recursively process each of the children nodes
  //  for (uint32 i = 0; i < node->mNumChildren; ++i)
  //  {
  //    processNode(node->mChildren[i], scene, API);
  //  }
  //}

  //Mesh 
  //Model::processMesh(aiMesh* mesh,
  //                   const aiScene* scene,
  //                   GraphiAPI* API) {
  //  // data to fill
  //  std::vector<SimpleVertex> vertices;
  //  std::vector<unsigned int> indices;
  //  //std::vector<Texture> textures;

  //  // walk through each of the mesh's vertices
  //  for (unsigned int i = 0; i < mesh->mNumVertices; ++i)
  //  {
  //    SimpleVertex vertex;
  //    Vector3 vector; // we declare a placeholder vector since assimp uses its own vector class that doesn't directly convert to glm's vec3 class so we transfer the data to this placeholder glm::vec3 first.
  //    // positions
  //    vector.m_x = mesh->mVertices[i].x;
  //    vector.m_y = mesh->mVertices[i].y;
  //    vector.m_z = mesh->mVertices[i].z;
  //    vertex.Pos = vector;
  //    // normals
  //    /*if (mesh->HasNormals())
  //    {
  //        vector.x = mesh->mNormals[i].x;
  //        vector.y = mesh->mNormals[i].y;
  //        vector.z = mesh->mNormals[i].z;
  //        vertex.Normal = vector;
  //    }*/
  //    // texture coordinates
  //    if (mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
  //    {
  //      Vector2 vec;
  //      // a vertex can contain up to 8 different texture coordinates. We thus make the assumption that we won't 
  //      // use models where a vertex can have multiple texture coordinates so we always take the first set (0).
  //      vec.m_x = mesh->mTextureCoords[0][i].x;
  //      vec.m_y = mesh->mTextureCoords[0][i].y;
  //      vertex.Tex = vec;
  //      //// tangent
  //      //vector.x = mesh->mTangents[i].x;
  //      //vector.y = mesh->mTangents[i].y;
  //      //vector.z = mesh->mTangents[i].z;
  //      //vertex.Tangent = vector;
  //      //// bitangent
  //      //vector.x = mesh->mBitangents[i].x;
  //      //vector.y = mesh->mBitangents[i].y;
  //      //vector.z = mesh->mBitangents[i].z;
  //      //vertex.Bitangent = vector;
  //    }
  //    else
  //    {
  //      vertex.Tex = Vector2(0.0f, 0.0f);
  //    }

  //    vertices.push_back(vertex);
  //  }
  //  // now wak through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
  //  for (uint32 i = 0; i < mesh->mNumFaces; ++i) {
  //    aiFace face = mesh->mFaces[i];
  //    // retrieve all indices of the face and store them in the indices vector
  //    for (uint32 j = 0; j < face.mNumIndices; j++) {
  //      indices.push_back(face.mIndices[j]);
  //    }
  //  }
  //  // process materials
  //  aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
  //  // we assume a convention for sampler names in the shaders. Each diffuse texture should be named
  //  // as 'texture_diffuseN' where N is a sequential number ranging from 1 to MAX_SAMPLER_NUMBER. 
  //  // Same applies to other texture as the following list summarizes:
  //  // diffuse: texture_diffuseN
  //  // specular: texture_specularN
  //  // normal: texture_normalN

  //  // 1. diffuse maps
  //  //std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
  //  //textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
  //  //// 2. specular maps
  //  //std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
  //  //textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
  //  //// 3. normal maps
  //  //std::vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
  //  //textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
  //  //// 4. height maps
  //  //std::vector<Texture> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
  //  //textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());

  //  // return a mesh object created from the extracted mesh data
  //  return Mesh(vertices,
  //              indices,
  //              m_inpLayDesc,
  //              //textures, 
  //              API);
  //}
}