#include "xcVectorI2.h"



namespace xcEngineSDK {

  VectorI2
  VectorI2::operator+(const VectorI2& V) {
    return VectorI2(m_x + V.m_x, m_y + V.m_y);
  }


  VectorI2
  VectorI2::operator-(const VectorI2& V) {

    return VectorI2(m_x - V.m_x, m_y - V.m_y);
  }

  VectorI2
  VectorI2::operator*(const VectorI2& V) {

    return VectorI2(m_x * V.m_x, m_y * V.m_y);
  }

  VectorI2
  VectorI2::operator=(const VectorI2& V) {
    m_x = V.m_x;
    m_y = V.m_y;
    return *this;
  }

  bool
  VectorI2::operator==(const VectorI2& V) {

    if (m_x == V.m_x && m_y == V.m_y) {
      return true;
    }
    else {
      return false;
    }
  }

  VectorI2
  VectorI2::operator+(const int32& V) {

    return VectorI2(m_x + V, m_y + V);
  }

  VectorI2
  VectorI2::operator-(const int32& V) {

    return VectorI2(m_x - V, m_y - V);
  }

  VectorI2
  VectorI2::operator*(const int32& V) {

    return VectorI2(m_x * V, m_y * V);
  }

  VectorI2
  VectorI2::operator/(const int32& V) {

    return VectorI2(m_x / V, m_y / V);
  }

  VectorI2&
  VectorI2::operator +=(const VectorI2& V) {

    m_x += V.m_x;
    m_y += V.m_y;
    return *this;
  }

  VectorI2&
  VectorI2::operator -= (const VectorI2& V)
  {
    m_x -= V.m_x;
    m_y -= V.m_y;
    return *this;
  }

  VectorI2&
  VectorI2::operator *= (const VectorI2& V) {

    m_x *= V.m_x;
    m_y *= V.m_y;
    return *this;
  }

  bool 
  VectorI2::operator!=(const VectorI2& V) {
    return !this->operator==(V);
  }

  VectorI2&
  VectorI2::normalize() {

    int32 Temp = this->magnitud();

    if (Temp != 0) {
      //divide the vector whit temp
      this->m_x = this->m_x / Temp;
      this->m_x = this->m_y / Temp;
      return *this;
    }
    else {
      return *this;
    }
  }

  int32
  VectorI2::magnitud() {
    return (sqrt(m_x * m_x + m_y * m_y));
  }

  VectorI2
  VectorI2::proyection(VectorI2& VectorA,
                       VectorI2& VetorB) {
    return VectorI2(((VectorA * VetorB) / (VetorB.magnitud() * VetorB.magnitud())
      * VetorB));
  }


  int32
  VectorI2::Dot(VectorI2& VectorA,
                VectorI2& VetorB) {
    return (VectorA.m_x * VetorB.m_x) + (VectorA.m_y * VetorB.m_y);
  }
}