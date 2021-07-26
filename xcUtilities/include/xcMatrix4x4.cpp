#include "xcMatrix4x4.h"
namespace xcEngineSDK {

  const Matrix4x4 Matrix4x4::IDENTITY_MATRIX = Matrix4x4(1, 0, 0, 0,
                                                         0, 1, 0, 0, 
                                                         0, 0, 1, 0, 
                                                         0, 0, 0, 1);


  Matrix4x4::Matrix4x4(float _xx, float _yx, float _zx, float _wx,
                       float _xy, float _yy, float _zy, float _wy,
                       float _xz, float _yz, float _zz, float _wz,
                       float _xw, float _yw, float _zw, float _ww) {

    m_matrix[0].x = _xx;
    m_matrix[0].y = _xy;
    m_matrix[0].z = _xz;
    m_matrix[0].w = _xw;

    m_matrix[1].x = _yx;
    m_matrix[1].y = _yy;
    m_matrix[1].z = _yz;
    m_matrix[1].w = _yw;

    m_matrix[2].x = _zx;
    m_matrix[2].y = _zy;
    m_matrix[2].z = _zz;
    m_matrix[2].w = _zw;

    m_matrix[3].x = _wx;
    m_matrix[3].y = _wy;
    m_matrix[3].z = _wz;
    m_matrix[3].w = _ww;

  }

  Matrix4x4::Matrix4x4(Vector4 XVector,
                       Vector4 YVector,
                       Vector4 ZVector,
                       Vector4 WVector) {

    m_matrix[0] = XVector;
    m_matrix[1] = YVector;
    m_matrix[2] = ZVector;
    m_matrix[3] = WVector;
    
  }



  Matrix4x4&
  Matrix4x4::transpose() {

    std::swap(m_matrix[0].y, m_matrix[1].x);
    std::swap(m_matrix[0].z, m_matrix[2].x);
    std::swap(m_matrix[0].w, m_matrix[3].x);

    std::swap(m_matrix[1].z, m_matrix[2].y);
    std::swap(m_matrix[1].w, m_matrix[3].y);
    std::swap(m_matrix[2].w, m_matrix[3].z);
    return *this;
  }

