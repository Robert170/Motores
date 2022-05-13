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

#include <xcGraphiAPI.h>

#include "xcPrerequisitesCore.h"




namespace xcEngineSDK {

  class XC_CORE_EXPORT Resource
  {
   public:
     Resource() = default;

    virtual ~Resource() = default;


   public:
    
    //Functions to load data
    virtual bool loadFromFile(const String& filePath) = 0;
    virtual bool loadFromMemory(const char* pData, size_t sizeOfData) = 0;
    virtual bool loadXcFile(const String& filePath) = 0;

    //Functions to unload data
    virtual void unload() = 0;

    //Functions of serializations
    virtual void saveToFile(const String& filePath) = 0;



   //private:

   // /**
   //  * @brief      loadModel function, to load the model
   //  * @param      path parameter one, path of the model
   //  * @bug		     No know Bugs
   //  * @return     Returns nothing
   //  */
   // void 
   // loadModel(const String& path);

   // /**
   //  * @brief      processNode function, to process node of the model
   //  * @param      node parameter one, node of the model
   //  * @param      scene parameter two, scene of the model
   //  * @bug		     No know Bugs
   //  * @return     Returns nothing
   //  */
   // void 
   // processNode(void* node,
   //             void* scene);

   // /**
   //  * @brief      processMesh function, to process node of the mesh
   //  * @param      mesh parameter one, mesh of the model
   //  * @param      scene parameter two, scene of the model
   //  * @bug		     No know Bugs
   //  * @return     Returns a mesh
   //  */
   // ModelData
   // processMesh(void* mesh, 
   //             void* scene);

   // void 
   // loadVertexData(void* mesh, ModelData& data);

   // void
   // loadAnimationData(void* mesh, ModelData& data);

   // /**
   //  * @brief      LoadMaterialTextures function, to load material of the model
   //  * @param      mat parameter one, material of the model
   //  * @param      type parameter two, type of material of the model
   //  * @param      typeName parameter three, name of the material
   //  * @bug		     No know Bugs
   //  * @return     Returns nothing
   //  */
   // void 
   // loadMaterialTextures(void* mat,
   //                      TEXTURE_TYPE type,
   //                      ModelData& data);


   // String 
   // getTexturePath(String file);

   //public:

   // Vector<ModelData> m_vModelData;


   //private:

   // /**
   //  * @brief private variables
   //  */
   // // model data 
   //// /**
   ////  * @Variable m_vSamplers, is for all samplers
   ////  */
   //// Vector<SamplerState*> m_vSamplers;
   //// 
  
   //  /**
   //   * @Variable m_Directory, directory of textures
   //   */
   //  String m_directory;


   //// /**
   ////  * @Variable m_Sampler, sampler of model
   ////  */
   //// SPtr<SamplerState> m_sampler;




  };

}