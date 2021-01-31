#pragma once

class Radians
{
 public:
  Radians() = default;
  Radians(float angle) {
    m_angle = angle;
  }
  ~Radians() = default;

  float
  getRadians() {
    return m_angle;
  }

  float 
  getRadiansIntoDegrees() {
    return m_angle * 180.0f / 3.1416f;
  }

 protected:

 private:
  float m_angle = 0;

};