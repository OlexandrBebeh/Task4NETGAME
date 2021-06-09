#pragma once
#include "ArrayTransformer.h"
#include <functional>
class ArraySort : public ArrayTransformer {
	std::function<bool(int, int)> func = [](int a, int b) {return a < b; };
	void heapify(std::vector<int>& arr, int size,int index);
	void heapify(std::vector<int>& arr, int index);
	std::vector<int> heapSort(std::vector<int> arr);
public:
	std::vector<std::vector<int>> transform(std::vector<std::vector<int>>& arrays);
};