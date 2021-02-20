#include "xcMatrix4x4.h"
namespace xcEngineSDK {
  Matrix4x4::Matrix4x4(float R00, float R01, float R02, float R03,
                       float R10, float R11, float R12, float R13,
                       float R20, float R21, float R22, float R23,
                       float R30, float R31, float R32, float R33) {
    //up vector
    m_matrix[0][0] = R00;
    m_matrix[0][1] = R01;
    m_matrix[0][2] = R02;
    m_matrix[0][3] = R03;

    //middle 1 vector  
    m_matrix[1][0] = R10;
    m_matrix[1][1] = R11;
    m_matrix[1][2] = R12;
    m_matrix[1][3] = R13;

    //middle 2 vector    
    m_matrix[2][0] = R20;
    m_matrix[2][1] = R21;
    m_matrix[2][2] = R22;
    m_matrix[2][3] = R23;

    //down vector    
    m_matrix[3][0] = R20;
    m_matrix[3][1] = R21;
    m_matrix[3][2] = R22;
    m_matrix[3][3] = R33;
  }

  Matrix4x4::Matrix4x4(Vector4 upRow,
    Vector4 med1Row,
    Vector4 med2Row,
    Vector4 downRow) {

    //up vector
    m_matrix[0][0] = upRow.m_x;
    m_matrix[0][1] = upRow.m_y;
    m_matrix[0][2] = upRow.m_z;
    m_matrix[0][3] = upRow.m_w;

    //middle 1 vector  
    m_matrix[1][0] = med1Row.m_x;
    m_matrix[1][1] = med1Row.m_y;
    m_matrix[1][2] = med1Row.m_z;
    m_matrix[1][3] = med1Row.m_w;

    //middle 2 vector    
    m_matrix[2][0] = med2Row.m_x;
    m_matrix[2][1] = med2Row.m_y;
    m_matrix[2][2] = med2Row.m_z;
    m_matrix[2][3] = med2Row.m_w;

    //down vector    
    m_matrix[3][0] = downRow.m_x;
    m_matrix[3][1] = downRow.m_y;
    m_matrix[3][2] = downRow.m_z;
    m_matrix[3][3] = downRow.m_w;
  }

  Matrix4x4::Matrix4x4() {

    //up vector
    m_matrix[0][0] = 0.0f;
    m_matrix[0][1] = 0.0f;
    m_matrix[0][2] = 0.0f;
    m_matrix[0][3] = 0.0f;

    //middle 1 vector
    m_matrix[1][0] = 0.0f;
    m_matrix[1][1] = 0.0f;
    m_matrix[1][2] = 0.0f;
    m_matrix[1][3] = 0.0f;

    //middle 2 vector
    m_matrix[2][0] = 0.0f;
    m_matrix[2][1] = 0.0f;
    m_matrix[2][2] = 0.0f;
    m_matrix[2][3] = 0.0f;

    //down vector    
    m_matrix[3][0] = 0.0f;
    m_matrix[3][1] = 0.0f;
    m_matrix[3][2] = 0.0f;
    m_matrix[3][3] = 0.0f;
  }



  Matrix4x4
  Matrix4x4::transpose() {

    return Matrix4x4(m_matrix[0][0], m_matrix[1][0], m_matrix[2][0], m_matrix[3][0],
      m_matrix[0][1], m_matrix[1][1], m_matrix[2][1], m_matrix[3][1],
      m_matrix[0][2], m_matrix[1][2], m_matrix[2][2], m_matrix[3][2],
      m_matrix[0][3], m_matrix[1][3], m_matrix[2][3], m_matrix[3][3]);
  }

