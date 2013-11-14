#include <iostream>
using namespace std;

int main() {
    string name;
    double price = 0;

    cout << "Enter the product name: ";
    getline(cin, name);
    cout << "Price of the " << name << ": ";
    cin >> price;

    cout.setf(ios::fixed);     // fixed notation, not scientific
    cout.setf(ios::showpoint); // show decimal point
    cout.precision(2);         // show 2 decimal places
    
    const int PERCENT = 100;
    double taxRate = 0;
    cout << "Enter sales tax rate (%): ";
    cin >> taxRate;
    double tax = price * taxRate / PERCENT;
    price += tax;
    
    int dollars = (int) price;
    cout << "In whole dollars: $" << dollars << endl;

    return 0;
}