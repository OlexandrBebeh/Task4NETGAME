#pragma once
#include "ArrayReader.h"
#include "ArrayPrinter.h"
#include "TransformFactory.h"
#include <functional>

class Executor{
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
public:
	void exec() {
		ArrayReader reader("arrays.txt");

		std::string temp;
		try {
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
					tr = TransformFactory<std::vector<int>>::getTransformer(TransformType::sort);
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
					tr = TransformFactory<std::vector<int>>::getTransformer(TransformType::intersect);
					temp1 = tr->transform(arr);
					tr = TransformFactory<std::vector<int>>::getTransformer(TransformType::sort);
					temp1 = tr->transform(temp1);
				}

				ArrayPrinter::print(temp1);
			}
		}
		catch (std::string e) {
			std::cout << "Error: " + e;
		}
	}
};

