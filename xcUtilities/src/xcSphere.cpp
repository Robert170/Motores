#include "xcSphere.h"
#include "xcAABB.h"

namespace xcEngineSDK {

  bool
  Sphere::intersec(Vector3& vector) {
    XC_UNREFERENCED_PARAMETER(vector);
    return false;
  }


  bool
  Sphere::intersec(AABB& box) {
    XC_UNREFERENCED_PARAMETER(box);
    return false;
  }
}