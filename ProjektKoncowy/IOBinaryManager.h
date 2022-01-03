/*
* Klasa IOBinaryManager jest odpowiedzialna za zapis i odczyt plików binarnych.
* Klasa pos³uguje siê wektorem danych typu IOBinaryData
*/

#include <vector>
#include <fstream>

#pragma once

struct IOBinaryData {
	char* binaryData;
	std::streamsize size;
	IOBinaryData(char* arr, std::streamsize size);
};

class IOBinaryManager
{
public:
	static void write(std::vector<IOBinaryData> data, std::ofstream& file);
	static void read(std::vector<IOBinaryData> data, std::ifstream& file);
};