#pragma once


#include "xcPrerequisitesUtilities.h"
#include "xcVector3.h"


using xcEngineSDK::Vector3;

namespace xcEngineSDK {

class Sphere;
class AABB;

  class XC_UTILITY_EXPORT Ray 
  {
   public:
    Ray();
    ~Ray();

    Vector3 m_position;

    Vector3 m_direccion;

   public:

    bool
    intersec(Sphere& sphere);

    bool
    intersec(AABB& box);

  };
}
