#include <xcModel.h>
#include "xcRenderer.h"


namespace xcEngineSDK {

  Renderer& g_renderer() {

    return Renderer::instance();

  }
  void
  Renderer::setModels(Vector<SPtr<Model>> models) {
    m_vModels = models;
  }

  void
  Renderer::setModel(SPtr<Model> model) {
    m_vModels.push_back(model);
  }
  
}