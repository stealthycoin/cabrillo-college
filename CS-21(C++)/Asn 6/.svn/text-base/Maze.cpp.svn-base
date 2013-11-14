#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Maze.h"

Maze::Maze(int m) : size(m) {
  srand(time(NULL));
  set = new DisjointSet(size*size);
  tiles = new int*[size];
  pool = new int[size*size];

  for (int i = 0 ; i < size ; i++)
    tiles[i] = new int[size];
  buildMaze();
}


void Maze::buildMaze() {
  resetRandomPool();
  while (set->getCount() != 0) {

  }
}

void Maze::resetRandomPool() {
  for (int i = 0 ; i < size*size ; i++)
    pool[i] = i;
  int j = 0;
  for (int i = 0 ; i < size*size - j ; i++)
    swap(pool, i, rand() % (size-j));
}

inline void Maze::swap(int *&a, int x, int y) {
  int t = a[y];
  a[y] = a[x];
  a[x] = t;
}
