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
    m_color.setColor(0.0f, 0.0f, 1.0f, 1.0f);

    createShadowMap();
    createGbuffer();
    createSSAO();
    createBlurH();
    createBlurV();
    createLigth();

  }

  void 
  Renderer::update() {
    auto& graphicsApi = g_graphicsAPI();
    auto& sceneGraph = g_sceneGraph();

    m_constantBuffer.mView = 
    graphicsApi.matri4x4Context(sceneGraph.m_mainCamera.getView());
                                graphicsApi.updateSubresource(&m_constantBuffer,
                                *m_cbNeverChanges); 

    m_CBufferInverse.matInverseView =
    graphicsApi.matri4x4Context(sceneGraph.m_mainCamera.getView()).inverse();
  }

  void
    Renderer::render() {

    auto& sceneGraph = g_sceneGraph();

    setShadowMap();
    setGbuffer();
    setSSAO();
    setBlurH();
    setBlurV();
    setBlurH();
    setBlurV();
    setLigth();

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
                                                    TEXTURE_FORMAT::
                                                    kTF_R16G16B16A16_FLOAT,
                                                    TEXTURE_BIND_FLAG::
                                                    kTEXTURE_BIND_SHADER_RESOURCE
                                                    | TEXTURE_BIND_FLAG::
                                                    kTEXTURE_BIND_RENDER_TARGET,
                                                    TYPE_USAGE::kTYPE_USAGE_DEFAULT,
                                                    nullptr);

    m_vRenderTargets.push_back(m_positionTexture);
    m_vTexturesSSAO.push_back(m_positionTexture);

    m_normalTxture = graphicsApi.createTexture2D(graphicsApi.m_width,
                                                 graphicsApi.m_height,
                                                 1,
                                                 TEXTURE_FORMAT::
                                                 kTF_R16G16B16A16_FLOAT,
                                                 TEXTURE_BIND_FLAG::
                                                 kTEXTURE_BIND_SHADER_RESOURCE
                                                 | TEXTURE_BIND_FLAG::
                                                 kTEXTURE_BIND_RENDER_TARGET,
                                                 TYPE_USAGE::kTYPE_USAGE_DEFAULT,
                                                 nullptr);
    m_vRenderTargets.push_back(m_normalTxture);
    m_vTexturesSSAO.push_back(m_normalTxture);



    m_albedoTexture = graphicsApi.createTexture2D(graphicsApi.m_width,
                                                  graphicsApi.m_height,
                                                  1,
                                                  TEXTURE_FORMAT::
                                                  kTF_R16G16B16A16_FLOAT,
                                                  TEXTURE_BIND_FLAG::
                                                  kTEXTURE_BIND_SHADER_RESOURCE
                                                  | TEXTURE_BIND_FLAG::
                                                  kTEXTURE_BIND_RENDER_TARGET,
                                                  TYPE_USAGE::kTYPE_USAGE_DEFAULT,
                                                  nullptr);
    m_vRenderTargets.push_back(m_albedoTexture);
    m_vTexturesHisto.push_back(m_albedoTexture);


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

    //m_constantBufferTransform.mObjectPosition;



    //TODO checar parametros y funciones para que funcionen en D3d11 y Ogl
    m_cbNeverChanges = graphicsApi.createConstantBuffer(sizeof(CBNeverChanges),
                                                        1,
                                                        &m_constantBuffer);

    /*m_cbTransform = graphicsApi.createConstantBuffer(sizeof(CBTransform),
                                                     1,
                                                     &m_constantBufferTransform);*/


    ////create rasterizer
    m_rasterizerGbuffer = graphicsApi.createRasterizerState(FILL_MODE::kFILL_SOLID,
                                                            CULL_MODE::kCULL_FRONT,
                                                            true);

    m_rasterizerSAQ = graphicsApi.createRasterizerState(FILL_MODE::kFILL_SOLID,
                                                        CULL_MODE::kCULL_NONE,
                                                        false);

    
    //create depth stencil view
    m_depthStencilView = graphicsApi.createTexture2D(graphicsApi.m_width,
                                                     graphicsApi.m_height,
                                                     1, 
                                                     TEXTURE_FORMAT::
                                                     kTF_D24_UNORM_S8_UINT, 
                                                     TEXTURE_BIND_FLAG::
                                                     kTEXTURE_BIND_DEPTH_STENCIL, 
                                                     TYPE_USAGE::kTYPE_USAGE_DEFAULT,
                                                     nullptr);

    ////create depth stencil state
    m_depthStencilStateGbuffer = graphicsApi.createDepthStencilState(true, true);

    m_depthStencilStateSAQ = graphicsApi.createDepthStencilState(false, false);
  }

  void 
  Renderer::createSSAO() {
    auto& graphicsApi = g_graphicsAPI();
    
    m_Sampler = graphicsApi.createSamplerState();

    m_vSamplers.push_back(m_Sampler);

    m_ssaoTexture = graphicsApi.createTexture2D(graphicsApi.m_width,
                                                graphicsApi.m_height,
                                                1,
                                                TEXTURE_FORMAT::
                                                kTF_R16G16B16A16_FLOAT,
                                                TEXTURE_BIND_FLAG::
                                                kTEXTURE_BIND_SHADER_RESOURCE
                                                | TEXTURE_BIND_FLAG::
                                                kTEXTURE_BIND_RENDER_TARGET
                                                | TEXTURE_BIND_FLAG::
                                                kTEXTURE_BIND_UNORDERED_ACCESS,
                                                TYPE_USAGE::kTYPE_USAGE_DEFAULT,
                                                nullptr);

    m_vRenderTargetsSSAO.push_back(m_ssaoTexture);
    m_vTexturesBlurH.push_back(m_ssaoTexture);

    //Shader program
    //m_shaderProgramSSAO = graphicsApi.createShaderProgram("screnAlignedQuad", //file name VS
    //                                                      "SSAO", //file name PS
    //                                                      "vs_ssaligned", //Entry point vs
    //                                                      "ps_ssao", //entry point ps
    //                                                      "vs_5_0",
    //                                                      "ps_5_0",
    //                                                      1,
    //                                                      1);

    m_shaderProgramSSAO = graphicsApi.createComputeShader("SSAO_CS",
                                                          "cs_ssao",
                                                          "cs_5_0");

    //Input Layout
    /*m_inputLayoutSSAO = graphicsApi.createAutomaticInputLayout
                                    (*m_shaderProgramSSAO);*/

    // Create the constant buffers
    m_constantBufferSSAO.mBias = 0.08000f;
    m_constantBufferSSAO.mIntensity = 2.0f;
    m_constantBufferSSAO.mSampleradius = 10.0f;
    m_constantBufferSSAO.mScale = 1.0f;

    //TODO checar parametros y funciones para que funcionen en D3d11 y Ogl
    m_cbSSAO = graphicsApi.createConstantBuffer(sizeof(CBSSAO),
                                                1,
                                                &m_constantBufferSSAO);

    m_constantBufferSSAOTexture.mWidth = graphicsApi.m_width;
    m_constantBufferSSAOTexture.mHeight = graphicsApi.m_height;

    m_cbSSAOTexture = graphicsApi.createConstantBuffer(sizeof(CBSSAO),
                                                       1,
                                                       &m_constantBufferSSAOTexture);



    m_computeBuffSSAO = graphicsApi.createComputeBuffer(sizeof(float),
                                                        1024, 
                                                        TYPE_USAGE::
                                                        kTYPE_USAGE_DEFAULT, 
                                                        TEXTURE_FORMAT::
                                                        kTF_R32_FLOAT,
                                                        nullptr);

  }

  void 
  Renderer::createBlurH() {

    auto& graphicsApi = g_graphicsAPI();

    m_blurOutTexture = graphicsApi.createTexture2D(graphicsApi.m_width,
                                                  graphicsApi.m_height,
                                                  1,
                                                  TEXTURE_FORMAT::
                                                  kTF_R16G16B16A16_FLOAT,
                                                  TEXTURE_BIND_FLAG::
                                                  kTEXTURE_BIND_SHADER_RESOURCE
                                                  | TEXTURE_BIND_FLAG::
                                                  kTEXTURE_BIND_RENDER_TARGET
                                                  | TEXTURE_BIND_FLAG::
                                                  kTEXTURE_BIND_UNORDERED_ACCESS,
                                                  TYPE_USAGE::kTYPE_USAGE_DEFAULT,
                                                  nullptr);

    m_vRenderTargetsBlurH.push_back(m_blurOutTexture);
    m_vTexturesBlurV.push_back(m_blurOutTexture);

    //Shader program
    //m_shaderProgramBlurH = graphicsApi.createShaderProgram("screnAlignedQuad", //file name VS
    //                                                       "gaussyan_blur", //file name PS
    //                                                       "vs_ssaligned", //Entry point vs
    //                                                       "ps_gaussian_blurH", //entry point ps
    //                                                       "vs_5_0",
    //                                                       "ps_5_0",
    //                                                       1,
    //                                                       1);

    m_shaderProgramBlurH = graphicsApi.createComputeShader("gaussyan_blur_CS",
                                                          "cs_gaussian_blurH",
                                                          "cs_5_0");
    //Input Layout
    /*m_inputLayoutBlurH = graphicsApi.createAutomaticInputLayout
                                    (*m_shaderProgramBlurH);*/

    // Create the constant buffers
    m_constantBufferBlur.mViewporDimensionX = graphicsApi.m_width;
    m_constantBufferBlur.mViewporDimensionY = graphicsApi.m_width;
    m_constantBufferBlur.mWidth = graphicsApi.m_width;
    m_constantBufferBlur.mHeight = graphicsApi.m_height;

    //TODO checar parametros y funciones para que funcionen en D3d11 y Ogl
    m_cbBlur = graphicsApi.createConstantBuffer(sizeof(CBBLUR),
                                                1,
                                                &m_constantBufferBlur);

    m_computeBuffBlur = graphicsApi.createComputeBuffer(sizeof(float),
                                                        1024,
                                                        TYPE_USAGE::
                                                        kTYPE_USAGE_DEFAULT,
                                                        TEXTURE_FORMAT::
                                                        kTF_R32_FLOAT,
                                                        nullptr);


    ////create rasterizer
    //m_rasterizerBlurH = graphicsApi.createRasterizerState(FILL_MODE::kFILL_SOLID,
                                                          //CULL_MODE::kCULL_FRONT,
                                                          //true);

    ////create depth stencil state
    //m_depthStencilStateBlurH = graphicsApi.createDepthStencilState(false, false);
  }

  void 
  Renderer::createBlurV() {

    auto& graphicsApi = g_graphicsAPI();
    

    //Shader program
    /*m_shaderProgramBlurV = graphicsApi.createShaderProgram("screnAlignedQuad", //file name VS
                                                           "gaussyan_blur", //file name PS
                                                           "vs_ssaligned", //Entry point vs
                                                           "ps_gaussian_blurV", //entry point ps
                                                           "vs_5_0",
                                                           "ps_5_0",
                                                           1,
                                                           1);*/


    m_shaderProgramBlurV = graphicsApi.createComputeShader("gaussyan_blur_CS",
                                                          "cs_gaussian_blurV",
                                                          "cs_5_0");
  }

  void 
  Renderer::createLigth() {

    auto& graphicsApi = g_graphicsAPI();
    auto& sceneGraph = g_sceneGraph();

    m_vTexturesLight.push_back(m_positionTexture);
    m_vTexturesLight.push_back(m_normalTxture);
    m_vTexturesLight.push_back(m_albedoTexture);
    m_vTexturesLight.push_back(m_ssaoTexture);
    m_vTexturesLight.push_back(m_shadowTexture);



    //Shader program
    m_shaderProgramLight = graphicsApi.createShaderProgram("screnAlignedQuad", //file name VS
                                                           "Light", //file name PS
                                                           "vs_ssaligned", //Entry point vs
                                                           "ps_main", //entry point ps
                                                           "vs_5_0",
                                                           "ps_5_0",
                                                            1,
                                                            1);
    //Input Layout
    m_inputLayoutLight = graphicsApi.createAutomaticInputLayout
                                     (*m_shaderProgramLight);


    // Create the constant buffers
    //m_constantBufferLight.EmissiveIntensity = 1.0F;
    m_constantBufferLight.Light_pos0.x = 650.0f;
    m_constantBufferLight.Light_pos0.y = 300.0f;
    m_constantBufferLight.Light_pos0.z = -200.0f;
    m_constantBufferLight.LightIntensity_0 = 2.0f;
    m_constantBufferLight.vViewPosition = Vector4::UNIT;
    m_constantBufferLight.matView = graphicsApi.matri4x4Context
                                    (sceneGraph.m_mainCamera.getView());

    m_constantBufferLight.matWorld = Matrix4x4(Vector4(0.05f, 0.f, 0.f, 0.f),
                                               Vector4(0.f, 0.05f, 0.f, 0.f),
                                               Vector4(0.f, 0.f, 0.05f, 0.f),
                                               Vector4(0.f, 0.f, 0.f, 1.f));



    //TODO checar parametros y funciones para que funcionen en D3d11 y Ogl
    m_cbLight = graphicsApi.createConstantBuffer(sizeof(CBLIGHT),
                                                 1,
                                                 &m_constantBufferLight);

    m_constantBufferLightCamera.matProjection =
    graphicsApi.matri4x4Context(m_shadowCamera.getProyeccion());

    m_constantBufferLightCamera.matView =
    graphicsApi.matri4x4Context(m_shadowCamera.getView());

    m_cbLigthCamera = 
    graphicsApi.createConstantBuffer(sizeof(CBLIGHTCAMERA),
                                     1,
                                     &m_constantBufferLightCamera);


    m_CBufferInverse.matInverseView =
    graphicsApi.matri4x4Context(sceneGraph.m_mainCamera.getView()).inverse();

    m_cbInverseMatrix =
    graphicsApi.createConstantBuffer(sizeof(CBINVERSE), 
                                     1, 
                                     &m_CBufferInverse);
    
  }

  void 
  Renderer::createShadowMap() {

    auto& graphicsApi = g_graphicsAPI();
    auto& sceneGraph = g_sceneGraph();

    m_shadowCamera.setPosition(Vector3(14.0f, 0.0f, -8.0f));
    m_shadowCamera.setLookAt((Vector3(0.0f, 0.0f, -5.0f)));
    m_shadowCamera.setUp(Vector3(0.0f, 0.0f, -1.0f));
    //m_shadowCamera.setPosition(Vector3(0.0f, 1.0f, -10.0f));
    //m_shadowCamera.setLookAt((Vector3(0.0f, 1.0f, 0.0f)));
    //m_shadowCamera.setUp(Vector3(0.0f, 1.0f, 0.0f));
    m_shadowCamera.setfar(30000);
    m_shadowCamera.setNear(0.1f);
    m_shadowCamera.setFielOfView(0.78539816339f);
    m_shadowCamera.setWidth(graphicsApi.m_width);
    m_shadowCamera.setHeight(graphicsApi.m_height);

    m_shadowCamera.init();


    //Textures
    m_shadowTexture = graphicsApi.createTexture2D(graphicsApi.m_width,
                                                  graphicsApi.m_height,
                                                  1,
                                                  TEXTURE_FORMAT::kTF_R16_FLOAT,
                                                  TEXTURE_BIND_FLAG::
                                                  kTEXTURE_BIND_SHADER_RESOURCE
                                                  | TEXTURE_BIND_FLAG::
                                                  kTEXTURE_BIND_RENDER_TARGET,
                                                  TYPE_USAGE::kTYPE_USAGE_DEFAULT,
                                                  nullptr);

    m_vTexturesShadow.push_back(m_shadowTexture);


    m_shaderProgramShadow = graphicsApi.createShaderProgram("ShadowMapVS",
                                                            "ShadowMapPS",
                                                            "ShadowVS",
                                                            "ShadowPS",
                                                            "vs_5_0",
                                                            "ps_5_0",
                                                            1,
                                                            1);

    //Input Layout
    m_inputLayoutShadow = graphicsApi.createAutomaticInputLayout
                                     (*m_shaderProgramShadow);

    // Create the constant buffers
    m_constantBufferShadow.mView =
    graphicsApi.matri4x4Context(m_shadowCamera.getView());
      
    m_constantBufferShadow.mProjection =
    graphicsApi.matri4x4Context(m_shadowCamera.getProyeccion());

    m_constantBufferShadow.mWorld = Matrix4x4(Vector4(0.05f, 0.f, 0.f, 0.f),
                                              Vector4(0.f, 0.05f, 0.f, 0.f),
                                              Vector4(0.f, 0.f, 0.05f, 0.f),
                                              Vector4(0.f, 0.f, 0.f, 1.f));

    m_cbShadow = graphicsApi.createConstantBuffer(sizeof(CBNeverChanges),
                                                  1,
                                                  &m_constantBufferShadow);

    ////create rasterizer
    m_rasterizerDepth = graphicsApi.createRasterizerState(FILL_MODE::kFILL_SOLID,
                                                          CULL_MODE::kCULL_FRONT,
                                                          true);

    ////create depth stencil state
    m_depthStencilStateDepth = graphicsApi.createDepthStencilState(false, false);

  }

  void 
  Renderer::createHistogram() {
    auto& graphicsApi = g_graphicsAPI();
    

    m_histoTexture = graphicsApi.createTexture2D(graphicsApi.m_width,
                                                 graphicsApi.m_height,
                                                 1,
                                                 TEXTURE_FORMAT::
                                                 kTF_R16G16B16A16_FLOAT,
                                                 TEXTURE_BIND_FLAG::
                                                 kTEXTURE_BIND_SHADER_RESOURCE
                                                 | TEXTURE_BIND_FLAG::
                                                 kTEXTURE_BIND_RENDER_TARGET
                                                 | TEXTURE_BIND_FLAG::
                                                 kTEXTURE_BIND_UNORDERED_ACCESS,
                                                 TYPE_USAGE::kTYPE_USAGE_DEFAULT,
                                                 nullptr);

    m_vRenderTargetsHisto.push_back(m_histoTexture);

    //Shader program
    m_shaderProgramHisto = graphicsApi.createShaderProgram("screnAlignedQuad", //file name VS
                                                           "Histgram", //file name PS
                                                           "vs_ssaligned", //Entry point vs
                                                           "histo", //entry point ps
                                                           "vs_5_0",
                                                           "ps_5_0",
                                                           1,
                                                           1);

    m_shaderProgramHistoCS = graphicsApi.createComputeShader("Count_CS",
                                                             "cs_count",
                                                             "cs_5_0");

    //Input Layout
    m_inputLayoutHisto = graphicsApi.createAutomaticInputLayout
                                     (*m_shaderProgramHisto);

    //TODO checar parametros y funciones para que funcionen en D3d11 y Ogl
    m_cbHistogram = graphicsApi.createConstantBuffer(sizeof(CBHISTOGRAM),
                                                     1,
                                                     nullptr);

    for (uint32 i = 0; i < 256; i++) {

      m_countRG.countR[i] = 0;
      m_countRG.countG[i] = 0;
      m_countB.countB[i] = 0;
    }

    m_computeBuffHistoRG = graphicsApi.createComputeBuffer(sizeof(COUNTRG),
                                                           1024, 
                                                           TYPE_USAGE::
                                                           kTYPE_USAGE_DEFAULT, 
                                                           TEXTURE_FORMAT::
                                                           kTF_R32G32B32_FLOAT,
                                                           &m_countRG);

    m_computeBuffHistoB = graphicsApi.createComputeBuffer(sizeof(COUNTB),
                                                           1024, 
                                                           TYPE_USAGE::
                                                           kTYPE_USAGE_DEFAULT, 
                                                           TEXTURE_FORMAT::
                                                           kTF_R32G32B32_FLOAT,
                                                           &m_countB);


  }

  void 
  Renderer::setGbuffer() {
    auto& graphicsApi = g_graphicsAPI();

    auto& sceneGraph = g_sceneGraph();

    graphicsApi.setRenderTarget(m_vRenderTargets, m_depthStencilView);


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

    /*graphicsApi.setVSConstantBuffer(m_cbTransform,
                                    1,
                                    1);*/
    //set input layout
    graphicsApi.setInputLayout(m_inputLayoutGbuffer);

    
    //shader program
    graphicsApi.setShaderProgram(m_shaderProgramGbuffer);


    sceneGraph.render();

    graphicsApi.desbindingRT();
  }

  void 
  Renderer::setSSAO() {

    auto& graphicsApi = g_graphicsAPI();

    auto& sceneGraph = g_sceneGraph();

    graphicsApi.setShaderResourceCS(m_vTexturesSSAO);

    uint32 samplerSize = m_vSamplers.size();

    //set sampler state
    for (uint32 i = 0; i < samplerSize; ++i) {
      graphicsApi.setSamplerStateCS(m_vSamplers,
                                    1);
    }

    //graphicsApi.setComputeBuffer(m_computeBuffSSAO, 0, 1);
    graphicsApi.setComputeBufferRTUAV(m_ssaoTexture, 0, 1);
    graphicsApi.clearRenderTarget(m_ssaoTexture, m_color);

    graphicsApi.setComputeShader(m_shaderProgramSSAO);

    //set all vertex shader constant buffer
    graphicsApi.setCSConstantBuffer(m_cbSSAO, 0, 1);
    graphicsApi.setCSConstantBuffer(m_cbSSAOTexture, 1, 1);

    graphicsApi.dispatch(Math::ceil(graphicsApi.m_width / 32), 
                         Math::ceil(graphicsApi.m_height / 32), 
                         1);

    graphicsApi.desbindingUAV(0, 1);
    //graphicsApi.desbindingRT();
    graphicsApi.desbindingSR(m_vTexturesLight, 2);
   
  }

  void 
  Renderer::setBlurH() {

    auto& graphicsApi = g_graphicsAPI();

    auto& sceneGraph = g_sceneGraph();

    graphicsApi.setShaderResourceCS(m_vTexturesBlurH);

    graphicsApi.setComputeBufferRTUAV(m_blurOutTexture, 0, 1);
    graphicsApi.clearRenderTarget(m_blurOutTexture, m_color);

    graphicsApi.setComputeShader(m_shaderProgramBlurH);

    graphicsApi.setCSConstantBuffer(m_cbBlur, 0, 1);

    graphicsApi.dispatch(Math::ceil(graphicsApi.m_width / 32), 
                         Math::ceil(graphicsApi.m_height / 32), 
                         1);

    graphicsApi.desbindingUAV(0, 1);
    //graphicsApi.desbindingRT();
    graphicsApi.desbindingSR(m_vTexturesLight, 2);

  }

  void 
  Renderer::setBlurV() {

    auto& graphicsApi = g_graphicsAPI();

    auto& sceneGraph = g_sceneGraph();


    graphicsApi.setShaderResourceCS(m_vTexturesBlurV);

    graphicsApi.setComputeBufferRTUAV(m_ssaoTexture, 0, 1);
    graphicsApi.clearRenderTarget(m_ssaoTexture, m_color);

    graphicsApi.setComputeShader(m_shaderProgramBlurV);

    graphicsApi.setCSConstantBuffer(m_cbBlur, 0, 1);

    graphicsApi.dispatch(Math::ceil(graphicsApi.m_width / 32), 
                         Math::ceil(graphicsApi.m_height / 32), 
                         1);

    graphicsApi.desbindingUAV(0, 1);
    //graphicsApi.desbindingRT();
    graphicsApi.desbindingSR(m_vTexturesLight, 2);
    
  }

  void 
  Renderer::setShadowMap() {

    auto& graphicsApi = g_graphicsAPI();
    auto& sceneGraph = g_sceneGraph();

    graphicsApi.setRenderTarget(m_vTexturesShadow, m_depthStencilView);
    graphicsApi.clearRenderTarget(m_shadowTexture, m_color);

    graphicsApi.setVSConstantBuffer(m_cbShadow, 0, 1);
    //set input layout
    graphicsApi.setInputLayout(m_inputLayoutShadow);

    //Shader program
    graphicsApi.setShaderProgram(m_shaderProgramShadow);

    sceneGraph.render();

    graphicsApi.desbindingRT();

  }

  void 
  Renderer::setHistogram() {
    auto& graphicsApi = g_graphicsAPI();

    graphicsApi.setShaderResourceCS(m_vTexturesHisto);

    uint32 samplerSize = m_vSamplers.size();

    //set sampler state
    for (uint32 i = 0; i < samplerSize; ++i) {
      graphicsApi.setSamplerStateCS(m_vSamplers,
                                    1);
    }

    graphicsApi.setComputeBuffer(m_computeBuffHistoRG, 0, 1);
    graphicsApi.setComputeBuffer(m_computeBuffHistoB, 1, 1);
    graphicsApi.setComputeBufferRTUAV(m_histoTexture, 0, 1);
    graphicsApi.clearRenderTarget(m_histoTexture, m_color);

    graphicsApi.setComputeShader(m_shaderProgramHisto);

    //set all vertex shader constant buffer
    graphicsApi.setCSConstantBuffer(m_cbSSAOTexture, 0, 1);

    graphicsApi.dispatch(Math::ceil(graphicsApi.m_width / 32), 
                         Math::ceil(graphicsApi.m_height / 32), 
                         1);

    graphicsApi.desbindingUAV(0, 1);



    //graphicsApi.desbindingRT();
    graphicsApi.desbindingSR(m_vTexturesLight, 2);

    

    graphicsApi.setPSConstantBuffer(m_cbNeverChanges,
                                    0,
                                    1);

    //set input layout
    graphicsApi.setInputLayout(m_inputLayoutHisto);

    
    //shader program
    graphicsApi.setShaderProgram(m_shaderProgramHisto);

    m_SAQ->render();

    graphicsApi.desbindingRT();

  }

  void 
  Renderer::setLigth() {

    auto& graphicsApi = g_graphicsAPI();


    graphicsApi.setDefaultRenderTarget();
    graphicsApi.clearDefaultRenderTargetAndDepthStencil(m_color);

    graphicsApi.setShaderResource(m_vTexturesLight);

    graphicsApi.setPSConstantBuffer(m_cbLight, 0, 1);
    graphicsApi.setPSConstantBuffer(m_cbLigthCamera, 1, 1);
    graphicsApi.setPSConstantBuffer(m_cbInverseMatrix, 2, 1);

    //set input layout
    graphicsApi.setInputLayout(m_inputLayoutLight);

    //shader program
    graphicsApi.setShaderProgram(m_shaderProgramLight);

    m_SAQ->render();

    graphicsApi.desbindingSR(m_vTexturesLight, 1);

  }

  

}