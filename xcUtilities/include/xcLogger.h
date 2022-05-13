/*****************************************************************************/
/**
 * @file    xcLogger.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/06/29
 * @brief   Represents one engine module
 *
 * Represents one engine module. Essentially it is a specialized type of
 * singleton. Module must be manually started up and shut down before and
 * after use.
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

	class Logger
	{
	 public:
		Logger() = default;
		~Logger() = default;

		void
		saveError(String& error, String& fileOfError);

	 private:

	};

}