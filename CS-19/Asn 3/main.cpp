/**
 * John Carlyle
 * jcarlyle
 * john.w.carlyle@gmail.com
 * Solitaire.cpp
 * Assignment #3 Cinco
 * Given code.
 * Code Status: Working/Tested
 */

#include <iostream>
#include "IntSet.h"
using namespace std;

int main(){
	
	IntSet is1,is2(1,2,5),is3;
	cout << "CS19 Program #3 Integer Set Class"<<endl;
	cout << "John Carlyle john.w.carlyle@gmail.com" <<endl; 
	is1.insertElement(2);    is1.insertElement(4);
	is1.insertElement(2);    is1.insertElement(3);
	is1.insertElement(5);    is1.insertElement(7);
	is1.deleteElement(3);    is1.deleteElement(7);
	is1.deleteElement(9);
	
	for(int i=0; i < (is3.getMax()*0.10); i++)
		is3.insertElement( rand()%is3.getMax() );
	cout <<"is3 (random): ";
	is3.setPrint();
	cout <<endl;
	
	is3.unionOf(is1,is2);
	cout <<"is3 (union): ";
	is3.setPrint();
	cout <<endl;
	
	is3.intersectionOf(is1,is2);
	cout <<"is3 (intersection): ";
	is3.setPrint();
	cout << endl;
	
	if (is3.equals(is3))
		cout << "is3.equals(is3)"<<endl;
	if (is1.equals(is2))
		cout << "is1.equals(is2)"<<endl;
	if (is3.equals(is2))
		cout << "is3.equals(is2)"<<endl;
	if (is2.equals(is2))
		cout << "is2.equals(is2)"<<endl;
	
	cout <<"is1: ";
	is1.setPrint();
  	cout << endl;
	
	if (is1.hasElement(5) ){
		cout <<"is1 contains 5"  << endl;
	} else {
		cout <<"is1 does not contain 5"  << endl;
	}
	if (is1.hasElement(7) ){
		cout <<"is1 contains 7"  << endl;
	} else {
		cout <<"is1 does not contain 7"  << endl;
	}
	
	
}
