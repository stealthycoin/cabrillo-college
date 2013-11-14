#ifndef SCHMOO_H
#define SCHMOO_H

#include <ostream>

using std::ostream;

class Schmoo {
  friend ostream& operator<<(ostream &out,Schmoo &s);
 public:
  Schmoo(double ix = 0, double iy = 0) { x = ix; y = iy; }
  double getX() const {return x;}
  double getY() const {return y;}
  void incrementMud() { mud++; }
 private:
  double x, y;
  int mud;
};


#endif
