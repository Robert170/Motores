#include "xcVector2.h"

using xcEngineSDK::Vector2;

namespace xcEngineSDK {
	Vector2
	Vector2::operator + (const Vector2& V) {

		return Vector2(x + V.x, y + V.y);
	}

	Vector2
	Vector2::operator-(const Vector2& V) {

		return Vector2(x - V.x, y - V.y);
	}

	Vector2
	Vector2::operator*(const Vector2& V) {

		return Vector2(x * V.x, y * V.y);
	}


	Vector2&
	Vector2::operator=(const Vector2& V) {
		x = V.x;
		y = V.y;
		return *this;
	}

	bool
	Vector2::operator == (const Vector2& V) {

		if (x == V.x && y == V.y) {
			return true;
		}
		else {
			return false;
		}
	}

	Vector2
	Vector2::operator + (const float& V) {

		return Vector2(x + V, y + V);
	}

	Vector2
	Vector2::operator - (const float& V) {

		return Vector2(x - V, y - V);
	}

	Vector2
	Vector2::operator * (const float& V) {

		return Vector2(x * V, y * V);
	}

	Vector2
	Vector2::operator / (const float& V) {

		return Vector2(x / V, y / V);
	}

	Vector2&
	Vector2::operator += (const Vector2& V) {

		x += V.x;
		y += V.y;
		return *this;
	}

	Vector2&
	Vector2::operator -= (const Vector2& V) {

		x -= V.x;
		y -= V.y;
		return *this;
	}

	Vector2&
	Vector2::operator *= (const Vector2& V) {

		x *= V.x;
		y *= V.y;
		return *this;
	}

	Vector2& 
	Vector2::normalize() {
		float Temp = this->magnitud();

		if (Temp != 0) {
			//divide the vector whit temp
			this->x = x / Temp;
			this->y = y / Temp;
			return *this;
		}
		else {
			return *this;
		}
	}

	float 
	Vector2::magnitud() {
		float x= sqrtf(powf(x, 2) + powf(y, 2));
		return x;
	}

	Vector2
	Vector2::proyection(Vector2& VectorA, 
		                  Vector2& VetorB) {

		return ((VectorA * VetorB) / powf(VetorB.magnitud(), 2) * VetorB);
	}

	float 
	Vector2::dot(Vector2& VectorB) {

		return (this->x * VectorB.x) + (this->y * VectorB.y);
	}

	float
	Vector2::cross(Vector2& VectorB) {

		return (this->x * VectorB.y) - (this->y * VectorB.x);
	}
}
