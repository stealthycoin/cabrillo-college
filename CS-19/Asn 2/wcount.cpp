/**
 * John Carlyle
 * jcarlyle
 * john.w.carlyle@gmail.com
 * Solitaire.cpp
 * Assignment #2 WordScramble.cpp
 * Scarables up words
 * Code Status: Working/Tested
 */

#import <iostream>
#import <sstream>

using namespace std;

//simple unsorted array search
int indexOf(string words[], int wc, string word) {
	for (int i = 0 ; i < wc ; i++) {
		if (words[i] == word)
			return i;
	}
	return -1;
}

//attempts to insert a word into the word list
void insertWord(string words[], int& wc, string word, int lens[]) {
	//if its empty ignore it
	if (word.length() == 0) return;
	
	//remove leading and trailing non-letter characters
	if (word[0] < 'a' || word[0] > 'z') {
		word = word.substr(1);
	}
	if (word[word.length()-1] < 'a' || word[word.length()-1] > 'z') {
		word = word.substr(0,word.length()-1);
	}
	
	//if we already have that word increment the counter
	//if not add it to the list.
	int index = indexOf(words, wc, word);
	if (index == -1) {
		lens[wc] = 1;
		words[wc] = word;
		wc++;
	}
	else {
		lens[index]++;
	}
}

//swap two words and their counts
void swap(string words[], int lens[], int i, int j) {
	string t = words[i];
	words[i] = words[j];
	words[j] = t;
	
	int k = lens[i];
	lens[i] = lens[j];
	lens[j] = k;
}

//partition of quick sort
int partition(string words[], int lens[], int p, int r) {
	string x = words[r];
	int i = p - 1;
	for (int j = p ; j < r ; j++) {
		if (words[j] < x) {
			i++;
			swap(words, lens, i, j);
		}
	}
	swap(words, lens, i+1, r);
	return i+1;
}

//quick sort
void qsort(string words[], int lens[], int p, int r) {
	if (p < r) {
		int q = partition(words, lens, p, r);
		qsort(words, lens, p, q-1);
		qsort(words, lens, q+1, r);
	}
}

//calls quick sort
void sort(string words[], int lens[], int wc) {
	qsort(words, lens, 0, wc - 1);
}

int main() {
	string words[5000]; 
	int lens[5000] = {0};
	int wc = 0;
	
	char ch;
	int i;
	stringstream word;
	//read all characters 1 at a time (inefficient)
	while (cin.get(ch)) {
		i = (int)ch;
		if (i == 32 || i == (int)'\n' or i == (int)'\t') {
			//Space or newline signifies end of word
			insertWord(words, wc, word.str(), lens);
			word.str("");
		}
		else if (i >= 65 && i <= 90) {
			//Upper case character
			word << (char)(ch + 32);
		}
		else {//(i >= 97 && i <= 122) {
			//Some other symbol
			word << ch;
		}
	}
	//last word
	insertWord(words, wc, word.str(), lens);
	
	//use custom sort
	sort(words, lens, wc);
	
	//print results
	for (int i = 0 ; i < wc ; i++) {
		cout << words[i] << " " << lens[i] << endl;
	}
	
	return 0;
}