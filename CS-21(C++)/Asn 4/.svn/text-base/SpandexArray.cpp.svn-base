#include <iostream>
#include <sstream>
#include "SpandexArray.h"

SpandexArray::SpandexArray(int c) { 
  size = 0;
  capacity = c;
  a = new int[c];
 }

SpandexArray::SpandexArray(const SpandexArray &orig) { 
  *this = orig;
  /*size = orig.size;
  capacity = orig.capacity;
  a = new int[c];
  for (int i = 0 ; i < size ; i++)
  a[i] = orig.a[i];*/
}

SpandexArray::~SpandexArray() {
  if (a !=0) delete [] a;
  a = 0; 
 }

void SpandexArray::add(int key) {
  if (size >= capacity) resize();
  a[size++] = key;
}

void SpandexArray::clear() {
  size = 0;
}

int SpandexArray::get(int i) const {
  if (i >= 0 && i < size) return a[i];
  return 0;
}

void SpandexArray::print() const {
  std::stringstream ss;
  for (int i = 0 ;i < size; i++)
    ss << a[i] << std::endl;
  std::cout << ss.str();
}

int& SpandexArray::operator[] (unsigned i) const {
  if (i < size) return a[i];
  std::cerr << "Index out of bounds: " << i << std::endl;
  exit(1);
}

SpandexArray& SpandexArray::operator= (const SpandexArray &orig) {
  size = orig.size;
  capacity = orig.capacity;
  if (a != NULL) delete [] a;
  a = new int[capacity];
  for (int i = 0 ; i < size ; i++)
    a[i] = orig.a[i];
  return *this;
}

void SpandexArray::resize() {
  capacity *= 2 + 1;
  int *b = new int[capacity];
  for (int i = 0 ; i < size; i++)
    b[i] = a[i];

  delete [] a; 
  a = 0;
  a = b;
}
