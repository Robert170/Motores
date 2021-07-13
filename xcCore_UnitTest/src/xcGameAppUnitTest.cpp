#include "xcGameAppUnitTest.h"
#include "xcComponent.h"
#include "xcActor.h"



//TODO ERRORES CRITICOS
  
void 
GameAppUnitTest::onCreate() {

  auto& graphicsApi = g_graphicsAPI();

  auto& sceneGraph = g_sceneGraph();

  graphicsApi.init(graphicsApi.m_window.getSystemHandle());
  
  m_camera.setPosition(Vector3(0.0f, 1.0f, -10.0f ));
  m_camera.setLookAt(Vector3(0.0f, 1.0f, 0.0f));
  m_camera.setUp(Vector3(0.0f, 1.0f, 0.0f));
  m_camera.setfar(30000);
  m_camera.setNear(0.1f);
  m_camera.setFielOfView(0.78539816339f);
  m_camera.setWidth(graphicsApi.m_width);
  m_camera.setHeight(graphicsApi.m_height);

  m_camera.init();
  
  //load model

  //m_model.reset(new Model("Models/s/silly_dancing.fbx"));

  //m_model.reset(new Model("Models/Agnaktor/idle2.fbx"));

  m_model.reset(new Model("Models/Bea/bea_geo.fbx"));

  //m_model.reset(new Model("Models/Gwen/Angry.fbx"));

  //m_model.reset(new Model("Models/Bibi/bibi_geo.fbx"));

  //m_model.reset(new Model("Models/Alien/Xenomorphs_Queen.fbx"));

  //m_model.reset(new Model("Models/Grimoires/grimoires.fbx"));

  Component testComponent;
  testComponent.setComponent(m_model);

  SPtr<Actor> testActor(new Actor("test"));
  testActor->addComponent(testComponent);

  sceneGraph.addActor(SPtr<SceneNode>(nullptr), testActor);

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
	  	// positions                    // texture cords
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
  
  //Create render Target
  /*g_pRenderTarget = g_graphicsAPI().CreateTexture2D(800,
  	                                   600,
  	                                   1,
  	                                   TF_R8G8B8A8_UNORM,
  	                                   TEXTURE_BIND_RENDER_TARGET);*/
  
  //m_renderTargets.push_back(g_pRenderTarget);
  
  //// Create the depth stencil 
  /*m_depthStencil = g_graphicsAPI().CreateTexture2D(800,
  	                                   600,
  	                                   1,
  	                                   TF_D24_UNORM_S8_UINT,
  	                                   TEXTURE_BIND_DEPTH_STENCIL,
  	                                   TYPE_USAGE_DEFAULT);*/
  
  ////create shader resource
  /*g_pShaderResource = g_graphicsAPI().CreateTexture2D(800,
  	                                     600,
  	                                     1,
  	                                     TF_R8G8B8A8_UNORM,
  	                                     TEXTURE_BIND_SHADER_RESOURCE);
  
  g_vShaderResources.push_back(g_pShaderResource);*/
 
 

  m_shaderProgram = graphicsApi.createShaderProgram("VS",
 	                                                  "PS", 
 	                                                  "VS", 
 	                                                  "PS", 
 	                                                  "vs_4_0", 
 	                                                  "ps_4_0", 
 	                                                  1,
 	                                                  1);


  // //Set semantic 
  // m_inpLayDesc.Semantics.push_back("POSITION");
  //  m_inpLayDesc.Semantics.push_back("TEXCOORD");
  //m_inpLayDesc.Semantics.push_back("BLENDWEIGHT");
  //m_inpLayDesc.Semantics.push_back("BLENDINDICES");
  
  // m_inpLayDesc.Formats.push_back(TF_R32G32B32A32_FLOAT);
  // m_inpLayDesc.Formats.push_back(TF_R32G32_FLOAT);
  //m_inpLayDesc.Formats.push_back(TF_R32G32B32A32_FLOAT);
  //m_inpLayDesc.Formats.push_back(TF_R32G32B32A32_SINT);
  
  // /* m_inpLayDesc = g_graphicsAPI().CreateInputLayoutDesc(m_vSemanticNames,
  //	                                                m_vFormats);*/
  
  
  ////TODO Mandar puntero o referencia constante a puntero del objeto
  // // Create the input layout
  // m_inputLayout = g_graphicsAPI().createInputLayout(*m_shaderProgram,
  //                                                  m_inpLayDesc,
  //                                                  1);
  
  
  m_inputLayout = graphicsApi.createAutomaticInputLayout(*m_shaderProgram);

  // Create the pixel shader
  /*m_pixelShader = g_graphicsAPI().CreatePixelShaders("PS",
                                      "PS",
                                      "ps_4_0",
                                      1);*/
  /*m_pixelShader = g_graphicsAPI().CreatePixelShaders("Tutorial07.fx",
                                      "PS",
                                      "ps_4_0", 
                                       1);*/
  
  //// Create vertex buffer
  //g_pVertexBuffer = g_graphicsAPI().createVertexBuffer(vertices,
  //                                                 1);
  
  //// Create index buffer
  //g_pIndexBuffer = g_graphicsAPI().createIndexBuffer(indices,
  //	                                              1);
 

  //TODO nombre de funcion intuitivo es de las matrices no del graphi Api
  // Create the constant buffers
  m_constantBuffer.mView = graphicsApi.matri4x4Context(m_camera.getView());
  /*m_constantBuffer.mView = g_graphicsAPI().initMatrixView(m_view,
                                                       Eye,
                                                       At,
                                                       Up);*/
 
  m_constantBuffer.mProjection = graphicsApi.
	                             matri4x4Context(m_camera.getProyeccion());
  /*m_constantBuffer.mProjection = g_graphicsAPI().initMatrixProjection(m_projection,
 	                                                               Data.fov,
 	                                                               Data.height,
 	                                                               Data.width,
 	                                                               Data.Near,
 	                                                               Data.Far);*/
 
  m_constantBuffer.mWorld = graphicsApi.initMatrixWorld(m_world);
 
  m_constantBuffer.vMeshColor = m_meshColor;
 

  //TODO checar parametros y funciones para que funcionen en D3d11 y Ogl
  m_cbNeverChanges = graphicsApi.createConstantBuffer(sizeof(CBNeverChanges),
 	                                                      1, 
 	                                                      &m_constantBuffer);

  m_cbBonesAnimation = graphicsApi.createConstantBuffer(sizeof(CBBones),
	                                                        1, 
	                                                        &m_bonesBuffer);
 
  //// Create the sample state
 
  //g_pSamplerState = g_graphicsAPI().CreateSamplerState();
 
  //g_vSamplers.push_back(g_pSamplerState);

}

