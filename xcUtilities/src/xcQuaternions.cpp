#include "xcQuaternions.h"
#include "xcMath.h"


namespace xcEngineSDK {

  Quaternion 
  Quaternion::operator+(const Quaternion& quaternion) {

    return Quaternion(m_x + quaternion.m_x,
                      m_y + quaternion.m_y,
                      m_z + quaternion.m_z,
                      m_w + quaternion.m_w);
  }

  Quaternion 
  Quaternion::operator-(const Quaternion& quaternion) {
    
    return Quaternion(m_x - quaternion.m_x,
                      m_y - quaternion.m_y,
                      m_z - quaternion.m_z,
                      m_w - quaternion.m_w);
  }

  Quaternion 
  Quaternion::operator*(const Quaternion& quaternion) {

    Vector3 VecA(m_x, m_y, m_z);
    Vector3 VecB(quaternion.m_x, quaternion.m_y, quaternion.m_z);
    Vector3 VecResult = (VecB * m_w) + (VecA * quaternion.m_w) + VecA.cross(VecB);

    float tempW = (m_w * quaternion.m_w) - VecA.dot(VecB);
                                            
    return Quaternion(VecResult.m_x, VecResult.m_y, VecResult.m_z, m_w);
  }

  Quaternion 
  Quaternion::operator*(const float& scalar) {

    return Quaternion(scalar * m_x,
                      scalar * m_y,
                      scalar * m_z,
                      scalar * m_w);
  }

  //MAGNITUD
  float 
  Quaternion::magnitud() {
    return Math::sqrt(Math::pow(m_w, 2) +
                      Math::pow(m_x, 2) +
                      Math::pow(m_y, 2) +
                      Math::pow(m_z, 2));
  }

  Quaternion& 
  Quaternion::normalized() {

    *this = this->operator*=(magnitud());
    return *this;
  }

  Quaternion& 
  Quaternion::operator+=(const Quaternion& quaternion) {

    *this = this->operator+(quaternion);
    return *this;
  }

  Quaternion& 
  Quaternion::operator-=(const Quaternion& quaternion) {

    *this = this->operator-(quaternion);
    return *this;
  }

  Quaternion& 
  Quaternion::operator*=(const Quaternion& quaternion) {

    *this = this->operator*(quaternion);
    return *this;
  }

  Quaternion& 
  Quaternion::operator*=(const float& scalar) {

    *this = this->operator*(scalar);
    return *this;
  }

  Quaternion& 
  Quaternion::operator=(const Quaternion& quaternion) {

    m_x = quaternion.m_x;
    m_y = quaternion.m_y;
    m_z = quaternion.m_z;
    m_w = quaternion.m_w;
    return *this;
  }

  bool 
  Quaternion::operator==(const Quaternion& quaternion) {

    if (m_x == quaternion.m_x &&
        m_y == quaternion.m_y &&
        m_z == quaternion.m_z &&
        m_w == quaternion.m_w) {

      return true;
    }

    return false;
  }
}