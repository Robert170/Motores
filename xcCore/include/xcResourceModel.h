/*****************************************************************************/
/**
 * @file    xcResourceModel.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/07/17
 * @brief   Represents the resource of the model
 *
 * Represents all nodes of the scene
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once

/*****************************************************************************/
/**
 * Includes
 */
 /*****************************************************************************/
#include "xcPrerequisitesCore.h"
#include "xcComponent.h"
#include "xcMesh.h"

namespace xcEngineSDK {

  class ResourceModel : public Component
  {
   public:
    ResourceModel() = default;

    ResourceModel(const String& path);


    ~ResourceModel() = default;


    void 
    update(float deltaTime) override;

    void 
    render() override; 

   private:

    /**
     * @brief      loadModel function, to load the model
     * @param      path parameter one, path of the model
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    void 
    loadModel(const String& path);

    /**
     * @brief      processNode function, to process node of the model
     * @param      node parameter one, node of the model
     * @param      scene parameter two, scene of the model
     * @param      API parameter three, api to have acces to diferent functions
     * @bug		     No know Bugs
     * @return     Returns nothing
     */
    void 
    processNode(aiNode* node, 
                const aiScene* scene);

    /**
     * @brief      processMesh function, to process node of the mesh
     * @param      mesh parameter one, mesh of the model
     * @param      scene parameter two, scene of the model
     * @bug		     No know Bugs
     * @return     Returns a mesh
     */
    Mesh 
    processMesh(aiMesh* mesh, 
                const aiScene* scene);

    /**
     * @brief      processMesh function, to process node of the mesh
     * @param      mesh parameter one, mesh of the model
     * @param      vertex parameter two, struc to obtain the number of vertex
     * @bug		     No know Bugs
     * @return     Returns a mesh
     */
    void 
    loadAnimation(aiMesh* mesh, 
                  Vector<BoneVertex>& vertex,
                  BONES_INFO* skelletal);

    /**
     * @brief      LoadMaterialTextures function, to load material of the model
     * @param      mat parameter one, material of the model
     * @param      type parameter two, type of material of the model
     * @param      typeName parameter three, name of the material
     * @bug		 No know Bugs
     * @return     Returns nothing
     */
    void 
    loadMaterialTextures(aiMaterial* mat,
                         aiTextureType type);

    /**
     * @brief      getTexturePath function, get real path of the texture
     * @param      file parameter one, path of the texture
     * @bug		     No know Bugs
     * @return     Returns a string with the path of the texture
     */
    String 
    getTexturePath(String file);

   private:

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
    Vector<Mesh>  m_vMeshes;

    /**
     * @Variable m_Directory, directory of textures
     */
    String m_directory;

    /**
     * @Variable m_Texture, texture of model
     */
    Texture* m_texture = nullptr;

    /**
     * @Variable m_Sampler, sampler of model
     */
    SPtr<SamplerState> m_sampler;

    /**
     * @Variable m_importer, iporter of assimp
     */
    Assimp::Importer m_importer;

    /**
     * @Variable m_scene, sampler of scene of assimp
     */
    const aiScene* m_scene;

    /**
     * @Variable m_mesh, mesh of model
     */
    Mesh* m_mesh = nullptr;

  };

}