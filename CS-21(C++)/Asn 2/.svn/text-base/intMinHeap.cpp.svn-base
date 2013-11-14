#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "intMinHeap.h"

intMinHeap::intMinHeap(int a[], int length) {
  size = length;
  capacity = length+1;
  A = new int[capacity];
  A[0] = 0;
  for (int i = 0; i < length;i++)
      A[i+1] = a[i];
  heap = false;
  buildheap();
}

intMinHeap::~intMinHeap() {
  delete [] A;
}

void intMinHeap::heapify(int i) {
  int r = min(i, left(i), right (i));
  if (r == i) return;
  
  int t = A[i];
  A[i] = A[r];
  A[r] = t;

  heapify(r);
}

void intMinHeap::buildheap() {
  for (int i = size/2; i > 0; i--)
    heapify(i);
  heap = true;
}

void intMinHeap::heapsort() {
  int oldSize = size;
  while (size > 0) {
    int t = A[1];
    A[1] = A[size];
    A[size] = t;
    size--;
    heapify(1);
  }
  heap = false;
  size = oldSize;
}

void intMinHeap::print() {
  std::stringstream ss;
  bool first = true;
  if (heap) std::cout << "Heap: ";
  else std::cout << "Array: ";
  for (int i = 1 ; i <= size; i++) {
    if (!first) {
      ss << ", ";
    }
    ss << A[i];
    first = false;
  }
  std::cout << ss.str() << std::endl;
}

void intMinHeap::heapinsert(int key) {
  size++;
  if (size > capacity)
    expandArray();
  A[size] = key+1;
  decreasekey(size, key);
}

int intMinHeap::minimum() {
  if (size >= 1)
    return A[1];
  return 0;
}

int intMinHeap::extractmin() {
  if (size >= 1) {
    int min = A[1];
    A[1] = A[size];
    size--;
    heapify(1);
    return min;
  }
  rxeturn 0;
}

void intMinHeap::decreasekey(int i, int key) {
  if (A[i] <= key) return;
  A[i] = key;
  for (int j = i; j > 0 && A[j] < A[parent(j)]; j = parent(j)) {
    int t = A[parent(j)];
    A[parent(j)] = A[j];
    A[j] = t;
    heapify(j);
  }
}

void intMinHeap::expandArray() {
  int oldcapacity = capacity;
  capacity *= 2;
  int *B = new int[capacity];
  for (int i = 0 ; i <= oldcapacity;i++) {
    B[i] = A[i];
  }
  A = B;
  B = NULL;

}

int intMinHeap::min(int a, int b, int c) {
  if (b > size)
    return a;
  if (c > size)
    return A[a] > A[b] ? b : a;
  return A[a] < A[b] ? A[a] < A[c] ? a :c : A[b] < A[c] ? b : c;
}
