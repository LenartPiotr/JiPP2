/*
* Klasa przechowuj¹ca parametry wywo³ania procesu jako zmienne
*/

#pragma once
class ArgumentValues
{
private:
	int count;
	double speed;
	int width;
	int height;
	bool runApp;
public:
	ArgumentValues();
	ArgumentValues(int, double, int, int, bool);
	int getCount();
	double getSpeed();
	int getWidth();
	int getHeight();
	bool getRunApp();
	void setCount(int);
	void setSpeed(double);
	void setWidth(int);
	void setHeight(int);
	void setRunApp(bool);
	static ArgumentValues DefaultValues();
};

