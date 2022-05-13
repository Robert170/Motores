#include "xcDegrees.h"
#include "xcRadians.h"


namespace xcEngineSDK {


  Degrees::Degrees(Radians& angle) {

    m_angle = angle.getRadiansIntoDegrees();

  }

  Degrees::Degrees(Degrees& angle) {

    m_angle = angle.m_angle;

  }

  Degrees
  Degrees::operator+(const Degrees& Deg) const {

    return Degrees(m_angle + Deg.m_angle);
  }

  Degrees
  Degrees::operator-(const Degrees& Deg) const {

    return Degrees(m_angle - Deg.m_angle);
  }

  Degrees
  Degrees::operator*(const Degrees& Deg) const {

    return Degrees(m_angle * Deg.m_angle);
  }

  Degrees
  Degrees::operator/(const Degrees& Deg) const {

    return Degrees(m_angle / Deg.m_angle);
  }

  bool
  Degrees::operator==(const Degrees& Deg) const {

    if (m_angle == Deg.m_angle) {
      return true;
    }
    else {
      return false;
    }
  }

  Degrees&
  Degrees::operator+=(const Degrees& Deg) {

    m_angle += Deg.m_angle;
    return *this;
  }

  Degrees&
  Degrees::operator-=(const Degrees& Deg) {

    m_angle -= Deg.m_angle;
    return *this;
  }

  Degrees&
  Degrees::operator*=(const Degrees& Deg) {

    m_angle *= Deg.m_angle;
    return *this;
  }

  Degrees&
  Degrees::operator/=(const Degrees& Deg) {

    m_angle /= Deg.m_angle;
    return *this;
  }
}
