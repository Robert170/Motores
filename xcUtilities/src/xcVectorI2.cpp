#include "xcVectorI2.h"

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

  m_x = m_x + V.m_x;
  m_y = m_y + V.m_y;
  return *this;
}

VectorI2 
VectorI2::operator -= (const VectorI2& V) 
{
  m_x = m_x - V.m_x;
  m_y = m_y - V.m_y;
  return *this;
}

VectorI2 
VectorI2::operator *= (const VectorI2& V) {

  m_x = m_x * V.m_x;
  m_y = m_y * V.m_y;
  return *this;
}

VectorI2 
VectorI2::operator /= (const VectorI2& V) {

  m_x = m_x / V.m_x;
  m_y = m_y / V.m_y;
  return *this;
}
