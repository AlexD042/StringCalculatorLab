#include <iostream>
#include <string>
#include <cassert>

int stringCalculator(std::string str);
void test_stringCalculator();

int main() {
	test_stringCalculator();
	return 0;
}

int stringCalculator(std::string str) {

	if (str.empty()) {
		return 0;
	}

	int total = 0;
	std::string tempStr = "";

	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ',' && str[i] != ';') {
			tempStr += str[i];
		}
		else {
			total += stoi(tempStr);
			tempStr = "";
		}
	}

	if (!str.empty()) {
		total += stoi(tempStr);
	}

	return total;
}

void test_stringCalculator() {
	assert(stringCalculator("") == 0);
	assert(stringCalculator("0") == 0);
	assert(stringCalculator("1") == 1);
	assert(stringCalculator("1,2") == 3);
	assert(stringCalculator("4,5,6") == 15);
	assert(stringCalculator("-1,1") == 0);
	assert(stringCalculator("-9,1") == -8);
	assert(stringCalculator("16,24") == 40);
	assert(stringCalculator("4;7;8") == 19);
	assert(stringCalculator("1,2;3") == 6);

	std::cout << "test_stringCalculator PASSED";
}