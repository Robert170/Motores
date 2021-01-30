#pragma once

#include <iostream>

#include "xcPlatformTypes.h"

using std::memset;

using xcEngineSDK::int32;

class VectorIN
{
 public:
  VectorIN() = default;
	~VectorIN() = default;

  VectorIN(const int32& n) {
    Vector[&n];
    memset(&Vector, 0, sizeof(Vector));
  }

 private:
  
  int32 Vector;

};

