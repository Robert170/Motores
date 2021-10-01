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
namespace xcEngineSDK {

  namespace KEY_BOARD {
    enum E {
      KB_UNASSIGNED = 0x00,
      KB_ESCAPE = 0x01,
      KB_1 = 0x02,
      KB_2 = 0x03,
      KB_3 = 0x04,
      KB_4 = 0x05,
      KB_5 = 0x06,
      KB_6 = 0x07,
      KB_7 = 0x08,
      KB_8 = 0x09,
      KB_9 = 0x0A,
      KB_0 = 0x0B,
      KB_MINUS = 0x0C, // - on main keyboard
      KB_EQUALS = 0x0D,
      KB_BACK = 0x0E, // backspace
      KB_TAB = 0x0F,
      KB_Q = 0x10,
      KB_W = 0x11,
      KB_E = 0x12,
      KB_R = 0x13,
      KB_T = 0x14,
      KB_Y = 0x15,
      KB_U = 0x16,
      KB_I = 0x17,
      KB_O = 0x18,
      KB_P = 0x19,
      KB_LBRACKET = 0x1A,
      KB_RBRACKET = 0x1B,
      KB_RETURN = 0x1C, // Enter on main keyboard
      KB_LCONTROL = 0x1D,
      KB_A = 0x1E,
      KB_S = 0x1F,
      KB_D = 0x20,
      KB_F = 0x21,
      KB_G = 0x22,
      KB_H = 0x23,
      KB_J = 0x24,
      KB_K = 0x25,
      KB_L = 0x26,
      KB_SEMICOLON = 0x27,
      KB_APOSTROPHE = 0x28,
      KB_GRAVE = 0x29, // accent
      KB_LSHIFT = 0x2A,
      KB_BACKSLASH = 0x2B,
      KB_Z = 0x2C,
      KB_X = 0x2D,
      KB_C = 0x2E,
      KB_V = 0x2F,
      KB_B = 0x30,
      KB_N = 0x31,
      KB_M = 0x32,
      KB_COMMA = 0x33,
      KB_PERIOD = 0x34, // . on main keyboard
      KB_SLASH = 0x35, // / on main keyboard
      KB_RSHIFT = 0x36,
      KB_MULTIPLY = 0x37, // * on numeric keypad
      KB_LMENU = 0x38, // left Alt
      KB_SPACE = 0x39,
      KB_CAPITAL = 0x3A,
      KB_F1 = 0x3B,
      KB_F2 = 0x3C,
      KB_F3 = 0x3D,
      KB_F4 = 0x3E,
      KB_F5 = 0x3F,
      KB_F6 = 0x40,
      KB_F7 = 0x41,
      KB_F8 = 0x42,
      KB_F9 = 0x43,
      KB_F10 = 0x44,
      KB_NUMLOCK = 0x45,
      KB_SCROLL = 0x46, // Scroll Lock
      KB_NUMPAD7 = 0x47,
      KB_NUMPAD8 = 0x48,
      KB_NUMPAD9 = 0x49,
      KB_SUBTRACT = 0x4A, // - on numeric keypad
      KB_NUMPAD4 = 0x4B,
      KB_NUMPAD5 = 0x4C,
      KB_NUMPAD6 = 0x4D,
      KB_ADD = 0x4E, // + on numeric keypad
      KB_NUMPAD1 = 0x4F,
      KB_NUMPAD2 = 0x50,
      KB_NUMPAD3 = 0x51,
      KB_NUMPAD0 = 0x52,
      KB_DECIMAL = 0x53, // . on numeric keypad
      KB_OEM_102 = 0x56, // < > | on UK/Germany keyboards
      KB_F11 = 0x57,
      KB_F12 = 0x58,
      KB_F13 = 0x64, //                     (NEC PC98)
      KB_F14 = 0x65, //                     (NEC PC98)
      KB_F15 = 0x66, //                     (NEC PC98)
      KB_KANA = 0x70, // (Japanese keyboard)
      KB_ABNT_C1 = 0x73, // / ? on Portugese (Brazilian) keyboards
      KB_CONVERT = 0x79, // (Japanese keyboard)
      KB_NOCONVERT = 0x7B, // (Japanese keyboard)
      KB_YEN = 0x7D, // (Japanese keyboard)
      KB_ABNT_C2 = 0x7E, // Numpad . on Portugese (Brazilian) keyboards
      KB_NUMPADEQUALS = 0x8D, // = on numeric keypad (NEC PC98)
      KB_PREVTRACK = 0x90, // Previous Track (KC_CIRCUMFLEX on Japanese keyboard)
      KB_AT = 0x91, //                     (NEC PC98)
      KB_COLON = 0x92, //                     (NEC PC98)
      KB_UNDERLINE = 0x93, //                     (NEC PC98)
      KB_KANJI = 0x94, // (Japanese keyboard)
      KB_STOP = 0x95, //                     (NEC PC98)
      KB_AX = 0x96, //                     (Japan AX)
      KB_UNLABELED = 0x97, //                        (J3100)
      KB_NEXTTRACK = 0x99, // Next Track
      KB_NUMPADENTER = 0x9C, // Enter on numeric keypad
      KB_RCONTROL = 0x9D,
      KB_MUTE = 0xA0, // Mute
      KB_CALCULATOR = 0xA1, // Calculator
      KB_PLAYPAUSE = 0xA2, // Play / Pause
      KB_MEDIASTOP = 0xA4, // Media Stop
      KB_TWOSUPERIOR = 0xAA, // ² on French AZERTY keyboard (same place as ~ ` on QWERTY)
      KB_VOLUMEDOWN = 0xAE, // Volume -
      KB_VOLUMEUP = 0xB0, // Volume +
      KB_WEBHOME = 0xB2, // Web home
      KB_NUMPADCOMMA = 0xB3, // , on numeric keypad (NEC PC98)
      KB_DIVIDE = 0xB5, // / on numeric keypad
      KB_SYSRQ = 0xB7,
      KB_RMENU = 0xB8, // right Alt
      KB_PAUSE = 0xC5, // Pause
      KB_HOME = 0xC7, // Home on arrow keypad
      KB_UP = 0xC8, // UpArrow on arrow keypad
      KB_PGUP = 0xC9, // PgUp on arrow keypad
      KB_LEFT = 0xCB, // LeftArrow on arrow keypad
      KB_RIGHT = 0xCD, // RightArrow on arrow keypad
      KB_END = 0xCF, // End on arrow keypad
      KB_DOWN = 0xD0, // DownArrow on arrow keypad
      KB_PGDOWN = 0xD1, // PgDn on arrow keypad
      KB_INSERT = 0xD2, // Insert on arrow keypad
      KB_DELETE = 0xD3, // Delete on arrow keypad
      KB_LWIN = 0xDB, // Left Windows key
      KB_RWIN = 0xDC, // Right Windows key
      KB_APPS = 0xDD, // AppMenu key
      KB_POWER = 0xDE, // System Power
      KB_SLEEP = 0xDF, // System Sleep
      KB_WAKE = 0xE3, // System Wake
      KB_WEBSEARCH = 0xE5, // Web Search
      KB_WEBFAVORITES = 0xE6, // Web Favorites
      KB_WEBREFRESH = 0xE7, // Web Refresh
      KB_WEBSTOP = 0xE8, // Web Stop
      KB_WEBFORWARD = 0xE9, // Web Forward
      KB_WEBBACK = 0xEA, // Web Back
      KB_MYCOMPUTER = 0xEB, // My Computer
      KB_MAIL = 0xEC, // Mail
      KB_MEDIASELECT = 0xED, // Media Select
    };
  }

	class BaseInput : public Module<BaseInput>
	{
	public:
		BaseInput() = default;
		~BaseInput() = default;

    FORCEINLINE void
      setObject(BaseInput* input) {
			BaseInput::_instance() = input;
    }

	private:

    /**
		 * @brief      keyPressed function, to detect if a key is pressed
		 * @param      input parameter one, pressed key
		 * @bug		     No know Bugs
		 * @return     Returns nothing
		 */
    virtual void
    keyPressed(KEY_BOARD::E input) {};

		/**
		 * @brief      keyReleased function, to detect if a key is released
		 * @param      input parameter one, released key
		 * @bug		     No know Bugs
		 * @return     Returns nothing
		 */
		virtual void
    keyReleased(KEY_BOARD::E input) {};

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

