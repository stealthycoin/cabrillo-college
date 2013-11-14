#include <iostream>
using namespace std;

class Product {
public:
    Product();
    Product(string newName, double newPrice);
    string getName() const;
    double getPrice() const;
    void setName(string newName);
    void setPrice(double newPrice);
    void print() const;
private:
    string name;
    double price;
};

Product::Product() {
    name = "none";
    price = 0.0;
}

Product::Product(string newName, double newPrice) {
    setName(newName);
    setPrice(newPrice);
}

string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

void Product::setName(string newName) {
    name = newName;
}

void Product::setPrice(double newPrice) {
    if (newPrice > 0.0) {
        price = newPrice;
    } else {
        cout << "Error: negative price!\n"
             << "Setting price to 0.\n";
        price = 0.0;
    }
}

void Product::print() const {
    cout <<  name << " @ " << price << endl;
}
