#include "intMinHeap.h"
#include <iostream>

using namespace std;

int main() {

  int array[] = {5,3,7,1,2,4,9,8,6,10};
  intMinHeap imh(array, 10);
  cout << "John Carlyle\n";
  imh.print();
  cout << "Extract min: " << imh.extractmin() << endl;
  cout << "Extract min: " << imh.extractmin() << endl;
  imh.print();
  cout << "Inserting 1\n";
  imh.heapinsert(1);
  imh.print();
  imh.heapsort();
  imh.print();
}
