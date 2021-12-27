#pragma once

class Angle
{
private:
	double value;
public:
	Angle();
	Angle(double);
	Angle(const Angle&);
	double degrees() const;
	double radians() const;
	Angle limitTo1And4Quadrants() const;
	double percentAngleInclination() const;
	Angle operator-(const Angle&);
	Angle operator*(double);
	Angle operator+(double);
	Angle operator+(const Angle&);
};

