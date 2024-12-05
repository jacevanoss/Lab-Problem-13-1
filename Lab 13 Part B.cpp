#include <iostream>
#include <string>

using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);

int main() {

	string userInput;
	int month;
	int year;

	while (true) {
		cout << "Enter a month and year or Q to quit: ";
		cin >> userInput;
		if (userInput == "Q" || userInput == "q") {
			break;
		}
		month = stoi(userInput);
		cin >> year;
		int days = daysInMonth(month, year);
		string monthNames[] = { "Invalide", "Janary", "Febuary", "March", "April", "May", "June", "July", "Auguest", "September", "October", "November", "Decemver" };
		cout << monthNames[month] << " " << year << " has " << days << " days." << endl;


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
int daysInMonth(int month, int year) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		return 31;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	if (month == 2) {
		if (isLeapYear(year)) {
			return 29;
		}
		else {
			return 28;
		}
	}
	return -1;
}
int dayOfWeek(int month, int day, int year) {
	return 1;
}