#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	vector<int> cards(28);
	for (int i = 0; i < cards.size(); i++) {
		cards[i] = i+1;
	} 
	
	random_shuffle(cards.begin(), cards.end());
	
	int n;
	for (int i = 0; i < cards.size(); i++) {
		n = cards[i];
		if (n <= 9) cout << "0";
		cout << n << " ";
	}
	
	cout << endl;
}