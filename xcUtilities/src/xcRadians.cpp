#include "xcRadians.h"

Radians 
Radians::operator + (const Radians& Rad) {
  return m_angle + Rad.m_angle;
}

Radians 
Radians::operator - (const Radians& Rad) {
  return m_angle - Rad.m_angle;
}

Radians 
Radians::operator * (const Radians& Rad) {
  return m_angle * Rad.m_angle;
}

Radians 
Radians::operator / (const Radians& Rad) {
  return m_angle / Rad.m_angle;
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
  return m_angle + Value;
}

Radians 
Radians::operator - (const float& Value) {
  return m_angle - Value;
}

Radians 
Radians::operator * (const float& Value) {
  return m_angle * Value;
}

Radians 
Radians::operator / (const float& Value) {
  return m_angle / Value;
}


Radians 
Radians::operator += (const Radians& Rad) {
  m_angle += Rad.m_angle;
  return *this;
}

Radians 
Radians::operator -= (const Radians& Rad) {
  m_angle -= Rad.m_angle;
  return *this;
}

Radians 
Radians::operator *= (const Radians& Rad) {
  m_angle *= Rad.m_angle;
  return *this;
}

Radians 
Radians::operator /= (const Radians& Rad) {
  m_angle /= Rad.m_angle;
  return *this;
}
