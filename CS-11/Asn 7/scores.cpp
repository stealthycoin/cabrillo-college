/*
 *  scores.cpp
 *  
 *
 *  Created by John Carlyle on 2/28/09.
 *
 */


#include <iostream>
using namespace std;

int main() {
    double sumScores = 0.0, nextScore = 0.0;
    int count = 0;
    
    do {
        count++;
        cout << "Enter score #" << count << ": ";
        cin >> nextScore;
        

        if (nextScore >= 0) {
            sumScores += nextScore;
                
        }
    } while (nextScore >= 0);

    cout << "\nSum of scores: " << sumScores << endl;
    return 0;
}