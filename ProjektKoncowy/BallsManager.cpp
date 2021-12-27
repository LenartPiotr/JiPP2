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
	for (int i = 0; i < ballsCount; i++) {
		balls[i] = new Ball(&widthArea, &heightArea, settings.getSpeed(),
			Vector(random->NextDouble() * (widthArea),random->NextDouble() * (heightArea)),
			Vector(Angle(random->NextDouble() * Math::PI * 2), settings.getSpeed()),
			10);
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
	for (int i = 0; i < ballsCount; i++) {
		for (int j = i + 1; j < ballsCount; j++) {
			if (balls[i]->Distance(*balls[j]) < balls[i]->getRadius() + balls[j]->getRadius()) {
				Ball::Reflection(*balls[i], *balls[j]);
			}
		}
	}
}
