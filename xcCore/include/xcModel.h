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

    bool 
    loadFromFile(const String& filePath) override;
    bool 
    loadFromMemory(const char* pData, size_t sizeOfData) override;

    void 
    unload() override;

    void 
    saveToFile(const String& filePath) override;


    void
    update(float delta);

    void
    render();

    void
    setData(Vector<BoneVertex>& vertexData, 
            Vector<int32>& indexData, 
            uint32 numMeshes = 1);

    Vector<Vector3>
    getVertexes();

    Vector<int32>
    getIndexes();

    Vector<Vector3>
    getNormals();

    Vector<Vector2>
    getUV();

    uint32
    getFaceVertexCount();

    Vector<Mesh>
    getMeshes();



   public:
    Vector<Mesh> m_vMeshes;
    String m_directory;


   private:

    
  };

}