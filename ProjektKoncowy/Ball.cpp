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
}

Ball::Ball(int* widthArea, int* heightArea, double speed, Vector position, Vector velocity, double radius)
	:Drawable(widthArea, heightArea),
	position(position), velocity(velocity), radius(radius) {}

void Ball::Draw(BufferedGraphics^ buffer, Pen^ pen)
{
	// buffer->Graphics->DrawEllipse(pen, (float)(position.getX() - size / 2), (float)(position.getY() - size / 2), (float)size, (float)size);
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

void Ball::Reflection(Ball& b1, Ball& b2)
{
	// Wyznaczamy si³ê uderzeniow¹ wektora
	double forceA = b1.velocity.length();
	double forceB = b2.velocity.length();
	// Wyznaczamy k¹t nachylenia prostej k do osi OX
	// prosta k zwiera œrodki b1 i b2
	Angle collisionAngle = Vector::getAngleFromPoints(b1.position, b2.position);
	// Wyznaczamy k¹t ró¿nicy wektorów do tej prostej
	Angle differenceAToK = collisionAngle - b1.velocity.toAngle();
	Angle differenceBToK = collisionAngle - b2.velocity.toAngle();
	differenceAToK = differenceAToK.limitTo1And4Quadrants();
	differenceBToK = differenceBToK.limitTo1And4Quadrants();
	// Zamieniamy wektory na k¹ty
	Angle angleA = b1.velocity.toAngle();
	Angle angleB = b2.velocity.toAngle();
	// Wyznaczamy k¹ty wypadkowe
	// Dodajemy Pi aby uzyskaæ wektory przeciwne
	Angle resultAngleA = angleA + differenceAToK * 2 + Math::PI;
	Angle resultAngleB = angleB + differenceBToK * 2 + Math::PI;
	// Wyznaczamy znormalizowane wektory na podstawie k¹tów
	Vector resultVecA = Vector(resultAngleA);
	Vector resultVecB = Vector(resultAngleB);
	// Obliczamy % przes³anej si³y
	double forceTransPercentA = differenceAToK.percentAngleInclination();
	double forceTransPercentB = differenceBToK.percentAngleInclination();
	// Obliczamy nowe si³y wektorów
	double newForceA = forceA * (1 - forceTransPercentA) + forceB * forceTransPercentB;
	double newForceB = forceA * forceTransPercentA + forceB * (1 - forceTransPercentB);
	// Wyznaczamy wektory pouderzeniowy uwzglêdniaj¹c tylko swoj¹ pozosta³¹ si³ê po uderzeniu
	resultVecA = resultVecA * (1 - forceTransPercentA) * forceA;
	resultVecB = resultVecB * (1 - forceTransPercentB) * forceB;
	// Wyznaczamy wektory przekazywanej si³y
	Vector forceToA = Vector(b2.position, b1.position).normalize() * forceTransPercentB * forceB;
	Vector forceToB = Vector(b1.position, b2.position).normalize() * forceTransPercentA * forceA;
	// Obliczamy wektory wynikowe
	resultVecA = (resultVecA + forceToA).normalize() * newForceA;
	resultVecB = (resultVecB + forceToB).normalize() * newForceB;
	b1.velocity = resultVecA;
	b2.velocity = resultVecB;
}
