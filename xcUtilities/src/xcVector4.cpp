#include "xcVector4.h"

namespace xcEngineSDK {

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

  Vector4&
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

    return Vector4(m_x + V, 
                   m_y + V, 
                   m_z + V,
                   m_w + V);
  }

  Vector4
  Vector4::operator - (const float& V) {

    return Vector4(m_x - V, 
                   m_y - V, 
                   m_z - V,
                   m_w - V);
  }

  Vector4
  Vector4::operator * (const float& V) {

    return Vector4(m_x * V, 
                   m_y * V, 
                   m_z * V, 
                   m_w * V);
  }

  Vector4
  Vector4::operator / (const float& V) {

    return Vector4(m_x / V, 
                   m_y / V, 
                   m_z / V,
                   m_w / V);
  }

  Vector4
  Vector4::operator += (const Vector4& V) {

    *this = this->operator+(V);

    return *this;
  }

  Vector4
  Vector4::operator -= (const Vector4& V) {

    *this = this->operator-(V);

    return *this;
  }

  Vector4
  Vector4::operator*=(const Vector4& V) {

    *this = this->operator*(V);

    return *this;
  }


  Vector4&
  Vector4::normalize() {
    float Temp = this->magnitud();

    if (Temp != 0) {
      //divide the vector whit temp
      
      this->m_x = m_x / Temp;
      this->m_y = m_y / Temp;
      this->m_z = m_z / Temp;
      this->m_w = m_w / Temp;
      return *this; 
    }
    else {
      return *this;
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
  float 
  Vector4::dot(Vector4& VectorA, 
               Vector4& VectorB) {

    return (VectorA.m_x * VectorB.m_x) +
           (VectorA.m_y * VectorB.m_y) +
           (VectorA.m_z * VectorB.m_z) +
           (VectorA.m_w * VectorB.m_w);
  }

}

