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

Vector4 
Vector4::operator = (const Vector4& V) {
  m_x = V.m_x;
  m_y = V.m_y;
  m_z = V.m_z;
  m_w = V.m_w;
  return *this;;
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
  
  m_x += V.m_x;
  m_y += V.m_y;
  m_z += V.m_z;
  m_w += V.m_w;
  return *this;
}

Vector4 
Vector4::operator -= (const Vector4& V) {

  m_x -= V.m_x;
  m_y -= V.m_y;
  m_z -= V.m_z;
  m_w -= V.m_w;
  return *this;
}

Vector4 
Vector4::operator *= (const Vector4& V) {

  m_x *= V.m_x;
  m_y *= V.m_y;
  m_z *= V.m_z;
  m_w *= V.m_w;
  return *this;
}

Vector4 
Vector4::operator /= (const Vector4& V) {

  m_x /= V.m_x;
  m_y /= V.m_y;
  m_z /= V.m_z;
  m_w /= V.m_w;
  return *this;
}

Vector4 
Vector4::normalize() {
  float Temp = this->magnitud();

  if (Temp != 0) {
    //divide the vector whit temp
    return Vector4(m_x / Temp, m_y / Temp, m_z / Temp, m_w / Temp);
  }
  else {
    return Vector4();
  }
}

float 
Vector4::magnitud() {
  return sqrtf(powf(m_x, 2) + powf(m_y, 2) + powf(m_z, 2));
}

Vector4 
Vector4::proyection(Vector4& VectorA, Vector4& VetorB) {

  return ((VectorA * VetorB) / powf(VetorB.magnitud(), 2) * VetorB);
}
