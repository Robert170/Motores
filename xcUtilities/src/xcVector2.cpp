#include "xcVector2.h"

using xcEngineSDK::Vector2;

namespace xcEngineSDK {
	Vector2
	Vector2::operator + (const Vector2& V) {

		return Vector2(m_x + V.m_x, m_y + V.m_y);
	}

	Vector2
	Vector2::operator-(const Vector2& V) {

		return Vector2(m_x - V.m_x, m_y - V.m_y);
	}

	Vector2
	Vector2::operator*(const Vector2& V) {

		return Vector2(m_x * V.m_x, m_y * V.m_y);
	}


	Vector2&
	Vector2::operator=(const Vector2& V) {
		m_x = V.m_x;
		m_y = V.m_y;
		return *this;
	}

	bool
	Vector2::operator == (const Vector2& V) {

		if (m_x == V.m_x && m_y == V.m_y) {
			return true;
		}
		else {
			return false;
		}
	}

	Vector2
	Vector2::operator + (const float& V) {

		return Vector2(m_x + V, m_y + V);
	}

	Vector2
	Vector2::operator - (const float& V) {

		return Vector2(m_x - V, m_y - V);
	}

	Vector2
	Vector2::operator * (const float& V) {

		return Vector2(m_x * V, m_y * V);
	}

	Vector2
	Vector2::operator / (const float& V) {

		return Vector2(m_x / V, m_y / V);
	}

	Vector2&
	Vector2::operator += (const Vector2& V) {

		m_x += V.m_x;
		m_y += V.m_y;
		return *this;
	}

	Vector2&
	Vector2::operator -= (const Vector2& V) {

		m_x -= V.m_x;
		m_y -= V.m_y;
		return *this;
	}

	Vector2&
	Vector2::operator *= (const Vector2& V) {

		m_x *= V.m_x;
		m_y *= V.m_y;
		return *this;
	}

	Vector2& 
	Vector2::normalize() {
		float Temp = this->magnitud();

		if (Temp != 0) {
			//divide the vector whit temp
			this->m_x = m_x / Temp;
			this->m_y = m_y / Temp;
			return *this;
		}
		else {
			return *this;
		}
	}

	float 
	Vector2::magnitud() {
		float x= sqrtf(powf(m_x, 2) + powf(m_y, 2));
		return x;
	}

	Vector2
	Vector2::proyection(Vector2& VectorA, 
		                  Vector2& VetorB) {

		return ((VectorA * VetorB) / powf(VetorB.magnitud(), 2) * VetorB);
	}

	float 
	Vector2::dot(Vector2& VectorB) {

		return (this->m_x * VectorB.m_x) + (this->m_y * VectorB.m_y);
	}

	float
	Vector2::cross(Vector2& VectorB) {

		return (this->m_x * VectorB.m_y) - (this->m_y * VectorB.m_x);
	}
}
