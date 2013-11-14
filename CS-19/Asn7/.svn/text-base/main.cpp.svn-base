#include <iostream>
#include "DList.h"

using namespace std;

int main() {
	DList <int> *list = new DList<int>();
	
	int a = 34;
	int b = 35;
	int c = 36;
	int d = 37;
	int e = 38;
	
	list->insertOrdered(&c);
	list->insertOrdered(&e);
	list->insertOrdered(&b);
	list->insertOrdered(&d);
	list->insertOrdered(&a);
	list->printList();
	
	cout << "First: " << *list->removeFront() << endl;
	cout << "Last:  " << *list->removeBack() << endl;
	list->findDelete(&c);
	cout << "Remove Middle element" << endl;
	list->printList();
	
	cout << "Test removeFront()" << endl;
	list->removeFront();//two elements left
	list->removeFront();//one element left
	list->removeFront();//zero elements left
	cout << "removeFront() passed" << endl;
	
	list->insertBack(&a);
	list->insertBack(&b);
	
	cout << "Test removeBack()" << endl;
	list->removeBack();//two elements left
	list->removeBack();//one element left
	list->removeBack();//zero elements left
	cout << "removeBack() passed" << endl;
	
		
	cout << "Add all objects in order:" << endl;
	list->insertOrdered(&c);//36
	list->insertOrdered(&e);//38
	list->insertOrdered(&a);//34
	list->insertOrdered(&d);//37
	list->insertOrdered(&b);//35
	list->printList();
	
	cout << "Destructor test" << endl;
	delete list;
	list = NULL;
	
	cout << "All tests passed!" << endl;
	return 0;
}