#include "xcMatrix4x4.h"
namespace xcEngineSDK {
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
    

    return Matrix4x4(m_matrix->Dot(m_matrix[0], Temp.m_matrix[0]), 
                     m_matrix->Dot(m_matrix[1], Temp.m_matrix[0]), 
                     m_matrix->Dot(m_matrix[2], Temp.m_matrix[0]), 
                     m_matrix->Dot(m_matrix[3], Temp.m_matrix[0]),
                     m_matrix->Dot(m_matrix[0], Temp.m_matrix[1]), 
                     m_matrix->Dot(m_matrix[1], Temp.m_matrix[1]), 
                     m_matrix->Dot(m_matrix[2], Temp.m_matrix[1]), 
                     m_matrix->Dot(m_matrix[3], Temp.m_matrix[1]),
                     m_matrix->Dot(m_matrix[0], Temp.m_matrix[2]), 
                     m_matrix->Dot(m_matrix[1], Temp.m_matrix[2]), 
                     m_matrix->Dot(m_matrix[2], Temp.m_matrix[2]), 
                     m_matrix->Dot(m_matrix[3], Temp.m_matrix[2]),
                     m_matrix->Dot(m_matrix[0], Temp.m_matrix[3]), 
                     m_matrix->Dot(m_matrix[1], Temp.m_matrix[3]), 
                     m_matrix->Dot(m_matrix[2], Temp.m_matrix[3]), 
                     m_matrix->Dot(m_matrix[3], Temp.m_matrix[3]));
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
}
