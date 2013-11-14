#include <ctype.h>
#include <iostream>;
#include <algorithm>
#include "SchmooList.h"
#include "Schmoo.h"

using namespace std;

int main() {
  string s,a,b;
  int index;
  SchmooList list;

  while (getline(cin, s)) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if ((index = s.find("add schmoo ")) != 0) {
      s = s.substr(11);
      a = s.substr(0, s.find(" "));
      b = s.substr(s.find(" "));
      Schmoo *s = new Schmoo(atof(a.c_str()), atof(b.c_str()));
      list.insertFront(s);
    }
    else if ((index = s.find("throw mud ")) != 0) {
      s = s.substr(10);
      a = s.substr(0, s.find(" "));
      b = s.substr(s.find(" "));
      list.throwMudAt(atof(a.c_str()), atof(b.c_str()));
    }
    else if ((index = s.find("remove schmoo ")) != 0) {
    }
  }
  list.printAll();
}
