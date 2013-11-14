#include <iostream>
#include <algorithm>
#include <fstream>
#include "Solitaire.h"

using namespace std;

Solitaire::Solitaire(const char *filename){
	deck = new vector<int>;
	ifstream fin(filename);
	if (fin.fail()) {
		cerr << "Could not open file " << filename << endl;
		exit(1);
	}
	
	int j;
	for (int i = 0 ; i < 28 ; i++) {
		fin >> j;
		deck->push_back(j);
	}
	
	deckBuffer = new vector<int>(deck->size());
}

void Solitaire::encrypt(char *message){
	char c;
	for (int i = 0 ; i < strlen(message) ; i++) {
		c = message[i] - 31;	//Space=1 !=2......
		c += keystream();		//add keystream
		if (c > 94) c -= 94;	//make sure its within the range
		c += 31;				//back to capital letter
		message[i] = c;			//replace letter in word
	}
}

void Solitaire::decrypt(char *message) {
	char c;
	for (int i = 0 ; i < strlen(message) ; i++) {
		c = message[i] - 31;	//A=1 B=2......
		c -= keystream();		//sub keystream
		if (c < 1) c += 94;		//make sure its within the range
		c += 31;				//back to capital letter
		message[i] = c;			//replace letter in word
	}
}

//seems good
int Solitaire::keystream() {
	vector<int>::iterator it1;
	vector<int>::iterator it2;
	
	//swap 27 with the one after it
	it1 = find(deck->begin(), deck->end(), 27);
	it2 = it1+1;
	if (it2 >= deck->end()) it2 -= deck->size();
	iter_swap(it1, it2);

	//cout << "Swaped 27\n";
	
	//move 28 down by two (two swaps)
	it1 = find(deck->begin(), deck->end(), 28);
	it2 = it1+1;
	if (it2 >= deck->end()) it2 -= deck->size();
	iter_swap(it1, it2);
	it1 = it2;
	it2++;
	if (it2 >= deck->end()) it2 -= deck->size();
	iter_swap(it1, it2);
	
	//cout << "Swapped 28\n";
	
	//triple cut
	it1 = find(deck->begin(), deck->end(), 27);
	it2 = find(deck->begin(), deck->end(), 28);
	
	if (it1 > it2) {
		vector<int>::iterator t = it1;
		it1 = it2;
		it2 = t;
	}
	copy(deck->begin(), it1, copy(it1, it2+1, copy(it2+1, deck->end(), deckBuffer->begin())));
	copy(deckBuffer->begin(), deckBuffer->end(), deck->begin());
	
	//cout << "Triple cut\n";
	
	//get bottom card's value (x) move top x cards to bottom, put card of value x at the bottom
	it1 = deck->begin() + (deck->back() == 28 ? 27 : deck->back());
	if (it1 >= deck->end()) it1 -= deck->size();
	it2 = copy(deck->begin(), it1, deckBuffer->begin());
	it1 = copy (it1, deck->end()-1, deck->begin());
	copy(deckBuffer->begin(), it2, it1);
	
	//cout << "Bottom cut\n";
	
	//get top card's value (x) get the (x+1)th card from the deck (28 = 27)
	it1 = deck->begin() + (deck->front() == 28 ? 27 : deck->front());
	//that is the keystream value unless it is a joker.
	//recursively rpeat till its not a joker.
	if (*it1 == 27 || *it1 == 28) return keystream();
	
	//cout << "Retrieve keystream value: " << *it1 << "\n\n";
	
	return *it1;	
}