/**
 * John Carlyle
 * jcarlyle
 * john.w.carlyle@gmail.com
 * Solitaire.cpp
 * Assignment #3 IntSet
 * Represents a set of integers through a bitset.
 * Code Status: Working/Tested
 */


#include <iostream>
#include "IntSet.h"
using namespace std;

IntSet::IntSet(int a, int b, int c, int d, int e) {
	for (int i = 0 ; i <= MAXSETVAL ; i++) {
		data[i] = 0;
	}
	
	if (a != -1) insertElement(a);
	if (b != -1) insertElement(b);
	if (c != -1) insertElement(c);
	if (d != -1) insertElement(d);
	if (e != -1) insertElement(e);
}

void IntSet::insertElement(int e) {
	if (e >=0 && e <= MAXSETVAL) {
		data[e] = true;
	}
}

void IntSet::deleteElement(int e) {
	if (e >= 0 && e <= MAXSETVAL) {
		data[e] = false;
	}
}

void IntSet::setPrint() const {
	bool first = true;
	cout << "{";
	for (int i = 0 ; i <= MAXSETVAL ;i++) {
		if (data[i]) {
			if (!first)
				cout << ", ";
			first = false;
			cout << i;
		}
	}
	cout << "}\n";
}

void IntSet::unionOf(IntSet &a, IntSet &b) {
	for ( int i = 0 ; i <= MAXSETVAL ; i++) {
		if (a.data[i] || b.data[i]) {
			data[i] = 1;
		}
		else {
			data[i] = 0;
		}
	}
}

void IntSet::intersectionOf(IntSet &a, IntSet &b) {
	for ( int i = 0 ; i <= MAXSETVAL ; i++) {
		if (a.data[i] && b.data[i]) {
			data[i] = 1;
		}
		else {
			data[i] = 0;
		}
	}
}

bool IntSet::equals(IntSet set) const {
	for (int i = 0 ; i <= MAXSETVAL ; i++) {
		if (data[i] != set.data[i]) {
			return false;
		}
	}
	return true;
}

bool IntSet::hasElement(int e) const {
	if (e >= 0 && e <= MAXSETVAL) {
		return data[e];
	}
	return false;
}