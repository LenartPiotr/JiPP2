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
	void draw(BufferedGraphics^);
	void move();
};

