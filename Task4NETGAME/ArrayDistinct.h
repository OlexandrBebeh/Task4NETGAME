#pragma once
#include "ArrayTransformer.h"
#include <set>
template <class T>
class ArrayDistinct : public ArrayTransformer<T> {
public:
	std::vector<T> transform(std::vector<T>& arrays) {
		std::vector<T> temp;
		std::set<int, std::greater<int>> s;
		for (int i = 0; i < arrays.size(); i++) {
			for (auto iter = arrays[i].begin(); iter != arrays[i].end(); iter++)
				s.insert(*iter);
		}
		temp.push_back(T(s.begin(), s.end()));
		return temp;
	};
};