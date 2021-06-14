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

    m_matrix[0].m_x = _xx;
    m_matrix[0].m_y = _xy;
    m_matrix[0].m_z = _xz;
    m_matrix[0].m_w = _xw;

    m_matrix[1].m_x = _yx;
    m_matrix[1].m_y = _yy;
    m_matrix[1].m_z = _yz;
    m_matrix[1].m_w = _yw;

    m_matrix[2].m_x = _zx;
    m_matrix[2].m_y = _zy;
    m_matrix[2].m_z = _zz;
    m_matrix[2].m_w = _zw;

    m_matrix[3].m_x = _wx;
    m_matrix[3].m_y = _wy;
    m_matrix[3].m_z = _wz;
    m_matrix[3].m_w = _ww;

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

    std::swap(m_matrix[0].m_y, m_matrix[1].m_x);
    std::swap(m_matrix[0].m_z, m_matrix[2].m_x);
    std::swap(m_matrix[0].m_w, m_matrix[3].m_x);

    std::swap(m_matrix[1].m_z, m_matrix[2].m_y);
    std::swap(m_matrix[1].m_w, m_matrix[3].m_y);
    std::swap(m_matrix[2].m_w, m_matrix[3].m_z);
    return *this;
  }

  Matrix4x4&
  Matrix4x4::inverse() {


    return *this;
  }

  float 
  Matrix4x4::determinant(const Matrix4x4& matrix) {
    
    


    return 0.0f;
  }

  float 
  Matrix4x4::cofactor(const Matrix3x3& matrix) {
    return 0.0f;
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
    
    /*return Matrix4x4(xAxis.m_x, yAxis.m_x, zAxis.m_x, 0,
                     xAxis.m_y, yAxis.m_y, zAxis.m_y, 0,
                     xAxis.m_z, yAxis.m_z, zAxis.m_z, 0,
                     xAxis.dot(xAxis, negativeEye), yAxis.dot(yAxis, negativeEye), 
                     zAxis.dot(zAxis, negativeEye), 1);*/

    return Matrix4x4(xAxis.m_x, xAxis.m_y, xAxis.m_z, xAxis.dot(negativeEye),
                     yAxis.m_x, yAxis.m_y, yAxis.m_z, yAxis.dot(negativeEye),
                     zAxis.m_x, zAxis.m_y, zAxis.m_z, zAxis.dot(negativeEye),
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

    Matrix4x4 rotationMatrix;
    rotationMatrix.m_matrix[0].m_x = 1 - 2 * (Math::pow(Quat.m_y, 2) 
                                             + Math::pow(Quat.m_z, 2));

    rotationMatrix.m_matrix[0].m_y = 2 * (Quat.m_x * Quat.m_y 
                                          - Quat.m_w * Quat.m_z);

    rotationMatrix.m_matrix[0].m_z = 2 * (Quat.m_x * Quat.m_z 
                                          + Quat.m_w * Quat.m_y);

    rotationMatrix.m_matrix[1].m_x = 2 * (Quat.m_x * Quat.m_y 
                                          + Quat.m_w * Quat.m_z);

    rotationMatrix.m_matrix[1].m_y = 1 - 2 * (Math::pow(Quat.m_x, 2) 
                                             + Math::pow(Quat.m_z, 2));

    rotationMatrix.m_matrix[1].m_z = 2 * (Quat.m_y * Quat.m_z 
                                          - Quat.m_w * Quat.m_x);

    rotationMatrix.m_matrix[2].m_x = 2 * (Quat.m_x * Quat.m_z 
                                          - Quat.m_w * Quat.m_y);

    rotationMatrix.m_matrix[2].m_y = 2 * (Quat.m_y * Quat.m_z 
                                          + Quat.m_w * Quat.m_x);

    rotationMatrix.m_matrix[2].m_z = 1 - 2 * (Math::pow(Quat.m_x, 2) 
                                              + Math::pow(Quat.m_y, 2));

    rotationMatrix.m_matrix[3].m_w = 1.0f;
    return rotationMatrix;

  }
}
