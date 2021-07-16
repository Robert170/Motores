#include "xcSceneNode.h"

namespace xcEngineSDK {
  
  //TODO padres e hijos deben se weak
  SceneNode::SceneNode(SPtr<Actor> child, WeakSptr<SceneNode> parent) {
    
    m_pParent = parent;
    m_pActor = child;
  }

  void 
  SceneNode::addChild(SPtr<Actor> child, WeakSptr<SceneNode> parent) {

    SPtr<SceneNode> newNode; 
    newNode.reset(new SceneNode(child, parent));
    //newNode->m_pActor->setName("Actor");

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
  
  void 
  SceneNode::update(float deltaTime) {

  }

  void 
  SceneNode::render() {

    //TODO ActorRender

    m_pActor->renderComponent();

    if (m_pChild.empty()) {

      return;

    }


    for (auto node : m_pChild) {

      auto temp = node;

      if (temp) {
        temp->render();
      }

    }

  }

}