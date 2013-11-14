#ifndef MAZE_H
#define MAZE_H

#include "DisjointSet.h"

class Maze {
 public:
  Maze(int);
 private:
  void buildMaze();
  void resetRandomPool();
  inline void swap(int*&,int,int);

  const int size;
  int count;

  DisjointSet *set;
  int *pool;
  int **tiles;
};

#endif

