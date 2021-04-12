/**
 *
 * @brief .h for math instance, depends on runtime environment 
 *
 * This is an instance of the math for the engine
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 1/30/2021
 *
 *
 * @bug	No know Bugs
 */
#pragma once


#include "xcPrerequisitesUtilities.h"
#include "xcPlatformMath.h"

#if XC_PLATFORM == XC_PLATFORM_WIN32
#include "xcWindowsMath.h"
#elif XC_PLATFORM == XC_PLATFORM_LINUX
#include "xcLinuxMath.h"
#endif


namespace xcEngineSDK {
  #if XC_PLATFORM == XC_PLATFORM_WIN32
    using Math = PlatformMath;
  #elif XC_PLATFORM == XC_PLATFORM_LINUX
    using Math = LinuxMath;
  #else
    using Math = PlatformMath;
  #endif
}