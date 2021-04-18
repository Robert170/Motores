#include "xcBaseApp.h"
#include <xcPlugin.h>

namespace xcEngineSDK {

  int32
  BaseApp::run() {

    initSystems();
   // m_plugin->loadPlugin("xcDirectX_d.dll");

    createWindow();

    //onCreate();

    sf::Clock delta;

    float deltaTime ; 

    while (m_window.isOpen()) {

      sf::Event event;

      while (m_window.pollEvent(event)) {
        
        if (event.type == sf::Event::Closed) {
          m_window.close();
          break;
        }

      }

      deltaTime = delta.getElapsedTime().asSeconds();

      //onUpdate(deltaTime);

      //onRender();

    }


    //onDestroy();

    return 0;
  }

  LRESULT 
  BaseApp::handleWindowEvent(HWND hw, 
                             UINT mesg, 
                             WPARAM wParam, 
                             LPARAM lParam){
    return LRESULT();
  }

  void 
  BaseApp::createWindow() {

    String Temp = "Proyect";

    m_window.create(sf::VideoMode(500, 500), Temp);

  }

  void 
  BaseApp::update(float deltaTime) {
  }

  void 
  BaseApp::render() {
  }

  void 
  BaseApp::initSystems() {

    if (m_plugin.loadPlugin("xcDirectX_d.dll")) {

      auto createGraphiApi = reinterpret_cast<funProtoGraphiApi>(
                             m_plugin.getProcedureByName("createGraphiApi"));

      GraphiAPI::startUp();
      GraphiAPI* graphiApi = createGraphiApi();
      g_graphiAPI().setObject(graphiApi);
      m_graphiApi = &g_graphiAPI();
      m_graphiApi->init(500, 500);
    }

  }

  void 
  BaseApp::destroySystems() {
  }

}
