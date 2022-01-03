#include "pch.h"
#include "BallsManager.h"
#include <random>

using namespace System;

BallsManager::BallsManager(const RunSettings& settings)
{
	ballsCount = settings.getCount();
	balls = new Ball*[ballsCount];
	widthArea = settings.getWidth();
	heightArea = settings.getHeight();
	Random^ random = gcnew Random();
	int radius = 10;
	int posX = radius * 2;
	int posY = radius * 2;
	for (int i = 0; i < ballsCount; i++) {
		balls[i] = new Ball(&widthArea, &heightArea, settings.getSpeed(),
			Vector(posX, posY),
			Vector(Angle(random->NextDouble() * Math::PI * 2), settings.getSpeed()),
			radius);
		posX += radius * 4;
		if (posX > settings.getWidth() - radius * 2) {
			posX = radius * 2;
			posY += radius * 4;
		}
	}
}

BallsManager::~BallsManager()
{
	for (int i = 0; i < ballsCount; i++) {
		delete balls[i];
	}
	delete[] balls;
}

void BallsManager::draw(BufferedGraphics^ buffer)
{
	Pen^ pen = gcnew Pen(gcnew SolidBrush(Color::Blue));
	for (int i = 0; i < ballsCount; i++) {
		balls[i]->Draw(buffer, pen);
	}
}

void BallsManager::move()
{
	// Moving
	for (int i = 0; i < ballsCount; i++) {
		balls[i]->Move();
	}
	// Checking collision
	bool* collisionChecked = new bool[ballsCount];
	for (int i = 0; i < ballsCount; i++) collisionChecked[i] = false;
	for (int i = 0; i < ballsCount; i++) {
		for (int j = i + 1; j < ballsCount; j++) {
			if (balls[i]->ignoreCollisionTicks == 0 && balls[j]->ignoreCollisionTicks == 0)
			if (balls[i]->Distance(*balls[j]) < balls[i]->getRadius() + balls[j]->getRadius()) {
				Ball::reflection2(*balls[i], *balls[j]);
				collisionChecked[i] = true;
				collisionChecked[j] = true;
			}
		}
	}
	;
	for (int i = 0; i < ballsCount; i++) {
		if (balls[i]->ignoreCollisionTicks > 0) balls[i]->ignoreCollisionTicks--;
		if (collisionChecked[i])
			balls[i]->countCollisionTicksInARow++;
		else
			balls[i]->countCollisionTicksInARow = 0;
		if (balls[i]->countCollisionTicksInARow > 5) {
			balls[i]->countCollisionTicksInARow = 0;
			balls[i]->ignoreCollisionTicks = 5;
		}
	}
	delete collisionChecked;
}
