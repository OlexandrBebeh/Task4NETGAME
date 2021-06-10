#include "ArrayReader.h"
#include "ArrayPrinter.h"
#include "TransformFactory.h"
#include "Tests.h"
#include <set>


typedef std::vector<int> intVector;

int main()
{
	Tests test;
	test.startTests();
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

				std::cout << "Choose type of intersection\n";
				std::cout << "1. all\n";
				std::cout << "2. two longest\n";
				std::cin >> temp;
				if (temp == "1") {
					tr = TransformFactory<intVector>::getTransformer(TransformType::intersect);
					temp1 = tr->transform(arr);
				}
				else if (temp == "2") {
					tr = TransformFactory<intVector>::getTransformer(TransformType::longest);
					temp1 = tr->transform(arr);
					tr = TransformFactory<intVector>::getTransformer(TransformType::intersect);
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
