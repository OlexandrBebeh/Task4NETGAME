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
	T intersect(std::vector<T> arrays) {
		T temp;

		for (auto iter = arrays[0].begin(); iter != arrays[0].end(); iter++) {
			if (inall(arrays, *iter) && !contains(temp, *iter)) temp.insert(temp.end(),*iter);
		}
		return temp;
	};
public:
	std::vector<T> transform(std::vector<T>& arrays) {
		std::vector<T> temp;
		temp.push_back(intersect(arrays));
		return temp;
	}
};
