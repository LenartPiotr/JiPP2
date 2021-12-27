#pragma once
#include "Drawable.h"
#include "Vector.h"
#include "Angle.h"

class Ball : public Drawable
{
private:
	Vector position;
	Vector velocity;
	double radius;
public:
	Ball(int*, int*, double);
	Ball(int*, int*, double, Vector, Vector, double);
	virtual void Draw(BufferedGraphics^, Pen^) override;
	double Distance(const Ball&);
	void Move();
	double getRadius();

	static void Reflection(Ball& b1, Ball& b2);
};

