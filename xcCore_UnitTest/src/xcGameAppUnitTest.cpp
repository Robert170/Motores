#include "xcGameAppUnitTest.h"


namespace xcEngineSDK {
  
  void 
  GameAppUnitTest::onCreate() {

    CameraDatas Data;
	  Data.Far = 100;
	  Data.fov = 0.7f;
	  Data.height = m_graphiApi->m_height;
	  Data.width = m_graphiApi->m_width;
	  Data.Near = 1.0f;
		Data.position = { 20.0f, 50.0f, -6.0f };
		Data.at = { 0.0f, 1.0f, 0.0f };
		Data.up = { 0.0f, 1.0f, 0.0f };

    /*Vector3 Eye = { 0.0f, 3.0f, -6.0f };
    Vector3 At = { 0.0f, 1.0f, 0.0f };
    Vector3 Up = { 0.0f, 1.0f, 0.0f };*/

		m_camera.init(Data);


		//load model

		m_model = new Model("Models/Angry.fbx",
                        m_graphiApi);

		/*m_model = new Model("Models/S/silly_dancing.fbx",
                        m_graphiApi);*/

		/*m_model = new Model("C:/Users/Xc170/Desktop/xcEngine/bin/Models/Bea/bea_geo.fbx",
                        m_graphiApi);*/

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


	  m_meshColor.m_x = 1;
		m_meshColor.m_y = 1;
		m_meshColor.m_z = 1;


	  /*m_graphiApi->Init(800,
		         600);*/

	  //Create render Target
	  /*g_pRenderTarget = m_graphiApi->CreateTexture2D(800,
	  	                                   600,
	  	                                   1,
	  	                                   TF_R8G8B8A8_UNORM,
	  	                                   TEXTURE_BIND_RENDER_TARGET);*/
	  
	  //m_renderTargets.push_back(g_pRenderTarget);
	  
	  //// Create the depth stencil 
	  /*m_depthStencil = m_graphiApi->CreateTexture2D(800,
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
	  
	  
	  m_shaderProgram = m_graphiApi->createShaderProgram("VS",
	  	                                                  "PS", 
	  	                                                  "VS", 
	  	                                                  "PS", 
	  	                                                  "vs_4_0", 
	  	                                                  "ps_4_0", 
	  	                                                  1,
	  	                                                  1);


	  //Set semantic 
	  m_inpLayDesc.Semantics.push_back("POSITION");
		m_inpLayDesc.Semantics.push_back("BLENDWEIGHT");
		m_inpLayDesc.Semantics.push_back("BLENDINDICES");
	  // m_inpLayDesc.Semantics.push_back("TEXCOORD");
		//m_vSemanticNames.push_back("POSITION");
		//m_vSemanticNames.push_back("TEXCOORD");
	  //m_inpLayDesc.Formats.push_back(TF_R32G32B32_FLOAT);
	  //m_inpLayDesc.Formats.push_back(TF_R32G32_FLOAT);
	
		m_vFormats.push_back(TF_R32G32B32_FLOAT);
		m_vFormats.push_back(TF_R32G32B32A32_FLOAT);
		m_vFormats.push_back(TF_R32G32B32A32_SINT);

   /* m_inpLayDesc = m_graphiApi->CreateInputLayoutDesc(m_vSemanticNames,
			                                                m_vFormats);*/

	  // Create the input layout
	  m_inputLayout = m_graphiApi->createInputLayout(*m_shaderProgram,
		                                                m_inpLayDesc,
		                                                1);

	  // Create the pixel shader
	  /*m_pixelShader = m_graphiApi->CreatePixelShaders("PS",
		                                     "PS",
		                                     "ps_4_0",
		                                     1);*/
	  /*m_pixelShader = m_graphiApi->CreatePixelShaders("Tutorial07.fx",
		                                     "PS",
		                                     "ps_4_0", 
		                                      1);*/

	  //// Create vertex buffer
	  //g_pVertexBuffer = m_graphiApi->createVertexBuffer(vertices,
		 //                                                 1);

	  //// Create index buffer
	  //g_pIndexBuffer = m_graphiApi->createIndexBuffer(indices,
	  //	                                              1);
	  
	  // Create the constant buffers
		m_constantBuffer.mView = m_graphiApi->matri4x4Context(m_camera.getView());
    /*m_constantBuffer.mView = m_graphiApi->initMatrixView(m_view,
                                                         Eye,
                                                         At,
                                                         Up);*/
	  
		m_constantBuffer.mProjection = m_graphiApi->
			                             matri4x4Context(m_camera.getProyeccion());
	  /*m_constantBuffer.mProjection = m_graphiApi->initMatrixProjection(m_projection,
	  	                                                               Data.fov,
	  	                                                               Data.height,
	  	                                                               Data.width,
	  	                                                               Data.Near,
	  	                                                               Data.Far);*/
	  
	  m_constantBuffer.mWorld = m_graphiApi->initMatrixWorld(m_world);
	  
	  m_constantBuffer.vMeshColor = m_meshColor;
	  
	  m_cbNeverChanges = m_graphiApi->createConstantBuffer(sizeof(CBNeverChanges),
	  	                                                    1, 
	  	                                                    &m_constantBuffer);
	  
	  m_constantBuffers.push_back(m_cbNeverChanges);
	  
	  //// Create the sample state
	  
	  //g_pSamplerState = m_graphiApi->CreateSamplerState();
	  
	  //g_vSamplers.push_back(g_pSamplerState);

  }

