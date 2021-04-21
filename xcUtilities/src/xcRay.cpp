#include "xcRay.h"
#include "xcSphere.h"
#include "xcAABB.h"

namespace xcEngineSDK {

  bool
  Ray::intersec(Sphere& sphere) {
    XC_UNREFERENCED_PARAMETER(sphere);
    return false;
  }

  bool
  Ray::intersec(AABB& box) {
    XC_UNREFERENCED_PARAMETER(box);
    return false;
  }
}