  Matrix4x4
  Matrix4x4::inverse() {
    Matrix4x4 Res;

    // Check for zero scale matrix to invert
    if (getScaledAxis('x').isNearlyZero(Math::SMALL_NUMBER) &&
        getScaledAxis('y').isNearlyZero(Math::SMALL_NUMBER) &&
        getScaledAxis('z').isNearlyZero(Math::SMALL_NUMBER)) {
      Res = Matrix4x4::IDENTITY_MATRIX;
    }
    else {
      const float	Det = determinant();
      if (0.0f == Det) {
        Res = Matrix4x4::IDENTITY_MATRIX;
      } 
      else {
        Matrix4x4 Temp;

        Temp.m_matrix[0].x = m_matrix[2].z * m_matrix[3].w 
                             - m_matrix[2].w * m_matrix[3].z;
        Temp.m_matrix[0].y = m_matrix[1].z * m_matrix[3].w
                             - m_matrix[1].w * m_matrix[3].z;
        Temp.m_matrix[0].z = m_matrix[1].z * m_matrix[2].w 
                             - m_matrix[1].w * m_matrix[2].z;

        Temp.m_matrix[1].x = m_matrix[2].z * m_matrix[3].w 
                             - m_matrix[2].w * m_matrix[3].z;
        Temp.m_matrix[1].y = m_matrix[0].z * m_matrix[3].w 
                             - m_matrix[0].w * m_matrix[3].z;
        Temp.m_matrix[1].z = m_matrix[0].z * m_matrix[2].w 
                             - m_matrix[0].w * m_matrix[2].z;

        Temp.m_matrix[2].x = m_matrix[1].z * m_matrix[3].w 
                             - m_matrix[1].w * m_matrix[3].z;
        Temp.m_matrix[2].y = m_matrix[0].z * m_matrix[3].w
                             - m_matrix[0].w * m_matrix[3].z;
        Temp.m_matrix[2].z = m_matrix[0].z * m_matrix[1].w
                             - m_matrix[0].w * m_matrix[1].z;

        Temp.m_matrix[3].x = m_matrix[1].z * m_matrix[2].w 
                             - m_matrix[1].w * m_matrix[2].z;
        Temp.m_matrix[3].y = m_matrix[0].z * m_matrix[2].w 
                             - m_matrix[0].w * m_matrix[2].z;
        Temp.m_matrix[3].z = m_matrix[0].z * m_matrix[1].w 
                             - m_matrix[0].w * m_matrix[1].z;

        float Det0 = m_matrix[1].y * Temp.m_matrix[0].x - m_matrix[2].y 
                     * Temp.m_matrix[0].y + m_matrix[3].y * Temp.m_matrix[0].z;
        float Det1 = m_matrix[0].y * Temp.m_matrix[1].x - m_matrix[2].y 
                     * Temp.m_matrix[1].y + m_matrix[3].y * Temp.m_matrix[1].z;
        float Det2 = m_matrix[0].y * Temp.m_matrix[2].x - m_matrix[1].y 
                     * Temp.m_matrix[2].y + m_matrix[3].y * Temp.m_matrix[2].z;
        float Det3 = m_matrix[0].y * Temp.m_matrix[3].x - m_matrix[1].y 
                     * Temp.m_matrix[3].y + m_matrix[2].y * Temp.m_matrix[3].z;

        float Determinant = m_matrix[0].x * Det0 - m_matrix[1].x 
                            * Det1 + m_matrix[2].x * Det2 - m_matrix[3].x * Det3;
        const float	RDet = 1.0f / Determinant;

        Res.m_matrix[0].x = RDet * Det0;
        Res.m_matrix[0].y = -RDet * Det1;
        Res.m_matrix[0].z = RDet * Det2;
        Res.m_matrix[0].w = -RDet * Det3;
        Res.m_matrix[1].x = -RDet * (m_matrix[1].x * Temp.m_matrix[0].x -
                                     m_matrix[2].x * Temp.m_matrix[0].y +
                                     m_matrix[3].x * Temp.m_matrix[0].z);

        Res.m_matrix[1].y = RDet * (m_matrix[0].x * Temp.m_matrix[1].x -
                                    m_matrix[2].x * Temp.m_matrix[1].y +
                                    m_matrix[3].x * Temp.m_matrix[1].z);

        Res.m_matrix[1].z = -RDet * (m_matrix[0].x * Temp.m_matrix[2].x -
                                     m_matrix[1].x * Temp.m_matrix[2].y +
                                     m_matrix[3].x * Temp.m_matrix[2].z);

        Res.m_matrix[1].w = RDet * (m_matrix[0].x * Temp.m_matrix[3].x -
                                    m_matrix[1].x * Temp.m_matrix[3].y +
                                    m_matrix[2].x * Temp.m_matrix[3].z);

        Res.m_matrix[2].x = RDet * (m_matrix[1].x * (m_matrix[2].y * m_matrix[3].w 
                                    - m_matrix[2].w * m_matrix[3].y) -
                                    m_matrix[2].x * (m_matrix[1].y * m_matrix[3].w 
                                    - m_matrix[1].w * m_matrix[3].y) +
                                    m_matrix[3].x * (m_matrix[1].y * m_matrix[2].w 
                                    - m_matrix[1].w * m_matrix[2].y));

        Res.m_matrix[2].y = -RDet * (m_matrix[0].x * (m_matrix[2].y * m_matrix[3].w 
                                     - m_matrix[2].w * m_matrix[3].y) -
                                     m_matrix[2].x * (m_matrix[0].y * m_matrix[3].w 
                                     - m_matrix[0].w * m_matrix[3].y) +
                                     m_matrix[3].x * (m_matrix[0].y * m_matrix[2].w 
                                     - m_matrix[0].w * m_matrix[2].y));

        Res.m_matrix[2].z = RDet * (m_matrix[0].x * (m_matrix[1].y * m_matrix[3].w 
                                    - m_matrix[1].w * m_matrix[3].y) -
                                    m_matrix[1].x * (m_matrix[0].y * m_matrix[3].w 
                                    - m_matrix[0].w * m_matrix[3].y) +
                                    m_matrix[3].x * (m_matrix[0].y * m_matrix[1].w 
                                    - m_matrix[0].w * m_matrix[1].y));

        Res.m_matrix[2].w = -RDet * (m_matrix[0].x * (m_matrix[1].y * m_matrix[2].w 
                                     - m_matrix[1].w * m_matrix[2].y) -
                                     m_matrix[1].x * (m_matrix[0].y * m_matrix[2].w 
                                     - m_matrix[0].w * m_matrix[2].y) +
                                     m_matrix[2].x * (m_matrix[0].y * m_matrix[1].w 
                                     - m_matrix[0].w * m_matrix[1].y));

        Res.m_matrix[3].x = -RDet * (m_matrix[1].x * (m_matrix[2].y * m_matrix[3].z 
                                     - m_matrix[2].z * m_matrix[3].y) -
                                     m_matrix[2].x * (m_matrix[1].y * m_matrix[3].z 
                                     - m_matrix[1].z * m_matrix[3].y) +
                                     m_matrix[3].x * (m_matrix[1].y * m_matrix[2].z 
                                     - m_matrix[1].z * m_matrix[2].y));

        Res.m_matrix[3].y = RDet * (m_matrix[0].x * (m_matrix[2].y * m_matrix[3].z 
                                    - m_matrix[2].z * m_matrix[3].y) -
                                    m_matrix[2].x * (m_matrix[0].y * m_matrix[3].z 
                                    - m_matrix[0].z * m_matrix[3].y) +
                                    m_matrix[3].x * (m_matrix[0].y * m_matrix[2].z 
                                    - m_matrix[0].z * m_matrix[2].y));

        Res.m_matrix[3].z = -RDet * (m_matrix[0].x * (m_matrix[1].y * m_matrix[3].z 
                                     - m_matrix[1].z * m_matrix[3].y) -
                                     m_matrix[1].x * (m_matrix[0].y * m_matrix[3].z 
                                     - m_matrix[0].z * m_matrix[3].y) +
                                     m_matrix[3].x * (m_matrix[0].y * m_matrix[1].z 
                                     - m_matrix[0].z * m_matrix[1].y));

        Res.m_matrix[3].w = RDet * (m_matrix[0].x * (m_matrix[1].y * m_matrix[2].z 
                                    - m_matrix[1].z * m_matrix[2].y) -
                                    m_matrix[1].x * (m_matrix[0].y * m_matrix[2].z 
                                    - m_matrix[0].z * m_matrix[2].y) +
                                    m_matrix[2].x * (m_matrix[0].y * m_matrix[1].z 
                                    - m_matrix[0].z * m_matrix[1].y));
      }
    }
   
    return Res;
  }

