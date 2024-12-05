#include <iostream>

using namespace std;

bool isLeapYear(int year);

int main() {

	int userInput;

	while (true) {
		cout << "Enter a year or Q to quit: ";
		cin >> userInput;
		if (cin.fail()) {
			break;
		}
		if (isLeapYear(userInput)) {
			cout << userInput << " is a leap year." << endl;
		}
		else {
			cout << userInput << " is not a leap year." << endl;
		}
	}

	return 0;
}
bool isLeapYear(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return true;
			}
			else {
				return false;
			}
		}
		return true;
	}
	return false;
}