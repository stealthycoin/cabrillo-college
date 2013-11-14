#include <iostream>
#include <map>

using namespace std;

int main() {
	map<string, string> suits;
	suits["S"] = "Spades";
	suits["C"] = "Clubs";
	suits["H"] = "Hearts";
	suits["D"] = "Diamonds";
	
	map<string, string> values;
	values["J"] = "Jack";
	values["Q"] = "Queen";
	values["K"] = "King";
	values["A"] = "Ace";
	
	cout << "Enter a card: ";
	string input;
	cin >> input;
	
	string value, suit;
	
	if (input.size() == 3) {
		value = "10";
		suit = input.substr(2);
	}
	else{
		value = input.substr(0, 1);
		suit = input.substr(1);
	}
	
	value = values[value];
	
	/*if (value.compare("J") == 0) {
		value = "Jack";
	}
	else if (value.compare("Q") == 0) {
		value = "Queen";
	}
	else if (value.compare("K") == 0) {
		value = "King";
	}
	else if (value.compare("A") == 0) {
		value = "Ace";
	}*/
	
	suit = suits[suit];
	
	/*if (suit.compare("H") == 0) {
		suit = "Hearts";
	}
	else if (suit.compare("S") == 0) {
		suit = "Spades";
	}
	else if (suit.compare("C") == 0) {
		suit = "Clubs";
	}
	else if (suit.compare("D") == 0) {
		suit = "Diamonds";
	}*/
	
	cout << value << " of " << suit << endl;
	
	
	return 0;
}