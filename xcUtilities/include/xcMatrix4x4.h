/*****************************************************************************/
/**
 * @file    xcMatrix4x4.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/01/27
 * @brief   Vector3 of float
 *
 * This class has all necessary math for vector3 of float, like sum, rest,
 * dot product, cross product, etc.
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once

#include "xcPrerequisitesUtilities.h"
#include "xcMath.h"
#include "xcVector4.h"
#include "xcMatrix3x3.h"
#include "xcQuaternions.h"
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
     * @return     Returns a transpose matrix4x4
     */
    Matrix4x4&
    transpose();

    /**
     * @brief      inverse  function, to inverse a matrix
     * @bug	       No know Bugs
     * @return     Returns a inverse matrix4x4
     */
    Matrix4x4&
    inverse();

    /**
     * @brief      determinant  function, to inverse a matrix
     * @bug	       No know Bugs
     * @return     Returns the determinant of a matrix4x4
     */
    float
    determinant(const Matrix4x4& matrix);

    /**
     * @brief      determinant  function, to inverse a matrix
     * @bug	       No know Bugs
     * @return     Returns the determinant of a matrix4x4
     */
    float
    cofactor(const Matrix3x3& matrix);

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
    * @bug	      No know Bugs
    * @return     Returns a true if the matrix are different
    */
    bool
    operator!=(const Matrix4x4& M);

    /**
    * @brief      lookAtLH function name
    * @param      M parameter one, matrix equal
    * @param      M parameter two, matrix equal
    * @param      M parameter three, matrix equal
    * @bug	      No know Bugs
    * @return     Returns a matrix for look at
    */
    Matrix4x4
    lookAtLH(Vector3& Eye,
             Vector3& At,
             Vector3& Up);
    Matrix4x4
    perspectiveFovLH(float& Fov,
                     float& Height,
                     float& Width,
                     float& Near,
                     float& Far);

    Matrix4x4
    quatToMatRot(Quaternion& Quat);

   public:

    Vector4 m_matrix[4];

    static const Matrix4x4 IDENTITY_MATRIX;

  };
}