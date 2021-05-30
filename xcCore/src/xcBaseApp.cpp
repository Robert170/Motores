#include "xcBaseApp.h"
#include <xcPlugin.h>

namespace xcEngineSDK {

  int32
  BaseApp::run() {

    createWindow();

    initSystems();

    onCreate();

    sf::Clock delta;

    float deltaTime;

    while (m_window.isOpen()) {

      sf::Event event;

      while (m_window.pollEvent(event)) {

        deltaTime = delta.getElapsedTime().asSeconds();

        if (event.type == sf::Event::Closed) {
          m_window.close();
          break;
        }
        //update
        update(deltaTime);

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
    m_window.create(sf::VideoMode(500, 500), "SFML Window");
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
    //debug
    //if (m_plugin.loadPlugin("xcDirectX_d.dll")) {
    if (m_plugin.loadPlugin("xcOpenGL_d.dll")) {

    //release
    //if (m_plugin.loadPlugin("xcDirectX.dll")) {
    //if (m_plugin.loadPlugin("xcOpenGL.dll")) {

      auto createGraphiApi = reinterpret_cast<funProtoGraphiApi>(
                             m_plugin.getProcedureByName("createGraphisAPI"));

      GraphiAPI::startUp();
      GraphiAPI* graphiApi = createGraphiApi();
      g_graphiAPI().setObject(graphiApi);
      m_graphiApi = &g_graphiAPI();


      m_graphiApi->init(m_window.getSystemHandle());
    }

  }

  void 
  BaseApp::destroySystems() {
    m_plugin.destroy();
  }

}
