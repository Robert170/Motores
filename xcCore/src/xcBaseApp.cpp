#include "xcBaseApp.h"
#include <xcPlugin.h>

namespace xcEngineSDK {

  int32
  BaseApp::run() {
    
    initSystems();

    onCreate();

    sf::Clock delta;

    float deltaTime;

    auto myGraphicsApi = g_graphicsAPI().instancePtr();

    while (myGraphicsApi->m_window.isOpen()) {

      sf::Event event;
      deltaTime = delta.getElapsedTime().asSeconds();

      while (myGraphicsApi->m_window.pollEvent(event)) {


        handleWindowEvent(event);

        if (event.type == sf::Event::Closed) {
          myGraphicsApi->m_window.close();
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

    onEvents(event);
    return;
  }

  void 
  BaseApp::createWindow() {

    auto myGraphicsApi = g_graphicsAPI().instancePtr();

    myGraphicsApi->m_window.create(sf::VideoMode(myGraphicsApi->m_width,
                                                 myGraphicsApi->m_height),
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
      SceneGraph::startUp();
      g_graphicsAPI().setObject(createGraphiAPI());
      createWindow();
      //m_GraphicsAPI->init(m_GraphicsAPI->m_window.getSystemHandle());

    }

  }

  void 
  BaseApp::destroySystems() {
    m_plugin.destroy();
  }

}
