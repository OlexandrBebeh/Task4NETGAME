#include "ArraySort.h"

 std::vector<std::vector<int>> ArraySort::transform(std::vector<std::vector<int>>& arrays) {
	for (int i = 0; i < arrays.size(); i++) {
		arrays[i] = heapSort(arrays[i]);
	}
	return arrays;
}
 void ArraySort::heapify(std::vector<int>& arr, int size, int index) {
	 int largest = index;
	 int left = index * 2 + 1;
	 int right = index * 2 + 2;

	 if (left < size && func(arr[largest],arr[left])) {
		 largest = left;
	 }
	 if (right < size && func(arr[largest], arr[right])) {
		 largest = right;
	 }
	 if (largest != index) {
		 std::swap(arr[largest], arr[index]);
		 heapify(arr, size, largest);
	 }
 }
void ArraySort::heapify(std::vector<int>& arr, int index) {
	heapify(arr, arr.size() - 1, index);
}
std::vector<int> ArraySort::heapSort(std::vector<int> arr) {
	for (int i = arr.size() / 2 - 1; i >=0; i--) {
		heapify(arr, i);
	}
	for (int i = arr.size() - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]);
		heapify(arr, i,0);
	}
	return arr;
}