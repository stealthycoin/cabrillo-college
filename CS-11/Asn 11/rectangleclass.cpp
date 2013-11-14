#include <iostream>
using namespace std;

class Rectangle {
public:
    Rectangle();
    Rectangle(double newLength, double newWidth);
    void print();
    bool isBiggerThan(Rectangle& rec2);
    double getArea();
private:
    double length;
    double width;
};

Rectangle::Rectangle() {
    length = 0;
    width = 0;
}

Rectangle::Rectangle(double newLength, double newWidth) {
    length = newLength;
    width = newWidth;
}

void Rectangle::print() {
    cout << length << " long x " << width << " wide\n";
}

bool Rectangle::isBiggerThan(Rectangle& rec2)  {
    return (getArea() > rec2.getArea()) ? true : false;
}

double Rectangle::getArea() {
    return length * width;
}