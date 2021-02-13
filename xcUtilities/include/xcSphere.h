#pragma once

#include "xcVector3.h"

using xcEngineSDK::Vector3;

class Sphere {
public:
  Sphere();
  ~Sphere();

  Vector3 m_position;

  float m_radio;

 public:

  bool
  intersec(Vector3 vector);

};