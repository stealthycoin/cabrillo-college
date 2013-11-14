#include <iostream>
#include "SpandexArray.h"

void selectionsort(SpandexArray&);
inline void swap(SpandexArray&, int, int);

int main() {
  SpandexArray data;

   int line;
   while (std::cin >> line)
    data.add(line);
 
  selectionsort(data);
  data.print();
}


void selectionsort(SpandexArray &data) {
  int mindex;
  for (int i = 0 ; i < data.length() - 1 ; i++) {
    mindex = i;
    for (int j = i+1 ; j < data.length() ; j++) {
      if (data[mindex] > data[j])
	mindex = j;
    }
    swap(data, mindex, i);
  }
}


inline void swap(SpandexArray& data, int a, int b) {
  int t = data[a];
  data[a] = data[b];
  data[b] = t;
}
