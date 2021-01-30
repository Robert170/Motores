#include "xcVectorI4.h"

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
VectorI4::operator + (const float& V) {
  
  return VectorI4(m_x + V, m_y + V, m_z + V, m_w + V);
}

VectorI4 
VectorI4::operator - (const float& V) {
  
  return VectorI4(m_x - V, m_y - V, m_z - V, m_w - V);
}

VectorI4 
VectorI4::operator * (const float& V) {
  
  return VectorI4(m_x * V, m_y * V, m_z * V, m_w * V);
}

VectorI4 
VectorI4::operator / (const float& V) {
  
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
