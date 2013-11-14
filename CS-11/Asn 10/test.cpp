#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    cout << "*";
    cout.width(5);
    cout << 123
    << "*" << 123 << "*" << endl;
    cout << "*" << setw(5) << 123
    << "*" << 123 << "*" <<  endl;
    
    return 0;
}
