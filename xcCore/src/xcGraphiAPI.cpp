#include "xcGraphiAPI.h"

namespace xcEngineSDK {

  XC_CORE_EXPORT 
  GraphiAPI& xcEngineSDK::API() {

    return GraphiAPI::instance();

  }

}

