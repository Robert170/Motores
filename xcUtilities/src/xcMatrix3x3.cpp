#include "xcMatrix3x3.h"


Matrix3x3::Matrix3x3(float R00, float R01, float R02,
                     float R10, float R11, float R12,
                     float R20, float R21, float R22) {

  //up vector
  m_matrix[0][0] = R00;
  m_matrix[0][1] = R01;
  m_matrix[0][2] = R02;

  //middle vector  
  m_matrix[1][0] = R10;
  m_matrix[1][1] = R11;
  m_matrix[1][2] = R12;

  //down vector    
  m_matrix[2][0] = R20;
  m_matrix[2][1] = R21;
  m_matrix[2][2] = R22;

}

Matrix3x3::Matrix3x3(Vector3 upRow, Vector3 medRow, Vector3 downRow) {

  //up vector
  m_matrix[0][0] = upRow.m_x;
  m_matrix[0][1] = upRow.m_y;
  m_matrix[0][2] = upRow.m_z;

  //middle vector  
  m_matrix[1][0] = medRow.m_x;
  m_matrix[1][1] = medRow.m_y;
  m_matrix[1][2] = medRow.m_z;

  //down vector    
  m_matrix[2][0] = downRow.m_x;
  m_matrix[2][1] = downRow.m_y;
  m_matrix[2][2] = downRow.m_z;
}

Matrix3x3::Matrix3x3() {

  //up vector
  m_matrix[0][0] = 0.f;
  m_matrix[0][1] = 0.f;
  m_matrix[0][2] = 0.f;
                   
  //middle vector  
  m_matrix[1][0] = 0.f;
  m_matrix[1][1] = 0.f;
  m_matrix[1][2] = 0.f;
                   
  //down vector    
  m_matrix[2][0] = 0.f;
  m_matrix[2][1] = 0.f;
  m_matrix[2][2] = 0.f;
}

Matrix3x3 
Matrix3x3::identity() {
  return Matrix3x3(1, 0, 0,
                   0, 1, 0,
                   0, 0, 1);
}

Matrix3x3 
Matrix3x3::transpose() {

  return Matrix3x3(m_matrix[0][0], m_matrix[1][0], m_matrix[2][0],
                   m_matrix[0][1], m_matrix[1][1], m_matrix[2][1],
                   m_matrix[0][2], m_matrix[1][2], m_matrix[2][2]);
}

Matrix3x3
Matrix3x3::operator + (const Matrix3x3& M) {

  return Matrix3x3(m_matrix[0][0] + M.m_matrix[0][0], 
                   m_matrix[0][1] + M.m_matrix[0][1],
                   m_matrix[0][2] + M.m_matrix[0][2], 
                   m_matrix[1][0] + M.m_matrix[1][0], 
                   m_matrix[1][1] + M.m_matrix[1][1], 
                   m_matrix[1][2] + M.m_matrix[1][2], 
                   m_matrix[2][0] + M.m_matrix[2][0],
                   m_matrix[2][1] + M.m_matrix[2][1],
                   m_matrix[2][2] + M.m_matrix[2][2]);
}

Matrix3x3 
Matrix3x3::operator - (const Matrix3x3& M) {

  return Matrix3x3(m_matrix[0][0] - M.m_matrix[0][0],
                   m_matrix[0][1] - M.m_matrix[0][1],
                   m_matrix[0][2] - M.m_matrix[0][2],
                   m_matrix[1][0] - M.m_matrix[1][0],
                   m_matrix[1][1] - M.m_matrix[1][1],
                   m_matrix[1][2] - M.m_matrix[1][2],
                   m_matrix[2][0] - M.m_matrix[2][0],
                   m_matrix[2][1] - M.m_matrix[2][1],
                   m_matrix[2][2] - M.m_matrix[2][2]);
}

Matrix3x3 
Matrix3x3::operator / (const Matrix3x3& M) {

  return Matrix3x3(m_matrix[0][0] / M.m_matrix[0][0],
                   m_matrix[0][1] / M.m_matrix[0][1],
                   m_matrix[0][2] / M.m_matrix[0][2],
                   m_matrix[1][0] / M.m_matrix[1][0],
                   m_matrix[1][1] / M.m_matrix[1][1],
                   m_matrix[1][2] / M.m_matrix[1][2],
                   m_matrix[2][0] / M.m_matrix[2][0],
                   m_matrix[2][1] / M.m_matrix[2][1],
                   m_matrix[2][2] / M.m_matrix[2][2]);
}

Matrix3x3 
Matrix3x3::operator * (const Matrix3x3& M) {

  return Matrix3x3((m_matrix[0][0] * M.m_matrix[0][0]) + //first row
                   (m_matrix[0][1] * M.m_matrix[1][0]) +
                   (m_matrix[0][2] * M.m_matrix[2][0]),  

                   (m_matrix[0][0] * M.m_matrix[0][1]) +
                   (m_matrix[0][1] * M.m_matrix[1][1]) +
                   (m_matrix[0][2] * M.m_matrix[2][1]),

                   (m_matrix[0][0] * M.m_matrix[0][2]) +
                   (m_matrix[0][1] * M.m_matrix[1][2]) +
                   (m_matrix[0][2] * M.m_matrix[2][2]), 

                   (m_matrix[1][0] * M.m_matrix[0][0]) + //second row
                   (m_matrix[1][1] * M.m_matrix[1][0]) +
                   (m_matrix[1][2] * M.m_matrix[2][0]),

                   (m_matrix[1][0] * M.m_matrix[0][1]) +
                   (m_matrix[1][1] * M.m_matrix[1][1]) +
                   (m_matrix[1][2] * M.m_matrix[2][1]),

                   (m_matrix[1][0] * M.m_matrix[0][2]) +
                   (m_matrix[1][1] * M.m_matrix[1][2]) +
                   (m_matrix[1][2] * M.m_matrix[2][2]), 

                   (m_matrix[2][0] * M.m_matrix[0][0]) + //third row
                   (m_matrix[2][1] * M.m_matrix[1][0]) +
                   (m_matrix[2][2] * M.m_matrix[2][0]),
                             
                   (m_matrix[2][0] * M.m_matrix[0][1]) +
                   (m_matrix[2][1] * M.m_matrix[1][1]) +
                   (m_matrix[2][2] * M.m_matrix[2][1]),
                             
                   (m_matrix[2][0] * M.m_matrix[0][2]) +
                   (m_matrix[2][1] * M.m_matrix[1][2]) +
                   (m_matrix[2][2] * M.m_matrix[2][2]));
}
