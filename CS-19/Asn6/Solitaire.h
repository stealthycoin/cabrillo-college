/**
 * John Carlyle
 * jcarlyle
 * john.w.carlyle@gmail.com
 * Solitaire.h
 * Assignment #6 Solitaire Encryption
 * Header file.
 * Code Status: Working/Tested
 */


#ifndef SOLITAIRE_H
#define SOLITAIRE_H

#include <deque>

class Solitaire  {
public:
	Solitaire(const char *filename);
	~Solitaire() { delete deck; delete deckBuffer; }
	void encrypt(char *);
	void decrypt(char *);
private:
	std::deque<int> *deck;
	std::deque<int> *deckBuffer;
	void reformat(char *);
	int keystream();
};

#endif