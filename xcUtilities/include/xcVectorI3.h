#pragma once

#include "xcPlatformTypes.h"
#include "xcVectorI2.h"

using xcEngineSDK::int32;

namespace xcEngineSDK {

	class VectorI3 {
	 public:
	  VectorI3(int32 x, int32 y = 0, int32 z = 0)
			       :m_x(x), m_y(y), m_z(z) { };

		VectorI3(VectorI2 v, int32 z = 0)
			       :m_x(v.m_x), m_y(v.m_y), m_z(z) { };

		VectorI3()
			       :m_x(0), m_y(0), m_z(0) { };

		~VectorI3() = default;

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns sum of two vectors
		 */
		VectorI3
		operator + (const VectorI3& V);

		/**
		 * @brief      - operator overload
		 * @param      V parameter one, vector for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest of two vectors
		 */
		VectorI3
		operator - (const VectorI3& V);

		/**
		 * @brief      * operator overload
		 * @param      V parameter one, vector for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication of two vectors
		 */
		VectorI3
		operator * (const VectorI3& V);

		/**
		 * @brief      / operator overload
		 * @param      V parameter one, vector for divide
		 * @bug	       No know Bugs
		 * @return     Returns division of two vectors
		 */
		VectorI3
		operator / (const VectorI3& V);

		/**
		 * @brief      = operator overload
		 * @param      V parameter one, vector for equal
		 * @bug	       No know Bugs
		 * @return     Returns the value of the equal of
		 *             your vector whit other
		 */
		VectorI3
		operator = (const VectorI3& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, vector for comparative
		 * @bug	       No know Bugs
		 * @return     Returns true if both vectors are equal
		 */
		bool
		operator == (const VectorI3& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for sum
		 * @bug	       No know Bugs
		 * @return     Returns sum between a vector and a float
		 */
		VectorI3
		operator + (const int32& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest between a vector and a float
		 */
		VectorI3
		operator - (const int32& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication between a vector and a float
		 */
		VectorI3
		operator * (const int32& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for divide
		 * @bug	       No know Bugs
		 * @return     Returns division between a vector and a float
		 */
		VectorI3
		operator / (const int32& V);

		/**
		 * @brief      += operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the sum of
		 *             your vector whit pother
		 */
		VectorI3
		operator += (const VectorI3& V);

		/**
		 * @brief      -= operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the rest of
		 *             your vector whit pother
		 */
		VectorI3
		operator -= (const VectorI3& V);

		/**
		 * @brief      *= operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the multiplication of
		 *             your vector whit pother
		 */
		VectorI3
		operator *= (const VectorI3& V);

		/**
		 * @brief      /= operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the division of
		 *             your vector whit pother
		 */
		VectorI3
		operator /= (const VectorI3& V);

		/**
		 * @brief      normalize function
		 * @bug	       No know Bugs
		 * @return     Returns normalize vector
		 */
		VectorI3
		normalize();

		/**
		 * @brief      magnitud function
		 * @bug	       No know Bugs
		 * @return     Returns magnitud of a vector
		 */
		int32
		magnitud();

		/**
		 * @brief      proyection function
		 * @param      VectorA parameter one, for dot product
		 * @param      VetorB parameter two, for dot product
		 * @bug	       No know Bugs
		 * @return     Returns a perpendicular vector
		 */
		VectorI3
		proyection(VectorI3& VectorA, VectorI3& VetorB);


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

		/**
			* @Variable m_y
		*/
		int32 m_z;

	};
}