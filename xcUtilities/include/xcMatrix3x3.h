#pragma once

#include "xcVector3.h"

namespace xcEngineSDK {

  
  class XC_UTILITY_EXPORT Matrix3x3
  {
  public:
    Matrix3x3(float R00, float R01, float R02,
      float R10, float R11, float R12,
      float R20, float R21, float R22);

    Matrix3x3(Vector3 upRow, Vector3 medRow, Vector3 downRow);

    Matrix3x3();

    ~Matrix3x3() = default;

    /**
     * @brief      transpose  function, to transpose a matrix
     * @bug	       No know Bugs
     * @return     Returns a transpose matrix
     */
    Matrix3x3&
    transpose();

    /**
     * @brief      + operator overload
     * @param      M parameter one, matrix for sum
     * @bug	       No know Bugs
     * @return     Returns sum of two matrix 3x3
     */
    Matrix3x3
    operator + (const Matrix3x3& M);

    /**
     * @brief      - operator overload
     * @param      M parameter one, matrix for rest
     * @bug	       No know Bugs
     * @return     Returns rest of two matrix 3x3
     */
    Matrix3x3
    operator - (const Matrix3x3& M);

    /**
     * @brief      / operator overload
     * @param      M parameter one, matrix for divide
     * @bug	       No know Bugs
     * @return     Returns divide of two matrix 3x3
     */
    Matrix3x3
    operator / (const Matrix3x3& M);


    /**
     * @brief      * operator overload
     * @param      M parameter one, matrix for multiple
     * @bug	       No know Bugs
     * @return     Returns multiple of two matrix 3x3
     */
    Matrix3x3
    operator * (const Matrix3x3& M);

  public:

    float m_matrix[3][3];

  };
}