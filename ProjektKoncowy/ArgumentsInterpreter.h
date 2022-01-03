/*
* Klasa interpretuj¹ca parametry programu
* Zwraca obiekt klasy ArgumentValues
* Mo¿e zwróciæ wyj¹tki System::Exception
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