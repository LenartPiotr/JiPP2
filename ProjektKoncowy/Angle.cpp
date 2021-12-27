#include "pch.h"
#include "Angle.h"

using System::Math;

Angle::Angle() : value(0) {}

Angle::Angle(double radians) : value(radians) {}

Angle::Angle(const Angle& source) : value(source.value) {}

double Angle::degrees() const
{
	return value * 180 / Math::PI;
}

double Angle::radians() const
{
	return value;
}

Angle Angle::limitTo1And4Quadrants() const
{
	double v = value;
	while (v < -Math::PI / 2) v += Math::PI;
	while (v > Math::PI / 2) v -= Math::PI;
	return Angle(v);
}

double Angle::percentAngleInclination() const
{
	return value < 0 ? (1 + value / (Math::PI / 2)) : (1 - value / (Math::PI / 2));
}

Angle Angle::operator-(const Angle& rhs)
{
	return Angle(value - rhs.value);
}

Angle Angle::operator*(double rhs)
{
	return Angle(value * rhs);
}

Angle Angle::operator+(double rhs)
{
	return Angle(value + rhs);
}

Angle Angle::operator+(const Angle& rhs)
{
	return Angle(value + rhs.value);
}
