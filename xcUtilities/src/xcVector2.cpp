#include "xcVector2.h"

using xcEngineSDK::Vector2;

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

Vector2 
Vector2::operator = (const Vector2& V) {
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

Vector2 Vector2::normalize()
{
  float Temp = this->magnitud();

  if (Temp != 0) {
    //divide the vector whit temp
		return Vector2(m_x / Temp, m_y / Temp);
  }
  else {
		return Vector2();
  }
}

float Vector2::magnitud()
{
	return sqrtf(powf(m_x, 2) + powf(m_y, 2));
}

Vector2 
Vector2::proyection(Vector2& VectorA, Vector2& VetorB) {

	return ((VectorA * VetorB) / powf(VetorB.magnitud(), 2) * VetorB);
}
