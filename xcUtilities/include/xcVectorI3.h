/*****************************************************************************/
/**
 * @file    xcVectorI3.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
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
	  VectorI3(int32 _x, int32 _y = 0, int32 _z = 0)
			       :x(_x), y(_y), z(_z) { };

		/**
		 * @brief constructor of a VectorI2 and int32
		 */
		VectorI3(VectorI2 v, int32 z = 0)
			       :x(v.x), y(v.y), z(z) { };

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
		 * @param      VetorB parameter two, for dot product
		 * @bug	       No know Bugs
		 * @return     Returns a scalar
		 */
		int32
		dot(VectorI3& VetorB);

		/**
     * @brief      cross function
     * @param      VectorB parameter two, for cross product
     * @bug	       No know Bugs
     * @return     Returns a vector
     */
    VectorI3
    cross(VectorI3& VectorB);

		/**
     * @brief      - operator overload
     * @bug	       No know Bugs
     * @return     Returns a negated vector
     */
		VectorI3
    operator-() const;

	public:
		/**
			* @brief Public variable member
		*/

		/**
			* @Variable x
		*/
		int32 x;

		/**
			* @Variable y
		*/
		int32 y;

		/**
			* @Variable y
		*/
		int32 z;

		static const VectorI3 ZERO;
		static const VectorI3 UNIT;

	};
}