#include "ArrayPrinter.h"

void ArrayPrinter::print(std::vector<std::vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		print(arr[i]);
	}
}

void ArrayPrinter::print(std::vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}