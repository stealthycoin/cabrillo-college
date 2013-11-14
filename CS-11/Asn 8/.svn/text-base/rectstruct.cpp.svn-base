#include <iostream>
using namespace std;

struct Rectangle {
    int width, length;
    
};

// Read structure data from the keyboard
void read(Rectangle& rect);

// Print structure data to the console
void print(Rectangle& rect);

int main() {
    Rectangle rect;
    
    read(rect);
    print(rect);
    
    return 0;
}

void read(Rectangle& rect)  {
    cout << "Enter the rectangle length: ";
    cin >> rect.length;
    cout << "Enter the width: ";
    cin >> rect.width;
}


void print(Rectangle& rect) {
    cout << rect.length << " x " << rect.width << endl;
}