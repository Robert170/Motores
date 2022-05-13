#pragma once

#include "xcPrerequisitesUtilities.h"
#include "xcMath.h"


namespace xcEngineSDK {

  class Radians;


	class XC_UTILITY_EXPORT Degrees
	{
	 public:
     Degrees() = default;
     ~Degrees() = default;

		Degrees(float angle)
			      :m_angle(angle) {};

		Degrees(Radians& angle);

		Degrees(Degrees& angle);


		float
		getDegrees() {
			return m_angle;
		}

		float
		getDegreesIntoRadians() {
			return m_angle * Math::DEG2RAD;
		}

		/**
		 * @brief      + operator overload
		 * @param      Deg parameter one, degrees for sum
		 * @bug	       No know Bugs
		 * @return     Returns sum of two degrees
		 */
		Degrees
		operator+(const Degrees& Deg) const;

		/**
		 * @brief      - operator overload
		 * @param      Deg parameter one, degrees for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest of two degrees
		 */
		Degrees
		operator - (const Degrees& Deg) const;

		/**
		 * @brief      * operator overload
		 * @param      Deg parameter one, degrees for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication of two degrees
		 */
		Degrees
		operator * (const Degrees& Deg) const;

		/**
		 * @brief      / operator overload
		 * @param      Deg parameter one, degrees for divide
		 * @bug	       No know Bugs
		 * @return     Returns division of two degrees
		 */
		Degrees
		operator / (const Degrees& Deg) const;

		/**
		 * @brief      == operator overload
		 * @param      Deg parameter one, degrees for comparative
		 * @bug	       No know Bugs
		 * @return     Returns true if both degrees are equal
		 */
		bool
		operator == (const Degrees& Deg) const;


		/**
		 * @brief      += operator overload
		 * @param      Deg parameter one, degrees for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the sum of
		 *             your degrees whit pother
		 */
		Degrees&
		operator += (const Degrees& Deg);

		/**
		 * @brief      -= operator overload
		 * @param      Deg parameter one, degrees for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the rest of
		 *             your degrees whit pother
		 */
		Degrees&
		operator -= (const Degrees& Deg);

		/**
		 * @brief      *= operator overload
		 * @param      Deg parameter one, degrees for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the multiplication of
		 *             your degrees whit pother
		 */
		Degrees&
		operator *= (const Degrees& Deg);

		/**
		 * @brief      /= operator overload
		 * @param      Deg parameter one, degrees for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the division of
		 *             your degrees whit pother
		 */
		Degrees&
		operator /= (const Degrees& Deg);

	 protected:

	 private:
		float m_angle = 0;

	};
};