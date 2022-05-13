#include "xcVectorI4.h"

using xcEngineSDK::VectorI4;

namespace xcEngineSDK {

  VectorI4
  VectorI4::operator + (const VectorI4& V) {

    return VectorI4(x + V.x, y + V.y, z + V.z, w + V.w);
  }

  VectorI4
  VectorI4::operator - (const VectorI4& V) {

    return VectorI4(x - V.x, y - V.y, z - V.z, w - V.w);
  }

  VectorI4
  VectorI4::operator * (const VectorI4& V) {

    return VectorI4(x * V.x, y * V.y, z * V.z, w * V.w);
  }

  VectorI4
  VectorI4::operator=(const VectorI4& V) {
    x = V.x;
    y = V.y;
    z = V.z;
    w = V.w;
    return *this;
  }

  bool
  VectorI4::operator == (const VectorI4& V) {

    if (x == V.x && y == V.y && z == V.z && w == V.w) {
      return true;
    }
    else {
      return false;
    }
  }

  VectorI4
  VectorI4::operator + (const int32& V) {

    return VectorI4(x + V, y + V, z + V, w + V);
  }

  VectorI4
  VectorI4::operator - (const int32& V) {

    return VectorI4(x - V, y - V, z - V, w - V);
  }

  VectorI4
  VectorI4::operator * (const int32& V) {

    return VectorI4(x * V, y * V, z * V, w * V);
  }

  VectorI4
  VectorI4::operator / (const int32& V) {

    return VectorI4(x / V, y / V, z / V, w / V);
  }

  VectorI4
  VectorI4::operator += (const VectorI4& V) {

    *this = this->operator+(V);

    return *this;
  }

  VectorI4
  VectorI4::operator -= (const VectorI4& V) {

    *this = this->operator-(V);

    return *this;
  }

  VectorI4
  VectorI4::operator *= (const VectorI4& V) {

    *this = this->operator*(V);

    return *this;
  }

  bool 
  VectorI4::operator!=(const VectorI4& V) {

    return !this->operator==(V);

  }

  VectorI4&
  VectorI4::normalize() {
    int32 Temp = this->magnitud();

    if (Temp != 0) {
      //divide the vector whit temp
      this->x = this->x / Temp;
      this->y = this->y / Temp;
      this->z = this->z / Temp;
      this->w = this->w / Temp;
      return *this;
    }
    else {
      return *this;
    }
  }

  int32
  VectorI4::magnitud() {
    return static_cast <int32>(sqrt(x * x + y * y + z * z + w * w));
  }

  VectorI4
  VectorI4::proyection(VectorI4& VectorA,
                       VectorI4& VetorB) {

    return ((VectorA * VetorB) / (VetorB.magnitud() * VetorB.magnitud()) * VetorB);
  }

  int32
  VectorI4::dot(VectorI4& VetorB) {

    return (this->x * VetorB.x) +
           (this->y * VetorB.y) +
           (this->z * VetorB.z) +
           (this->w * VetorB.z);
  }
}