#pragma once
#include "ArrayTransformer.h"
#include <functional>
template <class T>
class ArrayLongestFilter : public ArrayTransformer<T> {
public:
	std::vector<T> transform(std::vector<T>& arrays) {
		std::vector<T> temp;
		int index1 = 0, max1 = 0;
		int index2 = 0, max2 = 0;
		for (int i = 0; i < arrays.size(); i++) {
			if (max1 <= arrays[i].size()) {
				max1 = arrays[i].size();
				index1 = i;
			};
			
		};
		for (int i = 0; i < arrays.size(); i++) {
			if (max2 < arrays[i].size() && arrays[i].size() != max1) {
				max2 = arrays[i].size();
				index2 = i;
			};

		};

		temp.push_back(arrays[index1]);
		temp.push_back(arrays[index2]);
		return temp;
	};
};
