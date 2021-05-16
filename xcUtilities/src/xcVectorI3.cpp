#include "xcVectorI3.h"



namespace xcEngineSDK {
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

  VectorI3&
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

  VectorI3
  VectorI3::operator / (const int32& V) {

    return VectorI3(m_x / V, m_y / V, m_z / V);
  }

  VectorI3&
  VectorI3::operator += (const VectorI3& V) {

    *this = this->operator+(V);

    return *this;
  }

  VectorI3&
  VectorI3::operator -= (const VectorI3& V) {

    *this = this->operator-(V);

    return *this;
  }

  VectorI3&
  VectorI3::operator *= (const VectorI3& V) {

    *this = this->operator*(V);

    return *this;
  }


  bool 
  VectorI3::operator!=(const VectorI3& V) {

    return !this->operator==(V);
  }

  VectorI3&
  VectorI3::normalize() {
    int32 Temp = this->magnitud();

    if (Temp != 0) {
      //divide the vector whit temp
      this->m_x = this->m_x / Temp;
      this->m_y = this->m_y / Temp;
      this->m_z = this->m_z / Temp;
      return *this;
    }
    else {
      return *this;
    }
  }




  int32
  VectorI3::magnitud() {
    return static_cast <int32>(sqrt(m_x * m_x + m_y * m_y + m_z * m_z));
  }

  VectorI3
  VectorI3::proyection(VectorI3& VectorA,
                       VectorI3& VetorB) {
    return ((VectorA * VetorB) / (VetorB.magnitud() * VetorB.magnitud()) * VetorB);
  }

  int32
  VectorI3::dot(VectorI3& VetorB) {

    return (this->m_x * VetorB.m_x) +
           (this->m_y * VetorB.m_y) +
           (this->m_z * VetorB.m_z);
  }


  VectorI3
    VectorI3::cross(VectorI3& VectorB) {

    return VectorI3(((this->m_y * VectorB.m_z) - (this->m_z * VectorB.m_y)),
                   ((this->m_z * VectorB.m_x) - (this->m_x * VectorB.m_z)),
                   ((this->m_x * VectorB.m_y) - (this->m_y * VectorB.m_x)));
  }

  VectorI3 
  VectorI3::operator-() const {
    return VectorI3(-m_x, -m_y, -m_z);
  }

}
