#include <xcModel.h>
#include <xcSceneGraph.h>
#include <xcGraphiAPI.h>
#include "xcRenderer.h"


namespace xcEngineSDK {

  

  void
  Renderer::init() {

    //SPtr<Model> saqModel(new Model("Models/ScreenAlignedQuad.3ds"));
    m_SAQ = std::make_shared<Model>();
    m_SAQ->loadFromFile("Models/ScreenAlignedQuad.3ds");
    createGbuffer();
    createSSAO();

  }

  void 
  Renderer::update() {
    auto& graphicsApi = g_graphicsAPI();
    auto& sceneGraph = g_sceneGraph();

    m_constantBuffer.mView = 
    graphicsApi.matri4x4Context(sceneGraph.m_mainCamera.getView());
                                graphicsApi.updateSubresource(&m_constantBuffer,
                                *m_cbNeverChanges); 
  }

  void
  Renderer::render() {

    auto& sceneGraph = g_sceneGraph();

    setGbuffer();
    setSSAO();

  }

  void
  Renderer::setModels(Vector<SPtr<Model>> models) {
    m_vModels = models;
  }

  void
  Renderer::setModel(SPtr<Model> model) {
    m_vModels.push_back(model);
  }

  void 
  Renderer::createGbuffer() {

    auto& graphicsApi = g_graphicsAPI();
    auto& sceneGraph = g_sceneGraph();

    //Textures
    m_positionTexture = graphicsApi.createTexture2D(graphicsApi.m_width,
                                                    graphicsApi.m_height,
                                                    1,
                                                    TF_R16G16B16A16_FLOAT,
                                                    TEXTURE_BIND_SHADER_RESOURCE
                                                    | TEXTURE_BIND_RENDER_TARGET,
                                                    TYPE_USAGE_DEFAULT,
                                                    nullptr);

    m_vRenderTargets.push_back(m_positionTexture);
    m_vTextures.push_back(m_positionTexture);

    m_normalTxture = graphicsApi.createTexture2D(graphicsApi.m_width,
                                                 graphicsApi.m_height,
                                                 1,
                                                 TF_R16G16B16A16_FLOAT,
                                                 TEXTURE_BIND_SHADER_RESOURCE
                                                 | TEXTURE_BIND_RENDER_TARGET,
                                                 TYPE_USAGE_DEFAULT,
                                                 nullptr);
    m_vRenderTargets.push_back(m_normalTxture);
    m_vTextures.push_back(m_normalTxture);



    m_albedoTexture = graphicsApi.createTexture2D(graphicsApi.m_width,
                                                  graphicsApi.m_height,
                                                  1,
                                                  TF_R16G16B16A16_FLOAT,
                                                  TEXTURE_BIND_SHADER_RESOURCE
                                                  | TEXTURE_BIND_RENDER_TARGET,
                                                  TYPE_USAGE_DEFAULT,
                                                  nullptr);
    m_vRenderTargets.push_back(m_albedoTexture);




    //Shader program
    m_shaderProgramGbuffer = graphicsApi.createShaderProgram("GbufferVS", //file name VS
                                                             "GbufferPS", //file name PS
                                                             "vs_gbuffer", //Entry point vs
                                                             "ps_gbuffer", //entry point ps
                                                             "vs_4_0",
                                                             "ps_4_0",
                                                              1,
                                                              1);
    //Input Layout
    m_inputLayoutGbuffer = graphicsApi.createAutomaticInputLayout
                                       (*m_shaderProgramGbuffer);


    // Create the constant buffers
    m_constantBuffer.mView =
    graphicsApi.matri4x4Context(sceneGraph.m_mainCamera.getView());
      
    m_constantBuffer.mProjection = 
    graphicsApi.matri4x4Context(sceneGraph.m_mainCamera.getProyeccion()); 

    m_constantBuffer.mWorld = Matrix4x4(Vector4(0.05f, 0.f, 0.f, 0.f),
                                        Vector4(0.f, 0.05f, 0.f, 0.f),
                                        Vector4(0.f, 0.f, 0.05f, 0.f),
                                        Vector4(0.f, 0.f, 0.f, 1.f));



    //TODO checar parametros y funciones para que funcionen en D3d11 y Ogl
    m_cbNeverChanges = graphicsApi.createConstantBuffer(sizeof(CBNeverChanges),
                                                        1,
                                                        &m_constantBuffer);


    ////create rasterizer
    m_rasterizerGbuffer = graphicsApi.createRasterizerState(FILL_MODE::FILL_SOLID,
                                                            CULL_MODE::CULL_FRONT,
                                                            true);

    m_rasterizerSAQ = graphicsApi.createRasterizerState(FILL_MODE::FILL_SOLID,
                                                        CULL_MODE::CULL_NONE,
                                                        false);

    
    //create depth stencil view
    m_depthStencilView = graphicsApi.createTexture2D(graphicsApi.m_width,
                                                     graphicsApi.m_height,
                                                     1, 
                                                     TF_D24_UNORM_S8_UINT, 
                                                     TEXTURE_BIND_DEPTH_STENCIL, 
                                                     TYPE_USAGE_DEFAULT,
                                                     nullptr);

    ////create depth stencil state
    m_depthStencilStateGbuffer = graphicsApi.createDepthStencilState(true, true);

    m_depthStencilStateSAQ = graphicsApi.createDepthStencilState(false, false);
  }

