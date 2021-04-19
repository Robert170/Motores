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
    sphere;
    return false;
  }

  bool
  Ray::intersec(AABB& box) {
    box;
    return false;
  }
}