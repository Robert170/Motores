#include "xcGameAppUnitTest.h"
#include "xcModel.h"
#include "xcComponent.h"
#include "xcStaticMesh.h"
#include "xcActor.h"
#include "xcSceneGraph.h"
#include "xcBaseInput.h"
#include "xcBaseOmvniverse.h"
#include "ImGuiImmplementation.h"

//TODO ERRORES CRITICOS

void 
GameAppUnitTest::onCreate() {

  auto& graphicsApi = g_graphicsAPI();

  auto& sceneGraph = g_sceneGraph();

  auto& omniverse = g_omvniverse();

  graphicsApi.init(graphicsApi.m_window.getSystemHandle());
  
  //ImGuiImplementation::init();

  

  // Set primitive topology
  graphicsApi.setPrimitiveTopology(PRIMITIVE_TOPOLOGY::kPRIMITIVE_TOPOLOGY_TRIANGLELIST);

  
  
  //load model
  //SPtr<Model> exampleModel(new Model("Models/Box_v2.fbx"));
  
  //SPtr<Component> testComponent(new StaticMesh(exampleModel));
  //SPtr<Model> exampleModel(new Model("Models/s/silly_dancing.fbx")); //

  //SPtr<Model> exampleModel(new Model("Models/Agnaktor/idle2.fbx"));

  //SPtr<Model> exampleModel(new Model("Models/Plane/plano.fbx")); //
  ///SPtr<Component> testComponent0(new StaticMesh(exampleModel0));

  //SPtr<Model> exampleModel(new Model("Models/Gwen/Angry.fbx")); //

  //SPtr<Model> exampleModel(new Model("Models/Alien/Xenomorphs_Queen.fbx"));

  //SPtr<Model> exampleModel(new Model("Models/Grimoires/grimoires.fbx"));

  ////////////////////////SPtr<Model> exampleModel(new Model("Models/Vela2/Vela2.fbx"));
  //SPtr<Model> exampleModel(new Model("Models/Cayde6.fbx"));

  //////////////////////SPtr<Component> testComponent(new StaticMesh(exampleModel));

  ///SPtr<Model> exampleModel2(new Model("Models/Plane/plano.fbx")); 
  ///SPtr<Component> testComponent2(new StaticMesh(exampleModel2));
  

 /// SPtr<Actor> testActor0(new Actor("test0"));
  ///testActor0->addComponent(testComponent0);

  ///////////////////////SPtr<Actor> testActor(new Actor("test"));
  ///////////////////////testActor->addComponent(testComponent);

  ///SPtr<Actor> testActor2(new Actor("test2"));
  ///testActor2->addComponent(testComponent2);

  ///sceneGraph.addActor(testActor0, SPtr<SceneNode>(nullptr));
  ///////////////sceneGraph.addActor(testActor, SPtr<SceneNode>(nullptr));
  ///sceneGraph.addActor(testActor2, SPtr<SceneNode>(nullptr));
  
  graphicsApi.setViewport(1,
                          graphicsApi.m_width,
                          graphicsApi.m_height,
                          0,
                          0);

  omniverse.connectFromOmni("http://localhost:8080/omniverse://127.0.0.1/Users/xc170/Example.usd");


}

void
GameAppUnitTest::onEvents(sf::Event event) {


}
void 
GameAppUnitTest::onUpdate(float deltaTime) {
  auto& graphicsApi = g_graphicsAPI();

  auto& sceneGraph = g_sceneGraph();

  auto& inputs = g_input();

  auto& omniverse = g_omvniverse();

  sceneGraph.m_mainCamera.setFowarMove(inputs.isKeyPressed(KEY_BOARD::kKB_W));
  sceneGraph.m_mainCamera.setBackMove(inputs.isKeyPressed(KEY_BOARD::kKB_S));
  sceneGraph.m_mainCamera.setLeftMove(inputs.isKeyPressed(KEY_BOARD::kKB_A));
  sceneGraph.m_mainCamera.setRigthMove(inputs.isKeyPressed(KEY_BOARD::kKB_D));
  
  /*if (omniverse.getLiveEdit()) {
    omniverse.setTransformOp(tmpActor->m_localPosition,
                             OMNI_OP::kTRANSLATE,
                             OMNI_PRECISION::kDOUBLE,
                             tmpActor->m_omniPath);
  }*/
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