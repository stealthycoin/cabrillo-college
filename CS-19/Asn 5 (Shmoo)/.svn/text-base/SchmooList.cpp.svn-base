#include <iostream>
#include "SchmooList.h"

void SchmooList::insertFront(Schmoo* s) {
  LinkNode *node = new LinkNode(s);
  node->next = head;
  head = node;
}

void SchmooList::throwMudAt(double x, double y) {
  LinkNode *node = head;
  while (node) {
    if (pow(x - node->data->getX(),2) + pow(y - node->data->getY(),2) <= 25) {
      node->data->incrementMud();
    }
    node = node->next;
  }
}

void SchmooList::removeAt(double x, double y) {
  LinkNode *prev = NULL;
  LinkNode *node = head;
  while (node) {
    if (pow(x-node->data->getX(),2) + pow(y-node->data->getY(),2) <= 1) {
      LinkNode *temp=node;
      node=node->next;
      prev->next = node;
      delete temp; temp = 0;
    }
    else {
      prev = node;
      node = node->next;
    }
  }
}


int SchmooList::getPopulation() const {
  int count = 0;
  LinkNode *node = head;
  while (node) {
    count++;
    node = node->next;
  }
  return count;
}


void SchmooList::printAll() const {
   LinkNode *node = head;
   while (node) {
     std::cout << *node;
    node = node->next;
  }

}
