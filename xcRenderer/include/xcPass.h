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
  class Texture;
 

  //render pass
  class XC_RENDERER_EXPORT Pass
  {
   public:
     Pass() = default;
    ~Pass() = default;

    void
    init();

    void 
    update();
    
    void
    render();

   private:
    SPtr<Texture> m_backBuffer;
    SPtr<Texture> m_depthStencil;
    SPtr<Texture> m_depthStencilView;

    SPtr<VertexShader> m_VS;
    SPtr<PixelShader> m_PS;
    SPtr<InputLayout> m_InputLayout;
  };
}



