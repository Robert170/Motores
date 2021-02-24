#include "xcMatrix3x3.h"

namespace xcEngineSDK {
  

  Matrix3x3::Matrix3x3(float _00, float _01, float _02, 
                       float _10, float _11, float _12, 
                       float _20, float _21, float _22) {


    m_matrix[0].m_x = _00;
    m_matrix[0].m_y = _01;
    m_matrix[0].m_z = _02;

    m_matrix[1].m_x = _10;
    m_matrix[1].m_y = _11;
    m_matrix[1].m_z = _12;

    m_matrix[2].m_x = _20;
    m_matrix[2].m_y = _21;
    m_matrix[2].m_z = _22;
  }

  Matrix3x3::Matrix3x3(const Vector3& XVector, 
                       const Vector3& YVector, 
                       const Vector3& ZVector) {

    m_matrix[0] = XVector;
    m_matrix[1] = YVector;
    m_matrix[2] = ZVector;
  }

  Matrix3x3& 
  Matrix3x3::transpose()
  {
    std::swap(m_matrix[0].m_y, m_matrix[1].m_x);
    std::swap(m_matrix[0].m_z, m_matrix[2].m_x);
    std::swap(m_matrix[1].m_z, m_matrix[2].m_y);
    return *this;
  }

  Matrix3x3 
  Matrix3x3::operator+(const Matrix3x3& M) {

    Vector3 x = m_matrix[0] + M.m_matrix[0];
    Vector3 y = m_matrix[1] + M.m_matrix[1];
    Vector3 z = m_matrix[2] + M.m_matrix[2];

    return Matrix3x3(x, y, z);
  }

  Matrix3x3 
  Matrix3x3::operator-(const Matrix3x3& M) {

    Vector3 x = m_matrix[0] - M.m_matrix[0];
    Vector3 y = m_matrix[1] - M.m_matrix[1];
    Vector3 z = m_matrix[2] - M.m_matrix[2];

    return Matrix3x3(x, y, z);
  }

  Matrix3x3 
  Matrix3x3::operator/(const Matrix3x3& M) {

    Vector3 x = m_matrix[0] / M.m_matrix[0];
    Vector3 y = m_matrix[1] / M.m_matrix[1];
    Vector3 z = m_matrix[2] / M.m_matrix[2];

    return Matrix3x3(x, y, z);
  }

  Matrix3x3 
  Matrix3x3::operator*(Matrix3x3& M) {

    Vector3 A (m_matrix[0].m_x,
               m_matrix[1].m_x,
               m_matrix[2].m_x);

    Vector3 B (M.m_matrix[0].m_x,
               M.m_matrix[1].m_x,
               M.m_matrix[2].m_x);

    float _00 = m_matrix->Dot(A,B);

    A = (m_matrix[0].m_x,
         m_matrix[1].m_x,
         m_matrix[2].m_x);

    B = (M.m_matrix[0].m_y,
         M.m_matrix[1].m_y,
         M.m_matrix[2].m_y);

    float _01 = m_matrix->Dot(A,B);

    A = (m_matrix[0].m_x,
         m_matrix[1].m_x,
         m_matrix[2].m_x);

    B = (M.m_matrix[0].m_z,
         M.m_matrix[1].m_z,
         M.m_matrix[2].m_z);

    float _02 = m_matrix->Dot(A, B);

    A = (m_matrix[0].m_y,
         m_matrix[1].m_y,
         m_matrix[2].m_y);

    B = (M.m_matrix[0].m_x,
         M.m_matrix[1].m_x,
         M.m_matrix[2].m_x);

    float _10 = m_matrix->Dot(A, B);

    A = (m_matrix[0].m_y,
         m_matrix[1].m_y,
         m_matrix[2].m_y);

    B = (M.m_matrix[0].m_y,
         M.m_matrix[1].m_y,
         M.m_matrix[2].m_y);

    float _11 = m_matrix->Dot(A, B);

    A = (m_matrix[0].m_y,
         m_matrix[1].m_y,
         m_matrix[2].m_y);

    B = (M.m_matrix[0].m_z,
         M.m_matrix[1].m_z,
         M.m_matrix[2].m_z);

    float _12 = m_matrix->Dot(A, B);

    A = (m_matrix[0].m_z,
         m_matrix[1].m_z,
         m_matrix[2].m_z);

    B = (M.m_matrix[0].m_x,
         M.m_matrix[1].m_x,
         M.m_matrix[2].m_x);

    float _20 = m_matrix->Dot(A, B);


    A = (m_matrix[0].m_z,
         m_matrix[1].m_z,
         m_matrix[2].m_z);

    B = (M.m_matrix[0].m_y,
         M.m_matrix[1].m_y,
         M.m_matrix[2].m_y);

    float _21 = m_matrix->Dot(A, B);

     A = (m_matrix[0].m_z,
         m_matrix[1].m_z,
         m_matrix[2].m_z);

    B = (M.m_matrix[0].m_z,
         M.m_matrix[1].m_z,
         M.m_matrix[2].m_z);


    float _22 = m_matrix->Dot(A, B);

    return Matrix3x3(_00, _01, _02,
                     _10, _11, _12,
                     _20, _21, _22);
  }

  Matrix3x3& 
  Matrix3x3::operator=(const Matrix3x3& M) {

    m_matrix[0] = M.m_matrix[0];
    m_matrix[1] = M.m_matrix[1];
    m_matrix[2] = M.m_matrix[2];
    return *this;
  }

  bool
  Matrix3x3::operator==(const Matrix3x3& M) {

    if (m_matrix[0] == M.m_matrix[0] &&
        m_matrix[1] == M.m_matrix[1] &&
        m_matrix[2] == M.m_matrix[2]) {

      return true; 
    }
    else {
      return false;
    }
  }

  Matrix3x3& 
  Matrix3x3::operator+=(const Matrix3x3& M) {
    m_matrix[0] += M.m_matrix[0];
    m_matrix[1] += M.m_matrix[1];
    m_matrix[2] += M.m_matrix[2];
    return *this;
  }

  Matrix3x3& 
  Matrix3x3::operator-=(const Matrix3x3& M) {
    m_matrix[0] -= M.m_matrix[0];
    m_matrix[1] -= M.m_matrix[1];
    m_matrix[2] -= M.m_matrix[2];
    return *this;
  }

  Matrix3x3& 
  Matrix3x3::operator/=(const Matrix3x3& M) {
    m_matrix[0] *= M.m_matrix[0];
    m_matrix[1] *= M.m_matrix[1];
    m_matrix[2] *= M.m_matrix[2];
    return *this;
  }

  Matrix3x3& 
  Matrix3x3::operator*=(const Matrix3x3& M) {
    // TODO: insert return statement here
    return *this;
  }


}