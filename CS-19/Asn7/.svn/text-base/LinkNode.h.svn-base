#ifndef LINKNODE_H
#define LINKNODE_H

#include <stdlib.h>
using namespace std;

template <class T> class DList;

template <class T> 
class LinkNode {
public:
	LinkNode() { value = NULL; next = NULL; prev = NULL; }
	LinkNode(T *initVal) { value = initVal; next = NULL ; prev = NULL; }
	~LinkNode() { next = NULL ; prev = NULL ; value = NULL; }
private:
	LinkNode<T> *next;
	LinkNode<T> *prev;
	T *value;
	friend class DList<T>;
};

#endif