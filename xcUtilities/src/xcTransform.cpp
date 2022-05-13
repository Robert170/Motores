#include "xcTransform.h"

namespace xcEngineSDK {
  Transfom::Transfom(const Vector3& traslation, 
                     const Quaternion& rotation, 
                     const Vector3& scale) {
    m_translation = traslation;
    m_rotation = rotation;
    m_scale = scale;
  }

  void
  Transfom::setTraslation(const Vector3& traslation) {
    m_translation = traslation;
  }

  void
  Transfom::setRotation(const Quaternion& rotation) {
    m_rotation = rotation;
  }

  void
  Transfom::setScale(const Vector3& scale) {
    m_scale = scale;
  }

  Vector3&
  Transfom::getTraslation() {
    return m_translation;
  }

  Quaternion&
  Transfom::getRotation() {
    return m_rotation;
  }

  Vector3&
  Transfom::getScale(){
    return m_scale;
  }
}
