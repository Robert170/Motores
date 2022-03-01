#include "xcGameAppUnitTest.h"
#include "xcModel.h"
#include "xcComponent.h"
#include "xcStaticMesh.h"
#include "xcActor.h"
#include "xcSceneGraph.h"
#include "xcBaseInput.h"
#include "ImGuiImmplementation.h"

//TODO ERRORES CRITICOS

void 
GameAppUnitTest::onCreate() {

  auto& graphicsApi = g_graphicsAPI();

  auto& sceneGraph = g_sceneGraph();

  graphicsApi.init(graphicsApi.m_window.getSystemHandle());
  
  //ImGuiImplementation::init();

  

  // Set primitive topology
  graphicsApi.setPrimitiveTopology(PRIMITIVE_TOPOLOGY::kPRIMITIVE_TOPOLOGY_TRIANGLELIST);

  
  
  //load model
  //SPtr<Model> exampleModel(new Model("Models/Box_v2.fbx"));
  
  //SPtr<Component> testComponent(new StaticMesh(exampleModel));
  //SPtr<Model> exampleModel(new Model("Models/s/silly_dancing.fbx")); //

  //SPtr<Model> exampleModel(new Model("Models/Agnaktor/idle2.fbx"));

  ///SPtr<Model> exampleModel0(new Model("Models/Bea/bea_geo.fbx")); //
  ///SPtr<Component> testComponent0(new StaticMesh(exampleModel0));

  //SPtr<Model> exampleModel(new Model("Models/Gwen/Angry.fbx")); //

  //SPtr<Model> exampleModel(new Model("Models/Alien/Xenomorphs_Queen.fbx"));

  //SPtr<Model> exampleModel(new Model("Models/Grimoires/grimoires.fbx"));

  SPtr<Model> exampleModel(new Model("Models/Vela2/Vela2.fbx"));
  //SPtr<Model> exampleModel(new Model("Models/Cayde6.fbx"));

  SPtr<Component> testComponent(new StaticMesh(exampleModel));

  ///SPtr<Model> exampleModel2(new Model("Models/Plane/plano.fbx")); 
  ///SPtr<Component> testComponent2(new StaticMesh(exampleModel2));
  

 /// SPtr<Actor> testActor0(new Actor("test0"));
  ///testActor0->addComponent(testComponent0);

  SPtr<Actor> testActor(new Actor("test"));
  testActor->addComponent(testComponent);

  ///SPtr<Actor> testActor2(new Actor("test2"));
  ///testActor2->addComponent(testComponent2);

  ///sceneGraph.addActor(testActor0, SPtr<SceneNode>(nullptr));
  sceneGraph.addActor(testActor, SPtr<SceneNode>(nullptr));
  ///sceneGraph.addActor(testActor2, SPtr<SceneNode>(nullptr));

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
  //m_constantBuffer.mView = graphicsApi.matri4x4Context(m_camera.getView());
  ///*m_constantBuffer.mView = g_graphicsAPI().initMatrixView(m_view,
  //                                                     Eye,
  //                                                     At,
  //                                                     Up);*/
 
  //m_constantBuffer.mProjection = graphicsApi.
     //                            matri4x4Context(m_camera.getProyeccion());
  ///*m_constantBuffer.mProjection = g_graphicsAPI().initMatrixProjection(m_projection,
    //                                                               Data.fov,
    //                                                               Data.height,
    //                                                               Data.width,
    //                                                               Data.Near,
    //                                                               Data.Far);*/
 
  //m_constantBuffer.mWorld = graphicsApi.initMatrixWorld(m_world);
 
  //m_constantBuffer.vMeshColor = m_meshColor;
 

  //TODO checar parametros y funciones para que funcionen en D3d11 y Ogl
  /*m_cbNeverChanges = graphicsApi.createConstantBuffer(sizeof(CBNeverChanges),
                                                          1, 
                                                          &m_constantBuffer);*/

  

  //// Create the sample state
 
  //g_pSamplerState = g_graphicsAPI().CreateSamplerState();
 
  //g_vSamplers.push_back(g_pSamplerState);

  graphicsApi.setViewport(1,
                          graphicsApi.m_width,
                          graphicsApi.m_height,
                          0,
                          0);

}

void
GameAppUnitTest::onEvents(sf::Event event) {


}
void 
GameAppUnitTest::onUpdate(float deltaTime) {
  auto& graphicsApi = g_graphicsAPI();

  auto& sceneGraph = g_sceneGraph();

  //auto& inputs = g_input();

  /*sceneGraph.m_mainCamera.setFowarMove(inputs.keyPress(KEY_BOARD::KB_W));
  sceneGraph.m_mainCamera.setBackMove(inputs.keyPress(KEY_BOARD::KB_S));
  sceneGraph.m_mainCamera.setLeftMove(inputs.keyPress(KEY_BOARD::KB_A));
  sceneGraph.m_mainCamera.setRigthMove(inputs.keyPress(KEY_BOARD::KB_D));*/
  
  
  //todo CONSTANBUFFER GENERICOS NO ESPECIFICOS
  /*m_constantBuffer.mView = graphicsApi.matri4x4Context(m_camera.getView());
  graphicsApi.updateSubresource(&m_constantBuffer,
                                  *m_cbNeverChanges);*/

  
}

void 
GameAppUnitTest::onRender() {

  auto& graphicsApi = g_graphicsAPI();
 
  /*g_graphicsAPI().SetRenderTarget(m_renderTargets,
                      m_depthStencil);*/
 
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
  
  
 
 
  //// Clear the render target
  /*g_graphicsAPI().ClearRenderTarget(g_pRenderTarget,
                        m_color);*/
 
  //// Clear the depth stencil
  /*g_graphicsAPI().ClearDepthStencil(m_depthStencil, CLEAR_DEPTH,1.0f,0);*/
 

 
 
  //set all vertex shader constant buffer
  
  //graphicsApi.setVSConstantBuffer(m_cbNeverChanges,
    //                                0,
    //                                1);
 
  ////set pixel shader constant buffer
 
  //graphicsApi.setPSConstantBuffer(m_cbNeverChanges,
  //                                0,
  //                                1);

  //graphicsApi.setVSConstantBuffer(m_cbBonesAnimation,
    //                                1,
    //                                1);
 
  ////set pixel shader constant buffer
 
  //graphicsApi.setPSConstantBuffer(m_cbBonesAnimation,
    //                                1,
    //                                1);
 
  /*g_graphicsAPI().SetShaderResource(g_vShaderResources,
                                         0);*/
 
  /*g_graphicsAPI().SetSamplerState(g_vSamplers,
                     0);*/


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
  /*for (int i = m_constantBuffers.size() - 1; i >= 0; --i) {
      if (nullptr != m_constantBuffers.at(i)) {
          delete m_constantBuffers.at(i);
      }
  }*/
 
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