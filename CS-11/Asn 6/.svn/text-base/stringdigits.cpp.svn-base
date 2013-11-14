/*
 *  stringdigits.cpp
 *  
 *
 *  Created by John Carlyle on 3/24/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string str;
    cout << "Enter an integer number: ";
    cin >> str;
    
    cout << "The number of characters is: " << str.length() << endl;
    int sum = 0;
    int num = 0;
    for (unsigned i = 0 ; i < str.length(); i++) {
        char c = str[i];
        int digit = c - 48;
        cout << "Digit: " << digit << endl;
        sum += digit;
        int exp = str.length() - (int)i - 1;
        num = num + (int) (digit * pow(10.0, exp));
    }
    cout << "The sum of the digits is: " << sum << endl;
    cout << "The number is: " << num << endl;
    return 0;
}