#include "xcBaseApp.h"
#include <xcPlugin.h>

namespace xcEngineSDK {

  int32
  BaseApp::run() {

    initSystems();

    onCreate();

    sf::Clock delta;

    float deltaTime;

    while (m_window.isOpen()) {

      sf::Event event;

      while (m_window.pollEvent(event)) {

        deltaTime = delta.getElapsedTime().asSeconds();

        handleWindowEvent(event);

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

  void 
  BaseApp::handleWindowEvent(sf::Event event){
 
      
    if (event.type == sf::Event::KeyPressed) {
      
      onEvents(event);

    }
      
    return;
  }

  void 
  BaseApp::createWindow() {
    m_window.create(sf::VideoMode(m_graphiApi->m_width, m_graphiApi->m_height), 
                                  "SFML Window");
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
    if (m_plugin.loadPlugin("xcDirectX_d.dll")) {
    //if (m_plugin.loadPlugin("xcOpenGL_d.dll")) {

    //release
    //if (m_plugin.loadPlugin("xcDirectX.dll")) {
    //if (m_plugin.loadPlugin("xcOpenGL.dll")) {

      auto createGraphiApi = reinterpret_cast<funProtoGraphiApi>(
                             m_plugin.getProcedureByName("createGraphisAPI"));

      GraphiAPI::startUp();
      GraphiAPI* graphiApi = createGraphiApi();
      g_graphiAPI().setObject(graphiApi);
      m_graphiApi = &g_graphiAPI();
      createWindow();

      m_graphiApi->init(m_window.getSystemHandle());
    }

  }

  void 
  BaseApp::destroySystems() {
    m_plugin.destroy();
  }

}
