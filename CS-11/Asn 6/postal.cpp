/*
 *  postal.cpp
 *  
 *
 *  Created by John Carlyle on 3/4/09.
 *
 */


#include <iostream>
#include <cmath>

using namespace std;

string intToPostalCode(int postalDigit);
bool isValidZip(int zip);
int getLastDigit(int zip);
int shaveOffLastDigit(int zip);
int checkDigit(int zip);


/**
    Main method, lancuhes the program.
    
    @return exit code of program
 */
int main()  {
    bool running = true;
    double zip;
    
    while (running) {
        cout << "Enter zip code to convert: ";
        cin >> zip;
        if (isValidZip(zip)) {
            int checkedDigit = checkDigit(zip);
            string postalCode;
            for (int i = 0 ; i < 5 ; i++)   {
                postalCode = intToPostalCode(getLastDigit(zip)) + postalCode;
                zip = shaveOffLastDigit(zip);
            }
            postalCode = "|" + postalCode + intToPostalCode(checkedDigit)
                + "|\n";
            cout << postalCode;
        }
        else {
            if (zip == 0) {
                running = false;
            }
            else {
                cout << "Invalid zip code." << endl;
            }
        }
    }
    cout << "Goodbye!" << endl;
    
    return 0;
}

/**
    Calculates the check digit of the zip cide
 
    @param zip : zip code to find check digit of
    @return smallest number to make the sum of zip code digits a multiple of 10
 */
int checkDigit(int zip) {
    int tot = 0;
    for (int i = 0 ; i < 5 ; i++) {
        tot += getLastDigit(zip);
        zip = shaveOffLastDigit(zip);
    }
    int nearestTen = getLastDigit(tot);
    nearestTen = min(nearestTen, 10 - nearestTen);
    
    return nearestTen;
}

/**
    Changes a digit of a zip code into barcode format
 
    @param postalDigit : digit to get bar code equivilent of.
    @return postal code of postalDigit
 */
string intToPostalCode(int postalDigit) {
    if (postalDigit == 0) {
        return "||,,,";
    }
    if (postalDigit == 1) {
        return ",,,||";
    }
    if (postalDigit == 2) {
        return ",,|,|";
    }
    if (postalDigit == 3) {
        return ",,||,";
    }
    if (postalDigit == 4) {
        return ",|,,|";
    }
    if (postalDigit == 5) {
        return ",|,|,";
    }
    if (postalDigit == 6) {
        return ",||,,";
    }
    if (postalDigit == 7) {
        return "|,,,|";
    }
    if (postalDigit == 8) {
        return "|,,|,";
    }
    if (postalDigit == 9) {
        return "|,|,,";
    }
    return "";
}

/**
    Finds if a number is a zip code
 
    @param number to determine zip code status of
    @return if zip code is valid
 */
bool isValidZip(int zip)    {
    if (zip >= 10000 && zip <= 99999) return true;
    return false;
}


/**
    Returns last digit of zip code
 
    @param zip : code to get last digit from
    @return last digit from zip
 */
int getLastDigit(int zip)   {
    return zip % 10;
}

/**
    Removes last digit from a number
 
    @param zip : zip code to remove last digit from.
    @return zip without its last digit
 */
int shaveOffLastDigit(int zip)  {
    return zip / 10;
}
