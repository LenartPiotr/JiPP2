#pragma once
#include "ArgumentValues.h"
#include "Range.h"

class RunSettings {
private:
	int count;
	double speed;
	int width;
	int height;
public:
	RunSettings(ArgumentValues);
	RunSettings(int, double, int, int);
	int getCount() const;
	double getSpeed() const;
	int getWidth() const;
	int getHeight() const;
	void setCount(int);
	void setSpeed(double);
	void setWidth(int);
	void setHeight(int);
	static const Range<int> countRange;
	static const Range<double> speedRange;
	static const Range<int> widthRange;
	static const Range<int> heightRange;
};