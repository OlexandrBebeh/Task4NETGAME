#pragma once
#include "ArrayTransformer.h"
#include <functional>
template <class T>
class ArraySort : public ArrayTransformer<T> {
	std::function<bool(int, int)> func = [](int a, int b) {return a < b; };

	void heapify(T& arr, int size, int index);
	void heapify(T& arr, int index);
	std::vector<int> heapSort(T arr);
public:
	std::vector<std::vector<int>> transform(std::vector<T>& arrays);
};