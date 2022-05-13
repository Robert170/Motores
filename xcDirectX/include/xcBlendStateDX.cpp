#include "xcBlendStateDX.h"
namespace xcEngineSDK {

  BlendStateDX::~BlendStateDX() {
    if (m_pBlendState) {
      m_pBlendState->Release();
    }
  }
}