#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;


inline void resize(int *&array, int &size);
void quicksort(int *&, int, int);
inline int partition(int *&, int, int);
inline void medof3(int *&, int, int);
inline void insertionsort(int *&, int, int);
inline void swap(int*&, int, int);

int main() {
  int size = 10000;
  int *array = new int[size];
  int i = -1, line;
  while (cin >> line) {
    if (i == size) resize(array, size);
    array[++i] = line;
  }
  quicksort(array, 0, i);
  insertionsort(array, 0, i);
  stringstream ss;
  for (int j = 0 ; j < i ; j++) {
    ss <<setfill('0') << setw(9) << array[j] << endl;
  }

  cout << ss.str();

  delete [] array;
}


inline void resize(int *&array, int &size) {
  size = size *  2 + 1;
  int *newArray = new int[size];
  for (int i = 0 ; i < size/2; i++)
    newArray[i] = array[i];
  delete [] array;
  array = newArray;
  newArray = NULL;
}


void quicksort(int *&a, int p, int r) {
  if (p >= r) return;
  int q = partition(a, p, r);
  if (q == -1) return;
  quicksort(a, p, q-1);
  quicksort(a, q+1, r);
}

inline int partition(int *&a, int p, int r) {
  if (r - p <= 17) {
    //insertionsort(a, p, r);
    return -1;
  }
  medof3(a, p, r);
  int x = a[r];
  int i = p - 1;
  for (int j = p; j < r;j++) {
    if (a[j] < x) {
      i++;
      swap(a, j, i);
    }
  }
  swap(a, i+1, r);
  return i+1;
}

inline void medof3(int *&a, int p, int r) {
  int m = (r+p)/2;
  if (a[m] > a[r])
    swap(a, m, r);
  if (a[p] < a[m])
    swap(a, m, r);
  else if (a[p] < a[r])
    swap(a, p, r);
  }

inline void swap(int *&a, int l, int r) {
  int t = a[l];
  a[l] = a[r];
  a[r] = t;
}

inline void insertionsort(int *&data, int p, int r) {
  int key, i;
  for (int j = p+1 ; j < r ; j++)    {
    key = data[j];
    for (i = j - 1; i >= p && data[i] > key ; i--)
      data[i+1] = data[i];
    data[i+1] = key;
  }
}

