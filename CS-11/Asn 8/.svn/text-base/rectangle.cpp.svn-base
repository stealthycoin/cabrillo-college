#include <iostream>
using namespace std;

class Rectangle {
public:
    Rectangle();
    void read();
    void print();
private:
    int width, length;
public:
};

int main() {
    Rectangle spongeBob;
    
    spongeBob.read();
    spongeBob.print();
    
    return 0;
}

Rectangle::Rectangle() {
    width = 0;
    length = 0;
}

void Rectangle::read()  {
    cout << "Enter the rectangle length: ";
    cin >> length;
    cout << "Enter the width: ";
    cin >> width;
}


void Rectangle::print() {
    cout << length << " x " << width << endl;
}
