#ifndef DISJOINTSET_H
#define DISJOINTSET_H

class DisjointSet {
 public:
  DisjointSet(int);
  ~DisjointSet() {delete [] p; delete [] r;}
  void makeSet(int);
  void setunion(int,int);
  int findSet(int);
  int getCount() const {return count;}
 private:
  int count;
  void link(int,int);
  int *p, *r;
};

#endif
