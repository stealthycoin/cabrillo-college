#ifndef SCHMOO_LIST_H
#define SCHMOO_LIST_H

#include <cmath>
#include "LinkNode.h"

/**
Really secretly a linked list
*/

class SchmooList {
 public:
  SchmooList() { head = NULL; }
  void insertFront(Schmoo*);
  void throwMudAt(double,double);
  void removeAt(double,double);
  int getPopulation() const;
  void printAll() const;
 private:
  LinkNode *head;
};

#endif
