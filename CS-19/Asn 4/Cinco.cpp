/**
 * John Carlyle
 * jcarlyle
 * john.w.carlyle@gmail.com
 * Cinco.cpp
 * Assignment #4 Cinco
 * Manages the game and input/output
 * Code Status: Working/Tested
 */

#include <iostream>
#include <algorithm>
#include "Cinco.h"

Cinco::Cinco(){ 
	secret = new char[6];
	cheated=false; 
	numguesses=0; 
	dict = new Dictionary((char*)"words5.txt");
}

int Cinco::countMatchingLetters(char *a, char *b) {
	int matchingLetters = 0;
	
	for (int i = 0 ; i < 5 ; i++) {
		for (int j = 0 ; j < 5 ; j++) {
			if (a[i] == b[j]) {
				matchingLetters++;
				j = 5;
			}
		}
	}
	
	return matchingLetters;
}

int Cinco::countInPlaceLetters(char *a, char *b)	{
	int inplace = 0;
	for (int i = 0 ; i < 5 ; i++) {
		if (a[i] == b[i]) {
			inplace++;
		}
	}
	return inplace;
}

void Cinco::ConsoleUI() {
	bool running = true;
	char *guess = new char[256];
	secret = dict->getLegalSecretWord();
	
	std::cout << "CS19 2011: Cinco!\nby John Carlyle\nI'm thinking of a 5 letter word...\n";
	
	do {
		numguesses++;
		std::cout << "Your guess? ";
		std::cin.getline(guess, 256);
		
		for (int i = 0 ; i < 5; i++) {
			guess[i] = tolower(guess[i]);
		}
		
		if (strncmp(guess, "xxxxx", 5) == 0) {
			std::cout << "Secret Word is: " << secret << std::endl;
			cheated = true;
		}
		else if (!dict->validWord(guess)) {
			std::cout << "I don't know that word.\n";
			numguesses--;
		}
		else if (strcmp(guess, secret) == 0) {
			running = false;
		}
		else{
			std::cout << "Matching: " << countMatchingLetters(secret, guess) << "\n";
			std::cout << "In-Place: " << countInPlaceLetters(secret, guess) << "\n";
		}
	} while (running);
	std::cout << "Correct! You got it in " << numguesses << " guesses";
	if (cheated) {
		std::cout << ", but only by cheating"; 
	}
	std::cout << ".\n";
	delete [] guess;
}
