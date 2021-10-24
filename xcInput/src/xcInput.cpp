#include "xcInput.h"

namespace xcEngineSDK {
  
  Input::Input(sf::WindowHandle window){
    OIS::ParamList pl;

    std::ostringstream wnd;
    wnd << (size_t)window;

    pl.insert(std::make_pair(std::string("WINDOW"), wnd.str()));
    m_inputManager = OIS::InputManager::createInputSystem(pl);

    //Lets enable all addons that were compiled in:
    m_inputManager->enableAddOnFactory(OIS::InputManager::AddOn_All);

    m_keyboard = (OIS::Keyboard*)m_inputManager->createInputObject(OIS::OISKeyboard, true);
    m_keyboard->setEventCallback(&m_eventHandler);

    m_mouse = (OIS::Mouse*)m_inputManager->createInputObject(OIS::OISMouse, true);
    m_mouse->setEventCallback(&m_eventHandler);
    const OIS::MouseState& ms = m_mouse->getMouseState();
    ms.width = 900;
    ms.height = 900;
  }

  void Input::init(sf::WindowHandle window) {
    OIS::ParamList pl;

    std::ostringstream wnd;
    wnd << (size_t)window;

    pl.insert(std::make_pair(std::string("WINDOW"), wnd.str()));
    m_inputManager = OIS::InputManager::createInputSystem(pl);

    //Lets enable all addons that were compiled in:
    m_inputManager->enableAddOnFactory(OIS::InputManager::AddOn_All);

    m_keyboard = (OIS::Keyboard*)m_inputManager->createInputObject(OIS::OISKeyboard, true);
    m_keyboard->setEventCallback(&m_eventHandler);

    m_mouse = (OIS::Mouse*)m_inputManager->createInputObject(OIS::OISMouse, true);
    m_mouse->setEventCallback(&m_eventHandler);
    const OIS::MouseState& ms = m_mouse->getMouseState();
    ms.width = 900;
    ms.height = 900;
  }

  void 
  Input::update() {
    m_keyboard->capture();
    m_mouse->capture();
  }

  bool 
  Input::keyPress(KEY_BOARD::E input) {
    return m_keyboard->isKeyDown(static_cast<OIS::KeyCode>(input));;
  }

  bool 
  Input::keyRelease(KEY_BOARD::E input) {
    return false;
  }

  bool 
  Input::mouseKeyPress(MOUSE_KEY::E input) {
    return false;
  }

  bool 
  Input::mouseKeyRelease(MOUSE_KEY::E input) {
    return false;
  }
 
  bool 
  EventHandler::keyPressed(const OIS::KeyEvent& input) {
    return true;
  }

  bool 
  EventHandler::keyReleased(const OIS::KeyEvent& input) {
    return true;
  }

  bool 
  EventHandler::mouseMoved(const OIS::MouseEvent& input) {
    return true;
  }

  bool 
  EventHandler::mousePressed(const OIS::MouseEvent& input, 
                             OIS::MouseButtonID id) {
    return true;
  }

  bool 
  EventHandler::mouseReleased(const OIS::MouseEvent& input, 
                              OIS::MouseButtonID id){
    return true;
  }

}
