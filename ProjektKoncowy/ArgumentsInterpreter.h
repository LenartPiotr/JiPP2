#pragma once
#include "pch.h"
#include <vector>
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