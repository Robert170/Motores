#include "xcVectorI4.h"

using xcEngineSDK::VectorI4;

namespace xcEngineSDK {

  VectorI4
  VectorI4::operator + (const VectorI4& V) {

    return VectorI4(m_x + V.m_x, m_y + V.m_y, m_z + V.m_z, m_w + V.m_w);
  }

  VectorI4
  VectorI4::operator - (const VectorI4& V) {

    return VectorI4(m_x - V.m_x, m_y - V.m_y, m_z - V.m_z, m_w - V.m_w);
  }

  VectorI4
  VectorI4::operator * (const VectorI4& V) {

    return VectorI4(m_x * V.m_x, m_y * V.m_y, m_z * V.m_z, m_w * V.m_w);
  }

  VectorI4
  VectorI4::operator / (const VectorI4& V) {

    return VectorI4(m_x / V.m_x, m_y / V.m_y, m_z / V.m_z, m_w / V.m_w);
  }

  VectorI4
  VectorI4::operator=(const VectorI4& V) {
    m_x = V.m_x;
    m_y = V.m_y;
    m_z = V.m_z;
    m_w = V.m_w;
    return *this;
  }

  bool
  VectorI4::operator == (const VectorI4& V) {

    if (m_x == V.m_x && m_y == V.m_y && m_z == V.m_z && m_w == V.m_w) {
      return true;
    }
    else {
      return false;
    }
  }

  VectorI4
  VectorI4::operator + (const int32& V) {

    return VectorI4(m_x + V, m_y + V, m_z + V, m_w + V);
  }

  VectorI4
  VectorI4::operator - (const int32& V) {

    return VectorI4(m_x - V, m_y - V, m_z - V, m_w - V);
  }

  VectorI4
  VectorI4::operator * (const int32& V) {

    return VectorI4(m_x * V, m_y * V, m_z * V, m_w * V);
  }

  VectorI4
  VectorI4::operator / (const int32& V) {

    return VectorI4(m_x / V, m_y / V, m_z / V, m_w / V);
  }

  VectorI4
  VectorI4::operator += (const VectorI4& V) {

    m_x += V.m_x;
    m_y += V.m_y;
    m_z += V.m_z;
    m_w += V.m_w;
    return *this;
  }

  VectorI4
  VectorI4::operator -= (const VectorI4& V) {

    m_x -= V.m_x;
    m_y -= V.m_y;
    m_z -= V.m_z;
    m_w -= V.m_w;
    return *this;
  }

  VectorI4
  VectorI4::operator *= (const VectorI4& V) {

    m_x *= V.m_x;
    m_y *= V.m_y;
    m_z *= V.m_z;
    m_w *= V.m_w;
    return *this;
  }

  VectorI4
  VectorI4::operator /= (const VectorI4& V) {

    m_x /= V.m_x;
    m_y /= V.m_y;
    m_z /= V.m_z;
    m_w /= V.m_w;
    return *this;
  }

  VectorI4&
  VectorI4::normalize() {
    int32 Temp = this->magnitud();

    if (Temp != 0) {
      //divide the vector whit temp
      this->m_x = this->m_x / Temp;
      this->m_y = this->m_y / Temp;
      this->m_z = this->m_z / Temp;
      this->m_w = this->m_w / Temp;
      return *this;
    }
    else {
      return *this;
    }
  }

  int32
  VectorI4::magnitud() {
    return static_cast <int32>(sqrt(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w));
  }

  VectorI4
  VectorI4::proyection(VectorI4& VectorA,
                       VectorI4& VetorB) {

    return ((VectorA * VetorB) / (VetorB.magnitud() * VetorB.magnitud()) * VetorB);
  }

  int32
  VectorI4::Dot(VectorI4& VectorA,
                VectorI4& VetorB) {

    return (VectorA.m_x * VetorB.m_x) +
      (VectorA.m_y * VetorB.m_y) +
      (VectorA.m_z * VetorB.m_z) +
      (VectorA.m_w * VetorB.m_z);
  }
}