#include "xcInput.h"

namespace xcEngineSDK {
  
  Input::Input(sf::WindowHandle window){
    OIS::ParamList pl;

    std::ostringstream wnd;
    wnd << (size_t)window;

    pl.insert(std::make_pair(std::string("WINDOW"), wnd.str()));
    m_InputManager = OIS::InputManager::createInputSystem(pl);

    //Lets enable all addons that were compiled in:
    m_InputManager->enableAddOnFactory(OIS::InputManager::AddOn_All);

    m_kb = (OIS::Keyboard*)m_InputManager->createInputObject(OIS::OISKeyboard, true);
    //m_kb->setEventCallback(&handler);

    m_m = (OIS::Mouse*)m_InputManager->createInputObject(OIS::OISMouse, true);
    //m_m->setEventCallback(&handler);
    const OIS::MouseState& ms = m_m->getMouseState();
    ms.width = 900;
    ms.height = 900;
  }
  void
  Input::keyPressed(KEY_BOARD::E input) {
  }

  void 
  Input::keyReleased(KEY_BOARD::E input) {
  }
}
