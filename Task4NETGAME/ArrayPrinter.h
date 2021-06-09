#pragma once
#include <vector>
#include <iostream>

class ArrayPrinter {
public:
	template <typename  T>
	static void printArrays(std::vector<T> arr) {
		for (int i = 0; i < arr.size(); i++) {
			print(arr[i]);
		}
	};
	template <typename  T>
	static void print(T arr) {
		for (auto iter = arr.begin(); iter != arr.end(); iter++) {
			std::cout << *iter << " ";
		}
		std::cout << std::endl;
	};
};