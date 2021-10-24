#include <imgui_impl_win32.h>
#include <imgui_impl_dx11.h>
#include "xcSceneGraph.h"
#include "xcGraphiAPI.h"
#include "xcBaseRenderer.h"
#include "xcBaseInput.h"
#include "xcBaseApp.h"
#include "xcBaseInput.h"

namespace xcEngineSDK {

  int32
  BaseApp::run() {
    
    initSystems();

    onCreate();

    auto& myGraphicsApi = g_graphicsAPI();

    auto& renderer = g_renderer();

    auto& sceneGraph = g_sceneGraph();

    auto& input = g_input();

    renderer.init();
    //renderer.setModels(sceneGraph.getModels());
    

    sf::Clock delta;

    float deltaTime;
    input.init(myGraphicsApi.m_window.getSystemHandle());


    while (myGraphicsApi.m_window.isOpen()) {

      sf::Event event;
      deltaTime = delta.getElapsedTime().asSeconds();

      while (myGraphicsApi.m_window.pollEvent(event)) {


        //handleWindowEvent(event);
        
        if (event.type == sf::Event::Closed) {
          myGraphicsApi.m_window.close();
          break;

        }
        
      }

     
      //update
      update(deltaTime);
      input.update();
      sceneGraph.update(deltaTime);
      renderer.update();


      //render
      renderer.render();

      render();

    }

    onDestroy();
    destroySystems();
    

    return 0;
  }

  void 
  BaseApp::handleWindowEvent(sf::Event eventInput){
    auto& sceneGraph = g_sceneGraph();
    //sceneGraph.m_mainCamera.event(eventInput);
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


    //// Setup Dear ImGui context
    //IMGUI_CHECKVERSION();
    //ImGui::CreateContext();
    //ImGuiIO& io = ImGui::GetIO();
    //// Setup Platform/Renderer bindings
    //ImGui_ImplGlfw_InitForOpenGL(window, true);
    //ImGui_ImplOpenGL3_Init(glsl_version);
    //// Setup Dear ImGui style
    //ImGui::StyleColorsDark();

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
    if (m_input.loadPlugin("xcInput_d.dll")) {

      auto createInput = reinterpret_cast<funProtoInput>
                         (m_input.getProcedureByName("create_Input"));


      BaseInput::startUp();

      g_input().setObject(createInput());


    }
    /*if (m_input.loadPlugin("xcSound_d.dll")) {

      auto createInput = reinterpret_cast<funProtoInput>
        (m_input.getProcedureByName("create_Input"));


      BaseInput::startUp();

      g_input().setObject(createInput());


    }
    if (m_input.loadPlugin("xcPhysics_d.dll")) {

      auto createInput = reinterpret_cast<funProtoInput>
        (m_input.getProcedureByName("create_Input"));


      BaseInput::startUp();

      g_input().setObject(createInput());


    }*/

  }

  void 
  BaseApp::destroySystems() {
    m_plugin.destroy();
    m_renderer.destroy();
  }

}
