#include "xcDegrees.h"

Degrees 
Degrees::operator+(const Degrees& Deg) {
  return Degrees(m_angle + Deg.m_angle);
}

Degrees 
Degrees::operator - (const Degrees& Deg) {
  return Degrees(m_angle - Deg.m_angle);
}

Degrees 
Degrees::operator * (const Degrees& Deg) {
  return Degrees(m_angle * Deg.m_angle);
}

Degrees 
Degrees::operator / (const Degrees& Deg) {
  return Degrees(m_angle / Deg.m_angle);
}

bool 
Degrees::operator == (const Degrees& Deg) {
  if (m_angle == Deg.m_angle) {
    return true;
  }
  else {
    return false;
  }
}
 
bool 
Degrees::operator == (const float& Value) {
  if (m_angle == Value) {
    return true;
  }
  else {
    return false;
  }
}

Degrees 
Degrees::operator + (const float& Value) {
  return Degrees(m_angle + Value);
}

Degrees 
Degrees::operator - (const float& Value) {
  return Degrees(m_angle - Value);
}

Degrees 
Degrees::operator*(const float& Value) {
  return Degrees(m_angle * Value);
}

Degrees 
Degrees::operator / (const float& Value) {
  return Degrees(m_angle / Value);
}

Degrees 
Degrees::operator += (const Degrees& Deg) {
  m_angle += Deg.m_angle;
  return *this;
}

Degrees 
Degrees::operator -= (const Degrees& Deg) {
  m_angle -= Deg.m_angle;
  return *this;
}

Degrees 
Degrees::operator *= (const Degrees& Deg) {
  m_angle *= Deg.m_angle;
  return *this;
}

Degrees 
Degrees::operator /= (const Degrees& Deg) {
  m_angle /= Deg.m_angle;
  return *this;
}
