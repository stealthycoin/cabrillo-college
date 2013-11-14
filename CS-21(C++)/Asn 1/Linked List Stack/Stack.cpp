#include "Stack.h"

Stack::Stack() {
	head = 0;
	size = 0;
}

void Stack::push(double d) {
	Node *node = new Node(d);
	
	if (!head) {
		head = node;
	}
	else {
		node->next = head;
		head = node;
	}
	size++;
}

double Stack::pop() {
	Node *temp = head;
	
	double val = head->data;
	head = head->next;
	
	delete temp;
	size--;
	return val;
}

bool Stack::isempty() {
	return (size == 0);
}