#include "ArrayReader.h"
#include "ArrayPrinter.h"
#include "TransformFactory.h"
#include <functional>
#include <set>

template <typename T>
std::vector<T> longest(std::vector<T> arrays) {
	std::vector<T> temp;
	int index1 = 0, max1 = 0;
	int index2 = 0, max2 = 0;
	for (int i = 0; i < arrays.size(); i++) {
		if (max1 <= arrays[i].size()) {
			max1 = arrays[i].size();
			index1 = i;
		};
		if (max2 < arrays[i].size() && arrays[i].size() <= max1) {
			max2 = arrays[i].size();
			index2 = i;
		};
	};
	temp.push_back(arrays[index1]);
	temp.push_back(arrays[index2]);
	return temp;
};
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
			}else if (temp == "2") {
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
