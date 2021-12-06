#include <imgui.h>
#include "ImGuiImmplementation.h"
#include <xcGraphiAPI.h>


void 
ImGuiImplementatio::init() {

  auto& graphicsApi = g_graphicsAPI();

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  // Setup Dear ImGui style
  ImGui::StyleColorsDark();

  // Create the vertex shader and pixel shader
  
  m_shaderProgramImGui = graphicsApi.createShaderProgram("IMGUIVS", //file name VS
                                                         "IMGUIPS", //file name PS
                                                         "main", //Entry point vs
                                                         "main", //entry point ps
                                                         "vs_4_0",
                                                         "ps_4_0",
                                                         1,
                                                         1);

  // Create the input layout

  m_inputLayout = graphicsApi.createAutomaticInputLayout(*m_shaderProgramImGui);

  // Create the constant buffer
  m_vertexConstantBuffer = graphicsApi.createConstantBuffer(sizeof(VERTEX_CONSTANT_BUFFER),
                                                            1,
                                                            &m_cbVertex, 
                                                            TYPE_USAGE::
                                                            kTYPE_USAGE_DEFAULT,
                                                            CPU_ACCESS_FLAG::
                                                            kCPU_ACCESS_WRITE);

  m_blendState = graphicsApi.createBlendState();

  m_rasterizerState = graphicsApi.createRasterizerState(FILL_MODE::kFILL_SOLID, 
                                                        CULL_MODE::kCULL_NONE, 
                                                        true);
  //si falla checar
  m_depthStencilState = graphicsApi.createDepthStencilState(false, false);

  io.Fonts->GetTexDataAsRGBA32(&m_pixels, &m_width, &m_height);

  m_fontTextureView = graphicsApi.createTexture2D(m_width,
                                                  m_height,
                                                  1, 
                                                  TEXTURE_FORMAT::
                                                  kTF_R8G8B8A8_UNORM, 
                                                  TEXTURE_BIND_FLAG::
                                                  kTEXTURE_BIND_SHADER_RESOURCE,
                                                  TYPE_USAGE::kTYPE_USAGE_DEFAULT,
                                                  m_pixels);

  io.Fonts->SetTexID((ImTextureID)m_fontTextureView);

}


void
ImGuiImplementatio::update() {
  //auto& graphicsApi = g_graphicsAPI();

}

void 
ImGuiImplementatio::render() {
}
