// To change in the next update
#include <imgui_impl_win32.cpp>
#include <imgui_impl_dx11.cpp>

#include "xcImGui.h"
#include <xcGraphiAPI.h>
#include <xcBaseInput.h>
using namespace xcEngineSDK;
using namespace ImGui;

void
UI::init(void* inWindow, Vector2 inWindowSize) {


  m_windowSize = inWindowSize;
  m_windowHandle = inWindow;

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  io.DisplaySize = ImVec2(inWindowSize.x, inWindowSize.y);
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;


  /*ImGuiStyle& style = ImGui::GetStyle();
  if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
    style.WindowRounding = 0.0f;
    style.Colors[ImGuiCol_WindowBg].w = 1.0f;
  }*/

  //ImGui::StyleColorsDark();

  ImGui_ImplWin32_Init(m_windowHandle);
  ImGui_ImplDX11_Init((ID3D11Device*)g_graphicsAPI().getDevice(),
    (ID3D11DeviceContext*)g_graphicsAPI().getDeviceContext());

  //Change font path to engine settings
  //io.Fonts->AddFontFromFileTTF("Resources/Fonts/Inter-Regular.ttf", 15.0f);

  m_text.resize(500);
  m_size = 100.0f;
  //embraceTheDarkness();
}

void
UI::update(void* inWindow, float inDT) {
  ImGui_ImplDX11_NewFrame();
  ImGui_ImplWin32_NewFrame();
  ImGui::NewFrame();
}

void
UI::render() {
  //isMouseTouchingImGui();

  ImGuiIO& io = ImGui::GetIO();


  //ImGui::ShowDemoWindow();

  ImGui::Render();
  ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

  // Update and Render additional Platform Windows
  if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefault();
  }
}

void
UI::shutDown() {

  ImGui_ImplDX11_Shutdown();
  ImGui_ImplWin32_Shutdown();
  ImGui::DestroyContext();
}

void
UI::callBack() {
  ImGuiIO& io = ImGui::GetIO();
  //Mouse Pressed case
  {
    int32 button = -1;
    button = xcEngineSDK::g_input().isMouseKeyPressed(xcEngineSDK::MOUSE_KEY::KMB_LEFT) ?
      0 : button;
    button = xcEngineSDK::g_input().isMouseKeyPressed(xcEngineSDK::MOUSE_KEY::KMB_RIGHT) ?
      1 : button;
    button = xcEngineSDK::g_input().isMouseKeyPressed(xcEngineSDK::MOUSE_KEY::KMB_MIDDLE) ?
      2 : button;
    button = xcEngineSDK::g_input().isMouseKeyPressed(xcEngineSDK::MOUSE_KEY::KMB_BUTTON3) ?
      3 : button;
    button = xcEngineSDK::g_input().isMouseKeyPressed(xcEngineSDK::MOUSE_KEY::KMB_BUTTON4) ?
      4 : button;
    if (button > -1) {
      io.MouseDown[button] = true;
    }
  }
  //Mouse released case
  {
    int32 button = -1;
    button = xcEngineSDK::g_input().isMouseKeyReleased(xcEngineSDK::MOUSE_KEY::KMB_LEFT) ?
      0 : button;
    button = xcEngineSDK::g_input().isMouseKeyReleased(xcEngineSDK::MOUSE_KEY::KMB_RIGHT) ?
      1 : button;
    button = xcEngineSDK::g_input().isMouseKeyReleased(xcEngineSDK::MOUSE_KEY::KMB_MIDDLE) ?
      2 : button;
    button = xcEngineSDK::g_input().isMouseKeyReleased(xcEngineSDK::MOUSE_KEY::KMB_BUTTON3) ?
      3 : button;
    button = xcEngineSDK::g_input().isMouseKeyReleased(xcEngineSDK::MOUSE_KEY::KMB_BUTTON4) ?
      4 : button;
    if (button > -1) {
      io.MouseDown[button] = false;
    }
  }
}

