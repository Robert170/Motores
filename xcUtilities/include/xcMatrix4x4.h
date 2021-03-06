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

    Matrix4x4(float _xx, float _yx, float _zx, float _wx,
              float _xy, float _yy, float _zy, float _wy,
              float _xz, float _yz, float _zz, float _wz,
              float _xw, float _yw, float _zw, float _ww);

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
     * @brief      == operator overload
     * @param      M parameter one, matrix equal
     * @bug	       No know Bugs
     * @return     Returns if two matrix are equals
     */
    bool
    operator==(const Matrix4x4& M);

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
    operator*=(const Matrix4x4 & M);

    /**
    * @brief      != operator overload
    * @param      M parameter one, matrix equal
    * @bug	       No know Bugs
    * @return     Returns a true if the matrix are different
    */
    bool
    operator!=(const Matrix4x4& M);

   public:

     Vector4 m_matrix[4];

  };
}