#ifndef SPANDEX_ARRAY
#define SPANDEX_ARRAY

class SpandexArray {
 public:
  SpandexArray(int c = 100);
  ~SpandexArray();
  void add(int);
  int get(int);
  void print();
  int length() {return size;}
  void empty();
  int& operator[] (unsigned i); 
 private:
  void expand();
  int size, capacity;
  int *a;
};


#endif
