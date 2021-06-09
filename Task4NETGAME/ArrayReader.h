#pragma once
#include <iostream>
#include <vector>
#include <string>
class ArrayReader {
	std::string filename;
public:
	ArrayReader(std::string name);
	void setFilename(std::string name);
	std::vector<std::vector<int>> readArrays();
};