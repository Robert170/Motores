#include "xcVectorI3.h"

VectorI3 
VectorI3::operator + (const VectorI3& V) {
    
  return VectorI3(m_x + V.m_x, m_y + V.m_y, m_z + V.m_z);
}

VectorI3 
VectorI3::operator - (const VectorI3& V) {
  
  return VectorI3(m_x - V.m_x, m_y - V.m_y, m_z - V.m_z);
}

VectorI3 
VectorI3::operator * (const VectorI3& V) {

  return VectorI3(m_x * V.m_x, m_y * V.m_y, m_z * V.m_z);
}

VectorI3 
VectorI3::operator / (const VectorI3& V) {
  
  return VectorI3(m_x / V.m_x, m_y / V.m_y, m_z / V.m_z);
}

bool 
VectorI3::operator == (const VectorI3& V) {
  
  if (m_x == V.m_x && m_y == V.m_y && m_z == V.m_z) {
    return true;
  }
  else {
    return false;
  }
}

VectorI3 
VectorI3::operator + (const int32& V) {
  
  return VectorI3(m_x + V, m_y + V, m_z + V);
}

VectorI3 
VectorI3::operator - (const int32& V) {
  
  return VectorI3(m_x - V, m_y - V, m_z - V);
}

VectorI3 
VectorI3::operator * (const int32& V) {
  
  return VectorI3(m_x * V, m_y * V, m_z * V);
}

VectorI3 VectorI3::operator / (const int32& V) {
  
  return VectorI3(m_x / V, m_y / V, m_z / V);
}

VectorI3 
VectorI3::operator += (const VectorI3& V) {
  
  m_x = m_x + V.m_x;
  m_y = m_y + V.m_y;
  m_z = m_z + V.m_z;
  return *this;
}

VectorI3 
VectorI3::operator -= (const VectorI3& V) {
  
  m_x = m_x - V.m_x;
  m_y = m_y - V.m_y;
  m_z = m_z - V.m_z;
  return *this;
}

VectorI3 
VectorI3::operator *= (const VectorI3& V) {
  
  m_x = m_x * V.m_x;
  m_y = m_y * V.m_y;
  m_z = m_z * V.m_z;
  return *this;
}

VectorI3 
VectorI3::operator /= (const VectorI3& V) {
  
  m_x = m_x / V.m_x;
  m_y = m_y / V.m_y;
  m_z = m_z / V.m_z;
  return *this;
}
