#include "xcVector3.h"

namespace xcEngineSDK {

  Vector3
  Vector3::operator + (const Vector3& V) {

    return Vector3(m_x + V.m_x, 
                   m_y + V.m_y, 
                   m_z + V.m_z);
  }

  Vector3
  Vector3::operator - (const Vector3& V) {

    return Vector3(m_x - V.m_x, 
                   m_y - V.m_y, 
                   m_z - V.m_z);
  }

  Vector3
  Vector3::operator * (const Vector3& V) {

    return Vector3(m_x * V.m_x, 
                   m_y * V.m_y, 
                   m_z * V.m_z);
  }

  Vector3&
  Vector3::operator=(const Vector3& V) {

    m_x = V.m_x;
    m_y = V.m_y;
    m_z = V.m_z;
    return *this;
  }

  bool
  Vector3::operator==(const Vector3& V) {

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

    *this = this->operator+(V);

    return *this;
  }

  Vector3
  Vector3::operator -= (const Vector3& V) {

    *this = this->operator-(V);

    return *this;
  }

  Vector3
  Vector3::operator *= (const Vector3& V) {

    *this = this->operator*(V);

    return *this;
  }


  Vector3&
  Vector3::normalize() {
    float Temp = this->magnitud();

    if (Temp != 0) {
      //divide the vector whit temp
      
      this->m_x = m_x / Temp;
      this->m_y = m_y / Temp;
      this->m_z= m_z / Temp;
      return *this; 
    }
    else {
      return *this;
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

  float 
  Vector3::dot(Vector3& VetorB) {

    return (this->m_x * VetorB.m_x) +
           (this->m_y * VetorB.m_y) +
           (this->m_z * VetorB.m_z);
  }

  Vector3
  Vector3::cross(Vector3& VectorB) {

    return Vector3(((this->m_y * VectorB.m_z) - (this->m_z * VectorB.m_y)),
                   ((this->m_z * VectorB.m_x) - (this->m_x * VectorB.m_z)),
                   ((this->m_x * VectorB.m_y) - (this->m_y * VectorB.m_x)));
  }

  Vector3 
  Vector3::operator-() const {
    return Vector3(-m_x, -m_y, -m_z);
  }
}