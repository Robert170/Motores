#pragma once


#include "xcPrerequisitesUtilities.h"
#include "xcPlatformMath.h"
#include "xcWindowsMath.h"
#include "xcLinuxMath.h"

namespace xcEngineSDK {
  #if XC_PLATFORM == XC_PLATFORM_WIN32
    using Math = PlatformMath;
  #elif XC_PLATFORM == XC_PLATFORM_LINUX
    using Math = LinuxMath;
  #else
    using Math = PlatformMath;
  #endif
}