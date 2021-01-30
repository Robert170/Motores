#include "xcVector2.h"

Vector2 
Vector2::operator + (const Vector2& V) {
	
	return Vector2(m_x + V.m_x, m_y + V.m_y);
}

Vector2 
Vector2::operator - (const Vector2& V) {

  return Vector2(m_x - V.m_x, m_y - V.m_y);
}

Vector2 
Vector2::operator * (const Vector2& V) {

	return Vector2(m_x * V.m_x, m_y * V.m_y);
}

Vector2 
Vector2::operator / (const Vector2& V) {

	return Vector2(m_x / V.m_x, m_y / V.m_y);
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

Vector2 
Vector2::operator += (const Vector2& V) {

	m_x += V.m_x;
	m_y += V.m_y;
	return *this;
}

Vector2 
Vector2::operator -= (const Vector2& V) {
	
	m_x -= V.m_x;
	m_y -= V.m_y;
	return *this;
}

Vector2 
Vector2::operator *= (const Vector2& V) {

	m_x *= V.m_x;
	m_y *= V.m_y;
	return *this;
}

Vector2 
Vector2::operator /= (const Vector2& V) {

	m_x /= V.m_x;
	m_y /= V.m_y;
	return *this;
}
