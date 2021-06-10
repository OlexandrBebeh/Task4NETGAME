#pragma once
#include "ArrayTransformer.h"
#include "ArraySort.h"
#include "ArrayIntersection.h"
#include "ArrayDistinct.h"
#include "ArrayLongestFilter.h"


enum class TransformType {
	sort,
	intersect,
	distinct,
	longest
};


template <class T>
class TransformFactory {
public:
	static ArrayTransformer<T>* getTransformer(TransformType type) {
		if (type == TransformType::sort) {
			return new ArraySort<T>();
		}
		else if (type == TransformType::intersect) {
			return new ArrayIntersection<T>();
		}
		else if (type == TransformType::distinct) {
			return new ArrayDistinct<T>();
		}
		else if (type == TransformType::longest) {
			return new ArrayLongestFilter<T>();
		}
	};
};