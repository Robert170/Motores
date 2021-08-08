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
#include "xcResource.h"
#include "xcMesh.h"

namespace xcEngineSDK {

  class XC_CORE_EXPORT Model : public Resource
  {
   public:

    Model() = default;
    ~Model() = default;

    Model(const String& path);

    bool loadFromFile(const String& filePath) override;
    bool loadFromMemory(const char* pData, size_t sizeOfData) override;

    void unload() override;

    void saveToFile(const String& filePath) override;


    void
    update(float delta);

    void
    render();

   public:
    Vector<Mesh> m_vMeshes;
    String m_directory;


   private:

    
  };

}