#pragma once
#include "ArrayTransformer.h"


enum class TransformType {
	sort,
	intersect
};


template <class T>
class TransformFactory {
public:
	static ArrayTransformer<T>* getTransformer(TransformType t);
};