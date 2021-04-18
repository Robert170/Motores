#include "xcGraphiAPI.h"

namespace xcEngineSDK {

  XC_CORE_EXPORT 
  GraphiAPI& xcEngineSDK::g_graphiAPI() {

    return GraphiAPI::instance();

  }

}

