#include <iostream>
using namespace std;

#include "product.cpp"

class ProductOrder {
public:
    ProductOrder();
    ProductOrder(string name, double price, int qty);
    Product getProduct();
    double getQuantity();
    void setProduct(Product& newProduct);
    void setQuantity(int newQuantity);
    double getTotal();
    void print();
private:
    Product prod;
    int quantity;
};

ProductOrder::ProductOrder() {
    quantity = 0;
}

ProductOrder::ProductOrder(string name, double price,
        int qty) {
    prod = Product(name, price);
    quantity = qty;
}

Product ProductOrder::getProduct() {
    return prod;
}

double ProductOrder::getQuantity() {
    return quantity;
}

void ProductOrder::setProduct(Product& newProduct) {
    prod = newProduct;
}

void ProductOrder::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

double ProductOrder::getTotal() {
    return quantity * prod.getPrice();
}

void ProductOrder::print() {
    cout << "Name: " << prod.getName()
         << "\nPrice: "
         << prod.getPrice()
         << "\nQuantity: " << quantity
         << "\nTotal Amount: "
         << getTotal() << "\n";
}
