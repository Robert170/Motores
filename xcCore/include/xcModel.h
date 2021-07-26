/**
 * @class CModel
 *
 * @brief class for the model
 *
 * This class is the  for model of Directx and opengl
 *
 * @author Roberto Ramirez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 12/3/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include <xcPrerequisitesCore.h>
#include <xcShaderProgram.h>
#include <xcInputLayout.h>
#include "xcComponent.h"
#include "xcMesh.h"

namespace xcEngineSDK {

  class XC_CORE_EXPORT Model : public Component
  {
   public:

    Model() = default;
    ~Model() = default;

    Model(String const& path,
          bool gamma = false);


    /*void 
    init(String const& path,
         GraphiAPI* API,
         InputLayout_Desc InpLayDesc,
         bool gamma = false);*/

    // draws the model, and thus all its meshes
    void 
    render() override;

    void 
    update(float deltaTime) override;

    void
    update(float delta, Vector<Matrix4x4>& transform);

   private:

    void 
    loadModel(String const& path);

    /**
       * @brief      processNode function, to process node of the model
       * @param      node parameter one, node of the model
       * @param      scene parameter two, scene of the model
       * @param      API parameter three, api to have acces to diferent functions
       * @bug		 No know Bugs
       * @return     Returns nothing
     */
    void 
    processNode(aiNode* node, 
                const aiScene* scene);

    /**
       * @brief      processMesh function, to process node of the mesh
       * @param      mesh parameter one, mesh of the model
       * @param      scene parameter two, scene of the model
       * @param      API parameter three, api to have acces to diferent functions
       * @bug		 No know Bugs
       * @return     Returns a mesh
     */
    Mesh*
    processMesh(aiMesh* mesh, 
                const aiScene* scene);

    /**
      * @brief      LoadMaterialTextures function, to load material of the model
      * @param      mat parameter one, material of the model
      * @param      type parameter two, type of material of the model
      * @param      typeName parameter three, name of the material
      * @param      API parameter four, api to have acces to diferent functions
      * @bug		 No know Bugs
      * @return     Returns nothing
    */
    void 
    loadMaterialTextures(aiMaterial* mat,
                         aiTextureType type, 
                         String typeName);


    String 
    getTexturePath(String file);

   public:
     /**
       * @brief private variables
     */
     // model data 

     /**
       * @Variable m_Texturesloaded, is for all textures of the model
     */
     Vector<Texture*> m_texturesloaded;

     /**
       * @Variable m_vSamplers, is for all samplers
     */
     Vector<SamplerState*> m_vSamplers;

     /**
       * @Variable m_vMeshes, is for all Meshes
     */
     Vector<Mesh*>  m_vMeshes;

     InputLayout_Desc m_inpLayDesc;

     /**
       * @Variable m_Directory, directory of textures
     */
     String m_directory;
     bool gammaCorrection = false;

     /**
       * @Variable m_Texture, texture of model
     */
     Texture* m_texture = nullptr;

     /**
       * @Variable m_Sampler, sampler of model
     */
     SPtr<SamplerState> m_sampler;
     Assimp::Importer m_importer;
     const aiScene* m_scene;

     Mesh* m_mesh;

  };

}