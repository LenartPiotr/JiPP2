#include "pch.h"
#include "IOException.h"

IOException::IOException(char* mess) : message(mess)
{
}

const char* IOException::what()
{
	return message;
}
