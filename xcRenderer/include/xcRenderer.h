/*****************************************************************************/
/**
 * @file    xcRenderer.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/07/25
 * @brief   Represents pases of renderer
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
  class SamplerState;

  struct ColorStruct;
  struct TextureDesc;
 

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
    createShadowMap();

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

    void
    setShadowMap();

   private:

    Vector<SPtr<Model>> m_vModels;
     
    //**Gbuffer**//
    SPtr<Pass> Gbuffer;

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

    CBTransform m_constantBufferTransform;
    SPtr<ConstantBuffer> m_cbTransform = nullptr;

    //////////////////////////

    //**SSAO**//
    
    Camera m_shadowCamera;

    SPtr<SamplerState> m_Sampler = nullptr;
    Vector<SPtr<SamplerState>> m_vSamplers;

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
    Vector<Texture*> m_vTexturesSSAO;

    //Constant buffer
    CBSSAO m_constantBufferSSAO;
    SPtr<ConstantBuffer> m_cbSSAO = nullptr;
    CBSSAO_TEXTURE m_constantBufferSSAOTexture;
    SPtr<ConstantBuffer> m_cbSSAOTexture = nullptr;


    SPtr<ComputeBuffer> m_computeBuffSSAO;

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
    CBBLUR m_constantBufferBlur;
    SPtr<ConstantBuffer> m_cbBlur = nullptr;

    SPtr<ComputeBuffer> m_computeBuffBlur;


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
    //Vector<Texture*> m_vRenderTargetsBlurV;

    //Vector of textures
    Vector<Texture*> m_vTexturesBlurV;
  
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
    CBLIGHT m_constantBufferLight;
    SPtr<ConstantBuffer> m_cbLight = nullptr;

    CBLIGHTCAMERA m_constantBufferLightCamera;
    SPtr<ConstantBuffer> m_cbLigthCamera = nullptr;

    CBINVERSE m_CBufferInverse;
    SPtr<ConstantBuffer> m_cbInverseMatrix = nullptr;

    //**Shadow**//
    
    //Texture
    Texture* m_shadowTexture;

    //Shader
    SPtr<ShaderProgram> m_shaderProgramShadow = nullptr;

    //depth stencil state
    SPtr<DepthStencilState> m_depthStencilStateDepth = nullptr;

    //Rasterizer
    SPtr<RasterizerState> m_rasterizerDepth = nullptr;

    //Input layout
    SPtr<InputLayout> m_inputLayoutShadow = nullptr;

    CBNeverChanges m_constantBufferShadow;
    SPtr<ConstantBuffer> m_cbShadow = nullptr;

    //Vector of textures
    Vector<Texture*> m_vTexturesShadow;

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
