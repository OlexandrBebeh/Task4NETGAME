#pragma once
#include "ArrayPrinter.h"
#include "TransformFactory.h"
#include "ArrayPrinter.h"
#include <list>
#include <deque >
typedef std::list<int> intlist;
typedef std::deque <int> intdeque;
class Tests {
	template <typename T>
	bool same(T arr1, T arr2) {
		if (arr1.size() != arr2.size())
			return false;

		for (auto iter1 = arr1.begin(), iter2 = arr2.begin(); iter1 != arr1.end(); iter1++, iter2++) {
			if (*iter1 != *iter2) return false;
		}
		return true;
	};
	void testList() {
		std::vector<intlist> lst;
		lst.push_back(intlist{ 1,5,23,21,543,84,45 });
		lst.push_back(intlist{ 1,53,23,21,543,840,45 });
		lst.push_back(intlist{ 14,5,23,212,543,84,45 });

		ArrayTransformer<intlist>* tr = TransformFactory<intlist>::getTransformer(TransformType::sort);

		std::vector<intlist> temp = tr->transform(lst);

		if (!same(temp[0], { 1,5,21,23,45,84,543 })) {
			std::cout << "Program work incorect\n";
		}

	}
	void testSet() {
		std::vector<intdeque> deq;
		deq.push_back(intdeque{ 1,5,23,21,543,84,45 });
		deq.push_back(intdeque{ 1,53,23,21,543,840,45 });
		deq.push_back(intdeque{ 14,5,23,212,543,84,45 });

		ArrayTransformer<intdeque>* tr = TransformFactory<intdeque>::getTransformer(TransformType::sort);

		std::vector<intdeque> temp = tr->transform(deq);

		if (!same(temp[0], { 1,5,21,23,45,84,543 })) {
			std::cout << "Program work incorect with list\n";
		}

	}
	void testSort() {
		std::vector<intdeque> deq;
		deq.push_back(intdeque{ 1,5,23,21,543,12,5,3,7547,27,2457,72457,245727,21,7237,17,1357,571,1,1,711-7,177,-7-17,54-71,-1784,45 });


		ArrayTransformer<intdeque>* tr = TransformFactory<intdeque>::getTransformer(TransformType::sort);

		std::vector<intdeque> temp = tr->transform(deq);

		if (!same(temp[0], { -1784, - 24, - 17, 1, 1, 1, 3, 5, 5, 12, 17, 21, 21, 23, 27, 45, 177, 543, 571, 704, 1357, 2457, 7237, 7547, 72457, 245727, })) 
			std::cout << "Program work incorect: sort\n";
		

	}
	void testDistinct() {
		std::vector<intdeque> deq;
		deq.push_back(intdeque{ 1,2,3,4,4,5,5,6,6,7,8,9,10,11,11,11,11,11 });
		deq.push_back(intdeque{ 12,12,12,12,12,13 });
		deq.push_back(intdeque{ 14 });
		ArrayTransformer<intdeque>* tr = TransformFactory<intdeque>::getTransformer(TransformType::distinct);

		std::vector<intdeque> temp = tr->transform(deq);

		if (!same(temp[0], { 14,13,12,11,10,9,8,7,6,5,4,3,2,1 }))
			std::cout << "Program work incorect: distinct\n";
	}
	void testIntersect() {
		std::vector<intdeque> deq;
		deq.push_back(intdeque{ 1,2,3,4,4,5,5,6,6,7,8,9,10,11,11,11,11,11 });
		deq.push_back(intdeque{ 12,12,12,12,12,13,6,7,11,2 });
		deq.push_back(intdeque{ 14,6,7,11,4 });
		ArrayTransformer<intdeque>* trIntersect = TransformFactory<intdeque>::getTransformer(TransformType::intersect);

		std::vector<intdeque> temp = trIntersect->transform(deq);
		if (!same(temp[0], { 6, 7, 11 }))
			std::cout << "Program work incorect: intersect\n";
		ArrayTransformer<intdeque>* trLongest = TransformFactory<intdeque>::getTransformer(TransformType::longest);

		temp = trLongest->transform(deq);
		ArrayPrinter::printArrays(temp);
		temp = trIntersect->transform(temp);
		ArrayPrinter::printArrays(temp);
		if (!same(temp[0], { 2, 6, 7, 11 }))
			std::cout << "Program work incorect: intersect\n";
	}
public:
	void startTests() {
		testList();
		testSet();
		testSort();
		testDistinct();
		testIntersect();
	};
};