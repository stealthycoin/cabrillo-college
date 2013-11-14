/**
 * John Carlyle
 * jcarlyle
 * john.w.carlyle@gmail.com
 * main.cpp
 * Assignment #6 Solitaire Encryption
 * Takes input and handles arguments
 * Code Status: Working/Tested
 */


#include <iostream>
#include "Solitaire.h"

using namespace std;


int main(int argc, char **argv) {
	//validate input
	bool error = false;
	char *action;
	if (argc == 2 || argc == 3) {
		action = argv[1];
		if (strlen(action) != 1 || strncmp(action,"e",1) && strncmp(action,"d",1)) {
			error = true;
		}
	}
	else {
		error = true;
	}
	if (error) {
		cerr << "Usage:\n./p6 e deck.txt for encryption\n./p6 d deck.txt for decryption\n";
		exit(1);
	}
	
	
	//get deckfile name
	char *filename;
	if (argc == 3)
		filename = argv[2];
	else {
		cout << "Please enter the filename for the deck file to use: ";
		filename = new char[256];
		cin.getline(filename, 256);
	}
	
	//create soiltaire instance with the filename
	Solitaire *s = new Solitaire(filename);
	
	//encrypt or decrypt
	const char *cryptType = new char[7];
	if (strncmp(action,"e",1) == 0) cryptType = "encrpyt";
	else cryptType = "decrypt";
	
	cout << "Enter a message to be " << cryptType << "ed (non letters ignored)\n";
	char *message = new char[1024];
	cin.getline(message, 1024);
	
	if (strncmp(cryptType,"e",1)==0) {
		s->encrypt(message);
	}
	else {
		s->decrypt(message);
	}
	cout << "The " << cryptType << "ed message is: " << message << endl;

	return 0;
}
