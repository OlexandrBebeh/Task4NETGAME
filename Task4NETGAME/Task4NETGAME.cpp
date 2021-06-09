#include <iostream>
#include "ArrayReader.h"
int main()
{
	ArrayReader reader("arrays.txt");
	std::string filename;
	try{
	while (true)
	{
		//std::cin >> filename;
		//reader.setFilename(filename);
		std::vector<std::vector<int>> temp = reader.readArrays();
	}
	}catch (std::string e) {
		std::cout << "Error: " + e;
	}
}
