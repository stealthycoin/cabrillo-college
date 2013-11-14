#ifndef SPANDEX_ARRAY
#define SPANDEX_ARRAY

class SpandexArray {
 public:
  SpandexArray(int=1000000);
  SpandexArray(const SpandexArray&);
  ~SpandexArray();
  void add(int);
  void clear();
  int get(int) const;
  void print() const;
  int length() const {return size;}
  int& operator[] (unsigned) const; 
  SpandexArray& operator= (const SpandexArray&);
 private:
  void resize();
  int size, capacity;
  int *a;
};


#endif
