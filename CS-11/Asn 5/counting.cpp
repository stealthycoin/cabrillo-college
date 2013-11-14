/*
 *  counting.cpp
 *  
 *
 *  Created by John Carlyle on 2/27/09.
 *
 */
 
 #include <iostream>
 using namespace std;
 
 int main() {
    int max = 0;
    cout << "This program uses a loop to count\n";
    cout << "Enter the maximum number: ";
    cin >> max;
    
    int sum = 0;
    for (int i = 1; i <= max; i = i + 1) {
        cout << i << endl;
        sum = sum + i;
    }
    cout << "The sum of these numbers is: "
         << sum << endl;
    
    return 0;
 }
