/*****************************************************************************/
/**
 * @file    xcPipeline.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/07/25
 * @brief   Represents pases of GBuffer
 *
 * Represents the pase of the Gbuffer that the engine will use to compile
 * different shaders
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
#include <xcModule.h>
#include "xcPrerequisitesRenderer.h"

namespace xcEngineSDK {
  class Model;
  class XC_RENDERER_EXPORT Renderer : public Module<Renderer>
  {
   public:
    Renderer() = default;
    ~Renderer() = default;


    FORCEINLINE void
      setObject(Renderer* api) {
      Renderer::_instance() = api;
    }

    void
    setModels(Vector<SPtr<Model>> models);

    void
    setModel(SPtr<Model> model);
    

   private:

    Vector<SPtr<Model>> m_vModels;

  };

  /**
   * @brief export the instance
   */
  XC_RENDERER_EXPORT Renderer& 
  g_renderer();

  /**
   * @Variable funProtoGraphiAPI, instance of the class
   */
  using funProtoRenderer = Renderer * (*)();


}
