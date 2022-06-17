
 /**
  * @include
  */
#include "xcDetails.h"
#include <xcSceneGraph.h>
#include <xcBaseOmvniverse.h>

Details::Details() {

}

void
Details::init() {

}

void
Details::update(float inDeltaTime) {

}

void
Details::render() {
  auto& sg = SceneGraph::instance();
  ImGui::Begin("Details", nullptr, m_windowFlags);
  if (sg.getSelectedActor() != nullptr) {
    auto tmpActor = sg.getSelectedActor();
    if (ImGui::CollapsingHeader("Transform", ImGuiWindowFlags_NoNav)) {

      ImGui::DragFloat3("Position", &sg.getSelectedActor()->m_actorPosition.x);
      if (ImGui::IsItemEdited()) {
        if (g_omvniverse().getLiveEdit() && !tmpActor->m_omniPath.empty()) {
          g_omvniverse().setTransformOp(tmpActor->m_actorPosition,
            OMNI_OP::kTRANSLATE,
            OMNI_PRECISION::kDOUBLE,
            tmpActor->m_omniPath);
        }
      }
      /*ImGui::DragFloat3("Rotation", &sg.getSelectedActor()->m_transform.m_rotation.x);
      if (ImGui::IsItemEdited() && !tmpActor->m_omniPath.empty()) {
        if (g_omvniverse().m_liveEditActivation) {
          g_omvniverse().setTransformOp(tmpActor->m_transform.m_rotation,
            OMNI_OP::kROTATE,
            OMNI_PRECISION::kFLOAT,
            tmpActor->m_omniPath);
        }
      }*/
      ImGui::DragFloat3("Scale", &sg.getSelectedActor()->m_actorScale.x);
      if (ImGui::IsItemEdited()) {
        if (g_omvniverse().getLiveEdit() && !tmpActor->m_omniPath.empty()) {
          g_omvniverse().setTransformOp(tmpActor->m_actorScale,
            OMNI_OP::kSCALE,
            OMNI_PRECISION::kFLOAT,
            tmpActor->m_omniPath);
        }
      }
    }
  }
  ImGui::End();
}

void
Details::destroy() {

}
