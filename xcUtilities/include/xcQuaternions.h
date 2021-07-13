
 /*****************************************************************************/
 /**
	* @file    xcQuaternions.h
	* @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
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
		 * @param      x parameter one, element x of quaternion
		 * @param      y parameter one, element y of quaternion
		 * @param      z parameter one, element z of quaternion
		 * @param      w parameter one, element w of quaternion
		 * @bug		     No know Bugs
		 * @return     Returns nothing
		 */
		Quaternion(const float& _x,
			         const float& _y,
			         const float& _z,
			         const float& _w) 
               : x(_x), y(_y), z(_z), w(_w) { };

		/**
		 * @brief      Quaternions function, specific constructor
		 * @param      vector parameter one, vector of quaternions whit a vector3
		 * @param      w parameter two, w of the quaternions
		 * @bug		     No know Bugs
		 * @return     Returns nothing
		 */
		Quaternion(const Vector3& vector,
			         const float& _w) 
               : x(vector.x), y(vector.y), z(vector.z), w(_w) { };

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
		 * @brief      magnitud function, the magnitud of a quaternion
		 * @bug	       No know Bugs
		 * @return     Returns a float
		 */
		float
		magnitud();

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

		//TODO: CAMBIAR EL VECTOR POR VALORES X, Y, Z y EL SCALAR POR W

	  /**
		 * @brief x, 
		 */
		float x;

		/**
		 * @brief y,
		 */
		float y;

		/**
		 * @brief z, the vector of the quaternion
		 */
		float z;

		/**
		 * @brief w, the scalar of the quaternion
		 */
		float w;

		static const Quaternion IDENTITY;

	};
}
