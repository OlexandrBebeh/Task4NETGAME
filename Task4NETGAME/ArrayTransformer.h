#pragma once
#include <vector>

class ArrayTransformer {
public:
	virtual std::vector<std::vector<int>> transform(std::vector<std::vector<int>>& arrays) = 0;
};