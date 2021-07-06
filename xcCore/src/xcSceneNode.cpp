#include "xcSceneNode.h"

namespace xcEngineSDK {
  
  SceneNode::SceneNode(WeakSptr<Actor> parent, WeakSptr<Actor> actor) {
    m_pParent = parent;
    m_pActor = actor.lock();
  }

  void 
  SceneNode::addChild(WeakSptr<Actor> parent, WeakSptr<Actor> child) {

    SPtr<SceneNode> newNode;
    newNode.reset(new SceneNode(parent, child));

    m_pChild.push_back(newNode);

  }

  void 
  SceneNode::removeChild(WeakSptr<Actor> child) {

  }

  void 
  SceneNode::selectChild(const uint32& index) {
    m_pChild.
  }

  void 
  SceneNode::renameChild(const uint32& index) {

  }
  
}