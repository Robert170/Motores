#include "xcBasePhysics.h"

namespace xcEngineSDK {
  BasePhysics& g_physics() {

    return BasePhysics::instance();

  }
}