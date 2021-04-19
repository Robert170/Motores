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
		/**
		 * @brief default constructor
		 */
		Plugin() = default;

		/**
		 * @brief default destructor
		 */
		~Plugin() = default;


		/**
		 * @brief public function
		 */

		/**
		 * @brief      loadPlugin function, load the dll
		 * @param      dllName parameter one, the name of dll
		 * @return     Returns a bool
		 */
		bool
	  loadPlugin(const String& dllName);

		/**
		 * @brief      getProcedureByName function, load the graphi api function
		 * @param      name parameter one, name of the function
		 * @return     Returns nothing
		 */
		void*
		getProcedureByName(const String& name);
		
		/**
		 * @brief      destroy function, to free the library
		 * @return     Returns nothing
		 */
		void
		destroy();

	 public:


		/**
		 * @brief public members
		 */

		/**
		 * @brief m_instance, instance of plugin
		 */
		void* m_instance = nullptr;


	 private:

	};

	/**
	 * @brief      loadPlugin function, load the dll
	 * @param      dllName parameter one, the name of dll
	 * @return     Returns a bool
	 */
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

	/**
	 * @brief      getProcedureByName function, load the graphi api function
	 * @param      name parameter one, name of the function
	 * @return     Returns nothing
	 */
	inline void*
	Plugin::getProcedureByName(const String& name) {

    auto myGPNFunction = GetProcAddress(reinterpret_cast<HINSTANCE>(m_instance),
                                        name.c_str());

    if (!myGPNFunction) {

			std::cout << "auto myGPNFunction not initialized" << std::endl;
    }

		return myGPNFunction;
	}


	/**
	 * @brief      destroy function, to free the library
	 * @return     Returns nothing
	 */
	inline void
	Plugin::destroy() {

		FreeLibrary(reinterpret_cast<HINSTANCE>(m_instance));

	}
}
