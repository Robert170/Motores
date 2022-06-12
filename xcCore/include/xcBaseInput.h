/*****************************************************************************/
/**
 * @file    xcBaseInput.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    30/09/2021
 * @brief   Represents Base of the renderer
 *
 * The base of the renderer
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once
/*****************************************************************************/
/**
 * Includes
 */
 /*****************************************************************************/
#include <xcModule.h>
#include <SFML/Window/Window.hpp>
#include <xcPrerequisitesCore.h>

using sf::WindowHandle;

namespace xcEngineSDK {

  namespace KEY_BOARD {
    enum E {
      kKB_UNASSIGNED = 0x00,
      kKB_ESCAPE = 0x01,
      kKB_1 = 0x02,
      kKB_2 = 0x03,
      kKB_3 = 0x04,
      kKB_4 = 0x05,
      kKB_5 = 0x06,
      kKB_6 = 0x07,
      kKB_7 = 0x08,
      kKB_8 = 0x09,
      kKB_9 = 0x0A,
      kKB_0 = 0x0B,
      kKB_MINUS = 0x0C, // - on main keyboard
      kKB_EQUALS = 0x0D,
      kKB_BACK = 0x0E, // backspace
      kKB_TAB = 0x0F,
      kKB_Q = 0x10,
      kKB_W = 0x11,
      kKB_E = 0x12,
      kKB_R = 0x13,
      kKB_T = 0x14,
      kKB_Y = 0x15,
      kKB_U = 0x16,
      kKB_I = 0x17,
      kKB_O = 0x18,
      kKB_P = 0x19,
      kKB_LBRACKET = 0x1A,
      kKB_RBRACKET = 0x1B,
      kKB_RETURN = 0x1C, // Enter on main keyboard
      kKB_LCONTROL = 0x1D,
      kKB_A = 0x1E,
      kKB_S = 0x1F,
      kKB_D = 0x20,
      kKB_F = 0x21,
      kKB_G = 0x22,
      kKB_H = 0x23,
      kKB_J = 0x24,
      kKB_K = 0x25,
      kKB_L = 0x26,
      kKB_SEMICOLON = 0x27,
      kKB_APOSTROPHE = 0x28,
      kKB_GRAVE = 0x29, // accent
      kKB_LSHIFT = 0x2A,
      kKB_BACKSLASH = 0x2B,
      kKB_Z = 0x2C,
      kKB_X = 0x2D,
      kKB_C = 0x2E,
      kKB_V = 0x2F,
      kKB_B = 0x30,
      kKB_N = 0x31,
      kKB_M = 0x32,
      kKB_COMMA = 0x33,
      kKB_PERIOD = 0x34, // . on main keyboard
      kKB_SLASH = 0x35, // / on main keyboard
      kKB_RSHIFT = 0x36,
      kKB_MULTIPLY = 0x37, // * on numeric keypad
      kKB_LMENU = 0x38, // left Alt
      kKB_SPACE = 0x39,
      kKB_CAPITAL = 0x3A,
      kKB_F1 = 0x3B,
      kKB_F2 = 0x3C,
      kKB_F3 = 0x3D,
      kKB_F4 = 0x3E,
      kKB_F5 = 0x3F,
      kKB_F6 = 0x40,
      kKB_F7 = 0x41,
      kKB_F8 = 0x42,
      kKB_F9 = 0x43,
      kKB_F10 = 0x44,
      kKB_NUMLOCK = 0x45,
      kKB_SCROLL = 0x46, // Scroll Lock
      kKB_NUMPAD7 = 0x47,
      kKB_NUMPAD8 = 0x48,
      kKB_NUMPAD9 = 0x49,
      kKB_SUBTRACT = 0x4A, // - on numeric keypad
      kKB_NUMPAD4 = 0x4B,
      kKB_NUMPAD5 = 0x4C,
      kKB_NUMPAD6 = 0x4D,
      kKB_ADD = 0x4E, // + on numeric keypad
      kKB_NUMPAD1 = 0x4F,
      kKB_NUMPAD2 = 0x50,
      kKB_NUMPAD3 = 0x51,
      kKB_NUMPAD0 = 0x52,
      kKB_DECIMAL = 0x53, // . on numeric keypad
      kKB_OEM_102 = 0x56, // < > | on UK/Germany keyboards
      kKB_F11 = 0x57,
      kKB_F12 = 0x58,
      kKB_F13 = 0x64, //                     (NEC PC98)
      kKB_F14 = 0x65, //                     (NEC PC98)
      kKB_F15 = 0x66, //                     (NEC PC98)
      kKB_KANA = 0x70, // (Japanese keyboard)
      kKB_ABNT_C1 = 0x73, // / ? on Portugese (Brazilian) keyboards
      kKB_CONVERT = 0x79, // (Japanese keyboard)
      kKB_NOCONVERT = 0x7B, // (Japanese keyboard)
      kKB_YEN = 0x7D, // (Japanese keyboard)
      kKB_ABNT_C2 = 0x7E, // Numpad . on Portugese (Brazilian) keyboards
      kKB_NUMPADEQUALS = 0x8D, // = on numeric keypad (NEC PC98)
      kKB_PREVTRACK = 0x90, // Previous Track (KC_CIRCUMFLEX on Japanese keyboard)
      kKB_AT = 0x91, //                     (NEC PC98)
      kKB_COLON = 0x92, //                     (NEC PC98)
      kKB_UNDERLINE = 0x93, //                     (NEC PC98)
      kKB_KANJI = 0x94, // (Japanese keyboard)
      kKB_STOP = 0x95, //                     (NEC PC98)
      kKB_AX = 0x96, //                     (Japan AX)
      kKB_UNLABELED = 0x97, //                        (J3100)
      kKB_NEXTTRACK = 0x99, // Next Track
      kKB_NUMPADENTER = 0x9C, // Enter on numeric keypad
      kKB_RCONTROL = 0x9D,
      kKB_MUTE = 0xA0, // Mute
      kKB_CALCULATOR = 0xA1, // Calculator
      kKB_PLAYPAUSE = 0xA2, // Play / Pause
      kKB_MEDIASTOP = 0xA4, // Media Stop
      kKB_TWOSUPERIOR = 0xAA, // ² on French AZERTY keyboard (same place as ~ ` on QWERTY)
      kKB_VOLUMEDOWN = 0xAE, // Volume -
      kKB_VOLUMEUP = 0xB0, // Volume +
      kKB_WEBHOME = 0xB2, // Web home
      kKB_NUMPADCOMMA = 0xB3, // , on numeric keypad (NEC PC98)
      kKB_DIVIDE = 0xB5, // / on numeric keypad
      kKB_SYSRQ = 0xB7,
      kKB_RMENU = 0xB8, // right Alt
      kKB_PAUSE = 0xC5, // Pause
      kKB_HOME = 0xC7, // Home on arrow keypad
      kKB_UP = 0xC8, // UpArrow on arrow keypad
      kKB_PGUP = 0xC9, // PgUp on arrow keypad
      kKB_LEFT = 0xCB, // LeftArrow on arrow keypad
      kKB_RIGHT = 0xCD, // RightArrow on arrow keypad
      kKB_END = 0xCF, // End on arrow keypad
      kKB_DOWN = 0xD0, // DownArrow on arrow keypad
      kKB_PGDOWN = 0xD1, // PgDn on arrow keypad
      kKB_INSERT = 0xD2, // Insert on arrow keypad
      kKB_DELETE = 0xD3, // Delete on arrow keypad
      kKB_LWIN = 0xDB, // Left Windows key
      kKB_RWIN = 0xDC, // Right Windows key
      kKB_APPS = 0xDD, // AppMenu key
      kKB_POWER = 0xDE, // System Power
      kKB_SLEEP = 0xDF, // System Sleep
      kKB_WAKE = 0xE3, // System Wake
      kKB_WEBSEARCH = 0xE5, // Web Search
      kKB_WEBFAVORITES = 0xE6, // Web Favorites
      kKB_WEBREFRESH = 0xE7, // Web Refresh
      kKB_WEBSTOP = 0xE8, // Web Stop
      kKB_WEBFORWARD = 0xE9, // Web Forward
      kKB_WEBBACK = 0xEA, // Web Back
      kKB_MYCOMPUTER = 0xEB, // My Computer
      kKB_MAIL = 0xEC, // Mail
      kKB_MEDIASELECT = 0xED, // Media Select
    };
  }

