#include "xcBaseApp.h"
#include <xcPlugin.h>

namespace xcEngineSDK {

  int32
  BaseApp::run() {

    initSystems();
   // m_plugin->loadPlugin("xcDirectX_d.dll");

    //createWindow();

    onCreate();

    //sf::Clock delta;

    //float deltaTime ; 

    //while (m_window.isOpen()) {

    //  sf::Event event;

    //  while (m_window.pollEvent(event)) {
    //    
    //    if (event.type == sf::Event::Closed) {
    //      m_window.close();
    //      break;
    //    }

    //  }

    //  deltaTime = delta.getElapsedTime().asSeconds();

    // Main message loop
	  MSG msg = { 0 };
	  while (WM_QUIT != msg.message)
	  {
	  	if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	  	{
	  		TranslateMessage(&msg);
	  		DispatchMessage(&msg);
	  	}
	  	else
	  	{
	  		//update
        update(0.f); 

	  		//render
        render();
	  		
	  	}
	  }

    onDestroy();
    destroySystems();

    return 0;
  }

  LRESULT 
  BaseApp::handleWindowEvent(HWND hw, 
                             UINT mesg, 
                             WPARAM wParam, 
                             LPARAM lParam){
    XC_UNREFERENCED_PARAMETER(hw);
    XC_UNREFERENCED_PARAMETER(mesg);
    XC_UNREFERENCED_PARAMETER(wParam);
    XC_UNREFERENCED_PARAMETER(lParam);
    return LRESULT();
  }

  void 
  BaseApp::createWindow() {

  }

  void 
  BaseApp::update(float deltaTime) {

    onUpdate(deltaTime);
  }

  void 
  BaseApp::render() {
    onRender();
  }

  void 
  BaseApp::initSystems() {

    //if (m_plugin.loadPlugin("xcDirectX_d.dll")) {
    if (m_plugin.loadPlugin("xcOpenGL_d.dll")) {

      auto createGraphiApi = reinterpret_cast<funProtoGraphiApi>(
                             m_plugin.getProcedureByName("createGraphisAPI"));

      GraphiAPI::startUp();
      GraphiAPI* graphiApi = createGraphiApi();
      g_graphiAPI().setObject(graphiApi);
      m_graphiApi = &g_graphiAPI();
      m_graphiApi->init(800, 600);
    }

  }

  void 
  BaseApp::destroySystems() {
    m_plugin.destroy();
  }

}
