#pragma once
#include "xcVectorI3.h"

using xcEngineSDK::int32;

class VectorI4 {

 public:
	VectorI4(int32 x, int32 y = 0, int32 z = 0, int32 w = 0)
		       :m_x(x), m_y(y), m_z(z), m_w(w) { };

	VectorI4(VectorI3 v, int32 w = 0)
		       :m_x(v.m_x), m_y(v.m_y), m_z(v.m_z), m_w(w) { };

	VectorI4()
		       :m_x(0.f), m_y(0.f), m_z(0.f), m_w(0.f) { };

	~VectorI4() = default;

	/**
		* @brief      + operator overload
		* @param      V parameter one, vector for sum
		* @bug	      No know Bugs
		* @return     Returns sum of two vectors
	*/
	VectorI4
	operator + (const VectorI4& V);

	/**
		* @brief      - operator overload
		* @param      V parameter one, vector for rest
		* @bug	      No know Bugs
		* @return     Returns rest of two vectors
	*/
	VectorI4
	operator - (const VectorI4& V);

	/**
		* @brief      * operator overload
		* @param      V parameter one, vector for multiply
		* @bug	      No know Bugs
		* @return     Returns multiplication of two vectors
	*/
	VectorI4
	operator * (const VectorI4& V);

	/**
		* @brief      / operator overload
		* @param      V parameter one, vector for divide
		* @bug	      No know Bugs
		* @return     Returns division of two vectors
	*/
	VectorI4
	operator / (const VectorI4& V);

	/**
		* @brief      + operator overload
		* @param      V parameter one, vector for comparate
		* @bug	      No know Bugs
		* @return     Returns true if both vectors are equal
	*/
	bool
	operator == (const VectorI4& V);

	/**
		* @brief      + operator overload
		* @param      V parameter one, number for sum
		* @bug	      No know Bugs
		* @return     Returns sum between a vector and a float
	*/
	VectorI4
	operator + (const float& V);

	/**
		* @brief      + operator overload
		* @param      V parameter one, number for rest
		* @bug	      No know Bugs
		* @return     Returns rest between a vector and a float
	*/
	VectorI4
	operator - (const float& V);

	/**
		* @brief      + operator overload
		* @param      V parameter one, number for multiply
		* @bug	      No know Bugs
		* @return     Returns multiplication between a vector and a float
	*/
	VectorI4
	operator * (const float& V);

	/**
		* @brief      + operator overload
		* @param      V parameter one, number for divide
		* @bug	      No know Bugs
		* @return     Returns division between a vector and a float
	*/
	VectorI4
	operator / (const float& V);

	/**
		* @brief      += operator overload
		* @param      V parameter one, vector for sum
		* @bug	      No know Bugs
		* @return     Returns the value of the sum of
		*             your vector whit pother
	*/
	VectorI4
	operator += (const VectorI4& V);

	/**
		* @brief      -= operator overload
		* @param      V parameter one, vector for sum
		* @bug	      No know Bugs
		* @return     Returns the value of the rest of
		*             your vector whit pother
	*/
	VectorI4
	operator -= (const VectorI4& V);

	/**
		* @brief      *= operator overload
		* @param      V parameter one, vector for sum
		* @bug	      No know Bugs
		* @return     Returns the value of the multiplication of
		*             your vector whit pother
	*/
	VectorI4
	operator *= (const VectorI4& V);

	/**
		* @brief      /= operator overload
		* @param      V parameter one, vector for sum
		* @bug	      No know Bugs
		* @return     Returns the value of the division of
		*             your vector whit pother
	*/
	VectorI4
	operator /= (const VectorI4& V);


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
		* @Variable m_z
	*/
	int32 m_z;

	/**
		* @Variable m_z
	*/
	int32 m_w;

};