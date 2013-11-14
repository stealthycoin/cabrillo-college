/**
 * John Carlyle
 * jcarlyle
 * john.w.carlyle@gmail.com
 * main.cpp
 * Assignment #5 Looking out for number one
 * Reads in data from either cin or a file and sends it to be processed then outputs a table with the results
 * Code Status: Working/Tested
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "DigitAnalyzer.h"

using namespace std;

int main(int argc, char **argv) {
	istream *fin;
	bool deleteFin = false;
	if (argc == 1) {
		fin = &cin;
	}
	else if (argc == 2) {
		deleteFin = true;
		fin = new ifstream(argv[1]);
		if (fin->fail()) {
			cerr << "Could not open file: " << argv[1] << endl;
			exit(1);
		}
	}
	else {
		cerr << "Incorrect usage. Supply filename as argument on command line. Or supply no arguments and enter filename through stdin.\n";
	}
	
	DigitAnalyzer *list = new DigitAnalyzer;
	
	
	
	string line;
	int i;
	while(getline(*fin, line)) {
		if ((i = line.find("(*")) != -1) {
			line = line.substr(0,i).append(line.substr(line.find("*)")+2));
		}
		if (line.length() > 0) {
			list->insert(atoi(line.c_str()));
		}
	}
	int *sd = list->getStartingDigits();
	
	
	cout << "Total: " << list->getSize() << endl;
	cout << setw(10) << left << "Digit" << setw(10) << left << "Count" << setw(10) << left << "Percent" << endl;
	for (int i = 0 ; i < 10 ; i++) {
		cout << setw(10) << left << i << setw(10) << left << sd[i] << setprecision(1) << fixed << sd[i]*100.0f/list->getSize() << "%" << endl;
	}
	if (deleteFin) delete fin;
	delete[] sd;
	delete list;
	return 0;
}