	void 
	GameAppUnitTest::onEvents(sf::Event event) {

		m_camera.input(event);
	}

  void 
  GameAppUnitTest::onUpdate(float deltaTime) {
		deltaTime = 0;
		//m_camera.move();
		//m_constantBuffer.mView = m_graphiApi->matri4x4Context(m_camera.getView());
    m_graphiApi->updateSubresource(&m_constantBuffer,
      		                         *m_cbNeverChanges);
  }

  void 
  GameAppUnitTest::onRender() {
    m_color.R = 0.0f;
	  m_color.G = 0.125f;
	  m_color.B = 0.3f;
	  m_color.A = 1.0f;
	  
	  
	  /*m_graphiApi->SetRenderTarget(m_renderTargets,
	  	                 m_depthStencil);*/
	  
	  m_graphiApi->setDefaultRenderTarget();
	  
		m_graphiApi->clearDefaultRenderTargetAndDepthStencil(m_color);
	  
	  // Setup the viewport
	  m_graphiApi->setViewport(1,
	  	                       m_graphiApi->m_width,
	  	                       m_graphiApi->m_height,
			                       0,
			                       0);
	  
	  //set input layout
	  m_graphiApi->setInputLayout(m_inputLayout);
	  
	  ////set vertex buffer
	  //m_graphiApi->setVertexBuffer(g_pVertexBuffer,
	  //	                           0,
	  //	                           1,
	  //	                           sizeof(SimpleVertex),
	  //	                           0);
	  //
	  //////set index buffer
	  //m_graphiApi->setIndexBuffer(g_pIndexBuffer, 
	  //	                          0);
	  
	  // Set primitive topology
	  m_graphiApi->setPrimitiveTopology(PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	  
	  
	  //// Clear the render target
	  /*m_graphiApi->ClearRenderTarget(g_pRenderTarget,
	  	                   m_color);*/
	  
	  //// Clear the depth stencil
	  /*m_graphiApi->ClearDepthStencil(m_depthStencil, CLEAR_DEPTH,1.0f,0);*/
	  
	 
	  
	  //shader program
	  m_graphiApi->setShaderProgram(m_shaderProgram);
	  
	  //set vertex shader
	  //m_graphiApi->SetVertexShaders(m_vertexShader);
	  
	  //set all vertex shader constant buffer
	  
	  m_graphiApi->setVertexShaderConstantBuffer(m_cbNeverChanges,
	  	                                         0,
	  	                                         1);
	  
	  
	  
	  //set pixel shader
	  //m_graphiApi->SetPixelShaders(m_pixelShader);
	  
	  //set pixel shader constant buffer
	  
	  m_graphiApi->setPixelShaderConstantBuffer(m_cbNeverChanges,
	  	                                        0,
	  	                                        1);
	  
	  /*m_graphiApi->SetShaderResource(g_vShaderResources,
	  	                   0);*/
	  
	  /*m_graphiApi->SetSamplerState(g_vSamplers,
	  	                 0);*/

	  m_model->draw(*m_shaderProgram, m_graphiApi);

    /*m_graphiApi->drawIndexed(36,
                             0,
                             0,
                             nullptr);*/
	  m_graphiApi->present();
  }

  void 
  GameAppUnitTest::onDestroy() {
    //sampler state
	  /*for (int i = g_vSamplers.size() - 1; i >= 0; i--)
	  {
	  	if (nullptr != g_vSamplers.at(i))
	  	{
	  		delete g_vSamplers.at(i);
	  	}
	  }*/
	  
	  //ShaderResource
	  /*for (int i = g_vShaderResources.size() - 1; i >= 0; i--)
	  {
	  	if (nullptr != g_vShaderResources.at(i))
	  	{
	  		delete g_vShaderResources.at(i);
	  	}
	  }
	  */
	  //constant Buffers
	  for (int i = m_constantBuffers.size() - 1; i >= 0; i--)
	  {
	  	if (nullptr != m_constantBuffers.at(i))
	  	{
	  		delete m_constantBuffers.at(i);
	  	}
	  }
	  
	  //vertex buffer
	  //delete g_pVertexBuffer;
	  
	  //index buffer
	  //delete g_pIndexBuffer;
	  
	  //input layout
	  delete m_inputLayout;
	  
	  //vertex shader
	  delete m_vertexShader;
	  
	  //pixel shader
	  delete m_pixelShader;
	  
	  //depthstencil
	  delete m_depthStencil;
	  
	  //render targets
    /*for (int i = m_renderTargets.size() - 1; i >= 0; i--)
    {
      if (nullptr != m_renderTargets.at(i))
      {
        delete m_renderTargets.at(i);
      }
    }*/
  }
}