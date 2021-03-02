#pragma once


#include "xcPrerequisitesUtilities.h"
#include "xcVector3.h"



namespace xcEngineSDK {

  class Sphere;

  using xcEngineSDK::Vector3;

  class XC_UTILITY_EXPORT AABB 
  {
   public:
    AABB() = default;
    ~AABB() = default;

    Vector3 m_min;

    Vector3 m_max;

   public:

    bool
    intersec(Vector3& vector);

    bool
    intersec(Sphere& sphere);

  };
}
