#pragma once

#include "xcVector2.h"

class Vector3 {

 public:
  Vector3(float x, float y = 0.f, float z = 0.0f)
		      :m_x(x), m_y(y), m_z(z) { };

	Vector3(Vector2 v, float z = 0.0f)
		      :m_x(v.m_x), m_y(v.m_y), m_z(z) { };

	Vector3()  
		      :m_x(0.f), m_y(0.f), m_z(0.f) { };

	~Vector3() = default;

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, vector for sum
	 * @bug	       No know Bugs
	 * @return     Returns sum of two vectors
	 */
	Vector3
	operator + (const Vector3& V);

	/**
	 * @brief      - operator overload
	 * @param      V parameter one, vector for rest
	 * @bug	       No know Bugs
	 * @return     Returns rest of two vectors
	 */
	Vector3
	operator - (const Vector3& V);

	/**
	 * @brief      * operator overload
	 * @param      V parameter one, vector for multiply
	 * @bug	       No know Bugs
	 * @return     Returns multiplication of two vectors
	 */
	Vector3
	operator * (const Vector3& V);

	/**
	 * @brief      / operator overload
	 * @param      V parameter one, vector for divide
	 * @bug	       No know Bugs
	 * @return     Returns division of two vectors
	 */
	Vector3
	operator / (const Vector3& V);

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, vector for comparative
	 * @bug	       No know Bugs
	 * @return     Returns true if both vectors are equal
	 */

	/**
	 * @brief      = operator overload
	 * @param      V parameter one, vector for equal
	 * @bug	       No know Bugs
	 * @return     Returns the value of the equal of
	 *             your vector whit other
	 */
	Vector3
	operator = (const Vector3& V);


	bool
	operator == (const Vector3& V);

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, number for sum
	 * @bug	       No know Bugs
	 * @return     Returns sum between a vector and a float
	 */
	Vector3
	operator + (const float& V);

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, number for rest
	 * @bug	       No know Bugs
	 * @return     Returns rest between a vector and a float
	 */
	Vector3
	operator - (const float& V);

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, number for multiply
	 * @bug	       No know Bugs
	 * @return     Returns multiplication between a vector and a float
	 */
	Vector3
	operator * (const float& V);

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, number for divide
	 * @bug	       No know Bugs
	 * @return     Returns division between a vector and a float
	 */
	Vector3
	operator / (const float& V);

	/**
	 * @brief      += operator overload
	 * @param      V parameter one, vector for sum
	 * @bug	       No know Bugs
	 * @return     Returns the value of the sum of
	 *             your vector whit pother
	 */
	Vector3
	operator += (const Vector3& V);

	/**
	 * @brief      -= operator overload
	 * @param      V parameter one, vector for sum
	 * @bug	       No know Bugs
	 * @return     Returns the value of the rest of
	 *             your vector whit pother
	 */
	Vector3
	operator -= (const Vector3& V);

	/**
	 * @brief      *= operator overload
	 * @param      V parameter one, vector for sum
	 * @bug	       No know Bugs
	 * @return     Returns the value of the multiplication of
	 *             your vector whit pother
	 */
	Vector3
	operator *= (const Vector3& V);

	/**
	 * @brief      /= operator overload
	 * @param      V parameter one, vector for sum
	 * @bug	       No know Bugs
	 * @return     Returns the value of the division of
	 *             your vector whit pother
	 */
	Vector3
	operator /= (const Vector3& V);


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

