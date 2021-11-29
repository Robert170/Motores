#include <imgui.h>
#include "ImGuiImmplementation.h"
void 
ImGuiImplementatio::Init() {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
}
