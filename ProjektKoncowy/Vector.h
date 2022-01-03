/*
* Klasa Vector przedstawia matematyczny wektor.
* S³u¿y do operacji matematycznych.
*/

#pragma once
#include "Angle.h"

class Vector
{
private:
	double x, y;
public:
	Vector();
	Vector(double, double);
	Vector(const Vector&);
	Vector(const Vector&, const Vector&);
	Vector(const Angle&);
	Vector(const Angle&,double);
	Angle toAngle() const;
	double getX() const;
	double getY() const;
	void setX(double);
	void setY(double);
	double length() const;
	Vector normalize() const;
	Vector add(const Vector&) const;
	Vector add(double, double) const;
	void reverseX();
	void reverseY();
	Vector operator+(const Vector&) const;
	Vector operator*(double);
	double operator*(const Vector&);
	Vector operator-();
	Vector operator-(const Vector&) const;

	// Rzut punktu v3 na prost¹ v1 v2
	static Vector projection(const Vector& v1, const Vector& v2, const Vector& v3);
	static Angle getAngleFromPoints(const Vector&, const Vector&);
};