  namespace MOUSE_KEY {
    enum E {
      KMB_LEFT = 0,
      KMB_RIGHT,
      KMB_MIDDLE,
      KMB_BUTTON3,
      KMB_BUTTON4,
      KMB_BUTTON5,
      KMB_BUTTON6,
      KMB_BUTTON7
    };
  }

  namespace STATUS_KEY {
    enum E {
      kIDLE = 0,
      kPRESSED,
      kRELEASED
    };
  }


  class BaseInput : public Module<BaseInput>
  {
   public:
    BaseInput() = default;
    virtual ~BaseInput() = default;

    virtual void
    init(WindowHandle) {}

    virtual void
    update() {}

    virtual bool
    isKeyPressed(KEY_BOARD::E key) {
      XC_UNREFERENCED_PARAMETER(key);
      return false;}

    virtual bool
    isKeyReleased(KEY_BOARD::E key) {
      XC_UNREFERENCED_PARAMETER(key);
      return false;
    }

    virtual bool
    isMouseKeyPressed(MOUSE_KEY::E key) {
      XC_UNREFERENCED_PARAMETER(key);
      return false;
    }

    virtual bool
    isMouseKeyReleased(MOUSE_KEY::E key) {
      XC_UNREFERENCED_PARAMETER(key);
      return false;
    }

