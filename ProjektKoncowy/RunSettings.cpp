#include "pch.h"
#include "RunSettings.h"
#include "Range.h"

RunSettings::RunSettings(ArgumentValues values) :count(values.getCount()), speed(values.getSpeed()), width(values.getWidth()), height(values.getHeight()) {}

RunSettings::RunSettings(int count, double speed, int width, int height)
	:count(count), speed(speed), width(width), height(height) {}

int RunSettings::getCount() const
{
	return count;
}

double RunSettings::getSpeed() const
{
	return speed;
}

int RunSettings::getWidth() const
{
	return width;
}

int RunSettings::getHeight() const
{
	return height;
}

void RunSettings::setCount(int value)
{
	count = value;
}

void RunSettings::setSpeed(double value)
{
	speed = value;
}

void RunSettings::setWidth(int value)
{
	width = value;
}

void RunSettings::setHeight(int value)
{
	height = value;
}

const Range<int> RunSettings::countRange = Range<int>(10, 1000);
const Range<double> RunSettings::speedRange = Range<double>(0, 20);
const Range<int> RunSettings::widthRange = Range<int>(50, 2000);
const Range<int> RunSettings::heightRange = Range<int>(50, 1000);

