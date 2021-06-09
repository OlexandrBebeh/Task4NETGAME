#include <iostream>
#include "ArrayReader.h"
#include "ArrayPrinter.h"
#include "ArraySort.h"
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
		ArrayPrinter::print(temp);
		ArraySort sort;
		sort.transform(temp);
		ArrayPrinter::print(temp);
		std::cin >> filename;
	}
	}catch (std::string e) {
		std::cout << "Error: " + e;
	}
}
