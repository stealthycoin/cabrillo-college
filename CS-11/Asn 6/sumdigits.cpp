/*
 *  sumdigits.cpp
 *  
 *
 *  Created by John Carlyle on 2/27/09.
 *
 */


#include <iostream>
using namespace std;

int main() {
    cout << "Enter a positive integer: ";
    int input = 0;
    cin >> input;

    cout << "The sum of the digits ";
    int sum = 0;
    while (input != 0) {
        int digit = input % 10;
        sum += digit;
        input /= 10;
        cout << digit << " ";
    }

    return 0;
}