/*****************************************************************************/
/**
 * @file    xcVector3.h
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
#include "xcVector2.h"

namespace xcEngineSDK {

  class XC_UTILITY_EXPORT Vector3 
  {

   public:

    /**
     * @brief default constructor
     */
    Vector3() = default;

    /**
     * @brief default destructor
     */
    ~Vector3() = default;

    /**
     * @brief constructor of float
     */
    Vector3(float x, float y = 0.f, float z = 0.0f)
            :m_x(x), m_y(y), m_z(z) { };

    /**
     * @brief constructor of Vector2 and float
     */
    Vector3(Vector2 v, float z = 0.0f)
            :m_x(v.m_x), m_y(v.m_y), m_z(z) { };


    /**
     * @brief      + operator overload
     * @param      V parameter one, vector for sum
     * @bug	       No know Bugs
     * @return     Returns sum of two vectors
     */
    Vector3
    operator+(const Vector3& V);

    /**
     * @brief      - operator overload
     * @param      V parameter one, vector for rest
     * @bug	       No know Bugs
     * @return     Returns rest of two vectors
     */
    Vector3
    operator-(const Vector3& V);

    /**
     * @brief      * operator overload
     * @param      V parameter one, vector for multiply
     * @bug	       No know Bugs
     * @return     Returns multiplication of two vectors
     */
    Vector3
    operator*(const Vector3& V);

    /**
     * @brief      = operator overload
     * @param      V parameter one, vector for equal
     * @bug	       No know Bugs
     * @return     Returns the value of the equal of
     *             your vector whit other
     */
    Vector3&
    operator=(const Vector3& V);


    bool
    operator==(const Vector3& V);

    /**
     * @brief      + operator overload
     * @param      V parameter one, number for sum
     * @bug	       No know Bugs
     * @return     Returns sum between a vector and a float
     */
    Vector3
    operator+(const float& V);

    /**
     * @brief      + operator overload
     * @param      V parameter one, number for rest
     * @bug	       No know Bugs
     * @return     Returns rest between a vector and a float
     */
    Vector3
    operator-(const float& V);

    /**
     * @brief      + operator overload
     * @param      V parameter one, number for multiply
     * @bug	       No know Bugs
     * @return     Returns multiplication between a vector and a float
     */
    Vector3
    operator*(const float& V);

    /**
     * @brief      + operator overload
     * @param      V parameter one, number for divide
     * @bug	       No know Bugs
     * @return     Returns division between a vector and a float
     */
    Vector3
    operator/(const float& V);

    /**
     * @brief      += operator overload
     * @param      V parameter one, vector for sum
     * @bug	       No know Bugs
     * @return     Returns the value of the sum of
     *             your vector whit pother
     */
    Vector3
    operator+=(const Vector3& V);

    /**
     * @brief      -= operator overload
     * @param      V parameter one, vector for sum
     * @bug	       No know Bugs
     * @return     Returns the value of the rest of
     *             your vector whit pother
     */
    Vector3
    operator-=(const Vector3& V);

    /**
     * @brief      *= operator overload
     * @param      V parameter one, vector for sum
     * @bug	       No know Bugs
     * @return     Returns the value of the multiplication of
     *             your vector whit pother
     */
    Vector3
    operator*=(const Vector3& V);

    /**
     * @brief      normalize function
     * @bug	       No know Bugs
     * @return     Returns normalize vector
     */
    Vector3&
    normalize();

    /**
     * @brief      magnitud function
     * @bug	       No know Bugs
     * @return     Returns magnitud of a vector
     */
    float
    magnitud();

    /**
     * @brief      proyection function
     * @param      VectorA parameter one, for dot product
     * @param      VetorB parameter two, for dot product
     * @bug	       No know Bugs
     * @return     Returns a perpendicular vector
     */
    Vector3
    proyection(Vector3& VectorA, Vector3& VetorB);

    /**
     * @brief      Dot function
     * @param      VectorA parameter one, for dot product
     * @param      VetorB parameter two, for dot product
     * @bug	       No know Bugs
     * @return     Returns a scalar
     */
    float
    dot(Vector3& VectorA,
        Vector3& VetorB);

    /**
     * @brief      cross function
     * @param      VectorA parameter one, for cross product
     * @param      VectorB parameter two, for cross product
     * @bug	       No know Bugs
     * @return     Returns a vector
     */
    Vector3
    cross(Vector3& VectorA,
          Vector3& VectorB);



  public:
    /**
     * @brief Public variable member
     */

    /**
     * @Variable m_x
     */
    float m_x;

    /**
     * @Variable m_y
     */
    float m_y;

    /**
     * @Variable m_z
     */
    float m_z;

  };
}

