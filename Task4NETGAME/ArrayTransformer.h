#pragma once
#include <vector>
template <class T>
class ArrayTransformer {
public:
	virtual std::vector<T> transform(std::vector<T>& arrays) = 0;
};