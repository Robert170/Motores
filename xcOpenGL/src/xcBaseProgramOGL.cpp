
#include <xcOGLGraphiAPI.h>

namespace xcEngineSDK {

  extern "C" _declspec(dllexport) GraphiAPI * createGraphisAPI() {

    return new OGLGraphiAPI();

  }
}