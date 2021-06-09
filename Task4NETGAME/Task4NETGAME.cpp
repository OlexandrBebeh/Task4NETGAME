#include "ArrayReader.h"
#include "ArrayPrinter.h"
#include <functional>
#include <set>
#include <list>
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
	std::vector<std::vector<int>> temp;
	for (int i = 0; i < arrays.size(); i++) {

		temp.push_back(heapSort(arrays[i]));
	}
	return temp;
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
	heapify(arr, arr.size(), index);
}

template <class T>
std::vector<int> ArraySort<T>::heapSort(T arr) {
	for (int i = arr.size() / 2 - 1; i >= 0; i--) {
		heapify(arr, i);
	}
	for (int i = arr.size() -1; i >= 0; i--) {
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

	for (auto iter = arrays[0].begin(); iter != arrays[0].end(); iter++) {
		if (inall(arrays, *iter)) temp.push_back(*iter);
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
	intersect,
	distinct
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
	} else if (type == TransformType::intersect) {
		return new ArrayIntersection<T>();
	} else if (type == TransformType::distinct) {
		return new ArrayDistinct<T>();
	}
}


std::vector<std::vector<int>> longest(std::vector<std::vector<int>> arrays) {

	std::vector<std::vector<int>> temp;
	int index1 = 0, max1 = 0;
	int index2 = 0, max2 = 0;
	for (int i = 0; i < arrays.size(); i++) {
		if (max1 <= arrays[i].size()) {
			max1 = arrays[i].size();
			index1 = i;
		}
		if (max2 < arrays[i].size() && arrays[i].size() <= max1) {
			max2 = arrays[i].size();
			index2 = i;
		}
	}
	temp.push_back(arrays[index1]);
	temp.push_back(arrays[index2]);
	return temp;
}
typedef std::vector<int> intVector;

int main()
{
	ArrayReader reader;

	std::string temp;
	try {
		while (true)
			{
			std::cout << "Enter filename or filepath\n";
			std::cin >> temp;
			reader.setFilename(temp);
			std::vector<intVector> arr = reader.readArrays();
			ArrayPrinter::printArrays(arr);

			std::cout << "Enter number of action\n";
			std::cout << "1. sort\n";
			std::cout << "2. intersection\n";
			std::cout << "3. sort and distinct\n";
			std::cin >> temp;
			ArrayTransformer<intVector>* tr;
			std::vector<intVector> temp1;
			if (temp == "1") {
				tr = TransformFactory<intVector>::getTransformer(TransformType::sort);
				temp1 = tr->transform(arr);
			}
			else if (temp == "2") {
				tr = TransformFactory<intVector>::getTransformer(TransformType::intersect);
				std::cout << "Choose type of intersection\n";
				std::cout << "1. all\n";
				std::cout << "2. two longest\n";
				std::cin >> temp;
				if (temp == "1") {

					temp1 = tr->transform(arr);
				}
				else if (temp == "2") {
					temp1 = longest(arr);
					temp1 = tr->transform(temp1);
					}
				}
			else if (temp == "3") {
				tr = TransformFactory<intVector>::getTransformer(TransformType::distinct);
				temp1 = tr->transform(arr);
			}

			ArrayPrinter::printArrays(temp1);
		}
	}
	catch (std::string e) {
		std::cout << "Error: " + e;
	}
	
}
