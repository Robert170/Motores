#include "xcQuaternions.h"


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
}