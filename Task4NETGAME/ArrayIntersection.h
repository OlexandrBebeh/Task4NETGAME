#pragma once
#include "ArrayTransformer.h"
template <class T>
class ArrayIntersection : public ArrayTransformer<T> {
	bool contains(T arr, int el) {

		for (auto iter = arr.begin(); iter != arr.end(); iter++) {
			if (*iter == el)
				return true;
		}
		return false;
	};
	bool inall(std::vector<T> arrays, int el) {
		for (int i = 1; i < arrays.size(); i++) {
			if (!contains(arrays[i], el))
				return false;
		}
		return true;
	};
	std::vector<int> intersect(std::vector<T> arrays) {
		std::vector<int> temp;

		for (auto iter = arrays[0].begin(); iter != arrays[0].end(); iter++) {
			if (inall(arrays, *iter)) temp.push_back(*iter);
		}
		return temp;
	};
public:
	std::vector<std::vector<int>> transform(std::vector<T>& arrays) {
		std::vector<std::vector<int>> temp;
		temp.push_back(intersect(arrays));
		return temp;
	}
};
