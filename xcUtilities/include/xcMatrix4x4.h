#pragma once


#include "xcPrerequisitesUtilities.h"
#include "xcVector4.h"

using xcEngineSDK::Vector4;
namespace xcEngineSDK {

  class XC_UTILITY_EXPORT Matrix4x4 
  {
   public:

    Matrix4x4() = default;

    ~Matrix4x4() = default;

    Matrix4x4(float _00, float _01, float _02, float _03,
              float _10, float _11, float _12, float _13,
              float _20, float _21, float _22, float _23,
              float _30, float _31, float _32, float _33);

    Matrix4x4(Vector4 XVector, 
              Vector4 YVector,
              Vector4 ZVector,
              Vector4 WVector);

    /**
     * @brief      transpose  function, to transpose a matrix
     * @bug	       No know Bugs
     * @return     Returns a transpose matrix
     */
    Matrix4x4&
    transpose();

    /**
     * @brief      + operator overload
     * @param      M parameter one, matrix for sum
     * @bug	       No know Bugs
     * @return     Returns sum of two matrix 4x4
     */
    Matrix4x4
    operator+(const Matrix4x4& M);

    /**
     * @brief      - operator overload
     * @param      M parameter one, matrix for rest
     * @bug	       No know Bugs
     * @return     Returns rest of two matrix 4x4
     */
    Matrix4x4
    operator-(const Matrix4x4& M);

    /**
     * @brief      / operator overload
     * @param      M parameter one, matrix for divide
     * @bug	       No know Bugs
     * @return     Returns divide of two matrix 4x4
     */
    Matrix4x4
    operator/(const Matrix4x4& M);


    /**
     * @brief      * operator overload
     * @param      M parameter one, matrix for multiple
     * @bug	       No know Bugs
     * @return     Returns multiple of two matrix 4x4
     */
    Matrix4x4
    operator*(const Matrix4x4& M);

    /**
     * @brief      = operator overload
     * @param      M parameter one, matrix equal
     * @bug	       No know Bugs
     * @return     Returns a equals between matrix
     */
    Matrix4x4&
    operator=(const Matrix4x4& M);

    /**
     * @brief      = operator overload
     * @param      M parameter one, matrix equal
     * @bug	       No know Bugs
     * @return     Returns a equals between matrix
     */
    Matrix4x4&
    operator+=(const Matrix4x4& M);

    /**
     * @brief      = operator overload
     * @param      M parameter one, matrix equal
     * @bug	       No know Bugs
     * @return     Returns a equals between matrix
     */
    Matrix4x4&
    operator-=(const Matrix4x4& M);

    /**
     * @brief      = operator overload
     * @param      M parameter one, matrix equal
     * @bug	       No know Bugs
     * @return     Returns a equals between matrix
     */
    Matrix4x4&
    operator/=(const Matrix4x4& M);

    /**
     * @brief      = operator overload
     * @param      M parameter one, matrix equal
     * @bug	       No know Bugs
     * @return     Returns a equals between matrix
     */
    Matrix4x4&
    operator*=(const Matrix4x4 & M);

   public:

     Vector4 m_matrix[4];

  };
}