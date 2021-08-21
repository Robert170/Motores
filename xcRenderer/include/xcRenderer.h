/*****************************************************************************/
/**
 * @file    xcPipeline.h
 * @author  Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
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
#include <xcBaseRenderer.h>
#include "xcPrerequisitesRenderer.h"

namespace xcEngineSDK {

  class Model;
  class DepthStencilState;
  class RasterizerState;
  class ShaderProgram;
  class InputLayout;
  class Pass;
  class Texture;

  struct ColorStruct;

  class Renderer : public BaseRenderer
  {
   public:
    Renderer() = default;
    ~Renderer() = default;

    void
    init() override;

    void
    update() override;

    void
    render() override;

    void
    setModels(Vector<SPtr<Model>> models) override;

    void
    setModel(SPtr<Model> model) override;
    
   private:
    
    void
    createGbuffer();

    void
    createSSAO();

    void
    createBlurH();

    void
    createBlurV();

    void
    createLigth();

    void
    setGbuffer();

    void
    setSSAO();

    void
    setBlurH();

    void
    setBlurV();

    void
    setLigth();

   private:

    Vector<SPtr<Model>> m_vModels;
     
    //**Gbufer**//
    //Shader
    SPtr<ShaderProgram> m_shaderProgramGbuffer = nullptr;

    //Input layout
    SPtr<InputLayout> m_inputLayoutGbuffer = nullptr;

    //depth stencil state
    SPtr<DepthStencilState> m_depthStencilStateGbuffer = nullptr;
    SPtr<DepthStencilState> m_depthStencilStateSAQ = nullptr;

    //Rasterizer
    SPtr<RasterizerState> m_rasterizerGbuffer = nullptr;
    SPtr<RasterizerState> m_rasterizerSAQ = nullptr;

    //Texture
    Texture* m_positionTexture;
    Texture* m_normalTxture;
    Texture* m_albedoTexture;

    //Vector of render targets
    Vector<Texture*> m_vRenderTargets;

    //Constant buffer
    CBNeverChanges m_constantBuffer;
    SPtr<ConstantBuffer> m_cbNeverChanges = nullptr;

    //////////////////////////

    //**SSAO**//
    //Shader
    SPtr<ShaderProgram> m_shaderProgramSSAO = nullptr;

    //Input layout
    SPtr<InputLayout> m_inputLayoutSSAO = nullptr;

    //depth stencil state
    SPtr<DepthStencilState> m_depthStencilStateSSAO = nullptr;

    //Rasterizer
    SPtr<RasterizerState> m_rasterizerSSAO = nullptr;

    //Texture
    Texture* m_ssaoTexture;

    //Vector of render targets
    Vector<Texture*> m_vRenderTargetsSSAO;

    //Vector of render targets
    Vector<Texture*> m_vTextures;

    //Constant buffer
    CBSSAO m_constantBufferSSAO;
    SPtr<ConstantBuffer> m_cbSSAO = nullptr;
    /////////////////////////////////////////////////////////////////


    //**BlurH**//

    //Shader
    SPtr<ShaderProgram> m_shaderProgramBlurH = nullptr;

    //Input layout
    SPtr<InputLayout> m_inputLayoutBlurH = nullptr;

    //depth stencil state
    SPtr<DepthStencilState> m_depthStencilStateBlurH = nullptr;

    //Rasterizer
    SPtr<RasterizerState> m_rasterizerBlurH = nullptr;

    //Texture
    Texture* m_blurOutTexture;

    //Vector of render targets
    Vector<Texture*> m_vRenderTargetsBlurH;

    //Vector of render targets
    Vector<Texture*> m_vTexturesBlurH;

    //Constant buffer
    CBBLUR m_constantBufferBlurH;
    SPtr<ConstantBuffer> m_cbBlurH = nullptr;

    //**BlurV**//
    //Shader
    SPtr<ShaderProgram> m_shaderProgramBlurV = nullptr;

    //Input layout
    SPtr<InputLayout> m_inputLayoutBlurV = nullptr;

    //depth stencil state
    SPtr<DepthStencilState> m_depthStencilStateBlurV = nullptr;

    //Rasterizer
    SPtr<RasterizerState> m_rasterizerBlurV = nullptr;

    //Vector of render targets
    Vector<Texture*> m_vRenderTargetsBlurV;

    //Vector of textures
    Vector<Texture*> m_vTexturesBlurV;

    //Constant buffer
    CBBLUR m_constantBufferBlurV;
    SPtr<ConstantBuffer> m_cbBlurV = nullptr;
    ///////////////////////////////////////////////////

    //**Ligth**//
    //Shader
    SPtr<ShaderProgram> m_shaderProgramLight = nullptr;

    //Input layout
    SPtr<InputLayout> m_inputLayoutLight = nullptr;

    //depth stencil state
    SPtr<DepthStencilState> m_depthStencilStateLight = nullptr;

    //Rasterizer
    SPtr<RasterizerState> m_rasterizerLight = nullptr;
    
    //Vector of textures
    Vector<Texture*> m_vTexturesLight;

    //Constant buffer
    CBNeverChanges m_constantBufferLight;
    SPtr<ConstantBuffer> m_cbLight = nullptr;

    //DepthStencil view
    Texture* m_depthStencilView;

    //Color
    ColorStruct m_color;

    //Models
    SPtr<Model> m_SAQ;


  };

  extern "C" XC_PLUGIN_EXPORT Renderer * create_Renderer() {

    auto m_renderer = new Renderer();

    return m_renderer;

  }


}
