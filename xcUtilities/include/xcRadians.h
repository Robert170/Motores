/*****************************************************************************/
/**
 * @file    xcRadians.h
 * @author  Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 * @date    2021/01/31
 * @brief   class for the math of the radians
 *
 * This class contain the math logic to use radians and is compatible whit
 * degrees
 *
 * @bug	    No known bugs.
 */
 /*****************************************************************************/

#pragma once

#include "xcPrerequisitesUtilities.h"
#include "xcMath.h"

namespace xcEngineSDK {

  class Degrees;

	class XC_UTILITY_EXPORT Radians
	{
	 public:

	  /**
     * @brief default constructor
     */
    Radians() = default;

    /**
     * @brief default destructor
     */
    ~Radians() = default;

		/**
		 * @brief constructor of float
		 */
		Radians(float angle)
			      :m_angle(angle) { };

		/**
		 * @brief constructor of degrees
		 */
		Radians(Degrees& angle);

		/**
		 * @brief constructor of radians
		 */
		Radians(const Radians& angle);


		/**
		 * @brief      getRadians function, to get the angle of the radians
		 * @bug	       No know Bugs
		 * @return     Returns the angle
		 */
		float
		getRadians() {
			return m_angle;
		}

		/**
		 * @brief      getRadiansIntoDegrees function, to get the radians transform into
		 * 			       degrees
		 * @bug	       No know Bugs
		 * @return     Returns the angle
		 */
		float
		getRadiansIntoDegrees() {
			return m_angle * Math::RAD2DEG;
		}


		/**
		 * @brief      + operator overload
		 * @param      Rad parameter one, radians for sum
		 * @bug	       No know Bugs
		 * @return     Returns sum of two radians
		 */
		Radians
		operator + (const Radians& Rad);

		/**
		 * @brief      - operator overload
		 * @param      Rad parameter one, radians for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest of two radians
		 */
		Radians
		operator - (const Radians& Rad);

		/**
		 * @brief      * operator overload
		 * @param      Rad parameter one, radians for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication of two radians
		 */
		Radians
		operator * (const Radians& Rad);

		/**
		 * @brief      / operator overload
		 * @param      Rad parameter one, radians for divide
		 * @bug	       No know Bugs
		 * @return     Returns division of two radians
		 */
		Radians
		operator / (const Radians& Rad);

		/**
		 * @brief      + operator overload
		 * @param      Rad parameter one, radians for comparative
		 * @bug	       No know Bugs
		 * @return     Returns true if both radians are equal
		 */
		bool
		operator == (const Radians& Rad);

		/**
		 * @brief      += operator overload
		 * @param      Rad parameter one, radians for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the sum of
		 *             your radians whit pother
		 */
		Radians&
		operator+=(const Radians& Rad);

		/**
		 * @brief      -= operator overload
		 * @param      Rad parameter one, radians for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the rest of
		 *             your radians whit pother
		 */
		Radians&
		operator-=(const Radians& Rad);

		/**
		 * @brief      *= operator overload
		 * @param      Rad parameter one, radians for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the multiplication of
		 *             your radians whit pother
		 */
		Radians&
		operator*=(const Radians& Rad);

		/**
		 * @brief      /= operator overload
		 * @param      Rad parameter one, radians for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the division of
		 *             your radians whit pother
		 */
		Radians&
		operator/=(const Radians& Rad);


	 protected:

	 private:

		/**
     * @brief private members
     */

    /**
     * @brief m_angle, angle of the radian
     */
		float m_angle = 0;

	};
}