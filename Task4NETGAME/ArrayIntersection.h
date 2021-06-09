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
template <class T>
std::vector<std::vector<int>> ArrayIntersection<T>::transform(std::vector<T>& arrays) {
	std::vector<std::vector<int>> temp;
	temp.push_back(intersect(arrays));
	return temp;
}
template <class T>
std::vector<int> ArrayIntersection<T>::intersect(std::vector<T> arrays) {
	std::vector<int> temp;

	for (int i = 0; i < arrays[0].size(); i++) {
		if (inall(arrays, arrays[0][i])) {
			temp.push_back(arrays[0][i]);
		}
	}
	return temp;
}
template <class T>
bool ArrayIntersection<T>::contains(T arr, int el) {

	for (auto iter = arr.begin(); iter != arr.end(); iter++) {
		if (*iter == el)
			return true;
	}
	return false;
}
template <class T>
bool ArrayIntersection<T>::inall(std::vector<T> arrays, int el) {
	for (int i = 1; i < arrays.size(); i++) {
		if (!contains(arrays[i], el))
			return false;
	}
	return true;
}
