#include <iostream>
#include "SpandexArray.h"

void bubblesort(SpandexArray&);
inline void swap(SpandexArray&, int, int);

int main() {
  SpandexArray data;

   int line;
   while (std::cin >> line)
    data.add(line);
 
  bubblesort(data);
  data.print();
}

void bubblesort(SpandexArray& data) {
  for (int i = data.length()-1 ; i > 0 ; i--) {
    for (int j = 0 ; j < i ; j++) {
      if (data[j] > data[j+1]) {
	swap(data, j, j+1);
      }
    }
  }
}

inline void swap(SpandexArray& data, int a, int b) {
  int t = data[a];
  data[a] = data[b];
  data[b] = t;
}
