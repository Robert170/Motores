
#include "xcSceneGraph.h"
#include "xcGraphiAPI.h"
#include "xcBaseRenderer.h"
#include "xcBaseApp.h"


namespace xcEngineSDK {

  int32
  BaseApp::run() {
    
    initSystems();

    onCreate();

    auto& renderer = g_renderer();

    auto& sceneGraph = g_sceneGraph();

    renderer.init();

    renderer.setModels(sceneGraph.getModels());


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

      sceneGraph.update(deltaTime);

      //update
      update(deltaTime);

      renderer.render();

      //render
      render();

    }

    onDestroy();
    destroySystems();
    

    return 0;
  }

  void 
  BaseApp::handleWindowEvent(sf::Event eventInput){
    auto& sceneGraph = g_sceneGraph();
    sceneGraph.m_mainCamera.event(eventInput);
    onEvents(eventInput);
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

    }

    if (m_renderer.loadPlugin("xcRenderer_d.dll")) {

      auto createRenderer = reinterpret_cast<funProtoRenderer>
        (m_renderer.getProcedureByName("create_Renderer"));


      BaseRenderer::startUp();

      g_renderer().setObject(createRenderer());


    }

  }

  void 
  BaseApp::destroySystems() {
    m_plugin.destroy();
    m_renderer.destroy();
  }

}
