#include <iostream>
#include <fstream>
#include "hTable.h"

bool menu(hashTable&);

void loadFile(hashTable&);
void insert(hashTable&);
void remove(hashTable&);
void search(hashTable&);
void clear(hashTable&);
void save(hashTable&);

void processInput(hashTable&, const std::string);

int main() {

  hashTable hashtable(178000);
  
  bool loop = true;
  while (loop)
    loop = menu(hashtable);
}

bool menu(hashTable &ht) {
  int choice;

  std::cout << "1. Insert data from file.\n";
  std::cout << "2. Insert new entry\n";
  std::cout << "3. Delete record\n";
  std::cout << "4. Search\n";
  std::cout << "5. Clear\n";
  std::cout << "6. Save\n";
  std::cout << "7. Quit\n";
  std::cout << "Choice: ";

  std::cin >> choice;

  if (choice == 7)
    return false;
  else if (choice == 6)  
    save(ht);
  else if (choice == 5) 
    clear(ht);
  else if (choice == 4) 
    search(ht);
  else if (choice == 3) 
    remove(ht);
  else if (choice == 2) 
    insert(ht);
  else if (choice == 1)
    loadFile(ht);
  return true; 
}


void loadFile(hashTable &ht) {
  std::cout << "Filename to load: ";
  char *filename = new char[255];
  std::cin >> std::ws;
  std::cin.getline(filename, 255);


  std::ifstream fin(filename);
  if (fin.good()) {
    std::string line;
    while (std::getline(fin, line))
      processInput(ht, line);
  }
  else {
    std::cerr << "Failed to open " << filename << "\n";
  }
  fin.close();
}

void insert(hashTable &ht) {
  std::cout << "New entry: ";
  std::string entry;

  std::cin >> std::ws;
  std::getline(std::cin,  entry);

  processInput(ht, entry);
}

void remove(hashTable &ht) {
  std::cout << "Enter key to delete: ";
  int key;
  std::cin >> key;
  ht.remove(key);
}

void search(hashTable &ht) {
  int key;
  std::cout << "Search Key: ";
  std::cin >> key;
  record *r = ht.search(key);
  if (r == NULL)
    std::cout << "Could not find " << key << "\n";
  else
    r->print();

  r = NULL;
}

void clear(hashTable &ht) {
  ht.clear();
}


void save(hashTable &ht) {
  std::cout << "Filename to save to: ";
  char *filename = new char[255];
  std::cin >> std::ws;
  std::cin.getline(filename, 255);

  std::ofstream fout(filename);
  if (fout.good())
    ht.save(fout);
  else
    std::cout << "Could not write to file " << filename << std::endl;
  fout.close();

}


void processInput(hashTable &ht,  std::string input) {
  int index;
  if ((index = input.find(' ')) != -1) {
    record *r = new record(atoi(input.substr(0,index).c_str()),
			   atoi(input.substr(index+1).c_str()));

    ht.insert(r);
    r= NULL;
  } 
}
