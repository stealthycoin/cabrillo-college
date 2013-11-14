#include <fstream>   // for file I/O
#include <iostream>
using namespace std;

void toScreen(ifstream& fin);

int main() {
    string filename, line;
    
    cout << "Enter a file name: ";
    cin >> filename;
    
    ifstream fin;
    fin.open(filename.c_str());
    if (fin.fail()) {
        cout << "Input file failed to open\n";
        exit(-1);
    }
    
    toScreen(fin);
    
    return 0;
}

void toScreen(ifstream& fin)    {
    string temp;
    int i = 1;
    while (getline(fin, temp))  {
        cout << i << ". " << temp << endl; 
        i++;
    }
}