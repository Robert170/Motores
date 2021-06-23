/*****************************************************************************/
/**
 * @file    xcVectorI4.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/01/29
 * @brief   Vector4 of int32
 *
 * This class has all necessary math for vector4 of int32, like sum, rest, 
 * dot product, cross product, etc.
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/

#pragma once
#include "xcVectorI3.h"

#include "xcPrerequisitesUtilities.h"


namespace xcEngineSDK {
	
	using xcEngineSDK::int32;

	class XC_UTILITY_EXPORT VectorI4 
	{

	 public:

		/**
		 * @brief default constructor
		 */
		VectorI4() = default;

		/**
		 * @brief default destructor
		 */
		~VectorI4() = default;

		/**
		 * @brief constructor of int32
		 */
		VectorI4(int32 _x, int32 _y = 0, int32 _z = 0, int32 _w = 0)
		         :x(_x), y(_y), z(_z), w(_w) { };

		/**
		 * @brief constructor of a vectorI2 and int32
		 */
		VectorI4(VectorI2 v, int32 _z = 0, int32 _w = 0)
			       :x(v.x), y(v.y), z(_z), w(_w) { };

		/**
		 * @brief constructor of a VectorI4 and int32
		 */
		VectorI4(VectorI3 v, int32 _w = 0)
			       :x(v.x), y(v.y), z(v.z), w(_w) { };

		/**
		 * @brief public functions
		 */

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns sum of two vectors
		 */
		VectorI4
		operator + (const VectorI4& V);

		/**
		 * @brief      - operator overload
		 * @param      V parameter one, vector for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest of two vectors
		 */
		VectorI4
		operator - (const VectorI4& V);

		/**
		 * @brief      * operator overload
		 * @param      V parameter one, vector for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication of two vectors
		 */
		VectorI4
		operator * (const VectorI4& V);

		/**
		 * @brief      = operator overload
		 * @param      V parameter one, vector for equal
		 * @bug	       No know Bugs
		 * @return     Returns the value of the equal of
		 *             your vector whit other
		 */
		VectorI4
		operator = (const VectorI4& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, vector for comparative
		 * @bug	       No know Bugs
		 * @return     Returns true if both vectors are equal
		 */
		bool
		operator == (const VectorI4& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for sum
		 * @bug	       No know Bugs
		 * @return     Returns sum between a vector and a float
		 */
		VectorI4
		operator + (const int32& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest between a vector and a float
		 */
		VectorI4
		operator - (const int32& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication between a vector and a float
		 */
		VectorI4
		operator * (const int32& V);

		/**
		 * @brief      + operator overload
		 * @param      V parameter one, number for divide
		 * @bug	       No know Bugs
		 * @return     Returns division between a vector and a float
		 */
		VectorI4
		operator / (const int32& V);

		/**
		 * @brief      += operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the sum of
		 *             your vector whit pother
		 */
		VectorI4
		operator += (const VectorI4& V);

		/**
		 * @brief      -= operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the rest of
		 *             your vector whit pother
		 */
		VectorI4
		operator -= (const VectorI4& V);

		/**
		 * @brief      *= operator overload
		 * @param      V parameter one, vector for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the multiplication of
		 *             your vector whit pother
		 */
		VectorI4
		operator *= (const VectorI4& V);

		/**
     * @brief      != operator overload
     * @param      V parameter one, matrix equal
     * @bug	       No know Bugs
     * @return     Returns a true if the vectors are different
     */
    bool
    operator!=(const VectorI4& V);

		/**
		 * @brief      normalize function
		 * @bug	       No know Bugs
		 * @return     Returns normalize vector
		 */
		VectorI4&
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
		VectorI4
		proyection(VectorI4& VectorA, VectorI4& VetorB);

		/**
		 * @brief      Dot function
		 * @param      VetorB parameter two, for dot product
		 * @bug	       No know Bugs
		 * @return     Returns a scalar
		 */
		int32
		dot(VectorI4& VetorB);


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
		 * @Variable z
		 */
		int32 z;

		/**
		 * @Variable z
		 */
		int32 w;

	};
}