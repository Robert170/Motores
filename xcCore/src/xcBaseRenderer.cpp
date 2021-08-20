#include "xcBaseRenderer.h"

namespace xcEngineSDK {

  BaseRenderer& g_renderer() {

    return BaseRenderer::instance();

  }
}