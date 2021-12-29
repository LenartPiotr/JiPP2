#include "pch.h"
#include "Vector.h"

using System::Math;

Vector::Vector() :x(0), y(0) {}

Vector::Vector(double x, double y) : x(x), y(y) {}

Vector::Vector(const Vector& source) : x(source.x), y(source.y) {}

Vector::Vector(const Vector& p1, const Vector& p2)
	: x(p2.x - p1.x), y(p2.y - p1.y) {}

Vector::Vector(const Angle& angle) : x(Math::Cos(angle.radians())), y(Math::Sin(angle.radians())) {}

Vector::Vector(const Angle& angle, double value) : x(Math::Cos(angle.radians())* value), y(Math::Sin(angle.radians())* value) {}

Angle Vector::toAngle() const
{
	return Angle(Math::Atan2(y, x));
}

double Vector::getX() const
{
	return x;
}

double Vector::getY() const
{
	return y;
}

void Vector::setX(double value)
{
	x = value;
}

void Vector::setY(double value)
{
	y = value;
}

double Vector::length() const
{
	return Math::Sqrt(x * x + y * y);
}

Vector Vector::normalize() const
{
	double len = length();
	return Vector(x / len, y / len);
}

Vector Vector::add(const Vector& vec) const
{
	return Vector(x + vec.x, y + vec.y);
}

Vector Vector::add(double x, double y) const
{
	return Vector(this->x + x, this->y + y);
}

void Vector::reverseX()
{
	x *= -1;
}

void Vector::reverseY()
{
	y *= -1;
}

Vector Vector::operator+(const Vector& rhs) const
{
	return Vector(x + rhs.x, y + rhs.y);
}

Vector Vector::operator*(double value)
{
	return Vector(x * value, y * value);
}

double Vector::operator*(const Vector& rhs)
{
	return x * rhs.x + y * rhs.y;
}

Vector Vector::operator-()
{
	return Vector(-x, -y);
}

Vector Vector::operator-(const Vector& rhs) const
{
	return Vector(x - rhs.x, y - rhs.y);
}

Vector Vector::projection(const Vector& v1, const Vector& v2, const Vector& v3)
{
	double u = ((v3 - v1) * (v2 - v1)) / ((v1 - v2) * (v1 - v2));
	return v1 + (v2 - v1) * u;
}

Angle Vector::getAngleFromPoints(const Vector& p1, const Vector& p2)
{
	return Angle(Math::Atan2(p1.y - p2.y, p1.x - p2.x));
}
