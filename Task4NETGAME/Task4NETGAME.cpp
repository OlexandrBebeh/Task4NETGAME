#include "ArrayReader.h"
#include "ArrayPrinter.h"
#include "TransformFactory.h"
#include <functional>
#include <vector>
/* 

template <class T>
class ArrayTransformer {
public:

	virtual std::vector<std::vector<int>> transform(std::vector<T>& arrays) = 0;
};


template <class T>
class ArraySort : public ArrayTransformer<T> {
	std::function<bool(int, int)> func = [](int a, int b) {return a < b; };
	void heapify(T& arr, int size, int index);
	void heapify(T& arr, int index);
	std::vector<int> heapSort(T arr);
public:
	std::vector<std::vector<int>> transform(std::vector<T>& arrays);
};


template <class T>
std::vector<std::vector<int>> ArraySort<T>::transform(std::vector <T>& arrays) {
	for (int i = 0; i < arrays.size(); i++) {
		arrays[i] = heapSort(arrays[i]);
	}
	return arrays;
}


template <class T>
void ArraySort<T>::heapify(T& arr, int size, int index) {
	auto largest = arr.begin() + index;
	int i = index;
	if (index * 2 + 1 < size) {
		auto left = arr.begin() + index * 2 + 1;
		if (func(*largest, *left)) {
			largest = left;
			i = index * 2 + 1;
		}
	}
	if (index * 2 + 2 < size) {
		auto right = arr.begin() + index * 2 + 2;
		if (func(*largest, *right)) {
			largest = right;
			i = index * 2 + 2;
		}
	}

	if (i != index) {
		std::iter_swap(largest, arr.begin() + index);
		heapify(arr, size, i);
	}
}


template <class T>
void ArraySort<T>::heapify(T& arr, int index) {
	heapify(arr, arr.size() - 1, index);
}

template <class T>
std::vector<int> ArraySort<T>::heapSort(T arr) {
	for (int i = arr.size() / 2 - 1; i >= 0; i--) {
		heapify(arr, i);
	}
	for (int i = arr.size() - 1; i >= 0; i--) {
		std::iter_swap(arr.begin(), arr.begin() + i);
		heapify(arr, i, 0);
	}
	return arr;
}


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
enum class TransformType {
	sort,
	intersect
};


template <class T>
class TransformFactory {
public:
	static ArrayTransformer<T>* getTransformer(TransformType t);
};


template <class T>
ArrayTransformer<T>* TransformFactory<T>::getTransformer(TransformType type) {
	if (type == TransformType::sort) {
		return new ArraySort<T>();
	}
	else if (type == TransformType::intersect) {
		return new ArrayIntersection<T>();
	}
}
*/

int main()
{
	ArrayReader reader("arrays.txt");

	std::string temp;
	try{
	while (true)
	{
		std::cin >> temp;
		reader.setFilename(temp);
		std::vector<std::vector<int>> arr = reader.readArrays();
		ArrayPrinter::print(arr);
		std::cin >> temp;
		ArrayTransformer<std::vector<int>>* tr;
		std::vector<std::vector<int>> temp1;
		if (temp == "1") {
			tr = TransformFactory<std::vector<int>>::getTransformer(TransformType::sort);
			temp1 = tr->transform(arr);
		}
		else if (temp == "2") {
			tr = TransformFactory<std::vector<int>>::getTransformer(TransformType::intersect);
			temp1 = tr->transform(arr);
		} else if (temp == "3") {
			tr = TransformFactory<std::vector<int>>::getTransformer(TransformType::intersect);
			temp1 = tr->transform(arr);
			tr = TransformFactory<std::vector<int>>::getTransformer(TransformType::sort);
			temp1 = tr->transform(temp1);
		}

		ArrayPrinter::print(temp1);
	}
	}catch (std::string e) {
		std::cout << "Error: " + e;
	}
}
