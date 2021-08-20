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
#include <xcGraphiAPI.h>
#include "xcPrerequisitesRenderer.h"

namespace xcEngineSDK {

  class Model;
  class DepthStencilState;
  class RasterizerState;
  class ShaderProgram;
  class InputLayout;
  class Pass;
  class Texture;

  class XC_RENDERER_EXPORT Renderer : public Module<Renderer>
  {
   public:
    Renderer() = default;
    ~Renderer() = default;


    /*FORCEINLINE void
      setObject(Renderer* api) {
      Renderer::_instance() = api;
    }*/

    void
    init();

    void
    update();

    void
    render();

    void
    setModels(Vector<SPtr<Model>> models);

    void
    setModel(SPtr<Model> model);
    

   private:

    Vector<SPtr<Model>> m_vModels;

    //Shader
    SPtr<ShaderProgram> m_shaderProgram = nullptr;

    //Input layout
    SPtr<InputLayout> m_inputLayout = nullptr;

    //depth stencil state
    SPtr<DepthStencilState> m_depthStencilState = nullptr;
    SPtr<DepthStencilState> m_depthStencilStateSAQ = nullptr;

    //Rasterizer
    SPtr<RasterizerState> m_rasterizerGbuffer = nullptr;
    SPtr<RasterizerState> m_rasterizerSAQ = nullptr;

    //Texture
    Texture* m_positionTexture;
    Texture* m_normalTxture;
    Texture* m_albedoTexture;

    //DepthStencil view
    Texture* m_depthStencilView;


    //Vector of render targets
    Vector<Texture*> m_vRenderTargets;

    //Color
    ColorStruct m_color;

    //Constant buffer
    CBNeverChanges m_constantBuffer;
    SPtr<ConstantBuffer> m_cbNeverChanges = nullptr;

    //Matrix
    Matrix4x4 m_world;
    Matrix4x4 m_view;
    Matrix4x4 m_projection;


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
