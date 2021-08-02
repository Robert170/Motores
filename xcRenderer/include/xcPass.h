/*****************************************************************************/
/**
 * @file    xcPass.h
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
#include "xcPrerequisitesRenderer.h"

namespace xcEngineSDK {

  class VertexShader;
  class PixelShader;
  class InputLayout;
  //render pass
  class Pass
  {
   public:
     Pass() = default;
    ~Pass() = default;

    void 
    update();
    
    void
    render();

   private:
    SPtr<VertexShader> m_VS;
    SPtr<PixelShader> m_PS;
    SPtr<InputLayout> m_InputLayout;
  };
}



