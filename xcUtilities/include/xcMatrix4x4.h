#pragma once

#include "xcVector4.h"

using xcEngineSDK::Vector4;
namespace xcEngineSDK {

  class XC_UTILITY_EXPORT Matrix4x4 
  {
   public:
    Matrix4x4(float R00, float R01, float R02, float R03,
              float R10, float R11, float R12, float R13,
              float R20, float R21, float R22, float R23,
              float R30, float R31, float R32, float R33);

    Matrix4x4(Vector4 upRow, Vector4 med1Row, Vector4 med2Row, Vector4 downRow);

    Matrix4x4();

    ~Matrix4x4() = default;

    /**
     * @brief      transpose  function, to transpose a matrix
     * @bug	       No know Bugs
     * @return     Returns a transpose matrix
     */
    Matrix4x4
    transpose();

    /**
     * @brief      + operator overload
     * @param      M parameter one, matrix for sum
     * @bug	       No know Bugs
     * @return     Returns sum of two matrix 4x4
     */
    Matrix4x4
    operator + (const Matrix4x4& M);

    /**
     * @brief      - operator overload
     * @param      M parameter one, matrix for rest
     * @bug	       No know Bugs
     * @return     Returns rest of two matrix 4x4
     */
    Matrix4x4
    operator - (const Matrix4x4& M);

    /**
     * @brief      / operator overload
     * @param      M parameter one, matrix for divide
     * @bug	       No know Bugs
     * @return     Returns divide of two matrix 4x4
     */
    Matrix4x4
    operator / (const Matrix4x4& M);


    /**
     * @brief      * operator overload
     * @param      M parameter one, matrix for multiple
     * @bug	       No know Bugs
     * @return     Returns multiple of two matrix 4x4
     */
    Matrix4x4
    operator * (const Matrix4x4& M);

   public:

    float m_matrix[4][4];

  };
}