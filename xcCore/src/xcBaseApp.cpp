#include "xcBaseApp.h"
#include <xcPlugin.h>

namespace xcEngineSDK {

  int32
  BaseApp::run() {

    //m_plugin = new Plugin();
    m_plugin->loadPlugin("xcDirectX_d.dll");

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
  BaseApp::intSystems() {
  }

  void 
  BaseApp::destroySystems() {
  }

}
