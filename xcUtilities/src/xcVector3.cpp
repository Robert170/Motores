#include "xcVector3.h"

Vector3 
Vector3::operator + (const Vector3& V) {
  
  return Vector3(m_x + V.m_x, m_y + V.m_y, m_z + V.m_z);
}

Vector3 
Vector3::operator - (const Vector3& V) {
  
  return Vector3(m_x - V.m_x, m_y + V.m_y, m_z + V.m_z);
}

Vector3 
Vector3::operator * (const Vector3& V) {
  
  return Vector3(m_x * V.m_x, m_y * V.m_y, m_z * V.m_z);
}

Vector3 
Vector3::operator / (const Vector3& V) {

  return Vector3(m_x / V.m_x, m_y / V.m_y, m_z / V.m_z);
}

bool 
Vector3::operator == (const Vector3& V) {
  
  if (m_x == V.m_x && m_y == V.m_y && m_z == V.m_z) {
    return true;
  }
  else {
    return false;
  }
}

Vector3 
Vector3::operator + (const float& V) {

  return Vector3(m_x + V, m_y + V, m_z + V);
}

Vector3 
Vector3::operator - (const float& V) {
  
  return Vector3(m_x - V, m_y - V, m_z - V);
}

Vector3 
Vector3::operator * (const float& V) {
  
  return Vector3(m_x * V, m_y * V, m_z * V);
}

Vector3 
Vector3::operator / (const float& V) {
  
  return Vector3(m_x / V, m_y / V, m_z / V);
}

Vector3 
Vector3::operator += (const Vector3& V) {
  
  m_x = m_x + V.m_x;
  m_y = m_y + V.m_y;
  m_z = m_z + V.m_z;
  return *this;
}

Vector3 
Vector3::operator -= (const Vector3& V) {
  
  m_x = m_x - V.m_x;
  m_y = m_y - V.m_y;
  m_z = m_z - V.m_z;
  return *this;
}

Vector3 
Vector3::operator *= (const Vector3& V) {
  
  m_x = m_x * V.m_x;
  m_y = m_y * V.m_y;
  m_z = m_z * V.m_z;
  return *this;
}

Vector3 
Vector3::operator /= (const Vector3& V) {

  m_x = m_x / V.m_x;
  m_y = m_y / V.m_y;
  m_z = m_z / V.m_z;
  return *this;
}
