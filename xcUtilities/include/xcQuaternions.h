
 /*****************************************************************************/
 /**
	* @file    xcQuaternions.h
	* @author  Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
	* @date    2021/04/11
	* @brief   class for the math of the Quaternions
	*
	* This class is the Quaternions logic
	*
	* @bug	    No known bugs.
	*/
	/*****************************************************************************/
#pragma once

#include "xcPrerequisitesUtilities.h"
#include "xcVector3.h"

using xcEngineSDK::Vector3;

namespace xcEngineSDK {

	class XC_UTILITY_EXPORT Quaternion
	{
	 public:
		/**
		 * @brief public functions
		 */

		/**
		 * @brief default constructor
		 */
		 Quaternion() = default;

		/**
		 * @brief default destructor
		 */
		~Quaternion() = default;


		/**
		 * @brief      Quaternions function, specific constructor
		 * @param      vector parameter one, vector of quaternions whit a vector2
		 * @param      scalar parameter two, scalar of the quaternions
		 * @bug		     No know Bugs
		 * @return     Returns nothing
		 */
		Quaternion(const Vector2& vector,
			         const float& scalar) 
               : m_quaternionVector(Vector2(vector)), m_scalar(scalar) { };

		/**
		 * @brief      Quaternions function, specific constructor
		 * @param      vector parameter one, vector of quaternions whit a vector3
		 * @param      scalar parameter two, scalar of the quaternions
		 * @bug		     No know Bugs
		 * @return     Returns nothing
		 */
		Quaternion(const Vector3& vector,
			         const float& scalar) 
               : m_quaternionVector(vector), m_scalar(scalar) { };

		/**
		 * @brief      + operator overload
		 * @param      quaternion parameter one, quaternion for sum
		 * @bug	       No know Bugs
		 * @return     Returns sum of two quaternion
		 */
		Quaternion
		operator+(const Quaternion& quaternion);

		/**
		 * @brief      - operator overload
		 * @param      quaternion parameter one, quaternion for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest of two quaternion
		 */
		Quaternion
		operator-(const Quaternion& quaternion);

		/**
		 * @brief      * operator overload
		 * @param      quaternion parameter one, quaternion for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication of two quaternion
		 */
		Quaternion
		operator*(const Quaternion& quaternion);

		/**
		 * @brief      * operator overload
		 * @param      quaternion parameter one, scalar for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication of quaternion by a scalar
		 */
		Quaternion
		operator*(const float& scalar);


		/**
		 * @brief      norm function, the norm of a quaternion
		 * @bug	       No know Bugs
		 * @return     Returns a float
		 */
		float
		norm();

		/**
		 * @brief      normalized function, the normalize a quaternion
		 * @bug	       No know Bugs
		 * @return     Returns a normalize quaternion
		 */
		Quaternion&
	  normalized();

		/**
		 * @brief      += operator overload
		 * @param      quaternion parameter one, quaternion for sum
		 * @bug	       No know Bugs
		 * @return     Returns sum of two quaternion
		 */
		Quaternion&
		operator+=(const Quaternion& quaternion);

		/**
		 * @brief      -= operator overload
		 * @param      quaternion parameter one, quaternion for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest of two quaternion
		 */
		Quaternion&
		operator-=(const Quaternion& quaternion);

		/**
		 * @brief      *= operator overload
		 * @param      quaternion parameter one, quaternion for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication of two quaternion
		 */
		Quaternion&
		operator*=(const Quaternion& quaternion);

		/**
		 * @brief      *= operator overload
		 * @param      quaternion parameter one, scalar for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication of quaternion by a scalar
		 */
		Quaternion&
		operator*=(const float& scalar);

		/**
		 * @brief      = operator overload
		 * @param      quaternion parameter one, quaternion to equal
		 * @bug	       No know Bugs
		 * @return     Returns a quaternion equal to other
		 */
		Quaternion&
		operator=(const Quaternion& quaternion);

		/**
		 * @brief      == operator overload
		 * @param      quaternion parameter one, quaternion to compare
		 * @bug	       No know Bugs
		 * @return     Returns a bool, true if are equals and false if are not equals
		 */
		bool
		operator==(const Quaternion& quaternion);

	 public:

		/**
		 * @brief public variables member 
		 */

	 /**
		 * @brief m_quaternionVector, the vector of the quaternion
		 */
	  Vector3 m_quaternionVector;

		/**
		 * @brief m_scalar, the scalar of the quaternion
		 */
		float m_scalar;

	};
}