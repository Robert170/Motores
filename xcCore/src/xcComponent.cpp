#include "xcComponent.h"

namespace xcEngineSDK {
  void 
  Component::setComponent(SPtr<Model> model) {
    m_model = model;
  }
}