  void 
  Renderer::createSSAO() {
    auto& graphicsApi = g_graphicsAPI();

    m_ssaoTexture = graphicsApi.createTexture2D(graphicsApi.m_width,
                                                graphicsApi.m_height,
                                                1,
                                                TF_R16G16B16A16_FLOAT,
                                                TEXTURE_BIND_SHADER_RESOURCE
                                                | TEXTURE_BIND_RENDER_TARGET,
                                                TYPE_USAGE_DEFAULT,
                                                nullptr);

    m_vRenderTargetsSSAO.push_back(m_ssaoTexture);

    //Shader program
    m_shaderProgramSSAO = graphicsApi.createShaderProgram("screnAlignedQuad", //file name VS
                                                          "SSAO", //file name PS
                                                          "vs_ssaligned", //Entry point vs
                                                          "ps_ssao", //entry point ps
                                                          "vs_4_0",
                                                          "ps_4_0",
                                                          1,
                                                          1);
    //Input Layout
    m_inputLayoutSSAO = graphicsApi.createAutomaticInputLayout
                                    (*m_shaderProgramSSAO);

    // Create the constant buffers
    m_constantBufferSSAO.mBias = 0.08000f;
    m_constantBufferSSAO.mIntensity = 2.0f;
    m_constantBufferSSAO.mSampleradius = 10.0f;
    m_constantBufferSSAO.mScale = 1.0f;

    //TODO checar parametros y funciones para que funcionen en D3d11 y Ogl
    m_cbSSAO = graphicsApi.createConstantBuffer(sizeof(CBSSAO),
                                                1,
                                                &m_constantBufferSSAO);


    ////create rasterizer
    m_rasterizerSSAO = graphicsApi.createRasterizerState(FILL_MODE::FILL_SOLID,
                                                         CULL_MODE::CULL_FRONT,
                                                         true);

    ////create depth stencil state
    m_depthStencilStateSSAO = graphicsApi.createDepthStencilState(false, false);

  }

  void 
  Renderer::createBlurH() {
  }

  void 
  Renderer::createBlurV() {
  }

  void 
  Renderer::createBlurH_1() {
  }

  void 
  Renderer::createBlurV_1() {
  }

  void 
  Renderer::createLigth() {
  }

  void 
  Renderer::setGbuffer() {
    auto& graphicsApi = g_graphicsAPI();

    auto& sceneGraph = g_sceneGraph();

    graphicsApi.clearRenderTarget(m_positionTexture, m_color);
    graphicsApi.clearRenderTarget(m_normalTxture, m_color);
    graphicsApi.clearRenderTarget(m_albedoTexture, m_color);

    graphicsApi.clearDepthStencil(m_depthStencilView);


    //set rasterizer
    graphicsApi.setRasterizerState(m_rasterizerGbuffer);

    //set depth stencil state
    graphicsApi.setDepthStencilState(m_depthStencilStateGbuffer, 0);

    //set all vertex shader constant buffer

    graphicsApi.setVSConstantBuffer(m_cbNeverChanges,
                                    0,
                                    1);
    //set input layout
    graphicsApi.setInputLayout(m_inputLayoutGbuffer);

    
    //shader program
    graphicsApi.setShaderProgram(m_shaderProgramGbuffer);

    graphicsApi.setRenderTarget(m_vRenderTargets, m_depthStencilView);

    sceneGraph.render();
  }

  void 
  Renderer::setSSAO() {

    auto& graphicsApi = g_graphicsAPI();

    auto& sceneGraph = g_sceneGraph();

    graphicsApi.clearRenderTarget(m_ssaoTexture, m_color);

    //graphicsApi.clearDepthStencil(m_depthStencilView);

    //set rasterizer
    graphicsApi.setRasterizerState(m_rasterizerSSAO);
    graphicsApi.setRasterizerState(m_rasterizerSAQ);

    //set depth stencil state
    graphicsApi.setDepthStencilState(m_depthStencilStateSSAO, 0);
    graphicsApi.setDepthStencilState(m_depthStencilStateSAQ, 0);

    //set all vertex shader constant buffer

    graphicsApi.setPSConstantBuffer(m_cbSSAO,
                                    0,
                                    1);

    graphicsApi.setShaderResource(m_vTextures);

    //set input layout
    graphicsApi.setInputLayout(m_inputLayoutSSAO);

    //set render target
    graphicsApi.setRenderTarget(m_vRenderTargetsSSAO, m_depthStencilView);

    
    //shader program
    graphicsApi.setShaderProgram(m_shaderProgramSSAO);


    m_SAQ->render();
  }

  void 
  Renderer::setBlurH() {
  }

  void 
  Renderer::setBlurV() {
  }

  void 
  Renderer::setBlurH_1() {
  }

  void 
  Renderer::setBlurV_1() {
  }

  void 
  Renderer::setLigth() {
  }

}