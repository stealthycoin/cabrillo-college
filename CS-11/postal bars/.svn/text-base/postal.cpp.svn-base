/*
 *  postal.cpp
 *  CS-11 ASN 6
 *  Purpose: Generates postal codes from zip code
 * 
 *  @author John Carlyle & Michelle Giovannari
 *  @version 1.0 3/24/09 
 */

#include <iostream>

using namespace std;

const string codes[] = {"||,,,", ",,,||", ",,|,|", ",,||,", ",|,,|", ",|,|,", ",||,,", "|,,,|", "|,,|,", "|,|,,"};


/**
 Encodes a single digit of a POSTNET "A" bar code.
 
 @param digit the single integer digit to encode.
 @return a bar code of the digit using "|" as the long
 bar and "," as the half bar.
 */
string encode(int digit){
    return codes[digit];
}


/**
 Creates a POSTNET "A" bar code for a ZIP code.
 
 @param zip the code to convert to a barcode.
 @return a bar code of the zip using "|" as the long
 bar and "," as the half bar.
 */
string barcode(int zip) {
    string finalCode = "|";
    
    int input = zip;
    int sum = 0;
    while (input != 0)    {
        int lastDigit = input % 10;
        sum += lastDigit;
        input /= 10;
    }
    
    int checkDigit = sum % 10;
    checkDigit = 10 - checkDigit;
    string stringDigit = encode(checkDigit);
    
    finalCode = stringDigit +finalCode;
    
    for (int i = 0 ; i < 5 ; i++) {
        int digit = zip % 10;
        string code = encode(digit);
        finalCode = code + finalCode;
        zip /= 10;
    }
    
    finalCode = "|" + finalCode;
    
    return finalCode;
}


/**
     Starting point for program
     
     @returns error code to OS
 */
int main() {
    string repeat = "y";
    
    while (repeat == "y")   {
        bool more = true;
        int zip;
        do {
            cout << "Enter a zip code to convert: ";
            cin >> zip;
            if (zip == 0) {
                repeat = "n";
                more = false;
            }
            else if (cin.fail() || zip < 10000 || zip > 99999) {
                cout << "Enter a valid zip code, please." << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            else {
                more = false;
            }
        } while (more);
        
        if (zip != 0) {
            cout << barcode(zip) << endl;
        }
    }
    
    return 0;
}