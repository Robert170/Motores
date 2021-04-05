#include <iostream>
#include "xcGraphiAPI.h"

using namespace xcEngineSDK;

int
main() {

  HINSTANCE hInstance = LoadLibraryExA("Lib.dll",
                                       nullptr,
                                       LOAD_WITH_ALTERED_SEARCH_PATH);

  if (!hInstance) {
    return 1;
  }

  using fnProt = GraphiAPI * (*)();

  fnProt myGPNFunction = reinterpret_cast<fnProt>(GetProcAddress(hInstance,
                                                                 "createGraphisAPI"));

  if (!myGPNFunction) {
    return 2;
  }

  GraphiAPI* m_graphicsAPI = myGPNFunction();

  FreeLibrary(hInstance);

  return 0;

}