#include "xcVectorI2.h"

using xcEngineSDK::VectorI2;

VectorI2 
VectorI2::operator + (const VectorI2& V) {

  return VectorI2(m_x + V.m_x, m_y + V.m_y);
}

VectorI2 
VectorI2::operator - (const VectorI2& V) {

  return VectorI2(m_x - V.m_x, m_y - V.m_y);
}

VectorI2 
VectorI2::operator * (const VectorI2& V) {

  return VectorI2(m_x * V.m_x, m_y * V.m_y);
}

VectorI2 
VectorI2::operator / (const VectorI2& V) {

  return VectorI2(m_x / V.m_x, m_y / V.m_y);
}

VectorI2 
VectorI2::operator = (const VectorI2& V) {
  m_x = V.m_x;
  m_y = V.m_y;
  return *this;
}

bool
VectorI2::operator == (const VectorI2& V) {

  if (m_x == V.m_x && m_y == V.m_y) {
    return true;
  }
  else {
    return false;
  }
}

VectorI2 
VectorI2::operator + (const int32& V) {

  return VectorI2(m_x + V, m_y + V);
}

VectorI2 
VectorI2::operator - (const int32& V) {

  return VectorI2(m_x - V, m_y - V);
}

VectorI2 
VectorI2::operator * (const int32& V) {

  return VectorI2(m_x * V, m_y * V);
}

VectorI2 
VectorI2::operator / (const int32& V) {

  return VectorI2(m_x / V, m_y / V);
}

VectorI2 
VectorI2::operator += (const VectorI2& V) {

  m_x += V.m_x;
  m_y += V.m_y;
  return *this;
}

VectorI2 
VectorI2::operator -= (const VectorI2& V) 
{
  m_x -= V.m_x;
  m_y -= V.m_y;
  return *this;
}

VectorI2 
VectorI2::operator *= (const VectorI2& V) {

  m_x *= V.m_x;
  m_y *= V.m_y;
  return *this;
}

VectorI2 
VectorI2::operator /= (const VectorI2& V) {

  m_x /= V.m_x;
  m_y /= V.m_y;
  return *this;
}

VectorI2 
VectorI2::normalize() {
  int32 Temp = this->magnitud();

  if (Temp != 0) {
    //divide the vector whit temp
    return VectorI2(m_x / Temp, m_y / Temp);
  }
  else {
    return VectorI2();
  }
}

int32 
VectorI2::magnitud() {
  return static_cast <int32>(sqrt(m_x * m_x + m_y * m_y));
}

VectorI2 
VectorI2::proyection(VectorI2& VectorA, VectorI2& VetorB) {
  return ((VectorA * VetorB) / (VetorB.magnitud() * VetorB.magnitud()) * VetorB);
}
