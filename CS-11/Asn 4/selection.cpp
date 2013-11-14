#include <iostream>
using namespace std;

int main() {
    int guess = 0;
    cout << "I'm thinking of a number between"
         << " 1 and 10.\nCan you guess it?\n\n"
         << "Enter your guess: ";
    cin >> guess;
    cout << "You entered: " << guess << endl;

    const int ANSWER = 7;
    if (guess < 1) {
        cout << "Error: guess must be >= 1\n";
        return 1;
    }
    if (guess < 1) {
        cout << "Error: guess must be >= 1\n";
    } else if (guess > 10) {
        cout << "Error: guess must be <= 10\n";
    } else if (guess != ANSWER) {
        cout << "Sorry, that is not correct.\n";
    } else {
        cout << "*** Correct! ***\n";
    }

    return 0;
}