#include "pch.h"
#include "IOBinaryManager.h"

void IOBinaryManager::write(std::vector<IOBinaryData> data, std::ofstream& file)
{
	int size = data.size();
	for (int i = 0; i < size; i++) {
		file.write(data[i].binaryData, data[i].size);
	}
}

void IOBinaryManager::read(std::vector<IOBinaryData> data, std::ifstream& file)
{
	int size = data.size();
	for (int i = 0; i < size; i++) {
		file.read(data[i].binaryData, data[i].size);
	}
}

IOBinaryData::IOBinaryData(char* arr, std::streamsize size)
	:binaryData(arr), size(size) {}
