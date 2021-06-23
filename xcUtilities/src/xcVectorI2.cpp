#include "xcVectorI2.h"



namespace xcEngineSDK {

  VectorI2
  VectorI2::operator+(const VectorI2& V) {
    return VectorI2(x + V.x, y + V.y);
  }


  VectorI2
  VectorI2::operator-(const VectorI2& V) {

    return VectorI2(x - V.x, y - V.y);
  }

  VectorI2
  VectorI2::operator*(const VectorI2& V) {

    return VectorI2(x * V.x, y * V.y);
  }

  VectorI2
  VectorI2::operator=(const VectorI2& V) {
    x = V.x;
    y = V.y;
    return *this;
  }

  bool
  VectorI2::operator==(const VectorI2& V) {

    if (x == V.x && y == V.y) {
      return true;
    }
    else {
      return false;
    }
  }

  VectorI2
  VectorI2::operator+(const int32& V) {

    return VectorI2(x + V, y + V);
  }

  VectorI2
  VectorI2::operator-(const int32& V) {

    return VectorI2(x - V, y - V);
  }

  VectorI2
  VectorI2::operator*(const int32& V) {

    return VectorI2(x * V, y * V);
  }

  VectorI2
  VectorI2::operator/(const int32& V) {

    return VectorI2(x / V, y / V);
  }

  VectorI2&
  VectorI2::operator +=(const VectorI2& V) {

    x += V.x;
    y += V.y;
    return *this;
  }

  VectorI2&
  VectorI2::operator -= (const VectorI2& V)
  {
    x -= V.x;
    y -= V.y;
    return *this;
  }

  VectorI2&
  VectorI2::operator *= (const VectorI2& V) {

    x *= V.x;
    y *= V.y;
    return *this;
  }

  bool 
  VectorI2::operator!=(const VectorI2& V) {
    return !this->operator==(V);
  }

  VectorI2&
  VectorI2::normalize() {

    int32 Temp = this->magnitud();

    if (Temp != 0) {
      //divide the vector whit temp
      this->x = this->x / Temp;
      this->x = this->y / Temp;
      return *this;
    }
    else {
      return *this;
    }
  }

  int32
  VectorI2::magnitud() {
    return int32(sqrt(x * x + y * y));
  }

  VectorI2
  VectorI2::proyection(VectorI2& VectorA,
                       VectorI2& VetorB) {
    return VectorI2(((VectorA * VetorB) / (VetorB.magnitud() * VetorB.magnitud())
      * VetorB));
  }


  int32
  VectorI2::dot(VectorI2& VetorB) {

    return (this->x * VetorB.x) + (this->y * VetorB.y);
  }
}