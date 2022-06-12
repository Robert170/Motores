/*****************************************************************************/
/**
 * @file    xcInput.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    21/09/2021
 * @brief   Represents the implementation of input class
 *
 *
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once

/*****************************************************************************/
/**
 * Includes
 */
 /*****************************************************************************/

#include <OISInputManager.h>
#include <OISException.h>
#include <OISKeyboard.h>
#include <OISMouse.h>
#include <OISJoyStick.h>
#include <OISEvents.h>

#include <xcBaseInput.h>
#include "xcPrerequisitesInput.h"



namespace xcEngineSDK {

  //class EventHandler : public OIS::KeyListener, public OIS::MouseListener
  //{
  // public:
  //  EventHandler() { }
  //  ~EventHandler() { }

  //  /**
  //   * @brief      keyPressed function, to detect if a key is pressed
  //   * @param      input parameter one, pressed key
  //   * @bug		     No know Bugs
  //   * @return     Returns a boll
  //   */
  //  bool
  //  keyPressed(const OIS::KeyEvent& input) override;

  //  /**
  //   * @brief      keyReleased function, to detect if a key is released
  //   * @param      input parameter one, released key
  //   * @bug		     No know Bugs
  //   * @return     Returns bool
  //   */
  //  bool
  //  keyReleased(const OIS::KeyEvent& input) override;

  //  bool
  //  mouseMoved(const  OIS::MouseEvent& input);

  //  bool
  //  mousePressed(const  OIS::MouseEvent& input, OIS::MouseButtonID id);

  //  bool
  //  mouseReleased(const  OIS::MouseEvent& input, OIS::MouseButtonID id);
  //};


  class Input : public BaseInput,
                public OIS::KeyListener,
                public OIS::MouseListener
  {

    public:
    Input() = default;
    ~Input();

    void
    init(WindowHandle wHndl)                                          override;
    void
    update()                                                          override;

    bool
    isKeyPressed(KEY_BOARD::E key)                                         override;
    bool
    isKeyReleased(KEY_BOARD::E key)                                        override;

    bool
    isMouseKeyPressed(MOUSE_KEY::E key)                                   override;

    bool
    isMouseKeyReleased(MOUSE_KEY::E key)                                  override;

    void
    getMouseAxis(float& X, float& Y)                                  override;

   private:
    
    void
    fillKeys();

    void
    fillMouseKeys();
    
   private:
    OIS::InputManager* m_inputManager = nullptr;
    //Devices
    OIS::Keyboard* m_keyBoard = nullptr;
    OIS::Mouse* m_mouse = nullptr;

    std::map<OIS::KeyCode, KEY_BOARD::E> m_keys;
    std::map<OIS::MouseButtonID, MOUSE_KEY::E> m_mouseKeys;

    bool
    keyPressed(const OIS::KeyEvent& arg)                              override;
    bool
    keyReleased(const OIS::KeyEvent& arg)                             override;
    bool
    mouseMoved(const OIS::MouseEvent& arg)                            override;
    bool
    mousePressed(const OIS::MouseEvent& arg,
                      OIS::MouseButtonID id)                          override;
    bool
    mouseReleased(const OIS::MouseEvent& arg,
                        OIS::MouseButtonID id)                        override;

    void
    checkButtonStates();
   //public:

   // Input(sf::WindowHandle window);
   // Input() = default;
   // ~Input() = default;


   // void
   // init(sf::WindowHandle window) override;

   // void
   // update() override;

   // /**
   //  * @brief      keyPressed function, to detect if a key is pressed
   //  * @param      input parameter one, pressed key
   //  * @bug		     No know Bugs
   //  * @return     Returns a bool
   //  */
   // virtual bool
   // keyPress(KEY_BOARD::E input) override;

   // /**
   //  * @brief      keyReleased function, to detect if a key is released
   //  * @param      input parameter one, released key
   //  * @bug		     No know Bugs
   //  * @return     Returns a bool
   //  */
   // virtual bool
   // keyRelease(KEY_BOARD::E input) override;

   // /**
   //  * @brief      mouseKeyPress function, to detect if a key is pressed of mouse
   //  * @param      input parameter one, pressed key
   //  * @bug		     No know Bugs
   //  * @return     Returns a bool
   //  */
   // virtual bool
   // mouseKeyPress(MOUSE_KEY::E input) override;

   // /**
   //  * @brief      mouseKeyRelease function, to detect if a key is released of mouse
   //  * @param      input parameter one, released key
   //  * @bug		     No know Bugs
   //  * @return     Returns a bool
   //  */
   // virtual bool
   // mouseKeyRelease(MOUSE_KEY::E input) override;

   //private:

   // void
   // fillKeyboardKeys();

   // void
   // fillMouseKeys();

   // OIS::InputManager* m_inputManager = nullptr;		 //Our Input System
   // OIS::Keyboard* m_keyboard = nullptr;								   //Keyboard Device
   // OIS::Mouse* m_mouse = nullptr;                       //Mouse Device

   // std::map<OIS::KeyCode, KEY_BOARD::E> m_keyboardkeys;
   // std::map<OIS::MouseButtonID, MOUSE_KEY::E> m_mouseKeys;

   // EventHandler m_eventHandler;

  };

  extern "C" XC_PLUGIN_EXPORT Input * create_Input() {

    auto m_input = new Input();

    return m_input;

  }


}