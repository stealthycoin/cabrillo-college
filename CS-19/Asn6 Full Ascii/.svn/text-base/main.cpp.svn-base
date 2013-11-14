#include <iostream>
#include "Solitaire.h"

using namespace std;


int main(int argc, char **argv) {
	//validate input
	bool delFilename = false;
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
		delFilename = true;
	}
	
	Solitaire *s = new Solitaire(filename);
	
	//encrypt or decrypt
	char *cryptType = new char[8];
	if (strncmp(action,"e",1) == 0) strcpy(cryptType, "encrpyt");
	else cryptType = strcpy(cryptType, "decrypt");
	
	cout << "Enter a message to be " << cryptType << "ed\n";
	char *message = new char[1024];
	cin.getline(message, 1024);
	
	if (strncmp(cryptType,"e",1)==0) {
		//strip out non printable characters
		int len = strlen(message);
		int j = 0;
		for (int i = 0 ; i < len ; i++) {
			if (message[i] >= 32 && message[i] <= 126) {
				message[j] = message[i];
				j++;
			}
		}
		
		/*//put Xs on the end
		int numX = 5 - (j % 5);
		for (int i = 0 ; i < numX ; i++) {
			message[j] = 'X';
			j++;
		}*/
		message[j] = '\0';
		cout << "Plaintext message is: " << message << endl;
		s->encrypt(message);
	}
	else {
		s->decrypt(message);
	}
	cout << "The " << cryptType << "ed message is: " << message << endl;

	//cleanup
	delete [] cryptType;
	if (delFilename) delete [] filename;
	delete s;
	delete [] message;
	
	
	return 0;
}
