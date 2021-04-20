#include "xcGameAppUnitTest.h"

namespace xcEngineSDK {
  //TextureBs
  TextureB* g_pRenderTarget = nullptr;
  TextureB* g_pDepthStencil = nullptr;
  TextureB* g_pShaderResource = nullptr;
  
  std::vector<TextureB*> g_vRenderTargets;
  std::vector<TextureB*> g_vShaderResources;
  std::vector<SamplerState*> g_vSamplers;
  std::vector<ConstantBuffer*> g_vConstantBuffers;
  std::vector<std::string> g_vSemanticNames;
  
  //Shader
  VertexShader* g_pVertexShader = nullptr;
  PixelShader* g_pPixelShader = nullptr;
  ShaderProgram* g_pShaderProgram = nullptr;
  InputLayout* g_pInputLayout = nullptr;
  
  //Buffers
  VertexBuffer* g_pVertexBuffer = nullptr;
  IndexBuffer* g_pIndexBuffer = nullptr;
  ConstantBuffer* g_pCBNeverChanges = nullptr;
  
  //Sampler
  SamplerState* g_pSamplerState = nullptr;
  
  //World matrix
  Matrix4x4 g_World;
  Matrix4x4 g_View;
  Matrix4x4 g_Projection;
  
  Vector4 g_MeshColor;
  
  ColorStruct Color;
  
  InputLayout_Desc g_InpLayDesc;
  
  Model* g_Model;
  
  
  struct CBNeverChanges
  {
    Matrix4x4 mView;
    Matrix4x4 mProjection;
    Matrix4x4 mWorld;
    Vector4 vMeshColor;
  };
  
  CBNeverChanges g_ConstantBuffer;


