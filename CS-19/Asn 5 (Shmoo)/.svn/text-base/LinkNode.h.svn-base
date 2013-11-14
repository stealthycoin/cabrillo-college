#ifndef LINKNODE_H
#define LINKNODE_H

#include "Schmoo.h"

class LinkNode {
  friend class SchmooList;
 public:
  LinkNode(Schmoo*d=NULL) { next = NULL; data = d; }
  ~LinkNode() { delete data; data = NULL; }
 private:
  LinkNode *next;
  Schmoo *data;
};

#endif
