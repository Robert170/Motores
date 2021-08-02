#include "xcVector4.h"

namespace xcEngineSDK {

  const Vector4 Vector4::ZERO = Vector4(0.f, 0.f, 0.f, 0.0f);
  const Vector4 Vector4::UNIT = Vector4(1.f, 1.f, 1.f, 1.0f);

  Vector4
  Vector4::operator + (const Vector4& V) {

    return Vector4(x + V.x, y + V.y, z + V.z, w + V.w);
  }

  Vector4
  Vector4::operator - (const Vector4& V) {

    return Vector4(x - V.x, y - V.y, z - V.z, w - V.w);
  }

  Vector4
  Vector4::operator * (const Vector4& V) {

    return Vector4(x * V.x, y * V.y, z * V.z, w * V.w);
  }

  Vector4&
  Vector4::operator = (const Vector4& V) {
    x = V.x;
    y = V.y;
    z = V.z;
    w = V.w;
    return *this;;
  }

  bool
  Vector4::operator == (const Vector4& V) {

    if (x == V.x && y == V.y && z == V.z && w == V.w) {
      return true;
    }
    else {
      return false;
    }
  }

  Vector4
  Vector4::operator + (const float& V) {

    return Vector4(x + V, 
                   y + V, 
                   z + V,
                   w + V);
  }

  Vector4
  Vector4::operator - (const float& V) {

    return Vector4(x - V, 
                   y - V, 
                   z - V,
                   w - V);
  }

  Vector4
  Vector4::operator * (const float& V) {

    return Vector4(x * V, 
                   y * V, 
                   z * V, 
                   w * V);
  }

  Vector4
  Vector4::operator / (const float& V) {

    return Vector4(x / V, 
                   y / V, 
                   z / V,
                   w / V);
  }

  Vector4
  Vector4::operator += (const Vector4& V) {

    *this = this->operator+(V);

    return *this;
  }

  Vector4
  Vector4::operator -= (const Vector4& V) {

    *this = this->operator-(V);

    return *this;
  }

  Vector4
  Vector4::operator*=(const Vector4& V) {

    *this = this->operator*(V);

    return *this;
  }


  Vector4&
  Vector4::normalize() {
    float Temp = this->magnitud();

    if (Temp != 0) {
      //divide the vector whit temp
      
      this->x = x / Temp;
      this->y = y / Temp;
      this->z = z / Temp;
      this->w = w / Temp;
      return *this; 
    }
    else {
      return *this;
    }
  }

  float
  Vector4::magnitud() {
    return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
  }

  Vector4
  Vector4::proyection(Vector4& VectorA, Vector4& VetorB) {

    return ((VectorA * VetorB) / powf(VetorB.magnitud(), 2) * VetorB);
  }
  float 
  Vector4::dot(Vector4& VectorB) {

    return (this->x * VectorB.x) +
           (this->y * VectorB.y) +
           (this->z * VectorB.z) +
           (this->w * VectorB.w);
  }

}

