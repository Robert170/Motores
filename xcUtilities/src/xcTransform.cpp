#include "xcTransform.h"

namespace xcEngineSDK {
  Transfom::Transfom(const Vector3& traslation, 
                     const Quaternion& rotation, 
                     const Vector3& scale) {
    m_translation = traslation;
    m_rotation = rotation;
    m_scale = scale;
  }
}