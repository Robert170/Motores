#pragma once

#include "xcPlatformTypes.h"
#include "xcVectorI4.h"

using xcEngineSDK::int32;

namespace xcEngineSDK {

  class XC_UTILITY_EXPORT Plane {
  public:
    Plane() = default;
    ~Plane() = default;

    Plane(int32 x, int32 y = 0, int32 z = 0, int32 d = 0)
      :m_x(x), m_y(y), m_z(z), m_d(d) { };

    Plane(VectorI2 v, int32 z = 0, int32 d = 0)
      :m_x(v.m_x), m_y(v.m_y), m_z(z), m_d(d) { };

    Plane(VectorI3 v, int32 d = 0)
      :m_x(v.m_x), m_y(v.m_y), m_z(v.m_z), m_d(d) { };

    Plane(VectorI4 v)
      :m_x(v.m_x), m_y(v.m_y), m_z(v.m_z), m_d(v.m_w) { };

    Plane()
      :m_x(0.f), m_y(0.f), m_z(0.f), m_d(0.f) { };

    ~Plane() = default;

  private:

    int32 m_x;
    int32 m_y;
    int32 m_z;
    int32 m_d;

  };
}