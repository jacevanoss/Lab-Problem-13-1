#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);
int getMonthName(const string& monthName);
void printCalender(int month, int year);

int main() {

	int month;
	int year;
	string inputMonth;
	string inputYear;

	while (true) {
		cout << "Enter a month and year or Q to quit: ";
		cin >> inputMonth;
		if (inputMonth == "Q" || inputMonth == "q") {
			break;
		}
		else {
			month = getMonthName(inputMonth);
			if (month != -1) {
				cin >> inputYear;
				year = stoi(inputYear);
				printCalender(month, year);
			}
			else {
				cout << "Invalid Month" << endl;
			}
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
}
int dayOfWeek(int month, int day, int year) {
	if (month <= 2){
		month += 12;
		year -= 1;
	}
	int k = year % 100;
	int j = year / 100;
	int h = (day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
	return (h + 5) % 7;
}
int getMonthName(const string& monthName) {
	if (monthName == "January") {
		return 1;
	}
	else if (monthName == "February") {
		return 2;
	}
	else if (monthName == "March") {
		return 3;
	}
	else if (monthName == "April") {
		return 4;
	}
	else if (monthName == "May") {
		return 5;
	}
	else if (monthName == "June") {
		return 6;
	}
	else if (monthName == "July") {
		return 7;
	}
	else if (monthName == "August") {
		return 8;
	}
	else if (monthName == "September") {
		return 9;
	}
	else if (monthName == "October") {
		return 10;
	}
	else if (monthName == "November") {
		return 11;
	}
	else if (monthName == "December") {
		return 12;
	}
	else {
		return -1;
	}
}
void printCalender(int month, int year) {
	string calendar[] = {
		"                   1  2  3  4  5  6  7 ",
		" 2  3  4  5  6  7  8  9 10 11 12 13 14 ",
		" 9 10 11 12 13 14 15 16 17 18 19 20 21 ",
		"16 17 18 19 20 21 22 23 24 25 26 27 28 ",
		"23 24 25 26 27 28 29 30 31             ",
		"30 31                                  "
	};
	
	cout << "Su Mo Tu We Th Fr Sa" << endl;

	int startDay = dayOfWeek(month, 1, year);
	int numDays = daysInMonth(month, year);

	int day = 1;
	for (int i = 0; i < startDay + 1; i++) {
		cout << "   ";
	}
	for (int i = startDay + 1; day <= numDays; i++) {
		cout << setw(2) << day << " ";
		day++;
		if (i == 6) {
			cout << endl;
			i = -1;
		}
	}
	cout << endl;
}
	