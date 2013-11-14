#include <iostream>
using namespace std;

int main() {
    string firstName, lastName, fullName;
    cout << "First name: ";
    cin >> firstName;
    cout << "Last name: ";
    cin >> lastName;
    
    fullName = firstName + " " + lastName;
    cout << "Full name: " << fullName << "!\n";
    cout << "Welcome \"" << fullName << "!\"\n";
    
    string message;
    cout << "Enter your message: ";
    cin >> ws;
    getline(cin, message);
    cout << "Your message: \"" << message << "\"\n";
    
    return 0;
}