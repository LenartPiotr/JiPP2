/*
* Klasa wyj¹tku, opisuje b³êdy, które zosta³y spowodowane operacjami na plikach
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

