#pragma once
#include "ArrayTransformer.h"
#include <functional>
template <class T>
class ArraySort : public ArrayTransformer<T> {
	std::function<bool(int, int)> func = [](int a, int b) {return a < b; };

	void heapify(T& arr, int size, int index) {
		auto largest = arr.begin() + index;
		int i = index;
		if (index * 2 + 1 < size) {
			auto left = arr.begin() + index * 2 + 1;
			if (func(*largest, *left)) {
				largest = left;
				i = index * 2 + 1;
			}
		}
		if (index * 2 + 2 < size) {
			auto right = arr.begin() + index * 2 + 2;
			if (func(*largest, *right)) {
				largest = right;
				i = index * 2 + 2;
			}
		}

		if (i != index) {
			std::iter_swap(largest, arr.begin() + index);
			heapify(arr, size, i);
		}
	};
	void heapify(T& arr, int index) {
		heapify(arr, arr.size(), index);
	};
	std::vector<int> heapSort(T arr) {
		for (int i = arr.size() / 2 - 1; i >= 0; i--) {
			heapify(arr, i);
		}
		for (int i = arr.size() - 1; i >= 0; i--) {
			std::iter_swap(arr.begin(), arr.begin() + i);
			heapify(arr, i, 0);
		}
		return arr;
	};
public:
	std::vector<std::vector<int>> transform(std::vector<T>& arrays) {
		std::vector<std::vector<int>> temp;
		for (int i = 0; i < arrays.size(); i++) {
			temp.push_back(heapSort(arrays[i]));
		}
		return temp;
	}
};