void
GameAppUnitTest::onEvents(sf::Event event) {

  m_camera.event(event);

}
void 
GameAppUnitTest::onUpdate(float deltaTime) {
  auto& graphicsApi = g_graphicsAPI();
 
  m_camera.update();
  
  //todo CONSTANBUFFER GENERICOS NO ESPECIFICOS
  m_constantBuffer.mView = graphicsApi.matri4x4Context(m_camera.getView());
  graphicsApi.updateSubresource(&m_constantBuffer,
      		                      *m_cbNeverChanges);
  
  
  
  //TODO la actualizacion del modelo no es aqui, es del componente
  m_model->update(deltaTime, m_transform);
  uint32 transformSize = m_transform.size();
  for (uint32 i = 0; i < transformSize; ++i) {
    if (i < 200) {
      m_bonesBuffer.Bones_CB[i] = m_transform[i];
    }
  }
  
  graphicsApi.updateSubresource(&m_bonesBuffer,
      		                      *m_cbBonesAnimation);
  
}

void 
GameAppUnitTest::onRender() {

  auto& graphicsApi = g_graphicsAPI();
 
  m_color.setColor(0.5f, 0.3f, 0.1f, 1.0f);
  /*m_color.R = 0.0f;
  m_color.G = 0.125f;
  m_color.B = 0.3f;
  m_color.A = 1.0f;*/
 
 
  /*g_graphicsAPI().SetRenderTarget(m_renderTargets,
 	                  m_depthStencil);*/
 
  graphicsApi.setDefaultRenderTarget();
 
  graphicsApi.clearDefaultRenderTargetAndDepthStencil(m_color);
 

  //TODO falta la profundidad
  // Setup the viewport
  graphicsApi.setViewport(1,
	                        graphicsApi.m_width,
 	                        graphicsApi.m_height,
	                        0,
	                        0);
 
  //set input layout
  graphicsApi.setInputLayout(m_inputLayout);
 
  ////set vertex buffer
  //g_graphicsAPI().setVertexBuffer(g_pVertexBuffer,
  //	                           0,
  //	                           1,
  //	                           sizeof(SimpleVertex),
  //	                           0);
  //
  //////set index buffer
  //g_graphicsAPI().setIndexBuffer(g_pIndexBuffer, 
  //	                          0);
  
  // Set primitive topology
  graphicsApi.setPrimitiveTopology(PRIMITIVE_TOPOLOGY_TRIANGLELIST);
 
 
  //// Clear the render target
  /*g_graphicsAPI().ClearRenderTarget(g_pRenderTarget,
 	                    m_color);*/
 
  //// Clear the depth stencil
  /*g_graphicsAPI().ClearDepthStencil(m_depthStencil, CLEAR_DEPTH,1.0f,0);*/
 

 
  //shader program
  graphicsApi.setShaderProgram(m_shaderProgram);
 
  //set all vertex shader constant buffer
  
  graphicsApi.setVSConstantBuffer(m_cbNeverChanges,
 	                                0,
 	                                1);
 
  //set pixel shader constant buffer
 
  graphicsApi.setPSConstantBuffer(m_cbNeverChanges,
                                  0,
                                  1);

  graphicsApi.setVSConstantBuffer(m_cbBonesAnimation,
 	                                1,
 	                                1);
 
  //set pixel shader constant buffer
 
  graphicsApi.setPSConstantBuffer(m_cbBonesAnimation,
 	                                1,
 	                                1);
 
  /*g_graphicsAPI().SetShaderResource(g_vShaderResources,
 	                                     0);*/
 
  /*g_graphicsAPI().SetSamplerState(g_vSamplers,
 	                 0);*/

  m_model->draw(*m_shaderProgram);

  /*g_graphicsAPI().drawIndexed(36,
                           0,
                           0,
                           nullptr);*/
  graphicsApi.present();
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
  /*for (int i = g_vShaderResources.size() - 1; i >= 0; i--) {
 	  if (nullptr != g_vShaderResources.at(i)) {
 		delete g_vShaderResources.at(i);
 	 }
  }
 */
  //constant Buffers
  for (int i = m_constantBuffers.size() - 1; i >= 0; --i) {
 	  if (nullptr != m_constantBuffers.at(i)) {
 		  delete m_constantBuffers.at(i);
 	  }
  }
 
  //vertex buffer
  //delete g_pVertexBuffer;
  
  //index buffer
  //delete g_pIndexBuffer;
  
  ////input layout
  //delete m_inputLayout;
  //
  ////vertex shader
  //delete m_vertexShader;
  //
  ////pixel shader
  //delete m_pixelShader;
  //
  ////depthstencil
  //delete m_depthStencil;
  
  //render targets
  /*for (int i = m_renderTargets.size() - 1; i >= 0; i--)
  {
    if (nullptr != m_renderTargets.at(i))
    {
      delete m_renderTargets.at(i);
    }
  }*/
}