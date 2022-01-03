/*
* Klasa ball opisuje obiekty, które bêd¹ wyœwietlane w aplikacji
*/

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
	int countCollisionTicksInARow;
	int ignoreCollisionTicks;
	Ball(int*, int*, double);
	Ball(int*, int*, double, Vector, Vector, double);
	virtual void Draw(BufferedGraphics^, Pen^) override;
	double Distance(const Ball&);
	void Move();
	double getRadius();

	/*
	* Statyczne metody reflection obliczaj¹ zderzenia dwóch kul
	* Druga metoda jest bardziej dok³adna
	*/

	static void reflection(Ball& b1, Ball& b2);	// Metoda wyznaczania kierunku i si³
	static void reflection2(Ball& b1, Ball& b2); // Metoda rozbijania wektora na wektory sk³adowe
};

