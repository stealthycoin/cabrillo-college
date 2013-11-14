/**
 * John Carlyle
 * jcarlyle
 * john.w.carlyle@gmail.com
 * Dictionary.cpp
 * Assignment #4 Cinco
 * Loads a dictionary file and provides functions for accessing it.
 * Code Status: Working/Tested
 */

#import <iostream>
#import <fstream>
#import "Dictionary.h"


Dictionary::Dictionary(char *file) {
	alphabet = new bool[26];
	std::ifstream fin(file);
	if (fin.fail()) {
		std::cerr << "Could not find file\n";
	}
	
	fin >> numwords;
	fin.ignore(1, '\n');
	
	words = new char*[numwords];
	
	for (int i = 0 ; i < numwords ; i++) {
		words[i] = new char[6];
		fin.getline(words[i], 6);
	}
	
	fin.close();
}


bool Dictionary::validWord(char *word) {
	int first = 0;
	int last = numwords-1;
	while (first <= last) {
		int mid = (first + last) / 2;  
		if (strcmp(word, words[mid]) > 0) 
			first = mid + 1;  
		else if (strcmp(word, words[mid]) < 0) 
			last = mid - 1; 
		else
			return true;     
	}
	return false;
}


char *Dictionary::getLegalSecretWord() {
	int n;
	do {
		n = rand() % numwords;
	} while (!testSecretWord(n));
	return words[n];
}


bool Dictionary::testSecretWord(int n) {
	
	for (int i = 0 ; i < 26 ; i++) {
		alphabet[i] = false;
	}
	
	char *word = words[n];
	for (int i = 0 ; i < 5 ; i++) {
		if (alphabet[word[i]-97] == false)
			alphabet[word[i]-97] = true;
		else 
			return false;
	}
	return true;
}


Dictionary::~Dictionary() {
	for (int i = 0 ; i < numwords ;i++) {
		delete [] words[i];
	}
	delete [] words;
	delete [] alphabet;
}