#include "xcSceneNode.h"

namespace xcEngineSDK {
  
  
  SceneNode::SceneNode(WeakSptr<SceneNode> parent, SPtr<Actor> actor) {
    
    m_pParent = parent;
    m_pActor = actor;
  }

  void 
  SceneNode::addChild(WeakSptr<SceneNode> parent, SPtr<Actor> child) {

    SPtr<SceneNode> newNode;
    newNode.reset(new SceneNode(parent, child));
    newNode->m_pActor->m_actorName = "Actor";
    newNode->m_pActor->m_isSelected = false;

    m_pChild.push_back(newNode);

  }

  void 
  SceneNode::removeChild(WeakSptr<Actor> child) {
    for (auto& node : m_pChild) {
      if (node.lock()->m_pActor == child.lock()) {
        
      }
    }
  }

  void 
  SceneNode::selectChild(WeakSptr<Actor> child) {
    //TODO cambiar por un find
    for (auto& node : m_pChild) {

      if (node.lock()->m_pActor == child.lock()) {

        if (node.lock()->m_pActor->m_isSelected) {
          node.lock()->m_pActor->m_isSelected = false;
        }
        else {
          node.lock()->m_pActor->m_isSelected = true;
        }
        return;
      }
    }
  }

  void 
  SceneNode::renameChild(WeakSptr<Actor> child, const String& newName) {
   
  }
  
}