#include "xcVector4.h"

Vector4 
Vector4::operator + (const Vector4& V) {

  return Vector4(m_x + V.m_x, m_y + V.m_y, m_z + V.m_z, m_w + V.m_w);
}

Vector4 
Vector4::operator - (const Vector4& V) {
  
  return Vector4(m_x - V.m_x, m_y - V.m_y, m_z - V.m_z, m_w - V.m_w);
}

Vector4 
Vector4::operator * (const Vector4& V) {
  
  return Vector4(m_x * V.m_x, m_y * V.m_y, m_z * V.m_z, m_w * V.m_w);
}

Vector4 
Vector4::operator / (const Vector4& V) {
  
  return Vector4(m_x / V.m_x, m_y / V.m_y, m_z / V.m_z, m_w * V.m_w);
}

bool 
Vector4::operator == (const Vector4& V) {
  
  if (m_x == V.m_x && m_y == V.m_y && m_z == V.m_z && m_w == V.m_w) {
    return true;
  }
  else {
    return false;
  }
}

Vector4 
Vector4::operator + (const float& V) {
  
  return Vector4(m_x + V, m_y + V, m_z + V, m_w + V);
}

Vector4 
Vector4::operator - (const float& V) {

  return Vector4(m_x - V, m_y - V, m_z - V, m_w - V);
}

Vector4 
Vector4::operator * (const float& V) {

  return Vector4(m_x * V, m_y * V, m_z * V, m_w * V);
}

Vector4 
Vector4::operator / (const float& V) {
  
  return Vector4(m_x / V, m_y / V, m_z / V, m_w / V);
}

Vector4 
Vector4::operator += (const Vector4& V) {
  
  m_x = m_x + V.m_x;
  m_y = m_y + V.m_y;
  m_z = m_z + V.m_z;
  m_w = m_w + V.m_w;
  return *this;
}

Vector4 
Vector4::operator -= (const Vector4& V) {

  m_x = m_x - V.m_x;
  m_y = m_y - V.m_y;
  m_z = m_z - V.m_z;
  m_w = m_w - V.m_w;
  return *this;
}

Vector4 
Vector4::operator *= (const Vector4& V) {

  m_x = m_x * V.m_x;
  m_y = m_y * V.m_y;
  m_z = m_z * V.m_z;
  m_w = m_w * V.m_w;
  return *this;
}

Vector4 
Vector4::operator /= (const Vector4& V) {

  m_x = m_x / V.m_x;
  m_y = m_y / V.m_y;
  m_z = m_z / V.m_z;
  m_w = m_w / V.m_w;
  return *this;
}
