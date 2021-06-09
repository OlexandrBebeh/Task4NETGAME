#include "ArrayReader.h"
#include <fstream>

ArrayReader::ArrayReader(std::string name): filename(name) {}

void ArrayReader::setFilename(std::string name) {
	this->filename = name;
}

std::vector<std::vector<int>> ArrayReader::readArrays() {
	std::vector<std::vector<int>> temp;

	std::ifstream file(filename);
	std::string str;

	int arraysSize = 0;
	while (std::getline(file, str)) {
		int flag = 0;
		temp.push_back(std::vector<int>());

		for (int i = 0; i < str.size(); i++) {
			if (std::isdigit(str[i])) {
				flag = i;
				for (; i < str.size(); i++) {
					if (!std::isdigit(str[i])) {
						temp[arraysSize].push_back(std::stoi(str.substr(flag, i)));
						break;
					}
					if( i == str.size() -1 ) temp[arraysSize].push_back(std::stoi(str.substr(flag, i)));
				}
			}
			else if (str[i] == ' ' || str[i] == ',') {
				continue;
			}
			else {
				throw "Invalid symbol";
			}

		}
		arraysSize++;
	}
	return temp;
}
