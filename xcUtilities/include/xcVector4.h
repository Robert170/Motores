/*****************************************************************************/
/**
 * @file    xcVector4.h
 * @author  Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/01/28
 * @brief   Vector4 of float
 *
 * This class has all necessary math for vector4 of float, like sum, rest,
 * dot product, cross product, etc.
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/
#pragma once

#include "xcPrerequisitesUtilities.h"
#include "xcVector3.h"

namespace xcEngineSDK {


	class XC_UTILITY_EXPORT Vector4 
	{

	 public:

		/**
		 * @brief default constructor
		 */
		Vector4() = default;

		/**
		 * @brief default destructor
		 */
		~Vector4() = default;

		/**
		 * @brief constructor of float
		 */
		Vector4(float x, float y = 0.f, float z = 0.0f, float w = 0.0f)
			      :m_x(x), m_y(y), m_z(z), m_w(w) { };

		/**
		 * @brief constructor of a vectorI2 and float
		 */
		Vector4(Vector2 v, float z = 0.0f, float w = 0.0f)
			      :m_x(v.m_x), m_y(v.m_y), m_z(z), m_w(w) { };

		/**
		 * @brief constructor of a VectorI4 and float
		 */
		Vector4(Vector3 v, float w = 0.0f)
			      :m_x(v.m_x), m_y(v.m_y), m_z(v.m_z), m_w(w) { };

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns sum of two vectors
		 */
		Vector4
		operator + (const Vector4& V);

		/**
		 * @brief      - operator overload
		 * @param      V parameter one, vector for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest of two vectors
		 */
		Vector4
		operator - (const Vector4& V);

		/**
		 * @brief      * operator overload
		 * @param      V parameter one, vector for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication of two vectors
		 */
		Vector4
		operator * (const Vector4& V);

		/**
		 * @brief      = operator overload
		 * @param      V parameter one, vector for equal
		 * @bug	       No know Bugs
		 * @return     Returns the value of the equal of
		 *             your vector whit other
		 */
		Vector4&
		operator = (const Vector4& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, vector for comparative
		 * @bug	       No know Bugs
		 * @return     Returns true if both vectors are equal
		 */
		bool
		operator == (const Vector4& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for sum
		 * @bug	       No know Bugs
		 * @return     Returns sum between a vector and a float
		 */
		Vector4
		operator + (const float& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest between a vector and a float
		 */
		Vector4
		operator - (const float& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication between a vector and a float
		 */
		Vector4
		operator * (const float& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for divide
		 * @bug	       No know Bugs
		 * @return     Returns division between a vector and a float
		 */
		Vector4
		operator / (const float& V);

		/**
		 * @brief      += operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the sum of
		 *             your vector whit pother
		 */
		Vector4
		operator += (const Vector4& V);

		/**
		 * @brief      -= operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the rest of
		 *             your vector whit pother
		 */
		Vector4
		operator -= (const Vector4& V);

		/**
		 * @brief      *= operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the multiplication of
		 *             your vector whit pother
		 */
		Vector4
		operator *= (const Vector4& V);

		/**
		 * @brief      normalize function
		 * @bug	       No know Bugs
		 * @return     Returns normalize vector
		 */
		Vector4&
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
		Vector4
		proyection(Vector4& VectorA, Vector4& VetorB);

		/**
		 * @brief      Dot function
		 * @param      VectorA parameter one, for dot product
		 * @param      VetorB parameter two, for dot product
		 * @bug	       No know Bugs
		 * @return     Returns a scalar
		 */
		float
		dot(Vector4& VectorA,
				Vector4& VectorB);

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

		/**
		 * @Variable m_z
		 */
		float m_w;

	};
}