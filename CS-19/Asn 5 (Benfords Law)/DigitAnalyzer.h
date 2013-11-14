/**
 * John Carlyle
 * jcarlyle
 * john.w.carlyle@gmail.com
 * DigitAnalzer.h
 * Assignment #5 Looking out for number one
 * Header File
 * Code Status: Working/Tested
 */

#ifndef D_A_H
#define D_A_H

#include "LinkNode.h"

class DigitAnalyzer {
public:
	DigitAnalyzer();
	~DigitAnalyzer();
	int getSize();
	int *getStartingDigits();
	int getFirstDigit(int);
	void insert(int);
private:
	LinkNode *head;
	int size;
};


#endif