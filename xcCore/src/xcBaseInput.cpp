#include "xcBaseInput.h"

namespace xcEngineSDK {

   XC_CORE_EXPORT BaseInput& g_input() {

    return BaseInput::instance();

  }

}