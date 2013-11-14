/**
 * John Carlyle
 * jcarlyle
 * john.w.carlyle@gmail.com
 * Solitaire.cpp
 * Assignment #3 IntSet
 * Header File
 * Code Status: Working/Tested
 */

#ifndef INTSET_H
#define INTSET_H

class IntSet{
public:
	IntSet(int a=-1,int b=-1, int c=-1, int d=-1, int e=-1);
	void insertElement(int);
	void deleteElement(int);
	void setPrint() const;
	void unionOf(IntSet &, IntSet &);
	void intersectionOf(IntSet &, IntSet &);
	bool equals(IntSet) const;
	bool hasElement(int) const;
	int static getMax(){ return MAXSETVAL; }
private:
	static const int MAXSETVAL=1000;
	bool data[MAXSETVAL+1];
};

#endif