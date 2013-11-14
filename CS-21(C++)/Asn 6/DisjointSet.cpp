#include "DisjointSet.h"

DisjointSet::DisjointSet(int n) {
  count = n;
  p = new int[n];
  r = new int[n];
  for (int i = 0 ; i < n ; i++) {
    makeSet(n);
  }
}

int DisjointSet::findSet(int x) {
  while (x != p[x]) {
    x = p[x];
  }
  return x;
}

void DisjointSet::makeSet(int n) {
  p[n] = n;
  r[n] = 1;
}

void DisjointSet::setunion(int a, int b) {
  if (r[a] > r[b])
    p[b] = a;
  else {
    p[a] = b;
    if (r[a] == r[b])
      r[b]++;
  }
  count--;
}

void DisjointSet::link(int a, int b) {
  setunion(findSet(a), findSet(b));
}
