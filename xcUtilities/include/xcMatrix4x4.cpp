#include "xcMatrix4x4.h"
namespace xcEngineSDK {
  Matrix4x4::Matrix4x4(float _00, float _01, float _02, float _03,
                       float _10, float _11, float _12, float _13,
                       float _20, float _21, float _22, float _23,
                       float _30, float _31, float _32, float _33) {
    m_matrix[0].m_x = _00;
    m_matrix[0].m_y = _01;
    m_matrix[0].m_z = _02;
    m_matrix[0].m_w = _03;

    m_matrix[1].m_x = _10;
    m_matrix[1].m_y = _11;
    m_matrix[1].m_z = _12;
    m_matrix[1].m_w = _13;

    m_matrix[2].m_x = _20;
    m_matrix[2].m_y = _21;
    m_matrix[2].m_z = _22;
    m_matrix[2].m_w = _23;

    m_matrix[3].m_x = _30;
    m_matrix[3].m_y = _31;
    m_matrix[3].m_z = _32;
    m_matrix[3].m_w = _33;

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
  Matrix4x4::operator/(const Matrix4x4& M) {

    Vector4 x = m_matrix[0] / M.m_matrix[0];
    Vector4 y = m_matrix[1] / M.m_matrix[1];
    Vector4 z = m_matrix[2] / M.m_matrix[2];
    Vector4 w = m_matrix[3] / M.m_matrix[3];

    return Matrix4x4(x, y, z, w);
  }

  Matrix4x4
  Matrix4x4::operator*(const Matrix4x4& M) {

    Vector4 A (m_matrix[0].m_x,
               m_matrix[1].m_x,
               m_matrix[2].m_x,
               m_matrix[3].m_x);

    Vector4 B (m_matrix[0].m_x,
               m_matrix[1].m_x,
               m_matrix[2].m_x,
                m_matrix[3].m_x);

    float _00 = m_matrix->Dot(A,B);

    A = (m_matrix[0].m_x,
         m_matrix[1].m_x,
         m_matrix[2].m_x,
         m_matrix[3].m_x);

    B = (m_matrix[0].m_y,
         m_matrix[1].m_y,
         m_matrix[2].m_y,
         m_matrix[3].m_y);

    float _01 = m_matrix->Dot(A,B);

    A = (m_matrix[0].m_x,
         m_matrix[1].m_x,
         m_matrix[2].m_x,
         m_matrix[3].m_x);

    B = (m_matrix[0].m_z,
         m_matrix[1].m_z,
         m_matrix[2].m_z,
         m_matrix[3].m_z);

    float _02 = m_matrix->Dot(A, B);

    A = (m_matrix[0].m_x,
         m_matrix[1].m_x,
         m_matrix[2].m_x,
         m_matrix[3].m_x);

    B = (m_matrix[0].m_w,
         m_matrix[1].m_w,
         m_matrix[2].m_w,
         m_matrix[3].m_w);

    float _03 = m_matrix->Dot(A, B);

    /////////////////////////////////////////

    A = (m_matrix[0].m_y,
         m_matrix[1].m_y,
         m_matrix[2].m_y,
         m_matrix[3].m_y);

    B = (m_matrix[0].m_x,
         m_matrix[1].m_x,
         m_matrix[2].m_x,
         m_matrix[3].m_x);

    float _10 = m_matrix->Dot(A, B);

    A = (m_matrix[0].m_y,
         m_matrix[1].m_y,
         m_matrix[2].m_y,
         m_matrix[3].m_y);

    B = (m_matrix[0].m_y,
         m_matrix[1].m_y,
         m_matrix[2].m_y,
         m_matrix[3].m_y);

    float _11 = m_matrix->Dot(A, B);

    A = (m_matrix[0].m_y,
         m_matrix[1].m_y,
         m_matrix[2].m_y,
         m_matrix[3].m_y);

    B = (m_matrix[0].m_z,
         m_matrix[1].m_z,
         m_matrix[2].m_z,
         m_matrix[3].m_z);

    float _12 = m_matrix->Dot(A, B);

    A = (m_matrix[0].m_y,
         m_matrix[1].m_y,
         m_matrix[2].m_y,
         m_matrix[3].m_y);

    B = (m_matrix[0].m_w,
         m_matrix[1].m_w,
         m_matrix[2].m_w,
         m_matrix[3].m_w);

    float _13 = m_matrix->Dot(A, B);

    ///////////////////////////////////////

    A = (m_matrix[0].m_z,
         m_matrix[1].m_z,
         m_matrix[2].m_z,
         m_matrix[3].m_z);

    B = (m_matrix[0].m_x,
         m_matrix[1].m_x,
         m_matrix[2].m_x,
         m_matrix[3].m_x);

    float _20 = m_matrix->Dot(A, B);


    A = (m_matrix[0].m_z,
         m_matrix[1].m_z,
         m_matrix[2].m_z,
         m_matrix[3].m_z);

    B = (m_matrix[0].m_y,
         m_matrix[1].m_y,
         m_matrix[2].m_y,
         m_matrix[3].m_y);

    float _21 = m_matrix->Dot(A, B);

     A = (m_matrix[0].m_z,
          m_matrix[1].m_z,
          m_matrix[2].m_z,
          m_matrix[3].m_z);

    B = (m_matrix[0].m_z,
         m_matrix[1].m_z,
         m_matrix[2].m_z,
         m_matrix[3].m_z);


    float _22 = m_matrix->Dot(A, B);


    A = (m_matrix[0].m_z,
         m_matrix[1].m_z,
         m_matrix[2].m_z,
         m_matrix[3].m_z);

    B = (m_matrix[0].m_w,
         m_matrix[1].m_w,
         m_matrix[2].m_w,
         m_matrix[3].m_w);

    float _23 = m_matrix->Dot(A, B);

    ///////////////////////////////////////

    A = (m_matrix[0].m_w,
         m_matrix[1].m_w,
         m_matrix[2].m_w,
         m_matrix[3].m_w);

    B = (m_matrix[0].m_x,
         m_matrix[1].m_x,
         m_matrix[2].m_x,
         m_matrix[3].m_x);

    float _30 = m_matrix->Dot(A, B);


    A = (m_matrix[0].m_w,
         m_matrix[1].m_w,
         m_matrix[2].m_w,
         m_matrix[3].m_w);

    B = (m_matrix[0].m_y,
         m_matrix[1].m_y,
         m_matrix[2].m_y,
         m_matrix[3].m_y);

    float _31 = m_matrix->Dot(A, B);

     A = (m_matrix[0].m_w,
          m_matrix[1].m_w,
          m_matrix[2].m_w,
          m_matrix[3].m_w);

    B = (m_matrix[0].m_z,
         m_matrix[1].m_z,
         m_matrix[2].m_z,
         m_matrix[3].m_z);


    float _32 = m_matrix->Dot(A, B);


    A = (m_matrix[0].m_w,
         m_matrix[1].m_w,
         m_matrix[2].m_w,
         m_matrix[3].m_w);

    B = (m_matrix[0].m_w,
         m_matrix[1].m_w,
         m_matrix[2].m_w,
         m_matrix[3].m_w);

    float _33 = m_matrix->Dot(A, B);

    return Matrix4x4(_00, _01, _02, _03,
                     _10, _11, _12, _13,
                     _20, _21, _22, _23,
                     _30, _31, _32, _33);
  }

  Matrix4x4& 
  Matrix4x4::operator=(const Matrix4x4& M) {

    m_matrix[0] = M.m_matrix[0];
    m_matrix[1] = M.m_matrix[1];
    m_matrix[2] = M.m_matrix[2];
    m_matrix[3] = M.m_matrix[3];
    return *this;
  }

  Matrix4x4& 
  Matrix4x4::operator+=(const Matrix4x4& M) {

    m_matrix[0] += M.m_matrix[0];
    m_matrix[1] += M.m_matrix[1];
    m_matrix[2] += M.m_matrix[2];
    m_matrix[3] += M.m_matrix[3];
    return *this;
  }

  Matrix4x4& 
  Matrix4x4::operator-=(const Matrix4x4& M) {

    m_matrix[0] -= M.m_matrix[0];
    m_matrix[1] -= M.m_matrix[1];
    m_matrix[2] -= M.m_matrix[2];
    m_matrix[3] -= M.m_matrix[3];
    return *this;
  }

  Matrix4x4& 
  Matrix4x4::operator/=(const Matrix4x4& M) {

    m_matrix[0] /= M.m_matrix[0];
    m_matrix[1] /= M.m_matrix[1];
    m_matrix[2] /= M.m_matrix[2];
    m_matrix[3] /= M.m_matrix[3];
    return *this;
  }

  Matrix4x4& 
  Matrix4x4::operator*=(const Matrix4x4& M) {
    return *this;
  }
}
