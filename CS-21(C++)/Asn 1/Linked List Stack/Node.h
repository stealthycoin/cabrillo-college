#ifndef NODE_H
#define NODE_H

class Node {
public:
	Node(double value) { next = 0; data = value; }
	Node *next;
	double data;
};

#endif