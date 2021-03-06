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


		float
			getDegrees() {
			return m_angle;
		}

		float
		getDegreesIntoRadians() {
			return m_angle * 3.1416f / 180.0f;
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
		 * @brief      == operator overload
		 * @param      Value parameter one, degrees for comparative
		 * @bug	       No know Bugs
		 * @return     Returns true if both degrees are equal
		 */
		bool
		operator == (const float& Value) const;

		/**
		 * @brief      + operator overload
		 * @param      Value parameter one, number for sum
		 * @bug	       No know Bugs
		 * @return     Returns sum between a degrees and a float
		 */
		Degrees
		operator + (const float& Value) const;

		/**
		 * @brief      + operator overload
		 * @param      Value parameter one, number for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest between a degrees and a float
		 */
		Degrees
	  operator - (const float& Value) const;

		/**
		 * @brief      + operator overload
		 * @param      Value parameter one, number for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication between a degrees and a float
		 */
		Degrees
		operator * (const float& Value) const;

		/**
		 * @brief      + operator overload
		 * @param      Value parameter one, number for divide
		 * @bug	       No know Bugs
		 * @return     Returns division between a degrees and a float
		 */
		Degrees
		operator / (const float& Value) const;

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


		/**
		 * Sections to degree using radians
		 */

		 /**
			* @brief      + operator overload
			* @param      Deg parameter one, degrees for sum
			* @bug	       No know Bugs
			* @return     Returns sum of two degrees
			*/
		Degrees
		operator + (Radians& Rad) const;

		/**
		 * @brief      - operator overload
		 * @param      Deg parameter one, degrees for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest of two degrees
		 */
		Degrees
		operator - (Radians& Rad) const;

		/**
		 * @brief      * operator overload
		 * @param      Deg parameter one, degrees for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication of two degrees
		 */
		Degrees
		operator * (Radians& Rad) const;

		/**
		 * @brief      / operator overload
		 * @param      Deg parameter one, degrees for divide
		 * @bug	       No know Bugs
		 * @return     Returns division of two degrees
		 */
		Degrees
		operator / (Radians& Rad) const;

		/**
		 * @brief      + operator overload
		 * @param      Deg parameter one, degrees for comparative
		 * @bug	       No know Bugs
		 * @return     Returns true if both degrees are equal
		 */
		bool
		operator == (Radians& Rad) const;


		/**
		 * @brief      += operator overload
		 * @param      Deg parameter one, degrees for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the sum of
		 *             your degrees whit pother
		 */
		Degrees&
		operator+=(Radians& Rad);

		/**
		 * @brief      = operator overload
		 * @param      Value parameter one, degrees for comparative
		 * @bug	       No know Bugs
		 * @return     Returns the same degrees but equal to radians
		 */
		Degrees&
		operator=(Radians& Rad);

		/**
		 * @brief      -= operator overload
		 * @param      Deg parameter one, degrees for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the rest of
		 *             your degrees whit pother
		 */
		Degrees&
		operator -= (Radians& Rad);

		/**
		 * @brief      *= operator overload
		 * @param      Deg parameter one, degrees for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the multiplication of
		 *             your degrees whit pother
		 */
		Degrees&
		operator *= (Radians& Rad);

		/**
		 * @brief      /= operator overload
		 * @param      Deg parameter one, degrees for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the division of
		 *             your degrees whit pother
		 */
		Degrees&
		operator /= (Radians& Rad);


	 protected:

	 private:
		float m_angle = 0;

	};
};