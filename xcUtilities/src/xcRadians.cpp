#include "xcRadians.h"
#include "xcDegrees.h"

namespace xcEngineSDK {

  Radians::Radians(Degrees& angle) {
    m_angle = angle.getDegreesIntoRadians();
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

  bool
  Radians::operator == (const float& Value) {
    if (m_angle == Value) {
      return true;
    }
    else {
      return false;
    }
  }

  Radians
  Radians::operator + (const float& Value) {
    return Radians(m_angle + Value);
  }

  Radians
  Radians::operator - (const float& Value) {
    return Radians(m_angle - Value);
  }

  Radians
  Radians::operator * (const float& Value) {
    return Radians(m_angle * Value);
  }

  Radians
  Radians::operator / (const float& Value) {
    return Radians(m_angle / Value);
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

  Radians
  Radians::operator + (Degrees& Deg) {
    return Radians(m_angle + Deg.getDegreesIntoRadians());
  }

  Radians
  Radians::operator - (Degrees& Deg) {
    return Radians(m_angle - Deg.getDegreesIntoRadians());
  }

  Radians
  Radians::operator * (Degrees& Deg) {
    return Radians(m_angle * Deg.getDegreesIntoRadians());
  }

  Radians
  Radians::operator / (Degrees& Deg) {
    return Radians(m_angle / Deg.getDegreesIntoRadians());
  }

  bool
  Radians::operator == (Degrees& Deg) {
    if (m_angle == Deg.getDegreesIntoRadians()) {
      return true;
    }
    else {
      return false;
    }
  }

  Radians&
  Radians::operator += (Degrees& Deg) {
    m_angle += Deg.getDegreesIntoRadians();
    return *this;
  }

  Radians&
  Radians::operator -= (Degrees& Deg) {
    m_angle -= Deg.getDegreesIntoRadians();
    return *this;
  }

  Radians&
  Radians::operator *= (Degrees& Deg) {
    m_angle *= Deg.getDegreesIntoRadians();
    return *this;
  }

  Radians&
  Radians::operator /= (Degrees& Deg) {
    m_angle /= Deg.getDegreesIntoRadians();
    return *this;
  }
}