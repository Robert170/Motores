#include "xcBaseApp.h"
#include <xcPlugin.h>

namespace xcEngineSDK {

  int32
  BaseApp::run() {

    initSystems();

    onCreate();

    sf::Clock delta;

    float deltaTime;

    while (m_GraphicsAPI->m_window.isOpen()) {

      sf::Event event;
      deltaTime = delta.getElapsedTime().asSeconds();

      while (m_GraphicsAPI->m_window.pollEvent(event)) {


        handleWindowEvent(event);

        if (event.type == sf::Event::Closed) {
          m_GraphicsAPI->m_window.close();
          break;
        }
        
      }
      
      //update
      update(deltaTime);

      //render
      render();

    }

    onDestroy();
    destroySystems();
    

    return 0;
  }

  void 
  BaseApp::handleWindowEvent(sf::Event event){
 
    /*
     if (event.type == sf::Event::KeyPressed ||
         event.type == sf::Event::KeyReleased) {

       onEvents(event);

     }*/
    onEvents(event);
    return;
  }

  void 
  BaseApp::createWindow() {
    m_GraphicsAPI->m_window.create(sf::VideoMode(m_GraphicsAPI->m_width, 
                                   m_GraphicsAPI->m_height),
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

      auto createGraphiAPI = reinterpret_cast<funProtoGraphiAPI>
                             (m_plugin.getProcedureByName("createGraphisAPI"));

      GraphicsAPI::startUp();
      GraphicsAPI* GraphiAPI = createGraphiAPI();
      g_GraphicsAPI().setObject(GraphiAPI);
      m_GraphicsAPI = &g_GraphicsAPI();
      createWindow();

      m_GraphicsAPI->init(m_GraphicsAPI->m_window.getSystemHandle());
    }

  }

  void 
  BaseApp::destroySystems() {
    m_plugin.destroy();
  }

}