  void 
  GameAppUnitTest::onCreate() {
    CCameraDatas Data;
	  Data.Far = 100;
	  Data.Fov = 0.7f;
	  Data.H = 800;
	  Data.W = 600;
	  Data.Near = 1.0f;

	  Vector3 Eye = { 0.0f, 3.0f, -6.0f };
	  Vector3 At = { 0.0f, 1.0f, 0.0f };
	  Vector3 Up = { 0.0f, 1.0f, 0.0f };

	  Vector<uint32_t> indices =
	  {
	  	3,1,0,
	  	2,1,3,
	  
	  	6,4,5,
	  	7,4,6,
	  
	  	11,9,8,
	  	10,9,11,
	  
	  	14,12,13,
	  	15,12,14,
	  
	  	19,17,16,
	  	18,17,19,
	  
	  	22,20,21,
	  	23,20,22
	  };
	

	  Vector<SimpleVertex> vertices =
	  {
	  	// positions                    // texture coords
	  	{Vector3(-1.0f, 1.0f, -1.0f),  Vector2(0.0f, 0.0f) },
	  	{Vector3(1.0f, 1.0f, -1.0f),   Vector2(1.0f, 0.0f) },
	  	{Vector3(1.0f, 1.0f, 1.0f),    Vector2(1.0f, 1.0f) },
	  	{Vector3(-1.0f, 1.0f, 1.0f),   Vector2(0.0f, 1.0f) },
	  
	  	{Vector3(-1.0f, -1.0f, -1.0f), Vector2(0.0f, 0.0f) },
	  	{Vector3(1.0f, -1.0f, -1.0f),  Vector2(1.0f, 0.0f) },
	  	{Vector3(1.0f, -1.0f, 1.0f),   Vector2(1.0f, 1.0f) },
	  	{Vector3(-1.0f, -1.0f, 1.0f),  Vector2(0.0f, 1.0f) },
	  
	  	{Vector3(-1.0f, -1.0f, 1.0f),  Vector2(0.0f, 0.0f) },
	  	{Vector3(-1.0f, -1.0f, -1.0f), Vector2(1.0f, 0.0f) },
	  	{Vector3(-1.0f, 1.0f, -1.0f),  Vector2(1.0f, 1.0f) },
	  	{Vector3(-1.0f, 1.0f, 1.0f),   Vector2(0.0f, 1.0f) },
	  
	  	{Vector3(1.0f, -1.0f, 1.0f),   Vector2(0.0f, 0.0f) },
	  	{Vector3(1.0f, -1.0f, -1.0f),  Vector2(1.0f, 0.0f) },
	  	{Vector3(1.0f, 1.0f, -1.0f),   Vector2(1.0f, 1.0f) },
	  	{Vector3(1.0f, 1.0f, 1.0f),    Vector2(0.0f, 1.0f) },
	  
	  	{Vector3(-1.0f, -1.0f, -1.0f), Vector2(0.0f, 0.0f) },
	  	{Vector3(1.0f, -1.0f, -1.0f),  Vector2(1.0f, 0.0f) },
	  	{Vector3(1.0f, 1.0f, -1.0f),   Vector2(1.0f, 1.0f) },
	  	{Vector3(-1.0f, 1.0f, -1.0f),  Vector2(0.0f, 1.0f) },
	  
	  	{Vector3(-1.0f, -1.0f, 1.0f),  Vector2(0.0f, 0.0f) },
	  	{Vector3(1.0f, -1.0f, 1.0f),   Vector2(1.0f, 0.0f) },
	  	{Vector3(1.0f, 1.0f, 1.0f),    Vector2(1.0f, 1.0f) },
	  	{Vector3(-1.0f, 1.0f, 1.0f),   Vector2(0.0f, 1.0f) },
	  };


	  g_MeshColor.m_x = 1;
	  g_MeshColor.m_y = 1;
	  g_MeshColor.m_z = 1;


	  /*m_graphiApi->Init(800,
		         600);*/

	  //Create render Target
	  /*g_pRenderTarget = m_graphiApi->CreateTexture2D(800,
	  	                                   600,
	  	                                   1,
	  	                                   TF_R8G8B8A8_UNORM,
	  	                                   TEXTURE_BIND_RENDER_TARGET);*/
	  
	  //g_vRenderTargets.push_back(g_pRenderTarget);
	  
	  //// Create the depth stencil 
	  /*g_pDepthStencil = m_graphiApi->CreateTexture2D(800,
	  	                                   600,
	  	                                   1,
	  	                                   TF_D24_UNORM_S8_UINT,
	  	                                   TEXTURE_BIND_DEPTH_STENCIL,
	  	                                   TYPE_USAGE_DEFAULT);*/
	  
	  ////create shader resource
	  /*g_pShaderResource = m_graphiApi->CreateTexture2D(800,
	  	                                     600,
	  	                                     1,
	  	                                     TF_R8G8B8A8_UNORM,
	  	                                     TEXTURE_BIND_SHADER_RESOURCE);
	  
	  g_vShaderResources.push_back(g_pShaderResource);*/
	  
	  
	  g_pShaderProgram = m_graphiApi->createShaderProgram("VS",
	  	                                                  "PS", 
	  	                                                  "VS", 
	  	                                                  "PS", 
	  	                                                  "vs_4_0", 
	  	                                                  "ps_4_0", 
	  	                                                  1,
	  	                                                  1);
	  // Create the vertex shader
	  /*g_pVertexShader = m_graphiApi->CreateVertexShaders("VS",
	  		                                   "VS",
	  		                                   "vs_4_0",
	  		                                    1);*/
	  
    /*g_pVertexShader = m_graphiApi->CreateVertexShaders("Tutorial07.fx",
	  		                                   "VS",
	  		                                   "vs_4_0", 
	  	                                        1);*/


	  //Set semantic 
	  g_InpLayDesc.Semantics.push_back("POSITION");
	  g_InpLayDesc.Semantics.push_back("TEXCOORD");
	  
	  g_InpLayDesc.Formats.push_back(TF_R32G32B32_FLOAT);
	  g_InpLayDesc.Formats.push_back(TF_R32G32_FLOAT);


	  //load model

    /*g_Model = new Model();
    g_Model->Init("Modelo/Scene.fbx",
                m_graphiApi,
                g_InpLayDesc);*/
	


	  // Create the input layout
	  g_pInputLayout = m_graphiApi->createInputLayout(*g_pShaderProgram,
		                                              g_InpLayDesc,
		                                              1);

	  // Create the pixel shader
	  /*g_pPixelShader = m_graphiApi->CreatePixelShaders("PS",
		                                     "PS",
		                                     "ps_4_0",
		                                     1);*/
	  /*g_pPixelShader = m_graphiApi->CreatePixelShaders("Tutorial07.fx",
		                                     "PS",
		                                     "ps_4_0", 
		                                      1);*/

	  // Create vertex buffer

	  g_pVertexBuffer = m_graphiApi->createVertexBuffer(vertices,
		                                                  vertices.size(),
		                                                  1);

	  // Create index buffer
	  g_pIndexBuffer = m_graphiApi->createIndexBuffer(indices,
	  	                                              indices.size(),
	  	                                              1);
	  
	  // Create the constant buffers
	  
	  
	  
	  g_ConstantBuffer.mView = m_graphiApi->initMatrixView(g_View,
	  	                                                   Eye,
	  	                                                   At,
	  	                                                   Up);
	  
	  g_ConstantBuffer.mProjection = m_graphiApi->initMatrixProjection(g_Projection,
	  	                                                               Data.Fov,
	  	                                                               Data.H,
	  	                                                               Data.W,
	  	                                                               Data.Near,
	  	                                                               Data.Far);
	  
	  g_ConstantBuffer.mWorld = m_graphiApi->initMatrixWorld(g_World);
	  
	  g_ConstantBuffer.vMeshColor = g_MeshColor;
	  
	  g_pCBNeverChanges = m_graphiApi->createConstantBuffer(sizeof(CBNeverChanges),
	  	                                                    1, 
	  	                                                    &g_ConstantBuffer);
	  
	  g_vConstantBuffers.push_back(g_pCBNeverChanges);
	  
	  //// Create the sample state
	  
	  //g_pSamplerState = m_graphiApi->CreateSamplerState();
	  
	  //g_vSamplers.push_back(g_pSamplerState);

  }

