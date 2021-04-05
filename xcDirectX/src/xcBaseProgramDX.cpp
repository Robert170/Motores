
#include <xcDXGraphiAPI.h>

namespace xcEngineSDK {

  extern "C" _declspec(dllexport) GraphiAPI * createGraphisAPI() {

    return new DXGraphiAPI();

  }
}