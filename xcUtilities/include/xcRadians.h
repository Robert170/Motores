#pragma once


#include "xcPrerequisitesUtilities.h"
#include "xcMath.h"

namespace xcEngineSDK {

  class Degrees;

	class XC_UTILITY_EXPORT Radians
	{
	 public:

	  Radians() = default;
    ~Radians() = default;


		Radians(float angle)
			      :m_angle(angle) { };

		Radians(Degrees& angle);

		Radians(const Radians& angle);


		float
		getRadians() {
			return m_angle;
		}

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
		float m_angle = 0;

	};
}