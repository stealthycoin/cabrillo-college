/**
    CS-11 Asn 2
    carcost.cpp
    Purpose: Calculates the cost and carbon emmitted when
    travelling 100 miles in a car.

    @author John Carlyle
    @version 1.0 02/23/09
*/

#include <iostream>
using namespace std;

int main() {
    float MPG;
    float galCost;
    cout << "Please enter the following data\n";
    cout << "The fuel efficiency of the car in MPG\n> ";
    cin >> MPG;
    cout << "The cost of a gallon of gas in dollars\n> ";
    cin >> galCost;
    
    float gallons = 100 / MPG;
    float cost = gallons * galCost;
    float pollution = gallons * 20;
    
    cout << "The cost of traveling 100 miles is: $" << cost << "\n";
    cout << "The carbon emitted by traveling 100 miles is: " 
    << pollution << " pounds\n"; 
    
    return 0;
}
