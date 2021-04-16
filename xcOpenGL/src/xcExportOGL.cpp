#include <xcPrerequisitesOGL.h>
#include "xcOGLGraphiAPI.h"

namespace xcEngineSDK {

  extern "C" XC_CORE_EXPORT GraphiAPI * createGraphisAPI() {

    return new OGLGraphiAPI();

  }
}