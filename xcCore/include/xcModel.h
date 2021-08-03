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
#include "xcMesh.h"

namespace xcEngineSDK {

  class XC_CORE_EXPORT Model : public ResourceModel
  {
   public:

    Model() = default;
    ~Model() = default;

    Model(const ResourceModel& resourse);

    Model(const String& path);

    void
    update(float delta);

    void
    render();

   private:
    void
    setMeshes();

   private:

    Vector<Mesh> m_vMeshes;

    ResourceModel m_resource;
  };

}