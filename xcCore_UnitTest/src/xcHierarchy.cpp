
 /**
  * @include
  */
#include "xcHierarchy.h"
#include <xcSceneGraph.h>


Hierarchy::Hierarchy() {

  init();
}

void
Hierarchy::init() {
  m_windowFlags = ImGuiWindowFlags_NoNav
    | ImGuiWindowFlags_NoCollapse;


  m_rootFlags = ImGuiTreeNodeFlags_OpenOnArrow
    | ImGuiTreeNodeFlags_OpenOnDoubleClick
    | ImGuiTreeNodeFlags_SpanAvailWidth;

  m_treeSelectableFlags = m_rootFlags | ImGuiTreeNodeFlags_Selected;


  m_leafFlags = m_treeSelectableFlags |= ImGuiTreeNodeFlags_Leaf
    | ImGuiTreeNodeFlags_NoTreePushOnOpen;
}

void
Hierarchy::update(float inDeltaTime) {

}

void
Hierarchy::render() {
  auto& sg = SceneGraph::instance();
  auto root = sg.getRoot();
  auto tmpNodes = sg.getNodesByParent(root);
  ImGui::Begin("Hierarchy", nullptr, m_windowFlags); {

    ImGui::SetNextItemOpen(true);

    if (ImGui::TreeNode("Root")) {
      for (auto node : tmpNodes) {
        evaluateNode(node);
      }
    }
    ImGui::TreePop();

    ImGui::End();
  }
}

void
Hierarchy::destroy() {

}

void
Hierarchy::renderNodeWithChilds(SPtr<SceneNode> inNode) {
  auto& sg = SceneGraph::instance();

  //ImGui::SetNextItemOpen(true);

  if (ImGui::TreeNode(inNode->m_pActor->m_actorName.c_str())) {
    //Get all the childs and create leafs with them information.
    for (auto child : inNode->m_pChild) {
      evaluateNode(inNode);
    }
    ImGui::TreePop();
  }
  if (ImGui::IsItemClicked()) {
    sg.setSelectedActor(inNode->m_pActor);
  }

}

void
Hierarchy::renderNode(SPtr<SceneNode> inNode) {
  auto& sg = SceneGraph::instance();
  //Create a leaf
  if (ImGui::TreeNodeEx((void*)(intptr_t)inNode->m_pActor->m_actorId,
    m_leafFlags,
    inNode->m_pActor->m_actorName.c_str())) {


    if (ImGui::IsItemClicked()) {
      sg.setSelectedActor(inNode->m_pActor);
    }
  }

}

void
Hierarchy::evaluateNode(SPtr<SceneNode> inNode) {
  //The actor have childs.
  if (0 < inNode->m_pChild.size()) {
    renderNodeWithChilds(inNode);
  }
  //The actor doesn't have childs.
  else if (0 == inNode->m_pChild.size()) {
    renderNode(inNode);
  }
}