  float 
  Matrix4x4::determinant() {
   
    return	m_matrix[0].x * (
      m_matrix[1].y * (m_matrix[2].z * m_matrix[3].w 
                       - m_matrix[2].w * m_matrix[3].z) -
      m_matrix[2].y * (m_matrix[1].z * m_matrix[3].w 
                         - m_matrix[1].w * m_matrix[3].z) +
      m_matrix[3].y * (m_matrix[1].z * m_matrix[2].w 
                         - m_matrix[1].w * m_matrix[2].z)) -
      m_matrix[1].x * (
        m_matrix[0].y * (m_matrix[2].z * m_matrix[3].w 
                           - m_matrix[2].w * m_matrix[3].z) -
        m_matrix[2].y * (m_matrix[0].z * m_matrix[3].w 
                           - m_matrix[0].w * m_matrix[3].z) +
        m_matrix[3].y * (m_matrix[0].z * m_matrix[2].w 
                           - m_matrix[0].w * m_matrix[2].z)) +
      m_matrix[2].x * (
        m_matrix[0].y * (m_matrix[1].z * m_matrix[3].w 
                         - m_matrix[1].w * m_matrix[3].z) -
        m_matrix[1].y * (m_matrix[0].z * m_matrix[3].w 
                         - m_matrix[0].w * m_matrix[3].z) +
        m_matrix[3].y * (m_matrix[0].z * m_matrix[1].w 
                           - m_matrix[0].w * m_matrix[1].z)) -
      m_matrix[3].x * (
        m_matrix[0].y * (m_matrix[1].z * m_matrix[2].w 
                         - m_matrix[1].w * m_matrix[2].z) -
        m_matrix[1].y * (m_matrix[0].z * m_matrix[2].w 
                         - m_matrix[0].w * m_matrix[2].z) +
        m_matrix[2].y * (m_matrix[0].z * m_matrix[1].w 
                           - m_matrix[0].w * m_matrix[1].z));
  }

