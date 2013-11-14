#include <iostream>
#include "SpandexArray.h"

void insertionsort(SpandexArray&);
inline void swap(SpandexArray&, int, int);

int main() {
  SpandexArray data;

   int line;
   while (std::cin >> line)
    data.add(line);
 
  insertionsort(data);
  data.print();
}


void insertionsort(SpandexArray &data) {
  for (int i = 1 ; i < data.length() ; i++) {
    int key = data[i];
    int j = i - 1;
    while (j >= 0 && data[j] > key) {
      data[j+1] = data[j];
      j--;
    }
    data[j+1] = key;
  } 
}

inline void swap(SpandexArray& data, int a, int b) {
  int t = data[a];
  data[a] = data[b];
  data[b] = t;
}
