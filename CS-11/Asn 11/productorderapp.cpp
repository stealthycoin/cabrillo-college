#include <iostream>
#include <vector>
using namespace std;

#include "productorder.cpp"

// For testing class ProductOrder
int main() {
    vector<ProductOrder> orders;
    string name;
    double price;
    int qty;
    char repeat = 'Y';
    while ('Y' == repeat || 'y' == repeat) {
        cout << "Enter a product name: ";
        cin >> name;
        cout << "Enter the price for a "
             << name << ": ";
        cin >> price;
        cout << "Enter a quantity of "
             << name << ": ";
        cin >> qty;

        ProductOrder po(name, price, qty);
        cout << "\nYou entered:\n";
        po.print();
        orders.push_back(po);

        cout << "\nEnter another product order? ";
        cin >> repeat;
    }

    cout << "\nAll your orders:\n";
    for (unsigned i = 0; i < orders.size(); i++) {
        orders[i].print();
    }

    return 0;
}