  Matrix4x4
  Matrix4x4::operator+(const Matrix4x4& M) {

    Vector4 x = m_matrix[0] + M.m_matrix[0];
    Vector4 y = m_matrix[1] + M.m_matrix[1];
    Vector4 z = m_matrix[2] + M.m_matrix[2];
    Vector4 w = m_matrix[3] + M.m_matrix[3];

    return Matrix4x4(x, y, z, w);
  }

  Matrix4x4
  Matrix4x4::operator-(const Matrix4x4& M) {

    Vector4 x = m_matrix[0] - M.m_matrix[0];
    Vector4 y = m_matrix[1] - M.m_matrix[1];
    Vector4 z = m_matrix[2] - M.m_matrix[2];
    Vector4 w = m_matrix[3] - M.m_matrix[3];

    return Matrix4x4(x, y, z, w);
  }

  Matrix4x4
  Matrix4x4::operator*(const Matrix4x4& M) {

    
    Matrix4x4 Temp = M;

    Temp.transpose();
    

    return Matrix4x4(m_matrix[0].dot(Temp.m_matrix[0]),
                     m_matrix[1].dot(Temp.m_matrix[0]), 
                     m_matrix[2].dot(Temp.m_matrix[0]), 
                     m_matrix[3].dot(Temp.m_matrix[0]),
                     m_matrix[0].dot(Temp.m_matrix[1]), 
                     m_matrix[1].dot(Temp.m_matrix[1]), 
                     m_matrix[2].dot(Temp.m_matrix[1]), 
                     m_matrix[3].dot(Temp.m_matrix[1]),
                     m_matrix[0].dot(Temp.m_matrix[2]), 
                     m_matrix[1].dot(Temp.m_matrix[2]), 
                     m_matrix[2].dot(Temp.m_matrix[2]), 
                     m_matrix[3].dot(Temp.m_matrix[2]),
                     m_matrix[0].dot(Temp.m_matrix[3]), 
                     m_matrix[1].dot(Temp.m_matrix[3]), 
                     m_matrix[2].dot(Temp.m_matrix[3]), 
                     m_matrix[3].dot(Temp.m_matrix[3]));
  }

  Matrix4x4& 
  Matrix4x4::operator=(const Matrix4x4& M) {

    m_matrix[0] = M.m_matrix[0];
    m_matrix[1] = M.m_matrix[1];
    m_matrix[2] = M.m_matrix[2];
    m_matrix[3] = M.m_matrix[3];
    return *this;
  }

  bool Matrix4x4::operator==(const Matrix4x4& M) {
    if (m_matrix[0] == M.m_matrix[0] &&
        m_matrix[1] == M.m_matrix[1] &&
        m_matrix[2] == M.m_matrix[2] &&
        m_matrix[3] == M.m_matrix[3]) {

      return true;
    }
    else {
      return false;
    }
  }

  Matrix4x4& 
  Matrix4x4::operator+=(const Matrix4x4& M) {

    *this = this->operator+(M);

    return *this;
  }

