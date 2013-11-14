#include "Schmoo.h"

ostream& operator<<(ostream &out,Schmoo &s) {
  out << "Schmoo at (" << s.x << ", " << s.y << ") was hit with mud " << s.mud << " time";
  if (s.mud == 1)
    out << "s.\n";
  else 
    out << ".\n";
  return out;
}
