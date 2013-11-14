#ifndef STACK_H
#define STACK_H
#include "Node.h"

class Stack {
public:
	Stack();
	void push(double);
	double pop();
	bool isempty();
private:
	Node *head;
	int size;
};

#endif