    virtual float
    getXAxis() { return 0.f; }

    virtual float
    getYAxis() { return 0.f; }

    virtual void
    getMouseAxis(float&, float&) {}

    FORCEINLINE void
    setObject(BaseInput* _api) {
      BaseInput::_instance() = _api;
    }

   protected:
    bool m_keyboardPress = false;
    bool m_keyboardRelease = false;
    bool m_mousePressed = false;
    bool m_mouseReleased = false;


    std::map<KEY_BOARD::E, STATUS_KEY::E> m_keyState;
    std::map<MOUSE_KEY::E, STATUS_KEY::E> m_mouseState;
   //public:
  
   // std::map<KEY_BOARD::E, STATUS_KEY::E> m_keyState;
   // std::map<MOUSE_KEY::E, STATUS_KEY::E> m_mouseState;
   // BaseInput() = default;
   // ~BaseInput() = default;

   // FORCEINLINE void
   // setObject(BaseInput* input) {
   //   BaseInput::_instance() = input;
   // }

   // virtual void
   // init(sf::WindowHandle window) {};
   // 
   // virtual void
   // update() {};

   // /**
   //* @brief      keyPressed function, to detect if a key is pressed
   //* @param      input parameter one, pressed key
   //* @bug		     No know Bugs
   //* @return     Returns a bool
   //*/
   // virtual bool
   // keyPress(KEY_BOARD::E input) { return false; };

   // /**
   //  * @brief      keyReleased function, to detect if a key is released
   //  * @param      input parameter one, released key
   //  * @bug		     No know Bugs
   //  * @return     Returns a bool
   //  */
   // virtual bool
   // keyRelease(KEY_BOARD::E input) { return false; };

   // /**
   //  * @brief      mouseKeyPress function, to detect if a key is pressed of mouse
   //  * @param      input parameter one, pressed key
   //  * @bug		     No know Bugs
   //  * @return     Returns a bool
   //  */
   // virtual bool
   // mouseKeyPress(MOUSE_KEY::E input) { return false; };
   // 
   // /**
   //  * @brief      mouseKeyRelease function, to detect if a key is released of mouse
   //  * @param      input parameter one, released key
   //  * @bug		     No know Bugs
   //  * @return     Returns a bool
   //  */
   // virtual bool
   // mouseKeyRelease(MOUSE_KEY::E input) { return false; };

   // protected:

   //  

   //  bool m_keyboardPress = false;
   //  bool m_keyboardRelease = false;
   //  bool m_mousePressed = false;
   //  bool m_mouseReleased = false;

  };

  /**
   * @brief export the instance
   */
  XC_CORE_EXPORT BaseInput&
  g_input();

  /**
   * @Variable funProtoGraphiAPI, instance of the class
   */
  using funProtoInput = BaseInput * (*)();
}

