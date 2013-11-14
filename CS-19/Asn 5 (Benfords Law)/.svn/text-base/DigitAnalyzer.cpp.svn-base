/**
 * John Carlyle
 * jcarlyle
 * john.w.carlyle@gmail.com
 * DigitAnalyzer.cpp
 * Assignment #5 Looking out for number one
 * Is a linkedlist of integers. Can calculate starting digits.
 * Code Status: Working/Tested
 */

#include <math.h>
#include <iostream>
#include <iomanip>
#include "DigitAnalyzer.h"

using namespace std;

DigitAnalyzer::DigitAnalyzer() {
	head = NULL;
	size = 0;
}

DigitAnalyzer::~DigitAnalyzer() {
	LinkNode *last;
	LinkNode *node = head;
	while (node) {
		last = node;
		node = node->next;
		delete last;
	}
	delete node;
}

int DigitAnalyzer::getSize(){
	return size;
}

int *DigitAnalyzer::getStartingDigits(){
	int *list = new int[10];
	for (int i = 0; i < 10; i++) {
		list[i] = 0;
	}
	
	LinkNode *testNode = head;
	while (testNode) {
		list[getFirstDigit(testNode->digit)]++;
		testNode = testNode->next;
	}
	return list;
}

int DigitAnalyzer::getFirstDigit(int num) {
	while (num >= 10) num /= 10;
	return num;
}

void DigitAnalyzer::insert(int i){
	LinkNode *node = new LinkNode(i);
	node->next = head;
	head = node;
	size++;
}

