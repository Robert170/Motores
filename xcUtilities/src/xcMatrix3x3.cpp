#include "xcMatrix3x3.h"

namespace xcEngineSDK {
  

  Matrix3x3::Matrix3x3(float _xx, float _yx, float _zx,
                       float _xy, float _yy, float _zy,
                       float _xz, float _yz, float _zz) {


    m_matrix[0].m_x = _xx;
    m_matrix[0].m_y = _xy;
    m_matrix[0].m_z = _xz;

    m_matrix[1].m_x = _yx;
    m_matrix[1].m_y = _yy;
    m_matrix[1].m_z = _yz;

    m_matrix[2].m_x = _zx;
    m_matrix[2].m_y = _zy;
    m_matrix[2].m_z = _zz;
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
  Matrix3x3::operator*(const Matrix3x3& M) {

    //si se transpone la matriz con la que se multiplica solo es dot entre matrices
    //M.transpose();

    Matrix3x3 Temp = M;

    Temp.transpose();

    return Matrix3x3(m_matrix->dot(m_matrix[0], Temp.m_matrix[0]), 
                     m_matrix->dot(m_matrix[1], Temp.m_matrix[0]), 
                     m_matrix->dot(m_matrix[2], Temp.m_matrix[0]),
                     m_matrix->dot(m_matrix[0], Temp.m_matrix[1]), 
                     m_matrix->dot(m_matrix[1], Temp.m_matrix[1]), 
                     m_matrix->dot(m_matrix[2], Temp.m_matrix[1]),
                     m_matrix->dot(m_matrix[0], Temp.m_matrix[2]), 
                     m_matrix->dot(m_matrix[1], Temp.m_matrix[2]), 
                     m_matrix->dot(m_matrix[2], Temp.m_matrix[2]));
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

    //agregar una funcion que revise si son iguales en un rago de error
    if (m_matrix[0] == M.m_matrix[0] &&
        m_matrix[1] == M.m_matrix[1] &&
        m_matrix[2] == M.m_matrix[2]) {

      return true; 
    }
    
    return false;
    
  }

  Matrix3x3& 
  Matrix3x3::operator+=(const Matrix3x3& M) {
    *this = this->operator+(M);
    return *this;
  }

  Matrix3x3& 
  Matrix3x3::operator-=(const Matrix3x3& M) {
    *this = this->operator-(M);
    return *this;
  }

  Matrix3x3& 
  Matrix3x3::operator*=(const Matrix3x3& M) {
   
    *this = this->operator*(M);
    
    return *this;
  }

  bool 
  Matrix3x3::operator!=(const Matrix3x3& M) {

    return !this->operator==(M);

  }


}