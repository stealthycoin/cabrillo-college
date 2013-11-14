/*
 *  Product.cpp
 *  
 *
 *  Created by John Carlyle on 4/21/09.
 *
 */
#include <iostream>
#include <string>
#include <iomanip> 
#include <sstream>

using namespace std;

const int AMT_ANTRHAX = 25;
const double PRICE_ANTRHAX = 25.99;
const int AMT_TERMITES = 50;
const double PRICE_TERMITES = 29.99;
const int AMT_BALLOONS = 4000;
const double PRICE_BALLOONS = 2.99;

const int COL1_WIDTH = 16;
const int COL_WIDTH = 10;

class Product   {
private:
    string name;
    double price;
    int quantity;
public:
    /*
     Default constructor, inits all varaibles to 0 and strings to ""
     */
    Product();
    /*
     Constructor that initiallises all values to user-specified values
     */
    Product(string, double, int);
    
    /*
     Accessor function that gets the name of the product
     
     @return a string representing the name of the product
     */
    string getName  () const;
    /*
     Accessor function that gets price of product
     
     @return the price
     */
    double getPrice () const;
    /*
     Accessor function that gets quantity of products
     
     @return the number of products of this type
     */
    int getQuantity () const;
    /*
     Accessor function that gets value of object
     
     @return quanity times price
     */
    double getValue () const;
    
    /*
     sets the name to whatever the string parameter is
     */
    void setName    (string);
    /*
     sets the price to whatever the double paramater is
     */
    void setPrice   (double);
    /*
     sets the quantity to whatever the int parameter is
     */
    void setQuantity(int);   
    
    /*
     uses a stringstream to combine all the descriptors of the
     product into one string and then returns it
     
     @return a printable string that describes the product object
     */
    string print();
    
    void read();
};

int main () {
    vector<Product> list;
    Product p1 = Product("Anthrax", PRICE_ANTRHAX, AMT_ANTRHAX);    
    Product p2 = Product("Termites", PRICE_TERMITES, AMT_TERMITES);  
    Product p3 = Product();
    p3.setName("Balloons");
    p3.setPrice(PRICE_BALLOONS);
    p3.setQuantity(AMT_BALLOONS);
    
    list.push_back(p1);
    list.push_back(p2);
    list.push_back(p3);
    
    bool running = true;
    while (running) {
        int choice;
        cout << "Please choose one of the following operations:\n
        0. Exit program\n
        1. Report inventory\n
        2. Add a new product\n
        3. Delete a product\n
        4. Sell a product\n
        5. Restock a product\n
        Choice (0-5): ";
        cin >> choice;
        
        switch (choice) {
            case 0:
                running = false;
                break;
            case 1:
                report(list);
                break;
        }
    }
    
    cout << "Goodbye!\n";
    
    return 0;
}

void report(vector<Prodcut>& v)   {
    for ( int i = 0 ; i < v.size() l i++)   {
        v.print();
    }
}

Product::Product() {
    name = "";
    price = 0.0;
    quantity = 0;
}

Product::Product(string n, double p, int q) {
    name = n;
    price = p;
    quantity = q;
}

void Product::setName(string n) {
    name = n;
}

void Product::setPrice(double p)    {
    price = p;
}

void Product::setQuantity(int q) {
    quantity = q;
}

string Product::getName  () const   {
    return name;
}

double Product::getPrice () const   {
    return price;
}

int Product::getQuantity () const   {
    return quantity;
}

double Product::getValue () const   {
    return price * quantity;
}

string Product::print() {
    stringstream out;
    out << fixed << setprecision(2);
    out << setw(COL1_WIDTH) << left << name;
    out << setw(COL_WIDTH) << left << price;
    out << setw(COL_WIDTH) << left << quantity;
    out << setw(COL_WIDTH) << left << getValue();
    out << endl;
    return out.str();
}

void read() {
    string name;
    double price;
    int qty;
    cout << "Enter the name of the product: ";
    cin >> ws;
    readLine(cin, name);
    
    cout << "Enter the price for a " << name << ": ";
    cin >> price;
    
    cout << "Enter the initial invintory: ";
    cin >> qty;
}

