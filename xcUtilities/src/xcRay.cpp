#include "xcRay.h"
#include "xcSphere.h"
#include "xcAABB.h"

namespace xcEngineSDK {

  Ray::Ray() {
  }

  Ray::~Ray() {
  }

  bool
  Ray::intersec(Sphere& sphere) {

    return false;
  }

  bool
  Ray::intersec(AABB& box) {
    return false;
  }
}