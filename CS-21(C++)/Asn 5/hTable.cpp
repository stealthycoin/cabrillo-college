#include <cmath>
#include "hTable.h"

hashTable::hashTable(int size) : m(size)  {
  entries = new std::list<record*>[m];
}

void hashTable::insert(record *r) {
  entries[hash(r)].push_front(r);
}

void hashTable::remove(int key) {
  record *r = find(key);
  if (r != NULL)
    entries[hash_key(key)].remove(r);
  r = NULL;
}

record *hashTable::search(int key) {
  return find(key);
}

void hashTable::clear() {
  for (int i = 0 ; i < m ; i++) {
    entries[i].clear();
  }
}

void hashTable::save(std::ofstream &fout) {
  for (int i = 0 ; i < m ; i++)
    for (std::list<record*>::iterator it = entries[i].begin() ; it != entries[i].end() ; it++)
      fout << (*it)->toString();
}

record *hashTable::find(int key) {
  int i = hash_key(key);
  for (std::list<record*>::iterator it = entries[i].begin() ; it != entries[i].end(); it++) {
    if (key == (*it)->key) {
      return *it;
    }
  }
  return NULL;

}

int hashTable::hash(record *r) {
  return hash_key(r->key);
}

int hashTable::hash_key(int key) {
    return floor(m*(c*key-floor(c*key)));
}