  Matrix4x4
  Matrix4x4::operator + (const Matrix4x4& M) {

    return Matrix4x4(m_matrix[0][0] + M.m_matrix[0][0],
      m_matrix[0][1] + M.m_matrix[0][1],
      m_matrix[0][2] + M.m_matrix[0][2],
      m_matrix[0][3] + M.m_matrix[0][3],

      m_matrix[1][0] + M.m_matrix[1][0],
      m_matrix[1][1] + M.m_matrix[1][1],
      m_matrix[1][2] + M.m_matrix[1][2],
      m_matrix[1][3] + M.m_matrix[1][3],

      m_matrix[2][0] + M.m_matrix[2][0],
      m_matrix[2][1] + M.m_matrix[2][1],
      m_matrix[2][2] + M.m_matrix[2][2],
      m_matrix[2][3] + M.m_matrix[2][3],

      m_matrix[3][0] + M.m_matrix[3][0],
      m_matrix[3][1] + M.m_matrix[3][1],
      m_matrix[3][2] + M.m_matrix[3][2],
      m_matrix[3][3] + M.m_matrix[3][3]);
  }

  Matrix4x4
  Matrix4x4::operator-(const Matrix4x4& M) {
    return Matrix4x4(m_matrix[0][0] - M.m_matrix[0][0],
      m_matrix[0][1] - M.m_matrix[0][1],
      m_matrix[0][2] - M.m_matrix[0][2],
      m_matrix[0][3] - M.m_matrix[0][3],

      m_matrix[1][0] - M.m_matrix[1][0],
      m_matrix[1][1] - M.m_matrix[1][1],
      m_matrix[1][2] - M.m_matrix[1][2],
      m_matrix[1][3] - M.m_matrix[1][3],

      m_matrix[2][0] - M.m_matrix[2][0],
      m_matrix[2][1] - M.m_matrix[2][1],
      m_matrix[2][2] - M.m_matrix[2][2],
      m_matrix[2][3] - M.m_matrix[2][3],

      m_matrix[3][0] - M.m_matrix[3][0],
      m_matrix[3][1] - M.m_matrix[3][1],
      m_matrix[3][2] - M.m_matrix[3][2],
      m_matrix[3][3] - M.m_matrix[3][3]);
  }

  Matrix4x4
  Matrix4x4::operator / (const Matrix4x4& M) {
    return Matrix4x4(m_matrix[0][0] / M.m_matrix[0][0],
      m_matrix[0][1] / M.m_matrix[0][1],
      m_matrix[0][2] / M.m_matrix[0][2],
      m_matrix[0][3] / M.m_matrix[0][3],

      m_matrix[1][0] / M.m_matrix[1][0],
      m_matrix[1][1] / M.m_matrix[1][1],
      m_matrix[1][2] / M.m_matrix[1][2],
      m_matrix[1][3] / M.m_matrix[1][3],

      m_matrix[2][0] / M.m_matrix[2][0],
      m_matrix[2][1] / M.m_matrix[2][1],
      m_matrix[2][2] / M.m_matrix[2][2],
      m_matrix[2][3] / M.m_matrix[2][3],

      m_matrix[3][0] / M.m_matrix[3][0],
      m_matrix[3][1] / M.m_matrix[3][1],
      m_matrix[3][2] / M.m_matrix[3][2],
      m_matrix[3][3] / M.m_matrix[3][3]);
  }

