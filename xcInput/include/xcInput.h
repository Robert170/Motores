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

  class EventHandler : public OIS::KeyListener, public OIS::MouseListener
  {
   public:
    EventHandler() { }
    ~EventHandler() { }
    bool
    keyPressed(const OIS::KeyEvent& arg);
    
    bool 
    keyReleased(const OIS::KeyEvent& arg);
    
    bool 
    mouseMoved(const  OIS::MouseEvent& arg);

    bool 
    mousePressed(const  OIS::MouseEvent& arg, OIS::MouseButtonID id);
    
    bool
    mouseReleased(const  OIS::MouseEvent& arg, OIS::MouseButtonID id);
  };


	class Input : public BaseInput
	{
	 public:

		Input(sf::WindowHandle window);
		Input() = default;
		~Input() = default;

	 private:

		/**
		 * @brief      keyPressed function, to detect if a key is pressed
		 * @param      input parameter one, pressed key
		 * @bug		     No know Bugs
		 * @return     Returns nothing
		 */
    void
    keyPressed(KEY_BOARD::E input);

		/**
		 * @brief      keyReleased function, to detect if a key is released
		 * @param      input parameter one, released key
		 * @bug		     No know Bugs
		 * @return     Returns nothing
		 */
		void
    keyReleased(KEY_BOARD::E input);



    OIS::InputManager* m_InputManager = nullptr;		 //Our Input System
    OIS::Keyboard* m_kb = nullptr;								   //Keyboard Device
    OIS::Mouse* m_m = nullptr;                       //Mouse Device


	};

  extern "C" XC_PLUGIN_EXPORT Input * create_Input() {

    auto m_input = new Input();

    return m_input;

  }


}