#include "xcAABB.h"
#include "xcSphere.h"

namespace xcEngineSDK {
  bool
    AABB::intersec(Vector3& vector) {
    XC_UNREFERENCED_PARAMETER(vector);
    return false;
  }

  bool
    AABB::intersec(Sphere& sphere) {
    XC_UNREFERENCED_PARAMETER(sphere);
    return false;
  }
}
