/*
 *  dice.cpp
 *  
 *
 *  Created by John Carlyle on 2/27/09.
 *
 */


#include <iostream>
using namespace std;

int main() {
    srand(time(0));
    int die1 = rand() % 6;
    int die2 = rand() % 6;
    cout << "You rolled a " << die1
         << " and a " << die2 << endl;

    return 0;
}