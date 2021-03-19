/**
 * @class CModel
 *
 * @brief class for the model
 *
 * This class is the  for model of Directx and opengl
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 12/3/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <fstream>
#include <sstream>
#include "xcMesh.h"

namespace xcEngineSDK {
  class Model
  {
   public:
    // model data 
    //std::vector<Texture> textures_loaded;	
    std::vector<Mesh>  meshes;
    std::string directory;
    bool gammaCorrection;
    InputLayout_Desc m_inpLayDesc;

    Model();
    ~Model();


    void 
    init(std::string const& path,
         GraphiAPI* API,
         InputLayout_Desc InpLayDesc,
         bool gamma = false);

    // draws the model, and thus all its meshes
    void 
    draw(ShaderProgram& shader, 
         GraphiAPI* API);

   private:

    void 
    loadModel(std::string const& path, 
              GraphiAPI* API);

    void 
    processNode(aiNode* node, 
                const aiScene* scene,
                GraphiAPI* API);

    Mesh 
    processMesh(aiMesh* mesh, 
                const aiScene* scene, 
                GraphiAPI* API);

    // checks all material textures of a given type and loads the textures if they're not loaded yet.
    // the required info is returned as a Texture struct.
    //std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);;
  };

}