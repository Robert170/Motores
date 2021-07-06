#include "xcSceneGraph.h"


namespace xcEngineSDK {

  void 
  SceneGraph::addActor(const SPtr<Actor>& actor) {

    m_pRoot->addChild(m_pRoot->m_pActor,actor);
    
  }

  void 
  SceneGraph::removeActor(const SPtr<Actor>& actor) {
    m_pRoot->removeChild(actor);
  }

  void 
  SceneGraph::selectActor(const uint32& index) {

    m_pRoot->selectChild(index);

  }

  void 
  SceneGraph::renameActor(const uint32& index) {

    m_pRoot->renameChild(index);

  }

  SceneGraph& g_sceneGraph() {

    return SceneGraph::instance();

  }
}

