#ifndef SOLITAIRE_H
#define SOLITAIRE_H

#include <vector>

class Solitaire  {
public:
	Solitaire(const char *filename);
	~Solitaire() { delete deck; delete deckBuffer; }
	void encrypt(char *);
	void decrypt(char *);
private:
	std::vector<int> *deck;
	std::vector<int> *deckBuffer;
	int keystream();
};


#endif