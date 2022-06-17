#include "xcSceneGraph.h"


namespace xcEngineSDK {
  SceneGraph::SceneGraph() {

    m_pRoot.reset(new SceneNode());
    SPtr<Actor> empyActor;
    empyActor.reset(new Actor("Root"));

    m_pRoot->m_pActor = empyActor;
   //m_pRoot->m_pParent = SPtr<SceneNode>(nullptr);

    auto& graphicsApi = g_graphicsAPI();
    //Vector3(0.0f, 1.0f, -10.0f)
    m_mainCamera.setPosition(Vector3(0.0f, 0.0f, -250.0f));
    m_mainCamera.setLookAt(Vector3(0.0f, 0.0f, -5.0f));
    m_mainCamera.setUp(Vector3(0.0f, 1.0f, 0.0f));
    m_mainCamera.setfar(30000);
    m_mainCamera.setNear(0.1f);
    m_mainCamera.setFielOfView(0.78539816339f);
    m_mainCamera.setWidth(graphicsApi.m_width);
    m_mainCamera.setHeight(graphicsApi.m_height);

    m_mainCamera.init();

    m_numActors = 0;


  }

  void
  SceneGraph::addActor(SPtr<Actor> actor, WeakSptr<SceneNode> parent) {
    actor->m_actorId = m_numActors;
    m_pRoot->addChild(actor, parent.lock() ? parent : m_pRoot);
    m_numActors++;
  }

  void
  SceneGraph::removeActor(const SPtr<Actor> actor) {
    m_pRoot->removeChild(actor);
  }

  void 
  SceneGraph::selectActor(const SPtr<Actor> actor) {

    m_pRoot->selectChild(actor);

  }

  //Tambien es weak 
  void 
  SceneGraph::renameActor(const SPtr<Actor>& actor, const String& newName) {

    m_pRoot->renameChild(actor, newName);

  }

  void 
  SceneGraph::update(float deltaTime) {
    m_pRoot->update(deltaTime);
    m_mainCamera.update();
  }

  Vector<SPtr<Model>> 
  SceneGraph::getModels() {

    m_pRoot->getModels(m_models);

    return m_models;
  }

  uint32 
  SceneGraph::getNumActors() {
    return m_numActors;
  }


  Vector<SPtr<SceneNode>>&
    SceneGraph::getNodesByParent(WeakSptr<SceneNode> inParent) {
    if (SPtr<SceneNode>(nullptr) == inParent.lock()) {
      Vector<SPtr<SceneNode>> tmpList;
      tmpList.push_back(m_pRoot);
      return tmpList;
    }

    return m_pRoot->getNodesByParent(inParent);
  }

  SPtr<SceneNode> 
  SceneGraph::getRoot() {
    return m_pRoot;
  }

  void 
  SceneGraph::render() {

 
    m_pRoot->render();
    
    
  }


  SceneGraph& g_sceneGraph() {

    return SceneGraph::instance();

  }
}

