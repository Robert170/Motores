#include "xcVectorI4.h"

using xcEngineSDK::VectorI4;

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

VectorI4 
VectorI4::normalize() {
  int32 Temp = this->magnitud();

  if (Temp != 0) {
    //divide the vector whit temp
    return VectorI4(m_x / Temp, m_y / Temp, m_z / Temp, m_w / Temp);
  }
  else {
    return VectorI4();
  }
}

int32 
VectorI4::magnitud() {
  return static_cast <int32>(sqrt(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w));
}

VectorI4 
VectorI4::proyection(VectorI4& VectorA, VectorI4& VetorB) {
  return ((VectorA * VetorB) / (VetorB.magnitud() * VetorB.magnitud()) * VetorB);
}
