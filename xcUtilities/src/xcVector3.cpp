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

Vector3
Vector3::operator = (const Vector3& V) {

  m_x = V.m_x;
  m_y = V.m_y;
  m_z = V.m_z;
  return *this;
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
  
  m_x += V.m_x;
  m_y += V.m_y;
  m_z += V.m_z;
  return *this;
}

Vector3 
Vector3::operator -= (const Vector3& V) {
  
  m_x -= V.m_x;
  m_y -= V.m_y;
  m_z -= V.m_z;
  return *this;
}

Vector3 
Vector3::operator *= (const Vector3& V) {
  
  m_x *= V.m_x;
  m_y *= V.m_y;
  m_z *= V.m_z;
  return *this;
}

Vector3 
Vector3::operator /= (const Vector3& V) {

  m_x /= V.m_x;
  m_y /= V.m_y;
  m_z /= V.m_z;
  return *this;
}

Vector3
Vector3::normalize() {
  float Temp = this->magnitud();

  if (Temp != 0){
    //divide the vector whit temp
    return Vector3(m_x / Temp, m_y / Temp, m_z / Temp);
  }
  else {
    return Vector3();
  }
}

float 
Vector3::magnitud() {
  return sqrtf(powf(m_x, 2) + powf(m_y, 2) + powf(m_z, 2));
}

Vector3 
Vector3::proyection(Vector3& VectorA, Vector3& VetorB) {
  return ((VectorA * VetorB) / powf(VetorB.magnitud(), 2) * VetorB);
}
