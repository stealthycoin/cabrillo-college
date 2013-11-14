/**
 * John Carlyle
 * jcarlyle
 * john.w.carlyle@gmail.com
 * Cinco.h
 * Assignment #4 Cinco
 * Header file
 * Code Status: Working/Tested
 */

#ifndef CINCO_H
#define CINCO_H

#include "Dictionary.h"

class Cinco{
public:
	Cinco();
	~Cinco() {  delete dict; }
	void start(){ ConsoleUI(); } // public interface to play game of cinco
private:
	int countMatchingLetters(char *, char *); // find common letters in any order
	int countInPlaceLetters(char *, char *);  // find common letters in place
	void ConsoleUI();  // play the game with text/keybd/screen UI
	Dictionary *dict; // legal words for the game
	int numguesses; // track number of guesses used
	bool cheated; // flag set to true if cheat code is used
	char *secret; // word to guess
};

#endif