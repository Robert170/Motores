#include "xcVectorI3.h"



namespace xcEngineSDK {

  const VectorI3 VectorI3::ZERO = VectorI3(0.f, 0.f, 0.f);
  const VectorI3 VectorI3::UNIT = VectorI3(1.f, 1.f, 1.f);

  VectorI3
  VectorI3::operator + (const VectorI3& V) {

    return VectorI3(x + V.x, y + V.y, z + V.z);
  }

  VectorI3
  VectorI3::operator - (const VectorI3& V) {

    return VectorI3(x - V.x, y - V.y, z - V.z);
  }

  VectorI3
  VectorI3::operator * (const VectorI3& V) {

    return VectorI3(x * V.x, y * V.y, z * V.z);
  }

  VectorI3&
  VectorI3::operator = (const VectorI3& V) {
    x = V.x;
    y = V.y;
    z = V.z;
    return *this;
  }

  bool
  VectorI3::operator == (const VectorI3& V) {

    if (x == V.x && y == V.y && z == V.z) {
      return true;
    }
    else {
      return false;
    }
  }

  VectorI3
  VectorI3::operator + (const int32& V) {

    return VectorI3(x + V, y + V, z + V);
  }

  VectorI3
  VectorI3::operator - (const int32& V) {

    return VectorI3(x - V, y - V, z - V);
  }

  VectorI3
  VectorI3::operator * (const int32& V) {

    return VectorI3(x * V, y * V, z * V);
  }

  VectorI3
  VectorI3::operator / (const int32& V) {

    return VectorI3(x / V, y / V, z / V);
  }

  VectorI3&
  VectorI3::operator += (const VectorI3& V) {

    *this = this->operator+(V);

    return *this;
  }

  VectorI3&
  VectorI3::operator -= (const VectorI3& V) {

    *this = this->operator-(V);

    return *this;
  }

  VectorI3&
  VectorI3::operator *= (const VectorI3& V) {

    *this = this->operator*(V);

    return *this;
  }


  bool 
  VectorI3::operator!=(const VectorI3& V) {

    return !this->operator==(V);
  }

  VectorI3&
  VectorI3::normalize() {
    int32 Temp = this->magnitud();

    if (Temp != 0) {
      //divide the vector whit temp
      this->x = this->x / Temp;
      this->y = this->y / Temp;
      this->z = this->z / Temp;
      return *this;
    }
    else {
      return *this;
    }
  }




  int32
  VectorI3::magnitud() {
    return static_cast <int32>(sqrt(x * x + y * y + z * z));
  }

  VectorI3
  VectorI3::proyection(VectorI3& VectorA,
                       VectorI3& VetorB) {
    return ((VectorA * VetorB) / (VetorB.magnitud() * VetorB.magnitud()) * VetorB);
  }

  int32
  VectorI3::dot(VectorI3& VetorB) {

    return (this->x * VetorB.x) +
           (this->y * VetorB.y) +
           (this->z * VetorB.z);
  }


  VectorI3
    VectorI3::cross(VectorI3& VectorB) {

    return VectorI3(((this->y * VectorB.z) - (this->z * VectorB.y)),
                   ((this->z * VectorB.x) - (this->x * VectorB.z)),
                   ((this->x * VectorB.y) - (this->y * VectorB.x)));
  }

  VectorI3 
  VectorI3::operator-() const {
    return VectorI3(-x, -y, -z);
  }

}
