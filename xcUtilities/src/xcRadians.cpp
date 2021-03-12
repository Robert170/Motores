#include "xcRadians.h"
#include "xcDegrees.h"

namespace xcEngineSDK {

  Radians::Radians(Degrees& angle) {

    m_angle = angle.getDegreesIntoRadians();
  }

  Radians::Radians(const Radians& angle) {
    m_angle = angle.m_angle;
  }

  Radians
  Radians::operator + (const Radians& Rad) {

    return Radians(m_angle + Rad.m_angle);
  }

  Radians
  Radians::operator - (const Radians& Rad) {

    return Radians(m_angle - Rad.m_angle);
  }

  Radians
  Radians::operator * (const Radians& Rad) {

    return Radians(m_angle * Rad.m_angle);
  }

  Radians
  Radians::operator / (const Radians& Rad) {

    return Radians(m_angle / Rad.m_angle);
  }


  bool
  Radians::operator == (const Radians& Rad) {

    if (m_angle == Rad.m_angle) {
      return true;
    }
    else {
      return false;
    }
  }


  Radians&
  Radians::operator += (const Radians& Rad) {

    m_angle += Rad.m_angle;
    return *this;
  }

  Radians&
  Radians::operator -= (const Radians& Rad) {

    m_angle -= Rad.m_angle;
    return *this;
  }

  Radians&
  Radians::operator *= (const Radians& Rad) {
    m_angle *= Rad.m_angle;
    return *this;
  }

  Radians&
  Radians::operator /= (const Radians& Rad) {
    m_angle /= Rad.m_angle;
    return *this;
  }

}