#pragma once

class Degrees
{
public:
  Degrees() = default;
  Degrees(float angle) {
    m_angle = angle;
  }
  ~Degrees() = default;

  float
  getDegrees() {
    return m_angle;
  }

  float
  getDegreesIntoRadians() {
    return m_angle * 3.1416f / 180.0f;
  }

protected:

private:
  float m_angle = 0;

};