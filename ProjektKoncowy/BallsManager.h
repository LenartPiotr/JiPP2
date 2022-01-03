/*
* Klasa BallsManager odpowiedzialna jest za zarz¹dzanie kulami
*/

#pragma once
#include "Ball.h"
#include "RunSettings.h"

using namespace System::Drawing;

class BallsManager
{
private:
	Ball** balls;
	int ballsCount;
	int widthArea, heightArea;
public:
	BallsManager(const RunSettings&);
	~BallsManager();
	void draw(BufferedGraphics^); // Rysuje wszystkie kule w buforze graficznym

	// Funkcja move symuluje ruch: przemieszcza kule i je¿eli nast¹pi³o zderzenie odpowiednio zmienia parametry kul
	void move();
};

