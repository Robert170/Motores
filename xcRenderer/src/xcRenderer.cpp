#include <xcModel.h>
#include <xcSceneGraph.h>
#include "xcRenderer.h"


namespace xcEngineSDK {

  Renderer& g_renderer() {

    return Renderer::instance();

  }

  void
  Renderer::init() {

    auto& graphicsApi = g_graphicsAPI();

    m_positionTexture = graphicsApi.createTexture2D(graphicsApi.m_width,
                                                    graphicsApi.m_height,
                                                    1,
                                                    TF_R16G16B16A16_FLOAT,
                                                    TEXTURE_BIND_SHADER_RESOURCE
                                                    | TEXTURE_BIND_RENDER_TARGET,
                                                    TYPE_USAGE_DEFAULT,
                                                    nullptr);

    m_vRenderTargets.push_back(m_positionTexture);

    m_normalTxture = graphicsApi.createTexture2D(graphicsApi.m_width,
                                                 graphicsApi.m_height,
                                                 1,
                                                 TF_R16G16B16A16_FLOAT,
                                                 TEXTURE_BIND_SHADER_RESOURCE
                                                 | TEXTURE_BIND_RENDER_TARGET,
                                                 TYPE_USAGE_DEFAULT,
                                                 nullptr);
    m_vRenderTargets.push_back(m_normalTxture);


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
    m_shaderProgram = graphicsApi.createShaderProgram("GbufferVS", //file name VS
                                                      "GbufferPS", //file name PS
                                                      "vs_gbuffer", //Entry point vs
                                                      "ps_gbuffer", //entry point ps
                                                      "vs_4_0",
                                                      "ps_4_0",
                                                      1,
                                                      1);
    //Input Layout
    m_inputLayout = graphicsApi.createAutomaticInputLayout(*m_shaderProgram);


    // Create the constant buffers
    Vector3 Eye(0.0f, 0.0f, -10.0f);
    Vector3 At(0.0f, 1.0f, 0.0f);
    Vector3 Up(0.0f, 1.0f, 0.0f);
    float fov = 0.78539816339f;
    float w = 900.0f;
    float h = 900.0f;
    float Near = 0.01f;
    float Far = 3000.0f;
    m_constantBuffer.mView = g_graphicsAPI().initMatrixView(m_view,
                                                            Eye,
                                                            At, 
                                                            Up);

    m_constantBuffer.mProjection = g_graphicsAPI().initMatrixProjection(m_projection,
                                                                        fov,
                                                                        w,
                                                                        h,
                                                                        Near,
                                                                        Far);

    m_constantBuffer.mWorld = Matrix4x4(Vector4(0.01f, 0.f, 0.f, 0.f),
                                        Vector4(0.f, 0.01f, 0.f, 0.f),
                                        Vector4(0.f, 0.f, 0.01f, 0.f),
                                        Vector4(0.f, 0.f, 0.f, 1.f));



    //TODO checar parametros y funciones para que funcionen en D3d11 y Ogl
    m_cbNeverChanges = graphicsApi.createConstantBuffer(sizeof(CBNeverChanges),
                                                        1,
                                                        &m_constantBuffer);


    ////create rasterizer
    //m_rasterizerGbuffer = graphicsApi.createRasterizerState(FILL_MODE::FILL_SOLID,
    //                                                        CULL_MODE::CULL_FRONT,
    //                                                        true);

    //m_rasterizerSAQ = graphicsApi.createRasterizerState(FILL_MODE::FILL_SOLID,
    //                                                    CULL_MODE::CULL_NONE,
    //                                                    false);

    
    //create depth stencil view
    m_depthStencilView = graphicsApi.createTexture2D(graphicsApi.m_width,
                                                     graphicsApi.m_height,
                                                     1, 
                                                     TF_D24_UNORM_S8_UINT, 
                                                     TEXTURE_BIND_DEPTH_STENCIL, 
                                                     TYPE_USAGE_DEFAULT,
                                                     nullptr);

    ////create depth stencil state
    //m_depthStencilState = graphicsApi.createDepthStencilState(true, true);

    //m_depthStencilStateSAQ = graphicsApi.createDepthStencilState(false, false);
  }

  void
    Renderer::render() {

    auto& graphicsApi = g_graphicsAPI();

    auto& sceneGraph = g_sceneGraph();

    graphicsApi.clearRenderTarget(m_positionTexture, m_color);
    graphicsApi.clearRenderTarget(m_normalTxture, m_color);
    graphicsApi.clearRenderTarget(m_albedoTexture, m_color);

    graphicsApi.clearDepthStencil(m_depthStencilView);

    m_color.setColor(0.5f, 0.3f, 0.1f, 1.0f);

    /*graphicsApi.setDefaultRenderTarget();

    graphicsApi.clearDefaultRenderTargetAndDepthStencil(m_color);*/

    //set all vertex shader constant buffer

    graphicsApi.setVSConstantBuffer(m_cbNeverChanges,
                                    0,
                                    1);
    //set input layout
    graphicsApi.setInputLayout(m_inputLayout);

    
    //shader program
    graphicsApi.setShaderProgram(m_shaderProgram);

    graphicsApi.setRenderTarget(m_vRenderTargets, m_depthStencilView);


    sceneGraph.render();


  }



  void
    Renderer::setModels(Vector<SPtr<Model>> models) {
    m_vModels = models;
  }

  void
    Renderer::setModel(SPtr<Model> model) {
    m_vModels.push_back(model);
  }

}