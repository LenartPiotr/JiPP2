/*
* Klasa interpretuj�ca parametry programu
* Zwraca obiekt klasy ArgumentValues
* Mo�e zwr�ci� wyj�tki System::Exception
*/

#pragma once
#include "pch.h"
#include "ArgumentValues.h"

using namespace System;

class ArgumentsInterpreter
{
private:
	array<String^>^& arguments;
public:
	ArgumentsInterpreter(array<String^>^ arguments);
	ArgumentValues GetValues();
};