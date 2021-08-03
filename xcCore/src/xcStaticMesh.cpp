
#include "xcStaticMesh.h"
#include "xcModel.h"

namespace xcEngineSDK {

  StaticMesh::StaticMesh(WeakSptr<Model> model) {

    m_model = model.lock();

  }

  void 
  StaticMesh::update(float deltaTime) {
    m_model->update(deltaTime);
  }

  void 
  StaticMesh::render() {
    m_model->render();
  }

  void 
  StaticMesh::setModel(WeakSptr<Model> model) {
    m_model = model.lock();
  }

}