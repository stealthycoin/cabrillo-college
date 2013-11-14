#ifndef H_TABLE
#define H_TABLE
#include <sstream>
#include <fstream>
#include <list>
#include <iostream>

class record;

class hashTable{
 public:
  hashTable(int=100);
  void insert(record *);
  void remove(int);
  record *search(int); 
  void clear();
  void save(std::ofstream&);
 private:
  std::list<record*> *entries;
  record *find(int);
  int hash(record *);
  int hash_key(int);
  const int m;
  static const double c = 0.6180339887498948;
};

class record {
 friend class hashTable;
 public:
  record(int k, int v) { key  = k; value = v; }
  void print() { std::cout << key << " " << value << std::endl; }
  std::string toString() {std::stringstream ss;ss << key << " " << value << std::endl;return ss.str();}
  private:
  int key, value;
};

#endif H_TABLE
