/**
 * John Carlyle
 * jcarlyle
 * john.w.carlyle@gmail.com
 * Dictionary.h
 * Assignment #4 Cinco
 * Header file
 * Code Status: Working/Tested
 */

#ifndef DICT_H
#define DICT_H

class Dictionary{
public:
	Dictionary(char *filename="words5.txt"); // arg: filename of input words text file
	~Dictionary();
	bool validWord(char *word); // check if word is in Dictionary 
	char *getLegalSecretWord(); // return a random word (w/out repeated letters)
private:
	bool testSecretWord(int n); // test if word n has only unique letters
	char **words; // char arrays of words {size: numwords by 5+1}
	int numwords; // number of words in the dictionary
	bool *alphabet; //for testing if a word has multiple of the same letter 
};


#endif