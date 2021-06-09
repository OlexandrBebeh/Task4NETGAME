#pragma once
#include "ArrayTransformer.h"
template <class T>
class ArrayIntersection : public ArrayTransformer<T> {
	bool contains(T arr, int el);
	bool inall(std::vector<T> arrays, int el);
	std::vector<int> intersect(std::vector<T> arrays);
public:
	std::vector<std::vector<int>> transform(std::vector<T>& arrays);
};