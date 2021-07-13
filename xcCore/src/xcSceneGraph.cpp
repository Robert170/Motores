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
  SceneGraph::addActor(const WeakSptr<SceneNode>& parent, 
                       const SPtr<Actor>& actor) {
    if (nullptr == parent.lock()) {
      m_pRoot->addChild(m_pRoot, actor);
    }
    else {
      m_pRoot->addChild(parent, actor);
    }
    
  }

  void 
  SceneGraph::removeActor(const SPtr<Actor>& actor) {
    m_pRoot->removeChild(actor);
  }

  void 
  SceneGraph::selectActor(const SPtr<Actor>& actor) {

    m_pRoot->selectChild(actor);

  }

  void 
  SceneGraph::renameActor(const SPtr<Actor>& actor, const String& newName) {

    m_pRoot->renameChild(actor, newName);

  }

  SceneGraph& g_sceneGraph() {

    return SceneGraph::instance();

  }
}