  Matrix4x4& 
  Matrix4x4::operator-=(const Matrix4x4& M) {

    *this = this->operator-(M);

    return *this;
  }

  Matrix4x4& 
  Matrix4x4::operator*=(const Matrix4x4& M) {
    *this = this->operator*(M);

    return *this;
  }

  bool 
  Matrix4x4::operator!=(const Matrix4x4& M) {

    return !this->operator==(M);

  }

  Matrix4x4
  Matrix4x4::lookAtLH(Vector3& Eye,
                      Vector3& At,
                      Vector3& Up) {

    Vector3 zAxis = At - Eye;
    zAxis.normalize();

    Vector3 xAxis = Up.cross(zAxis);
    xAxis.normalize();

    Vector3 yAxis = zAxis.cross(xAxis);

    Vector3 negativeEye = -Eye;
   

    return Matrix4x4(xAxis.x, xAxis.y, xAxis.z, xAxis.dot(negativeEye),
                     yAxis.x, yAxis.y, yAxis.z, yAxis.dot(negativeEye),
                     zAxis.x, zAxis.y, zAxis.z, zAxis.dot(negativeEye),
                     0, 0, 0, 1);
  }
  

  Matrix4x4 
  Matrix4x4::perspectiveFovLH(float& Fov,
                              float& Height,
                              float& Width,
                              float& Near,
                              float& Far) {
    
    float yScale = Math::cot(Fov / 2);
    float xScale = yScale / (Width / Height);

    return Matrix4x4(Vector4(xScale, 0.f, 0.f, 0.f),
                     Vector4(0.f, yScale, 0.f, 0.f),
                     Vector4(0.f, 0.f, Far / (Far - Near), 1.f),
                     Vector4(0.f, 0.f, -Near * Far / (Far - Near), 0.f));
  }


  Matrix4x4
  Matrix4x4::quatToMatRot(Quaternion& Quat) {

    Matrix4x4 rotationMatrix = Matrix4x4::IDENTITY_MATRIX;

    rotationMatrix.m_matrix[0].x = 1.0f - 2.0f * (Math::pow(Quat.y, 2.0f)
                                                  + Math::pow(Quat.z, 2.0f));

    rotationMatrix.m_matrix[0].y = 2.0f * (Quat.x * Quat.y
                                           - Quat.w * Quat.z);

    rotationMatrix.m_matrix[0].z = 2.0f * (Quat.x * Quat.z
                                           + Quat.w * Quat.y);

    rotationMatrix.m_matrix[1].x = 2.0f * (Quat.x * Quat.y
                                           + Quat.w * Quat.z);

    rotationMatrix.m_matrix[1].y = 1.0f - 2.0f * (Math::pow(Quat.x, 2.0f)
                                                  + Math::pow(Quat.z, 2.0f));

    rotationMatrix.m_matrix[1].z = 2.0f * (Quat.y * Quat.z
                                           - Quat.w * Quat.x);

    rotationMatrix.m_matrix[2].x = 2.0f * (Quat.x * Quat.z
                                           - Quat.w * Quat.y);

    rotationMatrix.m_matrix[2].y = 2.0f * (Quat.y * Quat.z
                                           + Quat.w * Quat.x);

    rotationMatrix.m_matrix[2].z = 1.0f - 2.0f * (Math::pow(Quat.x, 2.0f)
                                                  + Math::pow(Quat.y, 2.0f));

    rotationMatrix.m_matrix[3].w = 1.0f;
    return rotationMatrix;

  }

  Vector3 
  Matrix4x4::getScaledAxis(char Axis) const {
    switch (Axis)
    {
    case 'x':
      return Vector3(m_matrix[0].x, m_matrix[0].y, m_matrix[0].z);

    case 'y':
      return Vector3(m_matrix[1].x, m_matrix[1].y, m_matrix[1].z);

    case 'z':
      return Vector3(m_matrix[2].x, m_matrix[2].y, m_matrix[2].z);

    default:
      break;
    }

    return Vector3(0.0f, 0.0f, 0.0f);
  }
}
