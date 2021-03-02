#pragma once


#include "xcPrerequisitesUtilities.h"


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


		float
		getRadians() {
			return m_angle;
		}

		float
		getRadiansIntoDegrees() {
			return m_angle * 3.1416f / 180.0f;
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
		 * @brief      + operator overload
		 * @param      Value parameter one, radians for comparative
		 * @bug	       No know Bugs
		 * @return     Returns true if both radians are equal
		 */
		bool
		operator == (const float& Value);

		/**
		 * @brief      + operator overload
		 * @param      Value parameter one, number for sum
		 * @bug	       No know Bugs
		 * @return     Returns sum between a radians and a float
		 */
		Radians
		operator + (const float& Value);

		/**
		 * @brief      + operator overload
		 * @param      Value parameter one, number for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest between a radians and a float
		 */
		Radians
		operator - (const float& Value);

		/**
		 * @brief      + operator overload
		 * @param      Value parameter one, number for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication between a radians and a float
		 */
		Radians
		operator * (const float& Value);

		/**
		 * @brief      + operator overload
		 * @param      Value parameter one, number for divide
		 * @bug	       No know Bugs
		 * @return     Returns division between a radians and a float
		 */
		Radians
		operator / (const float& Value);

		/**
		 * @brief      += operator overload
		 * @param      Rad parameter one, radians for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the sum of
		 *             your radians whit pother
		 */
		Radians&
		operator += (const Radians& Rad);

		/**
		 * @brief      -= operator overload
		 * @param      Rad parameter one, radians for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the rest of
		 *             your radians whit pother
		 */
		Radians&
		operator -= (const Radians& Rad);

		/**
		 * @brief      *= operator overload
		 * @param      Rad parameter one, radians for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the multiplication of
		 *             your radians whit pother
		 */
		Radians&
		operator *= (const Radians& Rad);

		/**
		 * @brief      /= operator overload
		 * @param      Rad parameter one, radians for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the division of
		 *             your radians whit pother
		 */
		Radians&
		operator /= (const Radians& Rad);

		/**
		 * Sections to degree using radians
		 */

		 /**
			* @brief      + operator overload
			* @param      Deg parameter one, degrees for sum
			* @bug	       No know Bugs
			* @return     Returns sum of radians whit degree
			*/
		Radians
		operator + (Degrees& Deg);

		/**
		 * @brief      - operator overload
		 * @param      Deg parameter one, degrees for rest
		 * @bug	       No know Bugs
		 * @return     Returns rest of radians whit degree
		 */
		Radians
		operator - (Degrees& Deg);

		/**
		 * @brief      * operator overload
		 * @param      Deg parameter one, degrees for multiply
		 * @bug	       No know Bugs
		 * @return     Returns multiplication of radians whit degree
		 */
		Radians
		operator * (Degrees& Deg);

		/**
		 * @brief      / operator overload
		 * @param      Deg parameter one, degrees for divide
		 * @bug	       No know Bugs
		 * @return     Returns division of radians whit degree
		 */
		Radians
		operator / (Degrees& Deg);

		/**
		 * @brief      + operator overload
		 * @param      Deg parameter one, degrees for comparative
		 * @bug	       No know Bugs
		 * @return     Returns true if radians whit degree are equal
		 */
		bool
		operator == (Degrees& Deg);


		/**
		 * @brief      += operator overload
		 * @param      Deg parameter one, degrees for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the sum radians whit degree
		 */
		Radians&
		operator += (Degrees& Deg);

		/**
		 * @brief      -= operator overload
		 * @param      Deg parameter one, degrees for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the rest radians whit degree
		 */
		Radians&
		operator -= (Degrees& Deg);

		/**
		 * @brief      *= operator overload
		 * @param      Deg parameter one, degrees for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the multiplication radians whit degree
		 */
		Radians&
		operator *= (Degrees& Deg);

		/**
		 * @brief      /= operator overload
		 * @param      Deg parameter one, degrees for sum
		 * @bug	       No know Bugs
		 * @return     Returns the value of the division radians whit degree
		 */
		Radians&
		operator /= (Degrees& Deg);


	 protected:

	 private:
		float m_angle = 0;

	};
}