#include "xcInput.h"

namespace xcEngineSDK {
  
  Input::~Input() {
    if (m_inputManager) {
      OIS::InputManager::destroyInputSystem(m_inputManager);
    }
  }

  void
  Input::init(WindowHandle wHndl) {
    OIS::ParamList pl;
    std::ostringstream windowHndStr;
    windowHndStr << (size_t)wHndl;
    pl.insert(std::make_pair(String("WINDOW"), windowHndStr.str()));
    pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND")));
    pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));
  
    m_inputManager = OIS::InputManager::createInputSystem(pl);
    uint32 v = m_inputManager->getVersionNumber(); 
    std::cout << "OIS Version" << (v >> 16) << "." << ((v >> 8) & 0x000000FF) << "." << (v & 0x000000FF)
              << "\nRelease Name: " << m_inputManager->getVersionName()
              << "\nManager: " << m_inputManager->inputSystemName()
              << "\nTotal Keyboards: " << m_inputManager->getNumberOfDevices(OIS::OISKeyboard)
              << "\nTotal Mouse: " << m_inputManager->getNumberOfDevices(OIS::OISMouse)
              << "\nTotal JoySticks: " << m_inputManager->getNumberOfDevices(OIS::OISJoyStick);
  
    m_keyBoard = static_cast<OIS::Keyboard*>(
                  m_inputManager->createInputObject(OIS::OISKeyboard, true));
    m_keyBoard->setEventCallback(this); 
  
    m_mouse = static_cast<OIS::Mouse*>(
              m_inputManager->createInputObject(OIS::OISMouse, true));
    m_mouse->setEventCallback(this);
    const OIS::MouseState& ms = m_mouse->getMouseState();
    ms.width = 900;
    ms.height = 900;
    fillKeys();
    fillMouseKeys();
  }
  
  void Input::update() {
    checkButtonStates();
    m_keyBoard->capture();
    m_mouse->capture();
  }

  bool
  Input::isKeyPressed(KEY_BOARD::E key) {
    return m_keyState[key] == STATUS_KEY::kPRESSED ? true : false;
  }

  bool
  Input::isKeyReleased(KEY_BOARD::E key) {
    if (m_keyState[key] == STATUS_KEY::kRELEASED) {
      m_keyState[key] == STATUS_KEY::kIDLE;
      return true;
    }
    else {
      return false;
    }
  }

  bool
  Input::isMouseKeyPressed(MOUSE_KEY::E key) {
    return m_mouseState[key] == STATUS_KEY::kPRESSED ? true : false;
  }

  bool
  Input::isMouseKeyReleased(MOUSE_KEY::E key) {
    if(m_mouseState[key] == STATUS_KEY::kRELEASED) {
      m_mouseState[key] == STATUS_KEY::kIDLE;
      return true;
    }
    else {
      return false;
    }
  }

  void
  Input::getMouseAxis(float& X, float& Y) {
    const OIS::MouseState& ms = m_mouse->getMouseState();
    X = (float)ms.X.rel;
    Y = (float)ms.Y.rel;
  }

  void
  Input::fillKeys() {
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_ESCAPE, KEY_BOARD::kKB_ESCAPE));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_1, KEY_BOARD::kKB_1));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_2, KEY_BOARD::kKB_2));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_3, KEY_BOARD::kKB_3));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_4, KEY_BOARD::kKB_4));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_5, KEY_BOARD::kKB_5));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_6, KEY_BOARD::kKB_6));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_7, KEY_BOARD::kKB_7));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_8, KEY_BOARD::kKB_8));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_9, KEY_BOARD::kKB_9));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_0, KEY_BOARD::kKB_0));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_MINUS, KEY_BOARD::kKB_MINUS));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_EQUALS, KEY_BOARD::kKB_EQUALS));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_BACK, KEY_BOARD::kKB_BACK));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_TAB, KEY_BOARD::kKB_TAB));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_Q, KEY_BOARD::kKB_Q));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_W, KEY_BOARD::kKB_W));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_E, KEY_BOARD::kKB_E));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_R, KEY_BOARD::kKB_R));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_T, KEY_BOARD::kKB_T));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_Y, KEY_BOARD::kKB_Y));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_U, KEY_BOARD::kKB_U));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_I, KEY_BOARD::kKB_I));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_O, KEY_BOARD::kKB_O));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_P, KEY_BOARD::kKB_P));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_A, KEY_BOARD::kKB_A));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_S, KEY_BOARD::kKB_S));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_D, KEY_BOARD::kKB_D));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_F, KEY_BOARD::kKB_F));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_G, KEY_BOARD::kKB_G));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_H, KEY_BOARD::kKB_H));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_J, KEY_BOARD::kKB_J));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_K, KEY_BOARD::kKB_K));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_L, KEY_BOARD::kKB_L));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_Z, KEY_BOARD::kKB_Z));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_X, KEY_BOARD::kKB_X));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_C, KEY_BOARD::kKB_C));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_V, KEY_BOARD::kKB_V));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_B, KEY_BOARD::kKB_B));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_N, KEY_BOARD::kKB_N));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_M, KEY_BOARD::kKB_M));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_UP, KEY_BOARD::kKB_UP));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_DOWN, KEY_BOARD::kKB_DOWN));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_LEFT, KEY_BOARD::kKB_LEFT));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_RIGHT, KEY_BOARD::kKB_RIGHT));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_LBRACKET, KEY_BOARD::kKB_LBRACKET));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_RBRACKET, KEY_BOARD::kKB_RBRACKET));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_RETURN, KEY_BOARD::kKB_RETURN));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_LCONTROL, KEY_BOARD::kKB_LCONTROL));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_RCONTROL, KEY_BOARD::kKB_RCONTROL));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_SEMICOLON, KEY_BOARD::kKB_SEMICOLON));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_APOSTROPHE, KEY_BOARD::kKB_APOSTROPHE));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_GRAVE, KEY_BOARD::kKB_GRAVE));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_LSHIFT, KEY_BOARD::kKB_LSHIFT));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_BACKSLASH, KEY_BOARD::kKB_BACKSLASH));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_COMMA, KEY_BOARD::kKB_COMMA));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_PERIOD, KEY_BOARD::kKB_PERIOD));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_SLASH, KEY_BOARD::kKB_SLASH));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_RSHIFT, KEY_BOARD::kKB_RSHIFT));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_LMENU, KEY_BOARD::kKB_LMENU));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_RMENU, KEY_BOARD::kKB_RMENU));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_SPACE, KEY_BOARD::kKB_SPACE));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_CAPITAL, KEY_BOARD::kKB_CAPITAL));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_F1, KEY_BOARD::kKB_F1));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_F2, KEY_BOARD::kKB_F2));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_F3, KEY_BOARD::kKB_F3));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_F4, KEY_BOARD::kKB_F4));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_F5, KEY_BOARD::kKB_F5));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_F6, KEY_BOARD::kKB_F6));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_F7, KEY_BOARD::kKB_F7));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_F8, KEY_BOARD::kKB_F8));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_F9, KEY_BOARD::kKB_F9));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_F10, KEY_BOARD::kKB_F10));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_F11, KEY_BOARD::kKB_F11));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_F12, KEY_BOARD::kKB_F12));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_NUMLOCK, KEY_BOARD::kKB_NUMLOCK));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_SCROLL, KEY_BOARD::kKB_SCROLL));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD1, KEY_BOARD::kKB_NUMPAD1));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD2, KEY_BOARD::kKB_NUMPAD2));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD3, KEY_BOARD::kKB_NUMPAD3));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD4, KEY_BOARD::kKB_NUMPAD4));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD5, KEY_BOARD::kKB_NUMPAD5));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD6, KEY_BOARD::kKB_NUMPAD6));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD7, KEY_BOARD::kKB_NUMPAD7));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD8, KEY_BOARD::kKB_NUMPAD8));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD9, KEY_BOARD::kKB_NUMPAD9));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD0, KEY_BOARD::kKB_NUMPAD0));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_SUBTRACT, KEY_BOARD::kKB_SUBTRACT));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_ADD, KEY_BOARD::kKB_ADD));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_DECIMAL, KEY_BOARD::kKB_DECIMAL));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_DIVIDE, KEY_BOARD::kKB_DIVIDE));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_MULTIPLY, KEY_BOARD::kKB_MULTIPLY));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_PGDOWN, KEY_BOARD::kKB_PGDOWN));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_PGUP, KEY_BOARD::kKB_PGUP));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_INSERT, KEY_BOARD::kKB_INSERT));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_DELETE, KEY_BOARD::kKB_DELETE));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_HOME, KEY_BOARD::kKB_HOME));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_END, KEY_BOARD::kKB_END));
    m_keys.insert(std::make_pair(OIS::KeyCode::KC_INSERT, KEY_BOARD::kKB_INSERT));
  }

  void
  Input::fillMouseKeys() {
    m_mouseKeys.insert(std::make_pair(OIS::MouseButtonID::MB_Left,    MOUSE_KEY::KMB_LEFT));
    m_mouseKeys.insert(std::make_pair(OIS::MouseButtonID::MB_Right,   MOUSE_KEY::KMB_RIGHT));
    m_mouseKeys.insert(std::make_pair(OIS::MouseButtonID::MB_Middle,  MOUSE_KEY::KMB_MIDDLE));
    m_mouseKeys.insert(std::make_pair(OIS::MouseButtonID::MB_Button3, MOUSE_KEY::KMB_BUTTON3));
    m_mouseKeys.insert(std::make_pair(OIS::MouseButtonID::MB_Button4, MOUSE_KEY::KMB_BUTTON4));
    m_mouseKeys.insert(std::make_pair(OIS::MouseButtonID::MB_Button5, MOUSE_KEY::KMB_BUTTON5));
    m_mouseKeys.insert(std::make_pair(OIS::MouseButtonID::MB_Button6, MOUSE_KEY::KMB_BUTTON6));
    m_mouseKeys.insert(std::make_pair(OIS::MouseButtonID::MB_Button7, MOUSE_KEY::KMB_BUTTON7));
  }

  bool
  Input::keyPressed(const OIS::KeyEvent& arg) {
    if (m_keyState[m_keys[arg.key]] = STATUS_KEY::kPRESSED) {
      return true;
    }
    return false;
  }

  bool
  Input::keyReleased(const OIS::KeyEvent& arg) {
    //std::cout << "KeyReleased {" << std::hex << arg.key << std::dec << "}\n";

    m_keyState[m_keys[arg.key]] = STATUS_KEY::kRELEASED;
    return true;
  }

  bool
  Input::mouseMoved(const OIS::MouseEvent& arg) {
    XC_UNREFERENCED_PARAMETER(arg);
    //const OIS::MouseState& s = arg.state;
    /*std::cout << "\nMouseMoved: Abs("
              << s.X.abs << ", " << s.Y.abs << ", " << s.Z.abs << ") Rel(" << s.X.rel
              << ", " << s.Y.rel << ", " << s.Z.rel << ")";*/
    return true;
  }

  bool
  Input::mousePressed(const OIS::MouseEvent& arg, OIS::MouseButtonID id) {
    XC_UNREFERENCED_PARAMETER(arg);

    //const OIS::MouseState& s = arg.state;
   /* std::cout << "\nMouse button #" << id << " pressed. Abs(" << s.X.abs << ", "
              << s.Y.abs << ", " << s.Z.abs << ") Rel(" << s.X.rel << ", " << s.Y.rel
              << ", " << s.Z.rel << ")";*/
    m_mouseState[m_mouseKeys[id]] = STATUS_KEY::kPRESSED;
    return false;
  }

  bool
  Input::mouseReleased(const OIS::MouseEvent& arg, OIS::MouseButtonID id) {
    XC_UNREFERENCED_PARAMETER(arg);
    //const OIS::MouseState& s = arg.state;
    /*std::cout << "\nMouse button #" << id << " released. Abs(" << s.X.abs << ", "
              << s.Y.abs << ", " << s.Z.abs << ") Rel(" << s.X.rel << ", " << s.Y.rel
              << ", " << s.Z.rel << ")";*/
    m_mouseState[m_mouseKeys[id]] = STATUS_KEY::kRELEASED;
    return false;
  }

  void
  Input::checkButtonStates() {
    for (auto&  iterator : m_keyState) {
      if (iterator.second == STATUS_KEY::kRELEASED) {
        iterator.second = STATUS_KEY::kIDLE;
      }
    }

    for (auto& iterator : m_mouseState) {
      if (iterator.second == STATUS_KEY::kRELEASED) {
        iterator.second = STATUS_KEY::kIDLE;
      }
    }
  }

  //Input::Input(sf::WindowHandle window){
  //  OIS::ParamList pl;

  //  std::ostringstream wnd;
  //  wnd << (size_t)window;

  //  pl.insert(std::make_pair(std::string("WINDOW"), wnd.str()));

  //  pl.insert(std::make_pair(std::string("w32_mouse"), 
  //                           std::string("DISCL_FOREGROUND")));

  //  pl.insert(std::make_pair(std::string("w32_mouse"),
  //                           std::string("DISCL_NONEXCLUSIVE")));

  //  m_inputManager = OIS::InputManager::createInputSystem(pl);

  //  //Lets enable all addons that were compiled in:
  //  m_inputManager->enableAddOnFactory(OIS::InputManager::AddOn_All);

  //  m_keyboard = (OIS::Keyboard*)m_inputManager->
  //               createInputObject(OIS::OISKeyboard, true);
  //  m_keyboard->setEventCallback(&m_eventHandler);

  //  m_mouse = (OIS::Mouse*)m_inputManager->createInputObject(OIS::OISMouse, true);
  //  m_mouse->setEventCallback(&m_eventHandler);
  //  const OIS::MouseState& ms = m_mouse->getMouseState();
  //  ms.width = 900;
  //  ms.height = 900;
  //}

  //void Input::init(sf::WindowHandle window) {
  //  OIS::ParamList pl;

  //  std::ostringstream wnd;
  //  wnd << (size_t)window;

  //  pl.insert(std::make_pair(std::string("WINDOW"), wnd.str()));

  //  pl.insert(std::make_pair(std::string("w32_mouse"), 
  //                           std::string("DISCL_FOREGROUND")));

  //  pl.insert(std::make_pair(std::string("w32_mouse"),
  //                           std::string("DISCL_NONEXCLUSIVE")));

  //  m_inputManager = OIS::InputManager::createInputSystem(pl);

  //  //Lets enable all addons that were compiled in:
  //  m_inputManager->enableAddOnFactory(OIS::InputManager::AddOn_All);

  //  m_keyboard = (OIS::Keyboard*)m_inputManager->createInputObject(OIS::OISKeyboard, true);
  //  m_keyboard->setEventCallback(&m_eventHandler);

  //  m_mouse = (OIS::Mouse*)m_inputManager->createInputObject(OIS::OISMouse, true);
  //  m_mouse->setEventCallback(&m_eventHandler);
  //  const OIS::MouseState& ms = m_mouse->getMouseState();
  //  ms.width = 900;
  //  ms.height = 900;
  //  fillKeyboardKeys();
  //  fillMouseKeys();
  //}

  //void 
  //Input::update() {
  //  m_keyboard->capture();
  //  m_mouse->capture();
  //}

  //bool 
  //Input::keyPress(KEY_BOARD::E input) {
  // 
  //  return m_keyState[input] == STATUS_KEY::kPRESSED ? true : false;
  //  //return m_keyboard->isKeyDown(static_cast<OIS::KeyCode>(input));;
  //}

  //bool 
  //Input::keyRelease(KEY_BOARD::E input) {
  //  return m_keyState[input] == STATUS_KEY::kRELEASED ? true : false;
  //  //return false;
  //}

  //bool 
  //Input::mouseKeyPress(MOUSE_KEY::E input) {
  //  return m_mouseState[input] == STATUS_KEY::kPRESSED ? true : false;
  //  //return false;
  //}

  //bool 
  //Input::mouseKeyRelease(MOUSE_KEY::E input) {
  //  return m_mouseState[input] == STATUS_KEY::kRELEASED ? true : false;
  //  //return false;
  //}

  //void 
  //Input::fillKeyboardKeys() {
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_ESCAPE, KEY_BOARD::kKB_ESCAPE));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_1, KEY_BOARD::kKB_1));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_2, KEY_BOARD::kKB_2));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_3, KEY_BOARD::kKB_3));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_4, KEY_BOARD::kKB_4));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_5, KEY_BOARD::kKB_5));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_6, KEY_BOARD::kKB_6));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_7, KEY_BOARD::kKB_7));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_8, KEY_BOARD::kKB_8));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_9, KEY_BOARD::kKB_9));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_0, KEY_BOARD::kKB_0));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_MINUS, KEY_BOARD::kKB_MINUS));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_EQUALS, KEY_BOARD::kKB_EQUALS));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_BACK, KEY_BOARD::kKB_BACK));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_TAB, KEY_BOARD::kKB_TAB));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_Q, KEY_BOARD::kKB_Q));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_W, KEY_BOARD::kKB_W));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_E, KEY_BOARD::kKB_E));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_R, KEY_BOARD::kKB_R));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_T, KEY_BOARD::kKB_T));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_Y, KEY_BOARD::kKB_Y));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_U, KEY_BOARD::kKB_U));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_I, KEY_BOARD::kKB_I));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_O, KEY_BOARD::kKB_O));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_P, KEY_BOARD::kKB_P));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_A, KEY_BOARD::kKB_A));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_S, KEY_BOARD::kKB_S));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_D, KEY_BOARD::kKB_D));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_F, KEY_BOARD::kKB_F));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_G, KEY_BOARD::kKB_G));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_H, KEY_BOARD::kKB_H));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_J, KEY_BOARD::kKB_J));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_K, KEY_BOARD::kKB_K));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_L, KEY_BOARD::kKB_L));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_Z, KEY_BOARD::kKB_Z));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_X, KEY_BOARD::kKB_X));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_C, KEY_BOARD::kKB_C));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_V, KEY_BOARD::kKB_V));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_B, KEY_BOARD::kKB_B));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_N, KEY_BOARD::kKB_N));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_M, KEY_BOARD::kKB_M));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_UP, KEY_BOARD::kKB_UP));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_DOWN, KEY_BOARD::kKB_DOWN));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_LEFT, KEY_BOARD::kKB_LEFT));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_RIGHT, KEY_BOARD::kKB_RIGHT));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_LBRACKET, KEY_BOARD::kKB_LBRACKET));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_RBRACKET, KEY_BOARD::kKB_RBRACKET));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_RETURN, KEY_BOARD::kKB_RETURN));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_LCONTROL, KEY_BOARD::kKB_LCONTROL));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_RCONTROL, KEY_BOARD::kKB_RCONTROL));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_SEMICOLON, KEY_BOARD::kKB_SEMICOLON));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_APOSTROPHE, KEY_BOARD::kKB_APOSTROPHE));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_GRAVE, KEY_BOARD::kKB_GRAVE));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_LSHIFT, KEY_BOARD::kKB_LSHIFT));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_BACKSLASH, KEY_BOARD::kKB_BACKSLASH));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_COMMA, KEY_BOARD::kKB_COMMA));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_PERIOD, KEY_BOARD::kKB_PERIOD));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_SLASH, KEY_BOARD::kKB_SLASH));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_RSHIFT, KEY_BOARD::kKB_RSHIFT));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_LMENU, KEY_BOARD::kKB_LMENU));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_RMENU, KEY_BOARD::kKB_RMENU));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_SPACE, KEY_BOARD::kKB_SPACE));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_CAPITAL, KEY_BOARD::kKB_CAPITAL));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_F1, KEY_BOARD::kKB_F1));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_F2, KEY_BOARD::kKB_F2));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_F3, KEY_BOARD::kKB_F3));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_F4, KEY_BOARD::kKB_F4));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_F5, KEY_BOARD::kKB_F5));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_F6, KEY_BOARD::kKB_F6));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_F7, KEY_BOARD::kKB_F7));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_F8, KEY_BOARD::kKB_F8));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_F9, KEY_BOARD::kKB_F9));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_F10, KEY_BOARD::kKB_F10));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_F11, KEY_BOARD::kKB_F11));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_F12, KEY_BOARD::kKB_F12));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_NUMLOCK, KEY_BOARD::kKB_NUMLOCK));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_SCROLL, KEY_BOARD::kKB_SCROLL));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD1, KEY_BOARD::kKB_NUMPAD1));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD2, KEY_BOARD::kKB_NUMPAD2));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD3, KEY_BOARD::kKB_NUMPAD3));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD4, KEY_BOARD::kKB_NUMPAD4));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD5, KEY_BOARD::kKB_NUMPAD5));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD6, KEY_BOARD::kKB_NUMPAD6));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD7, KEY_BOARD::kKB_NUMPAD7));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD8, KEY_BOARD::kKB_NUMPAD8));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD9, KEY_BOARD::kKB_NUMPAD9));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_NUMPAD0, KEY_BOARD::kKB_NUMPAD0));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_SUBTRACT, KEY_BOARD::kKB_SUBTRACT));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_ADD, KEY_BOARD::kKB_ADD));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_DECIMAL, KEY_BOARD::kKB_DECIMAL));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_DIVIDE, KEY_BOARD::kKB_DIVIDE));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_MULTIPLY, KEY_BOARD::kKB_MULTIPLY));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_PGDOWN, KEY_BOARD::kKB_PGDOWN));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_PGUP, KEY_BOARD::kKB_PGUP));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_INSERT, KEY_BOARD::kKB_INSERT));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_DELETE, KEY_BOARD::kKB_DELETE));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_HOME, KEY_BOARD::kKB_HOME));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_END, KEY_BOARD::kKB_END));
  //  m_keyboardkeys.insert(std::make_pair(OIS::KeyCode::KC_INSERT, KEY_BOARD::kKB_INSERT));
  //}

  //void 
  //Input::fillMouseKeys() {
  //  m_mouseKeys.insert(std::make_pair(OIS::MouseButtonID::MB_Left, MOUSE_KEY::KMB_LEFT));
  //  m_mouseKeys.insert(std::make_pair(OIS::MouseButtonID::MB_Right, MOUSE_KEY::KMB_RIGHT));
  //  m_mouseKeys.insert(std::make_pair(OIS::MouseButtonID::MB_Middle, MOUSE_KEY::KMB_MIDDLE));
  //  m_mouseKeys.insert(std::make_pair(OIS::MouseButtonID::MB_Button3, MOUSE_KEY::KMB_BUTTON3));
  //  m_mouseKeys.insert(std::make_pair(OIS::MouseButtonID::MB_Button4, MOUSE_KEY::KMB_BUTTON4));
  //  m_mouseKeys.insert(std::make_pair(OIS::MouseButtonID::MB_Button5, MOUSE_KEY::KMB_BUTTON5));
  //  m_mouseKeys.insert(std::make_pair(OIS::MouseButtonID::MB_Button6, MOUSE_KEY::KMB_BUTTON6));
  //  m_mouseKeys.insert(std::make_pair(OIS::MouseButtonID::MB_Button7, MOUSE_KEY::KMB_BUTTON7));
  //}
 
  //bool 
  //EventHandler::keyPressed(const OIS::KeyEvent& input) {
  //  std::cout << " KeyPressed {" << std::hex << input.key << std::dec
  //    << "} || Character (" << (char)input.text << ")" << std::endl;
  //  //m_keyState[m_keyboardkeys[input.key]] = STATUS_KEY::kPRESSED;
  //  return true;
  //}

  //bool 
  //EventHandler::keyReleased(const OIS::KeyEvent& input) {
  //  return true;
  //}

  //bool 
  //EventHandler::mouseMoved(const OIS::MouseEvent& input) {
  //  return true;
  //}

  //bool 
  //EventHandler::mousePressed(const OIS::MouseEvent& input, 
  //                           OIS::MouseButtonID id) {
  //  return true;
  //}

  //bool 
  //EventHandler::mouseReleased(const OIS::MouseEvent& input, 
  //                            OIS::MouseButtonID id){
  //  return true;
  //}

}
