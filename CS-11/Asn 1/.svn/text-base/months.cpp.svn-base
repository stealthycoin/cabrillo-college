#include <iostream>

using namespace std;

bool input();

int main() {
	string months[] = {"31", "28 or 29", "31", "30", "31", "30", "31", "31", "30", "31", "30", "31"};
	
	bool repeat = true;
	int month;
	while (repeat == true) {
		cout << "The month (1-12): ";
		cin >> month;
		if (month >= 1 && month <= 12) {
			cout << months[month-1] << " days\n";
		}
		else {
			cout << "Error " << month << " is not a valid month number.\n";
		}

		repeat = input();
	}
	
	return 0;
}

bool input() {
	string input;
	while (true) {
		cout << "Run again? (y/n)";
		cin >> input;
		if (input.compare("y") == 0 || input.compare("Y") == 0) {
			return true;
		}
		if (input.compare("n") == 0 || input.compare("N") == 0) {
			return false;
		}
		
		cout << "Please enter a \"y\" or an \"n\"\n";
	}
}