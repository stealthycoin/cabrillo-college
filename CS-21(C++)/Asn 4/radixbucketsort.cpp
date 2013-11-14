#include <iostream>
#include "SpandexArray.h"

using namespace std;

inline void radixSort(SpandexArray&, int, int);
inline void bucketSort(SpandexArray&, SpandexArray*, int, int);
inline int ithDigit(int, int);

int main() {
  const int NUM_DIGITS = 9;
  const int D = 10;

  SpandexArray data(10000);

  int line;
  while (cin >> line) {
    data.add(line);
  }

  radixSort(data, D, NUM_DIGITS);
  data.print();
}

inline void radixSort(SpandexArray& data, int range, int digits) {

  SpandexArray *buckets = new SpandexArray[range];
  
  for (int i = 0 ; i < digits ; i++)
    bucketSort(data, buckets, i, range);

  delete [] buckets;
}
 
inline void bucketSort(SpandexArray &data, SpandexArray *buckets, int digit, int range) {
  for (int i = 0 ; i < data.length(); i++)
    buckets[ithDigit(data[i], digit)].add(data[i]);
  int index = 0;
  for (int i = 0 ; i < range; i++) {
    for (int j = 0 ; j < buckets[i].length() ; j++) {
      data[index++] = buckets[i][j];
    }
    buckets[i].clear();
  }
}

inline int ithDigit(int number, int digit)  {
  for (int i = 0 ; i < digit ; i++)
    number /= 10;
  return number % 10;
}


