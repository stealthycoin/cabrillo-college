#ifndef DLIST_H
#define DLIST_H
#include <iostream>
#include "LinkNode.h"

using namespace std;

template <class T> 
class DList {
public:
	DList() { head = NULL; tail = NULL; size = 0;}
	~DList();
	void insertFront(T*);
	void insertBack(T*);
	void insertOrdered(T*);
	T *removeFront();
	T *removeBack();
	void findDelete(T*);
	void printList() const;
	int getSize() const { return size; }
private:
	int size;
	LinkNode<T> *head;
	LinkNode<T> *tail;
};

template <class T>
DList<T>::~DList(){
	LinkNode<T> *node = head;
	while (node->next) {
		node = node->next;
		delete node->prev;
	}
	delete node;
	delete head;
	delete tail;
	head = NULL;
	tail = NULL;
	node = NULL;
}

template <class T>
void DList<T>::insertFront(T *v){
	LinkNode<T> *node = new LinkNode<T>(v);
	if (!head) {
		tail = node;
		head = node;
	}
	else {
		node->next = head;
		head->prev = node;
		head = node;
	}

	size++;
}

template <class T>
void DList<T>::insertBack(T *v) {
	LinkNode<T> *node = new LinkNode<T>(v);
	if (!head) {
		tail = node;
		head = node;
	}
	else {
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
	
	size++;
}


template <class T>
void DList<T>::insertOrdered(T *v){
	LinkNode<T> *newNode = new LinkNode<T>(v);	
	LinkNode<T> *node = head;
	while (node != NULL && node->value > newNode->value) {
		node = node->next;
	}
	
	if (!head) {
		//empty
		head = newNode;
		tail = newNode;
	}
	else if (!node) {
		//last in list
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	else {
		//right before node
		if (head == node) {
			//first in list
			head = newNode;
			newNode->next = node;
			node->prev = newNode;
		}
		else {
			//attach to item before it
			node->prev->next = newNode;
			newNode->prev = node->prev;
			
			//attach to node
			node->prev = newNode;
			newNode->next = node;
		}
	}
	size++;
}

template <class T>
T *DList<T>::removeFront() {
	if (!head) return NULL; //empty list	
	
	T *retval = head->value;
	
	if (!head->next) {
		//only item in list
		head = NULL;
		tail = NULL;
	}
	else {
		head = head->next;
		head->prev = NULL;
	}
	
	size--;
	return retval;
}

template <class T>
T *DList<T>::removeBack(){
	if (!tail) return NULL; //empty list
	
	T *retval = tail->value;
	
	if (!tail->prev) {
		//only one item in list
		head = NULL;
		tail = NULL;
	}
	else {
		tail = tail->prev;
		tail->next = NULL;
	}
	
	size--;
	return retval;
}




//no special cases
template <class T>
void DList<T>::findDelete(T *v) {
	LinkNode<T> *node = head;
	bool found = false;
	while (node && !found) {
		if (*(node->value) == *v) {
			node->prev->next = node->next;
			node->next->prev = node->prev;
			delete node;
			found = true;
			size--;
		}
		node = node->next;
	}
	
}


template <class T>
void DList<T>::printList() const {
	LinkNode<T> *node = head;
	while (node) {
		cout << *(node->value) << " ";
		node = node->next;
	}
	cout << endl;
}


#endif
