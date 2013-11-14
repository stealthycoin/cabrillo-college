#include <iostream>

using namespace std;

int main() {
	
	cout << "Size of square: ";
	int n;
	cin >> n;
	
	//square nxn
	//i is the row
	for (int i = 0; i < n; i++) {
		//print out n starts for the first square
		for (int j = 0; j < n; j++) {
			cout << "*";
		}
		
		//print out a space for the divide
		cout << " ";
		//if first or last row print out n stars
		if (i == 0 || i == n-1) {
			for (int j = 0; j < n; j++) {
				cout << "*";
			}
		}
		//if its a middle row 
		else {
			//print a star
			cout << "*";
			//followed by n-2 spaces
			for (int j = 0; j < n-2; j++) {
				cout << " ";
			}
			//and one more star
			cout << "*";
		}

		//print endline character between rows
		cout << endl;
	}
	
	return 0;
}