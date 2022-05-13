/*****************************************************************************/
/**
 * @file    xcMaterial.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/07/26
 * @brief   Represents the material 
 *
 * This class load the resources of textures to convert in material
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
#include "xcResource.h"


namespace xcEngineSDK {

  class Material : public Resource
  {
   public:
    Material() = default;
    ~Material() = default;

    bool 
    loadFromFile(const String& filePath) override;
    bool 
    loadFromMemory(const char* pData, size_t sizeOfData) override;

    void 
    unload() override;

    void 
    saveToFile(const String& filePath) override;


   private:

  };

}