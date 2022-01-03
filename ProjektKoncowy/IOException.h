/*
* Klasa wyj�tku, opisuje b��dy, kt�re zosta�y spowodowane operacjami na plikach
*/

#pragma once
#include <exception>
class IOException : public std::exception
{
private:
	char* message;
public:
	IOException(char*);
	const char* what();
};

