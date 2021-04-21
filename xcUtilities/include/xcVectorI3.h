/*****************************************************************************/
/**
 * @file    xcVectorI3.h
 * @author  Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/01/27
 * @brief   Vector3 of int32
 *
 * This class has all necessary math for vector3 of int32, like sum, rest,
 * dot product, cross product, etc.
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/

#pragma once
#include "xcPrerequisitesUtilities.h"
#include "xcVectorI2.h"

using xcEngineSDK::int32;

namespace xcEngineSDK {

	class XC_UTILITY_EXPORT VectorI3 
	{
	 public:

		/**
		 * @brief default constructor
		 */
		VectorI3() = default;

		/**
		 * @brief default destructor
		 */
		~VectorI3() = default;

		/**
		 * @brief constructor of  int32
		 */
	  VectorI3(int32 x, int32 y = 0, int32 z = 0)
			       :m_x(x), m_y(y), m_z(z) { };

		/**
		 * @brief constructor of a VectorI2 and int32
		 */
		VectorI3(VectorI2 v, int32 z = 0)
			       :m_x(v.m_x), m_y(v.m_y), m_z(z) { };

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
		operator-(const VectorI3& V);

		/**
		 * @brief      * operator overload
		 * @param      V parameter one, vector for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication of two vectors
		 */
		VectorI3
		operator*(const VectorI3& V);

		/**
		 * @brief      = operator overload
		 * @param      V parameter one, vector for equal
		 * @bug	       No know Bugs
		 * @return     Returns the value of the equal of
		 *             your vector whit other
		 */
		VectorI3&
		operator=(const VectorI3& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, vector for comparative
		 * @bug	       No know Bugs
		 * @return     Returns true if both vectors are equal
		 */
		bool
		operator==(const VectorI3& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for sum
		 * @bug	       No know Bugs
		 * @return     Returns sum between a vector and a float
		 */
		VectorI3
		operator+(const int32& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest between a vector and a float
		 */
		VectorI3
		operator-(const int32& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication between a vector and a float
		 */
		VectorI3
		operator*(const int32& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for divide
		 * @bug	       No know Bugs
		 * @return     Returns division between a vector and a float
		 */
		VectorI3
		operator/(const int32& V);

		/**
		 * @brief      += operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the sum of
		 *             your vector whit pother
		 */
		VectorI3&
		operator+=(const VectorI3& V);

		/**
		 * @brief      -= operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the rest of
		 *             your vector whit pother
		 */
		VectorI3&
		operator-=(const VectorI3& V);

		/**
		 * @brief      *= operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the multiplication of
		 *             your vector whit pother
		 */
		VectorI3&
		operator*=(const VectorI3& V);

		/**
     * @brief      != operator overload
     * @param      V parameter one, matrix equal
     * @bug	       No know Bugs
     * @return     Returns a true if the vectors are different
     */
    bool
    operator!=(const VectorI3& V);

		/**
		 * @brief      normalize function
		 * @bug	       No know Bugs
		 * @return     Returns normalize vector
		 */
		VectorI3&
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
		proyection(VectorI3& VectorA, 
			         VectorI3& VetorB);

		/**
		 * @brief      Dot function
		 * @param      VectorA parameter one, for dot product
		 * @param      VetorB parameter two, for dot product
		 * @bug	       No know Bugs
		 * @return     Returns a scalar
		 */
		int32
		dot(VectorI3& VectorA,
				VectorI3& VetorB);

		/**
     * @brief      cross function
     * @param      VectorA parameter one, for cross product
     * @param      VectorB parameter two, for cross product
     * @bug	       No know Bugs
     * @return     Returns a vector
     */
    VectorI3
    cross(VectorI3& VectorA,
          VectorI3& VectorB);


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