#include "xcQuaternions.h"
#include "xcMath.h"


namespace xcEngineSDK {

  const Quaternion Quaternion::IDENTITY = Quaternion(0.f, 0.f, 0.f, 1.f);

  Quaternion 
  Quaternion::operator+(const Quaternion& quaternion) {

    return Quaternion(x + quaternion.x,
                      y + quaternion.y,
                      z + quaternion.z,
                      w + quaternion.w);
  }

  Quaternion 
  Quaternion::operator-(const Quaternion& quaternion) {
    
    return Quaternion(x - quaternion.x,
                      y - quaternion.y,
                      z - quaternion.z,
                      w - quaternion.w);
  }

  Quaternion 
  Quaternion::operator*(const Quaternion& quaternion) {

    Vector3 VecA(x, y, z);
    Vector3 VecB(quaternion.x, quaternion.y, quaternion.z);
    Vector3 VecResult = (VecB * w) + (VecA * quaternion.w) + VecA.cross(VecB);

    float tempW = (w * quaternion.w) - VecA.dot(VecB);
                                            
    return Quaternion(VecResult.x, VecResult.y, VecResult.z, tempW);
  }

  Quaternion 
  Quaternion::operator*(const float& scalar) {

    return Quaternion(scalar * x,
                      scalar * y,
                      scalar * z,
                      scalar * w);
  }

  //MAGNITUD
  float 
  Quaternion::magnitud() {
    return Math::sqrt(Math::pow(w, 2) +
                      Math::pow(x, 2) +
                      Math::pow(y, 2) +
                      Math::pow(z, 2));
  }

  Quaternion& 
  Quaternion::normalized() {

    *this = this->operator*=(magnitud());
    return *this;
  }

  Quaternion& 
  Quaternion::operator+=(const Quaternion& quaternion) {

    *this = this->operator+(quaternion);
    return *this;
  }

  Quaternion& 
  Quaternion::operator-=(const Quaternion& quaternion) {

    *this = this->operator-(quaternion);
    return *this;
  }

  Quaternion& 
  Quaternion::operator*=(const Quaternion& quaternion) {

    *this = this->operator*(quaternion);
    return *this;
  }

  Quaternion& 
  Quaternion::operator*=(const float& scalar) {

    *this = this->operator*(scalar);
    return *this;
  }

  Quaternion& 
  Quaternion::operator=(const Quaternion& quaternion) {

    x = quaternion.x;
    y = quaternion.y;
    z = quaternion.z;
    w = quaternion.w;
    return *this;
  }

  bool 
  Quaternion::operator==(const Quaternion& quaternion) {

    if (x == quaternion.x &&
        y == quaternion.y &&
        z == quaternion.z &&
        w == quaternion.w) {

      return true;
    }

    return false;
  }
}