  void 
  GameAppUnitTest::onUpdate(float deltaTime) {

    m_graphiApi->updateSubresource(&g_ConstantBuffer,
      		                         *g_pCBNeverChanges);
  }

  void 
  GameAppUnitTest::onRender() {
    Color.R = 0.0f;
	  Color.G = 0.125f;
	  Color.B = 0.3f;
	  Color.A = 1.0f;
	  
	  
	  /*m_graphiApi->SetRenderTarget(g_vRenderTargets,
	  	                 g_pDepthStencil);*/
	  
	  m_graphiApi->setDefaultRenderTarget();
	  
	  
	  
	  // Setup the viewport
	  m_graphiApi->setViewport(1,
	  	                       800,
	  	                       600,0,0);
	  
	  //set inputlayout
	  m_graphiApi->setInputLayout(g_pInputLayout);
	  
	  //set vertex buffer
	  m_graphiApi->setVertexBuffer(g_pVertexBuffer,
	  	                           0,
	  	                           1,
	  	                           sizeof(SimpleVertex),
	  	                           0);
	  
	  ////set index buffer
	  m_graphiApi->setIndexBuffer(g_pIndexBuffer, 
	  	                          0);
	  
	  // Set primitive topology
	  m_graphiApi->setPrimitiveTopology(PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	  
	  
	  //// Clear the render target
	  /*m_graphiApi->ClearRenderTarget(g_pRenderTarget,
	  	                   Color);*/
	  
	  //// Clear the depth stencil
	  /*m_graphiApi->ClearDepthStencil(g_pDepthStencil, CLEAR_DEPTH,1.0f,0);*/
	  
	  m_graphiApi->clearDefaultRenderTargetAndDepthStencil(Color);
	  
	  //shader program
	  m_graphiApi->setShaderProgram(g_pShaderProgram);
	  
	  //set vertex shader
	  //m_graphiApi->SetVertexShaders(g_pVertexShader);
	  
	  //set all vertex shader constant buffer
	  
	  m_graphiApi->setVertexShaderConstantBuffer(g_pCBNeverChanges,
	  	                                         0,
	  	                                         1);
	  
	  
	  
	  //set pixel shader
	  //m_graphiApi->SetPixelShaders(g_pPixelShader);
	  
	  //set pixel shader constant buffer
	  
	  m_graphiApi->setPixelShaderConstantBuffer(g_pCBNeverChanges,
	  	                                        0,
	  	                                        1);
	  
	  /*m_graphiApi->SetShaderResource(g_vShaderResources,
	  	                   0);*/
	  
	  /*m_graphiApi->SetSamplerState(g_vSamplers,
	  	                 0);*/
	  //g_Model->Draw(*g_pShaderProgram, m_graphiApi);
	  m_graphiApi->drawIndexed(36,
	  	                       0,
	  	                       0,
	  	                       nullptr);
	  m_graphiApi->present();
  }

  void 
  GameAppUnitTest::onDestroy() {
    //sampler state
	  for (int i = g_vSamplers.size() - 1; i >= 0; i--)
	  {
	  	if (nullptr != g_vSamplers.at(i))
	  	{
	  		delete g_vSamplers.at(i);
	  	}
	  }
	  
	  //ShaderResource
	  for (int i = g_vShaderResources.size() - 1; i >= 0; i--)
	  {
	  	if (nullptr != g_vShaderResources.at(i))
	  	{
	  		delete g_vShaderResources.at(i);
	  	}
	  }
	  
	  //constant Buffers
	  for (int i = g_vConstantBuffers.size() - 1; i >= 0; i--)
	  {
	  	if (nullptr != g_vConstantBuffers.at(i))
	  	{
	  		delete g_vConstantBuffers.at(i);
	  	}
	  }
	  
	  //vertex buffer
	  //delete g_pVertexBuffer;
	  
	  //index buffer
	  //delete g_pIndexBuffer;
	  
	  //input layout
	  delete g_pInputLayout;
	  
	  //vertex shader
	  delete g_pVertexShader;
	  
	  //pixel shader
	  delete g_pPixelShader;
	  
	  //depthstencil
	  delete g_pDepthStencil;
	  
	  //render targets
	  for (int i = g_vRenderTargets.size() - 1; i >= 0; i--)
	  {
	  	if (nullptr != g_vRenderTargets.at(i))
	  	{
	  		delete g_vRenderTargets.at(i);
	  	}
	  }
  }
}