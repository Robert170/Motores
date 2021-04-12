/**
 * @class xcQuaternions
 *
 * @brief class for the math of the Quaternions
 *
 * This class is the Quaternions logic
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 4/11/2020
 *
 *
 * @bug	No know Bugs
 */
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
		 * @brief      Quaternions, default constructor
		 * @bug		     No know Bugs
		 * @return     Returns nothing
		 */
		 Quaternion() = default;

		/**
		 * @brief      Quaternions, default destructor
		 * @bug		     No know Bugs
		 * @return     Returns nothing
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

	 public:

		/**
		 * @brief public variables member
		 */
	  Vector3 m_quaternionVector;
		float m_scalar;

	};
}