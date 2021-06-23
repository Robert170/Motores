#include "xcGameAppUnitTest.h"

//TODO no se usa el name space

//namespace xcEngineSDK {

//TODO ERRORES CRITICOS
  
  void 
  GameAppUnitTest::onCreate() {

		
		m_camera.setPosition(Vector3(0.0f, 10.0f, -6.0f ));
		m_camera.setLookAt(Vector3(0.0f, 1.0f, 0.0f));
		m_camera.setUp(Vector3(0.0f, 1.0f, 0.0f));
		m_camera.setfar(100);
		m_camera.setNear(1);
		m_camera.setFielOfView(0.7f);
    m_camera.setWidth(g_GraphicsAPI().m_width);
    m_camera.setHeight(g_GraphicsAPI().m_height);

		m_camera.init();


		//load model
		//TODO Quitar el GraphiAPI, poder crear modelo vacio, puntero inteligente
		m_model = new Model("Models/Angry.fbx");

		/*m_model = new Model("Models/S/silly_dancing.fbx",
                        m_GraphiAPI);*/

		/*m_model = new Model("C:/Users/Xc170/Desktop/xcEngine/bin/Models/Bea/bea_geo.fbx",
                        m_GraphiAPI);*/

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

		
	  m_meshColor.x = 1;
		m_meshColor.y = 1;
		m_meshColor.z = 1;


	  /*g_GraphicsAPI().Init(800,
		         600);*/

	  //Create render Target
	  /*g_pRenderTarget = g_GraphicsAPI().CreateTexture2D(800,
	  	                                   600,
	  	                                   1,
	  	                                   TF_R8G8B8A8_UNORM,
	  	                                   TEXTURE_BIND_RENDER_TARGET);*/
	  
	  //m_renderTargets.push_back(g_pRenderTarget);
	  
	  //// Create the depth stencil 
	  /*m_depthStencil = g_GraphicsAPI().CreateTexture2D(800,
	  	                                   600,
	  	                                   1,
	  	                                   TF_D24_UNORM_S8_UINT,
	  	                                   TEXTURE_BIND_DEPTH_STENCIL,
	  	                                   TYPE_USAGE_DEFAULT);*/
	  
	  ////create shader resource
	  /*g_pShaderResource = g_GraphicsAPI().CreateTexture2D(800,
	  	                                     600,
	  	                                     1,
	  	                                     TF_R8G8B8A8_UNORM,
	  	                                     TEXTURE_BIND_SHADER_RESOURCE);
	  
	  g_vShaderResources.push_back(g_pShaderResource);*/
	  
	  

		m_shaderProgram = g_GraphicsAPI().createShaderProgram("VS",
	  	                                                    "PS", 
	  	                                                    "VS", 
	  	                                                    "PS", 
	  	                                                    "vs_4_0", 
	  	                                                    "ps_4_0", 
	  	                                                    1,
	  	                                                    1);
		//TODO reflection y simplificar, hacer funcion para llenar sematica y formato

	 // //Set semantic 
	 // m_inpLayDesc.Semantics.push_back("POSITION");
  //  m_inpLayDesc.Semantics.push_back("TEXCOORD");
		//m_inpLayDesc.Semantics.push_back("BLENDWEIGHT");
		//m_inpLayDesc.Semantics.push_back("BLENDINDICES");

	 // m_inpLayDesc.Formats.push_back(TF_R32G32B32A32_FLOAT);
	 // m_inpLayDesc.Formats.push_back(TF_R32G32_FLOAT);
		//m_inpLayDesc.Formats.push_back(TF_R32G32B32A32_FLOAT);
		//m_inpLayDesc.Formats.push_back(TF_R32G32B32A32_SINT);

  // /* m_inpLayDesc = g_GraphicsAPI().CreateInputLayoutDesc(m_vSemanticNames,
		//	                                                m_vFormats);*/


		////TODO Mandar puntero o referencia constante a puntero del objeto
	 // // Create the input layout
	 // m_inputLayout = g_GraphicsAPI().createInputLayout(*m_shaderProgram,
		//                                                  m_inpLayDesc,
		//                                                  1);


		m_inputLayout = g_GraphicsAPI().createAutomaticInputLayout(*m_shaderProgram);

	  // Create the pixel shader
	  /*m_pixelShader = g_GraphicsAPI().CreatePixelShaders("PS",
		                                     "PS",
		                                     "ps_4_0",
		                                     1);*/
	  /*m_pixelShader = g_GraphicsAPI().CreatePixelShaders("Tutorial07.fx",
		                                     "PS",
		                                     "ps_4_0", 
		                                      1);*/

	  //// Create vertex buffer
	  //g_pVertexBuffer = g_GraphicsAPI().createVertexBuffer(vertices,
		 //                                                 1);

	  //// Create index buffer
	  //g_pIndexBuffer = g_GraphicsAPI().createIndexBuffer(indices,
	  //	                                              1);
	  

		//TODO nombre de funcion intuitivo es de las matrices no del graphi Api
	  // Create the constant buffers
		m_constantBuffer.mView = g_GraphicsAPI().matri4x4Context(m_camera.getView());
    /*m_constantBuffer.mView = g_GraphicsAPI().initMatrixView(m_view,
                                                         Eye,
                                                         At,
                                                         Up);*/
	  
		m_constantBuffer.mProjection = g_GraphicsAPI().
			                             matri4x4Context(m_camera.getProyeccion());
	  /*m_constantBuffer.mProjection = g_GraphicsAPI().initMatrixProjection(m_projection,
	  	                                                               Data.fov,
	  	                                                               Data.height,
	  	                                                               Data.width,
	  	                                                               Data.Near,
	  	                                                               Data.Far);*/
	  
	  m_constantBuffer.mWorld = g_GraphicsAPI().initMatrixWorld(m_world);
	  
	  m_constantBuffer.vMeshColor = m_meshColor;
	  

		//TODO checar parametros y funciones para que funcionen en D3d11 y Ogl
	  m_cbNeverChanges = g_GraphicsAPI().createConstantBuffer(sizeof(CBNeverChanges),
	  	                                                      1, 
	  	                                                      &m_constantBuffer);

		m_cbBonesAnimation = g_GraphicsAPI().createConstantBuffer(sizeof(CBBones),
			                                                        1, 
			                                                        &m_bonesBuffer);

		//TODO no se hace
	  m_constantBuffers.push_back(m_cbNeverChanges);
		m_constantBuffers.push_back(m_cbBonesAnimation);
	  
	  //// Create the sample state
	  
	  //g_pSamplerState = g_GraphicsAPI().CreateSamplerState();
	  
	  //g_vSamplers.push_back(g_pSamplerState);

  }

	void 
	GameAppUnitTest::onEvents(sf::Event event) {

		//TODO 
		m_camera.input(event);
	}

  void 
  GameAppUnitTest::onUpdate(float deltaTime) {

		//TODO nombre update no move
		//m_camera.move();

		//todo CONSTANBUFFER GENERICOS NO ESPECIFICOS
		//m_constantBuffer.mView = g_GraphicsAPI().matri4x4Context(m_camera.getView());
		g_GraphicsAPI().updateSubresource(&m_constantBuffer,
      		                            *m_cbNeverChanges);



		//TODO la actualizacion del modelo no es aqui, es del componente
		m_model->update(deltaTime, m_transform);

    for (int32 i = 0; i < m_transform.size(); ++i) {
      if (i < 200)
      {
				m_bonesBuffer.Bones_CB[i] = m_transform[i];
      }
    }

		g_GraphicsAPI().updateSubresource(&m_bonesBuffer,
      		                            *m_cbBonesAnimation);

  }

  void 
  GameAppUnitTest::onRender() {

		//TODO todo en una sola linea
    m_color.R = 0.0f;
	  m_color.G = 0.125f;
	  m_color.B = 0.3f;
	  m_color.A = 1.0f;
	  
	  
	  /*g_GraphicsAPI().SetRenderTarget(m_renderTargets,
	  	                 m_depthStencil);*/
	  
	  g_GraphicsAPI().setDefaultRenderTarget();
	  
		g_GraphicsAPI().clearDefaultRenderTargetAndDepthStencil(m_color);
	  

		//TODO falta la profundidad
	  // Setup the viewport
	  g_GraphicsAPI().setViewport(1,
	  	                          g_GraphicsAPI().m_width,
	  	                          g_GraphicsAPI().m_height,
			                          0,
			                          0);
	  
	  //set input layout
	  g_GraphicsAPI().setInputLayout(m_inputLayout);
	  
	  ////set vertex buffer
	  //g_GraphicsAPI().setVertexBuffer(g_pVertexBuffer,
	  //	                           0,
	  //	                           1,
	  //	                           sizeof(SimpleVertex),
	  //	                           0);
	  //
	  //////set index buffer
	  //g_GraphicsAPI().setIndexBuffer(g_pIndexBuffer, 
	  //	                          0);
	  
	  // Set primitive topology
	  g_GraphicsAPI().setPrimitiveTopology(PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	  
	  
	  //// Clear the render target
	  /*g_GraphicsAPI().ClearRenderTarget(g_pRenderTarget,
	  	                   m_color);*/
	  
	  //// Clear the depth stencil
	  /*g_GraphicsAPI().ClearDepthStencil(m_depthStencil, CLEAR_DEPTH,1.0f,0);*/
	  
	 
	  
	  //shader program
	  g_GraphicsAPI().setShaderProgram(m_shaderProgram);
	  
	  //set vertex shader
	  //g_GraphicsAPI().SetVertexShaders(m_vertexShader);
	  
	  //set all vertex shader constant buffer
	  
		//TODO simplificar los nombre VS, PS
	  g_GraphicsAPI().setVertexShaderConstantBuffer(m_cbNeverChanges,
	  	                                            0,
	  	                                            1);
	  
	  
	  
	  //set pixel shader
	  //g_GraphicsAPI().SetPixelShaders(m_pixelShader);
	  
	  //set pixel shader constant buffer
	  
	  g_GraphicsAPI().setPixelShaderConstantBuffer(m_cbNeverChanges,
	  	                                           0,
	  	                                           1);


		//TODO simplificar los nombre VS, PS
	  g_GraphicsAPI().setVertexShaderConstantBuffer(m_cbBonesAnimation,
	  	                                            1,
	  	                                            1);
	  
	  
	  
	  //set pixel shader
	  //g_GraphicsAPI().SetPixelShaders(m_pixelShader);
	  
	  //set pixel shader constant buffer
	  
	  g_GraphicsAPI().setPixelShaderConstantBuffer(m_cbBonesAnimation,
	  	                                           1,
	  	                                           1);
	  
	  /*g_GraphicsAPI().SetShaderResource(g_vShaderResources,
	  	                   0);*/
	  
	  /*g_GraphicsAPI().SetSamplerState(g_vSamplers,
	  	                 0);*/

	  m_model->draw(*m_shaderProgram);

    /*g_GraphicsAPI().drawIndexed(36,
                             0,
                             0,
                             nullptr);*/
	  g_GraphicsAPI().present();
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
//}