  Matrix4x4
  Matrix4x4::operator*(const Matrix4x4& M) {

    return Matrix4x4((m_matrix[0][0] * M.m_matrix[0][0]) + //first row
      (m_matrix[0][1] * M.m_matrix[1][0]) +
      (m_matrix[0][2] * M.m_matrix[2][0]) +
      (m_matrix[0][3] * M.m_matrix[3][0]),

      (m_matrix[0][0] * M.m_matrix[0][1]) +
      (m_matrix[0][1] * M.m_matrix[1][1]) +
      (m_matrix[0][2] * M.m_matrix[2][1]) +
      (m_matrix[0][3] * M.m_matrix[3][1]),

      (m_matrix[0][0] * M.m_matrix[0][2]) +
      (m_matrix[0][1] * M.m_matrix[1][2]) +
      (m_matrix[0][2] * M.m_matrix[2][2]) +
      (m_matrix[0][3] * M.m_matrix[3][2]),

      (m_matrix[0][0] * M.m_matrix[0][3]) +
      (m_matrix[0][1] * M.m_matrix[1][3]) +
      (m_matrix[0][2] * M.m_matrix[2][3]) +
      (m_matrix[0][3] * M.m_matrix[3][3]),

      (m_matrix[1][0] * M.m_matrix[0][0]) + //second row
      (m_matrix[1][1] * M.m_matrix[1][0]) +
      (m_matrix[1][2] * M.m_matrix[2][0]) +
      (m_matrix[1][3] * M.m_matrix[3][0]),

      (m_matrix[1][0] * M.m_matrix[0][1]) +
      (m_matrix[1][1] * M.m_matrix[1][1]) +
      (m_matrix[1][2] * M.m_matrix[2][1]) +
      (m_matrix[1][3] * M.m_matrix[3][1]),

      (m_matrix[1][0] * M.m_matrix[0][2]) +
      (m_matrix[1][1] * M.m_matrix[1][2]) +
      (m_matrix[1][2] * M.m_matrix[2][2]) +
      (m_matrix[1][3] * M.m_matrix[3][2]),

      (m_matrix[1][0] * M.m_matrix[0][3]) +
      (m_matrix[1][1] * M.m_matrix[1][3]) +
      (m_matrix[1][2] * M.m_matrix[2][3]) +
      (m_matrix[1][3] * M.m_matrix[3][3]),

      (m_matrix[2][0] * M.m_matrix[0][0]) + //third row
      (m_matrix[2][1] * M.m_matrix[1][0]) +
      (m_matrix[2][2] * M.m_matrix[2][0]) +
      (m_matrix[2][3] * M.m_matrix[3][0]),

      (m_matrix[2][0] * M.m_matrix[0][1]) +
      (m_matrix[2][1] * M.m_matrix[1][1]) +
      (m_matrix[2][2] * M.m_matrix[2][1]) +
      (m_matrix[2][3] * M.m_matrix[3][1]),

      (m_matrix[2][0] * M.m_matrix[0][2]) +
      (m_matrix[2][1] * M.m_matrix[1][2]) +
      (m_matrix[2][2] * M.m_matrix[2][2]) +
      (m_matrix[2][3] * M.m_matrix[3][2]),

      (m_matrix[2][0] * M.m_matrix[0][3]) +
      (m_matrix[2][1] * M.m_matrix[1][3]) +
      (m_matrix[2][2] * M.m_matrix[2][3]) +
      (m_matrix[2][3] * M.m_matrix[3][3]),

      (m_matrix[3][0] * M.m_matrix[0][0]) + //fourth row
      (m_matrix[3][1] * M.m_matrix[1][0]) +
      (m_matrix[3][2] * M.m_matrix[2][0]) +
      (m_matrix[3][3] * M.m_matrix[3][0]),

      (m_matrix[3][0] * M.m_matrix[0][1]) +
      (m_matrix[3][1] * M.m_matrix[1][1]) +
      (m_matrix[3][2] * M.m_matrix[2][1]) +
      (m_matrix[3][3] * M.m_matrix[3][1]),

      (m_matrix[3][0] * M.m_matrix[0][2]) +
      (m_matrix[3][1] * M.m_matrix[1][2]) +
      (m_matrix[3][2] * M.m_matrix[2][2]) +
      (m_matrix[3][3] * M.m_matrix[3][2]),

      (m_matrix[3][0] * M.m_matrix[0][3]) +
      (m_matrix[3][1] * M.m_matrix[1][3]) +
      (m_matrix[3][2] * M.m_matrix[2][3]) +
      (m_matrix[3][3] * M.m_matrix[3][3]));
  }
}
