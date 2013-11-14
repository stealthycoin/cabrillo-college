/**
 CS-11 Asn 7
 gradebook.cpp
 Purpose: caclulates overall grade for the semester.
 
 @author John Carlyle
 @version 1.0
 */
#include <iostream>
using namespace std;

// Avoid magic numbers.
// Change the following constants however you like.
const double WEIGHT_ASN = .40;
const double WEIGHT_MID = .25;
const double WEIGHT_FINAL = .35;

const double MIN_A = .90;
const double MIN_B = .80;
const double MIN_C = .70;
const double MIN_D = .60;

const int NUM_DECIMAL_PLACES = 2;
const double PERCENT_MULTIPLIER = 100;

/**
 Reads the scores from cin using the standard input stream,
 sums the scores and values, and stores the sum of the
 scores and values in the reference parameters.
 
 @param sumScores Sum of all scores entered by the user.
 @param sumValues Sum of all max values entered by the user.
 */
void readScores(int& sumScores, int& sumValues);

/**
 Converts the percentage to a letter grade.
 
 @param percentage The percentage to convert.
 @return The letter grade.
 */
char toLetterGrade(double percentage);

int getInt();

// Application driver
int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(NUM_DECIMAL_PLACES);
    
    int asnValue = 0, asnActual = 0;
    int midValue = 0, midActual = 0;
    int finalValue = 0, finalActual = 0;
    
    cout << "Enter your assignment scores (-1 to exit):\n";
    readScores(asnActual, asnValue);
    cout << "\nEnter your midterm scores (-1 to exit):\n";
    readScores(midActual, midValue);
    cout << "\nEnter your final exam scores (-1 to exit):\n";
    readScores(finalActual, finalValue);
    cout << "\n\n";
    
    double asnAverage = 0;
    double midAverage = 0;
    double finalAverage = 0;
    
    if (asnValue != 0)  {
        asnAverage = (double)asnActual / (double)asnValue;
        asnAverage *= WEIGHT_ASN;
        asnAverage = min(asnAverage, WEIGHT_ASN);
    }
    
    if (midValue != 0)  {
        midAverage = (double)midActual / (double)midValue;
        midAverage *= WEIGHT_MID;
        midAverage = min(midAverage, WEIGHT_MID);
    }
    
    if (finalValue != 0)  {
        finalAverage = (double)finalActual / (double)finalValue;
        finalAverage *= WEIGHT_FINAL;
        finalAverage = min(finalAverage, WEIGHT_FINAL);
    }
    
    double sum = asnAverage + midAverage + finalAverage;
    double sumWithoutFinal = asnAverage + midAverage + WEIGHT_FINAL;
    
    
    cout << "Assignment Area" << endl;
    cout << "Sum of scores: " << asnActual << endl;
    cout << "Sum of values: " << asnValue << endl;
    cout << "Assignment weight: " << WEIGHT_ASN << endl;
    cout << "Assignment weigted average: " << asnAverage << endl;
    
    cout << "Midterm Area" << endl;
    cout << "Sum of scores: " << midActual << endl;
    cout << "Sum of values: " << midValue << endl;
    cout << "Midterm weight: " << WEIGHT_MID << endl;
    cout << "Midterm weigted average: " << midAverage << endl;
    
    cout << "Final Area" << endl;
    cout << "Sum of scores: " << finalActual << endl;
    cout << "Sum of values: " << finalValue << endl;
    cout << "Final weight: " << WEIGHT_FINAL << endl;
    cout << "Final weigted average: " << finalAverage << endl << endl;
    
    cout << "Sum of weighted averages: " << sum << endl;
    cout << "Letter grade to date: " << toLetterGrade(sum) << endl;
    cout << "Sum of weighted averages without final: " << sumWithoutFinal << endl;
    cout << "Letter grade to date: " << toLetterGrade(sumWithoutFinal) << endl;
    
    
    cout << endl << endl;
    cout << "Score needed for A on final: " << (MIN_A - sum) / WEIGHT_FINAL * PERCENT_MULTIPLIER << "%" << endl;
    cout << "Score needed for B on final: " << (MIN_B - sum) / WEIGHT_FINAL * PERCENT_MULTIPLIER << "%" << endl;
    cout << "Score needed for C on final: " << (MIN_C - sum) / WEIGHT_FINAL * PERCENT_MULTIPLIER << "%" << endl;
    
    
    return 0;
}


// Read the scores from standard input and sums the scores and values.
void readScores(int& sumScores, int& sumValues) {
    sumScores = 0;
    sumValues = 0;
    int i = 1;
    do {
        int newScore;
        int newValue;
        
        cout << "Score " << i << ": ";
        newScore = getInt();
        
        if (newScore < 0) return;
        
        cout << "Value of score " << i << ": ";
        newValue = getInt();
        
        sumScores += newScore;
        sumValues += newValue;
        
        i++;
    } while (true);
}

// Converts the percentage to a letter grade.
char toLetterGrade(double percentage) {
    if (percentage >= MIN_A) return 'A';
    else if (percentage >= MIN_B) return 'B';
    else if (percentage >= MIN_C) return 'C';
    else if (percentage >= MIN_D) return 'D';
    else return 'F';
}


int getInt()    {
    int input = 0;
    bool error = true;
    while (error) {
        cin >> input;
        if (cin.fail()) {
            cout << "Error: Please enter a number: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        else {
            error = false;
        }
    }
    
    return input;
}
