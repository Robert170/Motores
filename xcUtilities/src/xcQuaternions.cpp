#include "xcQuaternions.h"
#include "xcMath.h"


namespace xcEngineSDK {

  Quaternion 
  Quaternion::operator+(const Quaternion& quaternion) {

    return Quaternion(m_quaternionVector + quaternion.m_quaternionVector,
                      m_scalar + quaternion.m_scalar);
  }

  Quaternion 
  Quaternion::operator-(const Quaternion& quaternion) {
    
    return Quaternion(m_quaternionVector - quaternion.m_quaternionVector,
                      m_scalar - quaternion.m_scalar);
  }

  Quaternion 
  Quaternion::operator*(const Quaternion& quaternion) {

    return Quaternion(m_quaternionVector * quaternion.m_quaternionVector,
                      m_scalar * quaternion.m_scalar);
  }

  Quaternion 
  Quaternion::operator*(const float& scalar) {

    return Quaternion(m_quaternionVector * scalar,
                      scalar * m_scalar);
  }

  float 
  Quaternion::norm() {
    return Math::sqrt(Math::pow(m_scalar, 2) +
                      Math::pow(m_quaternionVector.m_x, 2)+
                      Math::pow(m_quaternionVector.m_y, 2)+
                      Math::pow(m_quaternionVector.m_z, 2));
  }

  Quaternion& 
  Quaternion::normalized() {

    *this = this->operator*=(norm());
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

    m_quaternionVector = quaternion.m_quaternionVector;
    m_scalar = quaternion.m_scalar;
    return *this;
  }

  bool 
  Quaternion::operator==(const Quaternion& quaternion) {

    if (m_quaternionVector == quaternion.m_quaternionVector &&
        m_scalar == quaternion.m_scalar) {

      return true;
    }

    return false;
  }
}