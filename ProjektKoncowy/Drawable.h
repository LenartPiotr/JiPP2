/*
* Klasa wirtualna Drawable opisuje obiekty, które bêd¹ rysowane w buforze graficznym
*/

#pragma once

using namespace System::Drawing;

class Drawable
{
protected:
	int* widthArea;
	int* heightArea;
public:
	Drawable(int* widthArea, int* heightArea);
	virtual void Draw(BufferedGraphics^, Pen^) = 0;
};

