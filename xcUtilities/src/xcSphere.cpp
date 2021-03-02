#include "xcSphere.h"
#include "xcAABB.h"

namespace xcEngineSDK {

  Sphere::Sphere() {

    m_radio = 0;
  }

  Sphere::~Sphere() {
  }

  bool
  Sphere::intersec(Vector3& vector) {
    return false;
  }


  bool
  Sphere::intersec(AABB& box) {
    return false;
  }
}