#include "pch.h"
#include "ArgumentValues.h"

ArgumentValues::ArgumentValues() : count(0), speed(0), width(0), height(0), runApp(false) {}

ArgumentValues::ArgumentValues(int count, double speed, int width, int height, bool run) :count(count), speed(speed), width(width), height(height), runApp(run) {}

int ArgumentValues::getCount()
{
	return count;
}

double ArgumentValues::getSpeed()
{
	return speed;
}

int ArgumentValues::getWidth()
{
	return width;
}

int ArgumentValues::getHeight()
{
	return height;
}

bool ArgumentValues::getRunApp()
{
	return runApp;
}

void ArgumentValues::setCount(int value)
{
	count = value;
}

void ArgumentValues::setSpeed(double value)
{
	speed = value;
}

void ArgumentValues::setWidth(int value)
{
	width = value;
}

void ArgumentValues::setHeight(int value)
{
	height = value;
}

void ArgumentValues::setRunApp(bool value)
{
	runApp = value;
}

ArgumentValues ArgumentValues::DefaultValues()
{
	return ArgumentValues(100, 1, 800, 600, false);
}
