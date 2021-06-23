#include "xcVector3.h"

namespace xcEngineSDK {

  Vector3
  Vector3::operator + (const Vector3& V) {

    return Vector3(x + V.x, 
                   y + V.y, 
                   z + V.z);
  }

  Vector3
  Vector3::operator - (const Vector3& V) {

    return Vector3(x - V.x, 
                   y - V.y, 
                   z - V.z);
  }

  Vector3
  Vector3::operator * (const Vector3& V) {

    return Vector3(x * V.x, 
                   y * V.y, 
                   z * V.z);
  }

  Vector3&
  Vector3::operator=(const Vector3& V) {

    x = V.x;
    y = V.y;
    z = V.z;
    return *this;
  }

  bool
  Vector3::operator==(const Vector3& V) {

    if (x == V.x && y == V.y && z == V.z) {
      return true;
    }
    else {
      return false;
    }
  }

  Vector3
  Vector3::operator + (const float& V) {

    return Vector3(x + V, y + V, z + V);
  }

  Vector3
  Vector3::operator - (const float& V) {

    return Vector3(x - V, y - V, z - V);
  }

  Vector3
  Vector3::operator * (const float& V) {

    return Vector3(x * V, y * V, z * V);
  }

  Vector3
  Vector3::operator / (const float& V) {

    return Vector3(x / V, y / V, z / V);
  }

  Vector3
  Vector3::operator += (const Vector3& V) {

    *this = this->operator+(V);

    return *this;
  }

  Vector3
  Vector3::operator -= (const Vector3& V) {

    *this = this->operator-(V);

    return *this;
  }

  Vector3
  Vector3::operator *= (const Vector3& V) {

    *this = this->operator*(V);

    return *this;
  }


  Vector3&
  Vector3::normalize() {
    float Temp = this->magnitud();

    if (Temp != 0) {
      //divide the vector whit temp
      
      this->x = x / Temp;
      this->y = y / Temp;
      this->z= z / Temp;
      return *this; 
    }
    else {
      return *this;
    }
  }

  float
  Vector3::magnitud() {
    return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
  }

  Vector3
  Vector3::proyection(Vector3& VectorA, Vector3& VetorB) {
    return ((VectorA * VetorB) / powf(VetorB.magnitud(), 2) * VetorB);
  }

  float 
  Vector3::dot(Vector3& VetorB) {

    return (this->x * VetorB.x) +
           (this->y * VetorB.y) +
           (this->z * VetorB.z);
  }

  Vector3
  Vector3::cross(Vector3& VectorB) {

    return Vector3(((this->y * VectorB.z) - (this->z * VectorB.y)),
                   ((this->z * VectorB.x) - (this->x * VectorB.z)),
                   ((this->x * VectorB.y) - (this->y * VectorB.x)));
  }

  Vector3 
  Vector3::operator-() const {
    return Vector3(-x, -y, -z);
  }

  bool
  Vector3::isNearlyZero(float tolerance) const {

    
    return  Math::abs(x) < tolerance &&
            Math::abs(y) < tolerance &&
            Math::abs(z) < tolerance;
  }
}