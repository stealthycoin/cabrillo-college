#ifndef IMH_H
#define IMH_H

// integer minimum heap with PQ 
class intMinHeap{
public:
  intMinHeap(int[], int);  // create an empty heap
  ~intMinHeap();  // clean up allocated memory
  void heapify(int i);  // heapify at position i
  void buildheap();  // convert array to a heap
  void heapsort();  // convert heap to sorted array
  void print();  // contents of array (data portion)
  void heapinsert(int); // add element to heap
  // min functions should return 0 in empty heaps 
  int minimum();  // return value of A[1]
  int extractmin(); // return and remove A[1]
  void decreasekey(int, int);  // A[i] decreased to k  
private:
  inline int left(int n) { return n*2; }
  inline int right(int n) { return n*2+1; }
  inline int parent(int n) { return n/2; }
  inline int min(int a, int b, int c);
  inline void expandArray();
  int *A;  // array of integers - data
  int capacity; // size of array A
  int size; // data size in array (<= capacity)
  bool heap; // is the data organized heap?
};

#endif
