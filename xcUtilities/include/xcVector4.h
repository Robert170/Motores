#pragma once

#include "xcVector3.h"

namespace xcEngineSDK {

	class XC_UTILITY_EXPORT Vector4 
	{

	 public:
		Vector4(float x, float y = 0.f, float z = 0.0f, float w = 0.0f)
			      :m_x(x), m_y(y), m_z(z), m_w(w) { };

		Vector4(Vector2 v, float z = 0.0f, float w = 0.0f)
			      :m_x(v.m_x), m_y(v.m_y), m_z(z), m_w(w) { };

		Vector4(Vector3 v, float w = 0.0f)
			      :m_x(v.m_x), m_y(v.m_y), m_z(v.m_z), m_w(w) { };

		Vector4()
			      :m_x(0.f), m_y(0.f), m_z(0.f), m_w(0.f) { };

		~Vector4() = default;

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
		 * @brief      / operator overload
		 * @param      V parameter one, vector for divide
		 * @bug	       No know Bugs
		 * @return     Returns division of two vectors
		 */
		Vector4
		operator / (const Vector4& V);

		/**
		 * @brief      = operator overload
		 * @param      V parameter one, vector for equal
		 * @bug	       No know Bugs
		 * @return     Returns the value of the equal of
		 *             your vector whit other
		 */
		Vector4
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
		 * @brief      /= operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the division of
		 *             your vector whit pother
		 */
		Vector4
		operator /= (const Vector4& V);

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
		Dot(Vector4& VectorA,
				Vector4& VetorB);

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