#include "xcVectorI3.h"

using xcEngineSDK::VectorI3;

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

VectorI3 
VectorI3::operator = (const VectorI3& V) {
  m_x = V.m_x;
  m_y = V.m_y;
  m_z = V.m_z;
  return *this;
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
  
  m_x += V.m_x;
  m_y += V.m_y;
  m_z += V.m_z;
  return *this;
}

VectorI3 
VectorI3::operator -= (const VectorI3& V) {
  
  m_x -= V.m_x;
  m_y -= V.m_y;
  m_z -= V.m_z;
  return *this;
}

VectorI3 
VectorI3::operator *= (const VectorI3& V) {
  
  m_x *= V.m_x;
  m_y *= V.m_y;
  m_z *= V.m_z;
  return *this;
}

VectorI3 
VectorI3::operator /= (const VectorI3& V) {
  
  m_x /= V.m_x;
  m_y /= V.m_y;
  m_z /= V.m_z;
  return *this;
}

VectorI3 
VectorI3::normalize() {
  int32 Temp = this->magnitud();

  if (Temp != 0) {
    //divide the vector whit temp
    return VectorI3(m_x / Temp, m_y / Temp, m_z / Temp);
  }
  else {
    return VectorI3();
  }
}

int32 
VectorI3::magnitud() {
  return static_cast <int32>(sqrt(m_x * m_x + m_y * m_y + m_z * m_z));
}

VectorI3 
VectorI3::proyection(VectorI3& VectorA, VectorI3& VetorB) {
  return ((VectorA * VetorB) / (VetorB.magnitud() * VetorB.magnitud()) * VetorB);
}
