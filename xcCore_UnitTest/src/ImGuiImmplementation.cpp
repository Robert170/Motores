#include <imgui.h>
#include "ImGuiImmplementation.h"
#include <xcGraphiAPI.h>


struct ImGuiData
{
  SPtr<IndexBuffer> m_IB;
  SPtr<VertexBuffer> m_VB;
  SPtr<ShaderProgram> m_shaderProgramImGui;
  SPtr<InputLayout> m_inputLayout;
  SPtr<ConstantBuffer> m_vertexConstantBuffer;
  CONSTANT_BUFFER m_cbVertex;

  SPtr<SamplerState> m_sampler;
  Vector<SPtr<SamplerState>> m_vfontSampler;
  SPtr<RasterizerState> m_rasterizerState;
  SPtr<DepthStencilState> m_depthStencilState;
  SPtr<BlendState> m_blendState;
  Texture* m_fontTextureView;


  uint32 m_vertexBufferSize = 5000;
  uint32 m_indexBufferSize = 10000;

  unsigned char* m_pixels;
  int32 m_width;
  int32 m_height;
};

static ImGuiData* ImGuiGetBackendData()
{
  return ImGui::GetCurrentContext() ? 
               (ImGuiData*)ImGui::GetIO().BackendRendererUserData : nullptr;
}

void 
ImGuiImplementation::init() {

  auto& graphicsApi = g_graphicsAPI();

  // Setup backend capabilities flags
 
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  IM_ASSERT(io.BackendRendererUserData == nullptr && "Already initialized a renderer backend!");
  ImGuiData* data = IM_NEW(ImGuiData)();
  io.BackendRendererUserData = (void*)data;
  io.BackendRendererName = "imgui_impl_dx11";
  io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset;

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();

  // Create the vertex shader and pixel shader
  
  data->m_shaderProgramImGui = graphicsApi.createShaderProgram("IMGUIVS", //file name VS
                                                               "IMGUIPS", //file name PS
                                                               "main", //Entry point vs
                                                               "main", //entry point ps
                                                               "vs_5_0",
                                                               "ps_5_0",
                                                               1,
                                                               1);

  // Create the input layout

  data->m_inputLayout = graphicsApi.createAutomaticInputLayout(*data->
                                                               m_shaderProgramImGui);

  // Create the constant buffer
  data->m_vertexConstantBuffer = graphicsApi.createConstantBuffer(sizeof
                                                                 (CONSTANT_BUFFER),
                                                                  1,
                                                                  nullptr,
                                                                  TYPE_USAGE::
                                                                  kTYPE_USAGE_DEFAULT,
                                                                  CPU_ACCESS_FLAG::
                                                                  kCPU_ACCESS_DEFAULT);

  data->m_blendState = graphicsApi.createBlendState();

  data->m_rasterizerState = graphicsApi.createRasterizerState(FILL_MODE::kFILL_SOLID,
                                                              CULL_MODE::kCULL_NONE, 
                                                              true);
  //si falla checar
  data->m_depthStencilState = graphicsApi.createDepthStencilState(false, false);

  io.Fonts->GetTexDataAsRGBA32(&data->m_pixels, 
                               &data->m_width, 
                               &data->m_height);

  data->m_fontTextureView = graphicsApi.createTexture2D(data->m_width,
                                                        data->m_height,
                                                        1, 
                                                        TEXTURE_FORMAT::
                                                        kTF_R8G8B8A8_UNORM, 
                                                        TEXTURE_BIND_FLAG::
                                                        kTEXTURE_BIND_SHADER_RESOURCE,
                                                        TYPE_USAGE::kTYPE_USAGE_DEFAULT,
                                                        data->m_pixels);

  io.Fonts->SetTexID((ImTextureID)data->m_fontTextureView);

  data->m_sampler = graphicsApi.createSamplerState(0,
                                                   0.0f,
                                                   0.0f,
                                                   0.0f,
                                                   COMPARISON_FUNC::
                                                   kCOMPARISON_ALWAYS,
                                                   TEXTURE_ADDRESS_MODE::
                                                   kTEXTURE_ADDRESS_WRAP,
                                                   FILTER::
                                                   kFILTER_MIN_MAG_MIP_LINEAR);
   
}


void
ImGuiImplementation::update() {
  //auto& graphicsApi = g_graphicsAPI();

}

void 
ImGuiImplementation::render() {

  ImDrawData* draw_data = ImGui::GetDrawData();

  // Avoid rendering when minimized
  if (draw_data->DisplaySize.x <= 0.0f || 
      draw_data->DisplaySize.y <= 0.0f) {
    return;
  }

  ImGuiData* bd = ImGuiGetBackendData();

  
}
