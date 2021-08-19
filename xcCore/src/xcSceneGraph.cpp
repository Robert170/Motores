#include "xcSceneGraph.h"


namespace xcEngineSDK {
  SceneGraph::SceneGraph() {

    m_pRoot.reset(new SceneNode());
    SPtr<Actor> empyActor;
    empyActor.reset(new Actor("Root"));

    m_pRoot->m_pActor = empyActor;
   //m_pRoot->m_pParent = SPtr<SceneNode>(nullptr);

  }

  void
  SceneGraph::addActor(SPtr<Actor> actor, WeakSptr<SceneNode> parent) {

    m_pRoot->addChild(actor, parent.lock() ? parent : m_pRoot);
    
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
  }

  Vector<SPtr<Model>> 
  SceneGraph::getModels() {

    m_pRoot->getModels(m_models);

    return m_models;
  }

  void 
  SceneGraph::render() {

 
    m_pRoot->render();
    
    
  }


  SceneGraph& g_sceneGraph() {

    return SceneGraph::instance();

  }
}

