#include "xcSceneNode.h"

namespace xcEngineSDK {
  
  //TODO padres e hijos deben ser weak
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
    //TODO ActorRender

    m_pActor->update(deltaTime);

    if (m_pChild.empty()) {

      return;

    }


    for (auto node : m_pChild) {

      auto temp = node;

      if (temp) {
        temp-> update(deltaTime);
      }

    }
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

  void 
  SceneNode::getModels(Vector<SPtr<Model>>& model) {
    m_pActor->getModels(model);

    if (m_pChild.empty()) {

      return;

    }



    for (auto node : m_pChild) {

      auto temp = node;

      if (temp) {
        temp->getModels(model);
      }

    }
  }

  Vector<SPtr<SceneNode>>&
  SceneNode::getNodesByParent(WeakSptr<SceneNode> inParent) {
    if (inParent.lock() == m_pParent.lock()) {
      return m_pParent.lock()->m_pChild;
    }
    else {
      for (auto nodes : m_pChild) {
        auto tmpListNodes = nodes->getNodesByParent(inParent);

        if (!tmpListNodes.empty() && (inParent.lock()->m_pParent.lock() == nodes->m_pParent.lock())) {
          return tmpListNodes;
        }

      }
    }
    return m_pChild;
  }
  

}