#include "xcSceneNode.h"

namespace xcEngineSDK {
  
  
  SceneNode::SceneNode(SPtr<SceneNode> parent, SPtr<Actor> actor) {
    
    m_pParent = parent;
    m_pActor = actor;
  }

  void 
  SceneNode::addChild(SPtr<SceneNode> parent, SPtr<Actor> child) {

    SPtr<SceneNode> newNode;
    newNode.reset(new SceneNode(parent, child));
    newNode->m_pActor->m_actorName = "Actor";
    newNode->m_pActor->m_isSelected = false;

    m_pChild.push_back(newNode);

  }

  void 
  SceneNode::removeChild(WeakSptr<Actor> child) {
    
  }

  void 
  SceneNode::selectChild(WeakSptr<Actor> child) {
    //TODO change to a find
    
  }

  void 
  SceneNode::renameChild(WeakSptr<Actor> child, const String& newName) {
   
  }
  
}