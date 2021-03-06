#pragma once
#include <cmath>

#include "xcPrerequisitesUtilities.h"

using xcEngineSDK::int32;
namespace xcEngineSDK {

	class XC_UTILITY_EXPORT VectorI2 
	{
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
		operator+(const VectorI2& V);

		/**
		 * @brief      - operator overload
		 * @param      V parameter one, vector for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest of two vectors
		 */
		VectorI2
		operator-(const VectorI2& V);

		/**
		 * @brief      * operator overload
		 * @param      V parameter one, vector for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication of two vectors
		 */
		VectorI2
		operator*(const VectorI2& V);

		/**
		 * @brief      = operator overload
		 * @param      V parameter one, vector for equal
		 * @bug	       No know Bugs
		 * @return     Returns the value of the equal of
		 *             your vector whit other
		 */
		VectorI2
		operator=(const VectorI2& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, vector for comparative
		 * @bug	       No know Bugs
		 * @return     Returns true if both vectors are equal
		 */
		bool
		operator==(const VectorI2& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for sum
		 * @bug	       No know Bugs
		 * @return     Returns sum between a vector and a float
		 */
		VectorI2
		operator+(const int32& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest between a vector and a float
		 */
		VectorI2
		operator-(const int32& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication between a vector and a float
		 */
		VectorI2
		operator*(const int32& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for divide
		 * @bug	       No know Bugs
		 * @return     Returns division between a vector and a float
		 */
		VectorI2
		operator/(const int32& V);

		/**
		 * @brief      += operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the sum of
		 *             your vector whit pother
		 */
		VectorI2&
		operator+=(const VectorI2& V);

		/**
		 * @brief      -= operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the rest of
		 *             your vector whit pother
		 */
		VectorI2&
		operator-=(const VectorI2& V);

		/**
		 * @brief      *= operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the multiplication of
		 *             your vector whit pother
		 */
		VectorI2&
		operator*=(const VectorI2& V);

		/**
		 * @brief      != operator overload
		 * @param      V parameter one, matrix equal
		 * @bug	       No know Bugs
		 * @return     Returns a true if the vectors are different
		 */
		bool
		operator!=(const VectorI2& V);

		
		/**
		 * @brief      normalize function
		 * @bug	       No know Bugs
		 * @return     Returns normalize vector
		 */
		VectorI2&
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
		VectorI2
		proyection(VectorI2& VectorA,
			         VectorI2& VetorB);

		/**
		 * @brief      Dot function
		 * @param      VectorA parameter one, for dot product
		 * @param      VetorB parameter two, for dot product
		 * @bug	       No know Bugs
		 * @return     Returns a scalar
	   */
		int32
		Dot(VectorI2& VectorA,
			  VectorI2& VetorB);


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
}


