#pragma once

#include "xcPlatformTypes.h"

using xcEngineSDK::int32;

class VectorI2 {
 public:
	VectorI2(int32 x, int32 y = 0)
		       :m_x(x), m_y(y) { };

	VectorI2() 
		       :m_x(0), m_y(0) { };

	~VectorI2() = default;

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, vector for sum
	 * @bug	       No know Bugs
	 * @return     Returns sum of two vectors
	 */
	VectorI2
	operator + (const VectorI2& V);

	/**
	 * @brief      - operator overload
	 * @param      V parameter one, vector for rest
	 * @bug	       No know Bugs
	 * @return     Returns rest of two vectors
	 */
	VectorI2
	operator - (const VectorI2& V);

	/**
	 * @brief      * operator overload
	 * @param      V parameter one, vector for multiply
	 * @bug	       No know Bugs
	 * @return     Returns multiplication of two vectors
	 */
	VectorI2
	operator * (const VectorI2& V);

	/**
	 * @brief      / operator overload
	 * @param      V parameter one, vector for divide
	 * @bug	       No know Bugs
	 * @return     Returns division of two vectors
	 */
	VectorI2
	operator / (const VectorI2& V);

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, vector for comparative
	 * @bug	       No know Bugs
	 * @return     Returns true if both vectors are equal
	 */
	bool
	operator == (const VectorI2& V);

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, number for sum
	 * @bug	       No know Bugs
	 * @return     Returns sum between a vector and a float
	 */
	VectorI2
	operator + (const int32& V);

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, number for rest
	 * @bug	       No know Bugs
	 * @return     Returns rest between a vector and a float
	 */
	VectorI2
	operator - (const int32& V);

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, number for multiply
	 * @bug	       No know Bugs
	 * @return     Returns multiplication between a vector and a float
	 */
	VectorI2
	operator * (const int32& V);

	/**
	 * @brief      + operator overload
	 * @param      V parameter one, number for divide
	 * @bug	       No know Bugs
	 * @return     Returns division between a vector and a float
	 */
	VectorI2
	operator / (const int32& V);

	/**
	 * @brief      += operator overload
	 * @param      V parameter one, vector for sum
	 * @bug	       No know Bugs
	 * @return     Returns the value of the sum of
	 *             your vector whit pother
	 */
	VectorI2
	operator += (const VectorI2& V);

	/**
	 * @brief      -= operator overload
	 * @param      V parameter one, vector for sum
	 * @bug	       No know Bugs
	 * @return     Returns the value of the rest of
	 *             your vector whit pother
	 */
	VectorI2
	operator -= (const VectorI2& V);

	/**
	 * @brief      *= operator overload
	 * @param      V parameter one, vector for sum
	 * @bug	       No know Bugs
	 * @return     Returns the value of the multiplication of
	 *             your vector whit pother
	 */
	VectorI2
	operator *= (const VectorI2& V);

	/**
	 * @brief      /= operator overload
	 * @param      V parameter one, vector for sum
	 * @bug	       No know Bugs
	 * @return     Returns the value of the division of
	 *             your vector whit pother
	 */
	VectorI2
	operator /= (const VectorI2& V);


 public:
	/**
	 * @brief Public variable member
	 */

	 /**
		* @Variable m_x
		*/
	int32 m_x;

	/**
	 * @Variable m_y
	 */
	int32 m_y;

};


