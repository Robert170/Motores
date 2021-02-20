#include "xcSphere.h"
#include "xcAABB.h"

namespace xcEngineSDK {

  Sphere::Sphere() {
  }

  Sphere::~Sphere() {
  }

  bool
  Sphere::intersec(Vector3 vector) {
    return false;
  }


  bool
  Sphere::intersec(AABB box) {
    return false;
  }
}