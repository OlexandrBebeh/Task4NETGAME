#pragma once
#include "ArrayTransformer.h"
#include <set>
template <class T>
class ArrayDistinct : public ArrayTransformer<T> {
public:
	std::vector<std::vector<int>> transform(std::vector<T>& arrays);
};

template <class T>
std::vector<std::vector<int>> ArrayDistinct<T>::transform(std::vector<T>& arrays) {
	std::vector<std::vector<int>> temp;
	std::set<int, std::greater<int>> s;
	for (int i = 0; i < arrays.size(); i++) {
		for (auto iter = arrays[i].begin(); iter != arrays[i].end(); iter++)
			s.insert(*iter);
	}
	temp.push_back(std::vector<int>(s.begin(), s.end()));
	return temp;
}