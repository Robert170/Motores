/*****************************************************************************/
/**
 * @file    xcPlugin.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/04/15
 * @brief   Represents plugin for dll
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
#include "xcPrerequisitesUtilities.h"


namespace xcEngineSDK {

	class Plugin
	{
	 public:
		Plugin() = default;
		~Plugin() = default;

		bool
	  loadPlugin(const String& dllName);

		void*
		getProcedureByName(const String& name);
		
		void
		destroy();

	 public:

		void* m_instance = nullptr;


	 private:

	};

  inline bool
  Plugin::loadPlugin(const String& dllName) { 
	  m_instance = LoadLibraryExA(dllName.c_str(),
                                nullptr,
                                LOAD_WITH_ALTERED_SEARCH_PATH);

    if (!m_instance) {

			DWORD err = GetLastError();

			destroy();

      return false;
    }
	}

	inline void*
	Plugin::getProcedureByName(const String& name) {

    auto myGPNFunction = GetProcAddress(reinterpret_cast<HINSTANCE>(m_instance),
                                        name.c_str());

    if (!myGPNFunction) {

			std::cout << "auto myGPNFunction not initialized" << std::endl;
    }

		return myGPNFunction;
	}

	inline void
	Plugin::destroy() {

		FreeLibrary(reinterpret_cast<HINSTANCE>(m_instance));

	}
}
