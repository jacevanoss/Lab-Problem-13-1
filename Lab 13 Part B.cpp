#include <iostream>
#include <string>

using namespace std;

//bool isLeapYear(int year);
//int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);
string getWeekdayName(int dayOfWeek);
string getMonthName(int month);

int main() {

	string userInput;
	int month;
	int year;
	int day;

	while (true) {
		cout << "Enter a date or Q to quit: ";
		cin >> userInput;
		if (userInput == "Q" || userInput == "q") {
			break;
		}
		month = stoi(userInput);
		cin >> day >> year;
		int Dow = dayOfWeek(month, day, year);
		string weekday = getWeekdayName(Dow);
		string monthName = getMonthName(month);
		cout << weekday << ", " << monthName << " " << day << ", " << year << endl;


	}

	return 0;
}
//bool isLeapYear(int year) {
	//if (year % 4 == 0) {
		//if (year % 100 == 0) {
			//if (year % 400 == 0) {
				//return true;
			//}
			//else {
				//return false;
			//}
		//}
		//return true;
	//}
	//return false;
//}
//int daysInMonth(int month, int year) {
	//if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		//return 31;
	//}
	//if (month == 4 || month == 6 || month == 9 || month == 11) {
		//return 30;
	//}
	//if (month == 2) {
		//if (isLeapYear(year)) {
			//return 29;
		//}
		//else {
			//return 28;
		//}
	//}
	//return -1;
//}
int dayOfWeek(int month, int day, int year) {
	if (month == 1 || month == 2) {
		month += 12;
		year -= 1;
	}
	int q = day;
	int m = month;
	int y = year % 100;
	int c = year / 100;
	int zellers = (q + (13 * (m + 1)) / 5 + y + y / 4 + c / 4 + 5 * c) % 7;
	return zellers;
}
string getWeekdayName(int dayOfWeek) {
	switch (dayOfWeek) {
		case 0: return "Saturday";
		case 1: return "Sunday";
		case 2: return "Monday";
		case 3: return "Tuesday";
		case 4: return "Wednesday";
		case 5: return "Thursday";
		case 6: return "Friday";
		default: return "Invalid day";
	}
}
string getMonthName(int month) {
	switch (month) {
		case 1: return "January";
		case 2: return "Febuary";
		case 3: return "March";
		case 4: return "April";
		case 5: return "May";
		case 6: return "June";
		case 7: return "July";
		case 8: return "August";
		case 9: return "September";
		case 10: return "October";
		case 11: return "November";
		case 12: return "December";
		default: return "Invalid Month";
	}
}