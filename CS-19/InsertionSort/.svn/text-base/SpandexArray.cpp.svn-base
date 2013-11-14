#include <iostream>
#include <sstream>
#include "SpandexArray.h"

SpandexArray::SpandexArray(int c) { 
  size = 0;
  capacity = c;
  a = new int[c];
 }

SpandexArray::~SpandexArray() {
  if (a !=0) delete [] a;
  a = 0; 
 }

void SpandexArray::add(int key) {
  if (size >= capacity) expand();
  a[size++] = key;
}

int SpandexArray::get(int i) {
  if (i >= 0 && i < size) return a[i];
  return 0;
}

void SpandexArray::print() {
  std::stringstream ss;
  for (int i = 0 ;i < size; i++)
    ss << a[i] << std::endl;
  std::cout << ss.str();
}

void SpandexArray::empty() {
  size = 0;
}

int& SpandexArray::operator[] (unsigned i) {
  if (i < size) return a[i];
  std::cerr << "Index out of bounds: " << i << std::endl;
  exit(1);
}

void SpandexArray::expand() {
  capacity *= 2 + 1;
  int *b = new int[capacity];
  for (int i = 0 ; i < size; i++)
    b[i] = a[i];

  delete [] a; 
  a = 0;
  a = b;
}
