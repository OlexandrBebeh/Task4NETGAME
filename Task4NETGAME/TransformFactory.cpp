#include "TransformFactory.h"
#include "ArraySort.h"
#include "ArrayIntersection.h"


template <class T>
static ArrayTransformer<T>* TransformFactory<T>::getTransformer(TransformType type) {
	if (type == TransformType::sort) {
		return new ArraySort<T>();
	} else if (type == TransformType::intersect) {
		return new ArrayIntersection<T>();
	}
}