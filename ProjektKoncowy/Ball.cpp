#include "pch.h"
#include "Ball.h"
#include <random>

using namespace System;

Ball::Ball(int* widthArea, int* heightArea, double speed)
	:Drawable(widthArea, heightArea)
{
	Random^ random = gcnew Random();
	position = Vector(random->NextDouble() * (*widthArea), random->NextDouble() * (*heightArea));
	velocity = Vector(Angle(random->NextDouble() * Math::PI * 2), speed);
	radius = 5;
	countCollisionTicksInARow = 0;
	ignoreCollisionTicks = 0;
}

Ball::Ball(int* widthArea, int* heightArea, double speed, Vector position, Vector velocity, double radius)
	:Drawable(widthArea, heightArea),
	position(position), velocity(velocity), radius(radius),
	countCollisionTicksInARow(0), ignoreCollisionTicks(0) {}

void Ball::Draw(BufferedGraphics^ buffer, Pen^ pen)
{
	buffer->Graphics->DrawEllipse(pen, (float)(position.getX() - radius), (float)(position.getY() - radius), (float)radius * 2,  (float)radius * 2);
}

double Ball::Distance(const Ball& obj)
{
	return (position - obj.position).length();
}

void Ball::Move()
{
	position = position + velocity;
	if (position.getX() - radius < 0 && velocity.getX() < 0) velocity.reverseX();
	if (position.getY() - radius < 0 && velocity.getY() < 0) velocity.reverseY();
	if (position.getX() + radius > *widthArea && velocity.getX() > 0) velocity.reverseX();
	if (position.getY() + radius > *heightArea && velocity.getY() > 0) velocity.reverseY();
}

double Ball::getRadius()
{
	return radius;
}

void Ball::reflection(Ball& b1, Ball& b2)
{
	// Wyznaczamy si�� uderzeniow� wektora
	double forceA = b1.velocity.length();
	double forceB = b2.velocity.length();
	// Wyznaczamy k�t nachylenia prostej k do osi OX
	// prosta k zwiera �rodki b1 i b2
	Angle collisionAngle = Vector::getAngleFromPoints(b1.position, b2.position);
	// Wyznaczamy k�t r�nicy wektor�w do tej prostej
	Angle differenceAToK = collisionAngle - b1.velocity.toAngle();
	Angle differenceBToK = collisionAngle - b2.velocity.toAngle();
	differenceAToK = differenceAToK.limitTo1And4Quadrants();
	differenceBToK = differenceBToK.limitTo1And4Quadrants();
	// Zamieniamy wektory na k�ty
	Angle angleA = b1.velocity.toAngle();
	Angle angleB = b2.velocity.toAngle();
	// Wyznaczamy k�ty wypadkowe
	// Dodajemy Pi aby uzyska� wektory przeciwne
	Angle resultAngleA = angleA + differenceAToK * 2 + Math::PI;
	Angle resultAngleB = angleB + differenceBToK * 2 + Math::PI;
	// Wyznaczamy znormalizowane wektory na podstawie k�t�w
	Vector resultVecA = Vector(resultAngleA);
	Vector resultVecB = Vector(resultAngleB);
	// Obliczamy % przes�anej si�y
	double forceTransPercentA = differenceAToK.percentAngleInclination();
	double forceTransPercentB = differenceBToK.percentAngleInclination();
	// Obliczamy nowe si�y wektor�w
	double newForceA = forceA * (1 - forceTransPercentA) + forceB * forceTransPercentB;
	double newForceB = forceA * forceTransPercentA + forceB * (1 - forceTransPercentB);
	// Wyznaczamy wektory pouderzeniowy uwzgl�dniaj�c tylko swoj� pozosta�� si�� po uderzeniu
	resultVecA = resultVecA * (1 - forceTransPercentA) * forceA;
	resultVecB = resultVecB * (1 - forceTransPercentB) * forceB;
	// Wyznaczamy wektory przekazywanej si�y
	Vector forceToA = Vector(b2.position, b1.position).normalize() * forceTransPercentB * forceB;
	Vector forceToB = Vector(b1.position, b2.position).normalize() * forceTransPercentA * forceA;
	// Obliczamy wektory wynikowe
	resultVecA = (resultVecA + forceToA).normalize() * newForceA;
	resultVecB = (resultVecB + forceToB).normalize() * newForceB;
	b1.velocity = resultVecA;
	b2.velocity = resultVecB;
}

void Ball::reflection2(Ball& b1, Ball& b2)
{
	// Wyznaczamy punkty rzut�w si� na prost� zawieraj�c� �rodki obiekt�w
	Vector p1 = Vector::projection(b1.position, b2.position, b1.position + b1.velocity);
	Vector p2 = Vector::projection(b1.position, b2.position, b2.position + b2.velocity);
	// Rozk�adamy wektory pr�dko�ci na wektory sk�adowe o i q
	Vector o1 = p1 - b1.position;
	Vector o2 = p2 - b2.position;
	Vector q1 = b1.velocity - o1;
	Vector q2 = b2.velocity - o2;
	// Wyznaczamy wektory wynikowe
	Vector r1 = o2 + q1;
	Vector r2 = o1 + q2;
	b1.velocity = r1;
	b2.velocity = r2;
}
