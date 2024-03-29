/*****************************************************************************/
/**
 * @file    xcMatrix3x3.h
 * @author  Roberto Ramirez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/02/12
 * @brief   Wrapper class which indicates a given angle value is in Degrees.
 *
 * In this class you can use basic operations of matrix 4x4 like +, -, /, *
 * you can transpose the matrix
 * 
 * Degree values are interchangeable with Radian values, and conversions will
 * be done automatically between them.
 * 
 * @bug	   No known bugs.
 */
 /*****************************************************************************/

#pragma once
/*****************************************************************************/
/**
 * Includes
 */
 /*****************************************************************************/
#include "xcPrerequisitesUtilities.h"
#include "xcVector3.h"

namespace xcEngineSDK {


  class XC_UTILITY_EXPORT Matrix3x3
  {
   public:

    Matrix3x3() = default;

    ~Matrix3x3() = default;
    Matrix3x3(float _00, float _01, float _02,
              float _10, float _11, float _12,
              float _20, float _21, float _22);

    Matrix3x3(const Vector3& XVector, 
              const Vector3& YVector,
              const Vector3& ZVector);

    

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
    operator * (Matrix3x3 M);

    /**
     * @brief      = operator overload
     * @param      M parameter one, matrix equal
     * @bug	       No know Bugs
     * @return     Returns a equals between matrix 
     */
    Matrix3x3&
    operator = (const Matrix3x3& M);

    /**
     * @brief      = operator overload
     * @param      M parameter one, matrix equal
     * @bug	       No know Bugs
     * @return     Returns a equals between matrix
     */
    Matrix3x3&
    operator += (const Matrix3x3& M);

    /**
     * @brief      = operator overload
     * @param      M parameter one, matrix equal
     * @bug	       No know Bugs
     * @return     Returns a equals between matrix
     */
    Matrix3x3&
    operator -= (const Matrix3x3& M);

    /**
     * @brief      = operator overload
     * @param      M parameter one, matrix equal
     * @bug	       No know Bugs
     * @return     Returns a equals between matrix
     */
    Matrix3x3&
    operator /= (const Matrix3x3& M);

    /**
     * @brief      = operator overload
     * @param      M parameter one, matrix equal
     * @bug	       No know Bugs
     * @return     Returns a equals between matrix
     */
    Matrix3x3&
    operator *= (const Matrix3x3& M);

   public:

     /*union
     {
       float m[9];
       float _m[3][3];
       Vector3 mv[3];
     }*/
    Vector3 m_matrix[3];

  };
}