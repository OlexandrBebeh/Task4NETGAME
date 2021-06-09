#pragma once
#include <vector>
template <class T>
class ArrayTransformer {
public:
	virtual std::vector<std::vector<int>> transform(std::vector<T>& arrays) = 0;
};