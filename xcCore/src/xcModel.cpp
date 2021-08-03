#include "xcModel.h"
#include <xcShaderProgram.h>

namespace xcEngineSDK {

  Model::Model(const ResourceModel& resourse) {

    m_resource = resourse;

  }

  Model::Model(const String& path) {

    m_resource = ResourceModel(path);
  }
  void 
  Model::setMeshes() {
    uint32 numData = m_resource.m_vModelData.size();

    for (uint32 i = 0; i < numData; ++i) {
      m_vMeshes.push_back(Mesh(m_resource.m_vModelData[i]));
    }

  }

  void 
  Model::update(float delta) {

    uint32 numMeshes = m_vMeshes.size();

    for (uint32 i = 0; i < numMeshes; ++i) {
      m_vMeshes[i].update(delta);
    }
  }

  void 
  Model::render() {

    uint32 numMeshes = m_vMeshes.size();

    for (uint32 i = 0; i < numMeshes; ++i) {
      m_vMeshes[i].render();
    }
  }
}