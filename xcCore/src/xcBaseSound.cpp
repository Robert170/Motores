#include "xcBaseSound.h"

namespace xcEngineSDK {

  BaseSound& g_sound() {

    return BaseSound::instance();

  }
}