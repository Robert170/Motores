#pragma once

class Vector2 {
 public:
	Vector2(float x, float y = 0.f)
		      :m_x(x), m_y(y) { };
	Vector2() 
		      :m_x(0.f), m_y(0.f) { };

	~Vector2() = default;

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, vector for sum
	 * @bug	       No know Bugs
	 * @return     Returns sum of two vectors
	 */
	Vector2 
	operator + (const Vector2& V);

	/**
	 * @brief      - operator overload
	 * @param      V parameter one, vector for rest
	 * @bug	       No know Bugs
	 * @return     Returns rest of two vectors
	 */
  Vector2 
	operator - (const Vector2& V);

	/**
	 * @brief      * operator overload
	 * @param      V parameter one, vector for multiply
	 * @bug	       No know Bugs
	 * @return     Returns multiplication of two vectors
	 */
	Vector2 
	operator * (const Vector2& V);

	/**
	 * @brief      / operator overload
	 * @param      V parameter one, vector for divide
	 * @bug	       No know Bugs
	 * @return     Returns division of two vectors
	 */
	Vector2 
	operator / (const Vector2& V);


	/**
	 * @brief      = operator overload
	 * @param      V parameter one, vector for equal
	 * @bug	       No know Bugs
	 * @return     Returns the value of the equal of
	 *             your vector whit other
	 */
	Vector2
	operator = (const Vector2& V);

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, vector for comparative
	 * @bug	       No know Bugs
	 * @return     Returns true if both vectors are equal
	 */
	bool 
	operator == (const Vector2& V);

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, number for sum
	 * @bug	       No know Bugs
	 * @return     Returns sum between a vector and a float
	 */
	Vector2 
	operator + (const float& V);

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, number for rest
	 * @bug	       No know Bugs
	 * @return     Returns rest between a vector and a float
	 */
	Vector2
	operator - (const float& V);

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, number for multiply
	 * @bug	       No know Bugs
	 * @return     Returns multiplication between a vector and a float
	 */
	Vector2 
	operator * (const float& V);

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, number for divide
	 * @bug	       No know Bugs
	 * @return     Returns division between a vector and a float
 	 */
	Vector2 
	operator / (const float& V);

	/**
	 * @brief      += operator overload
	 * @param      V parameter one, vector for sum
	 * @bug	       No know Bugs
	 * @return     Returns the value of the sum of 
	 *             your vector whit pother
	 */
	Vector2
	operator += (const Vector2& V);

	/**
	 * @brief      -= operator overload
	 * @param      V parameter one, vector for sum
	 * @bug	       No know Bugs
	 * @return     Returns the value of the rest of
	 *             your vector whit pother
	 */
	Vector2
	operator -= (const Vector2& V);

	/**
	 * @brief      *= operator overload
	 * @param      V parameter one, vector for sum
	 * @bug	       No know Bugs
	 * @return     Returns the value of the multiplication of
	 *             your vector whit pother
	 */
	Vector2
	operator *= (const Vector2& V);

	/**
	 * @brief      /= operator overload
	 * @param      V parameter one, vector for sum
	 * @bug	       No know Bugs
	 * @return     Returns the value of the division of
	 *             your vector whit pother
	 */
	Vector2
	operator /= (const Vector2& V);



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

};

