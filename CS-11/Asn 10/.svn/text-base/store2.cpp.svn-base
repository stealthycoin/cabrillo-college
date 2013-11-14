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
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

const int COL1_WIDTH = 20;
const int COL_WIDTH = COL1_WIDTH/2;

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
     uses cout to print the information about product to the screen.
     */
    void print();
    
    /*
     uses a stringstream to combine all the descriptors of the
     product into one string and then returns it
     
     @return a printable string that describes the product object
     */
    string toString();
    
    /*
        Reads user input from the screen into the Product object.
     */
    void read();
    
    /**
     Loads information about this Product from the file stream.
     
     @param fin An input stream connected to the files with the
     data to load.
     */
    void read(ifstream& fin);
    
    /**
     Writes information about this Product to the file stream.
     
     @param fout An output stream connected to the file in
     which to save the data.
     */
    void write(ofstream& fout);
};

/*
    Displays contents of the product list to the screen.
 
    @param v The list of Products to draw to the screen,
 */
void report(vector<Product>& v);

/*
    Removes a product from the product list.
 
    @param v List to remove product from
    @param i Index of product to remove
 */
void deleteProdcutNumber(vector<Product>& v, int i);

/*
    Sells products
 
    @param v List to sell products from
    @param id Index of product to sell
    @param num Number of the product to sell
 */
void sellProducts(vector<Product>& v, int id, int num);

/*
    Restock a product
 
    @param v List to restock products too
    @param id Index of product to restock
    @param num Number of products to add to stock
*/
void restockProducts(vector<Product>& v, int id, int num);

/*
    I dont remember what ci was supposed to stand for... im really tired
    It checks to see if cin fails and cleans it up if it did.
 */
void ci();

/**
 Loads the Product data from the specified file name and
 returns the data in a vector of Product objects.
 
 @param fileName The name of the file from which to read.
 */
void loadData(vector<Product>& list, string fileName);

/**
 Writes store data to an output file.
 
 @param store The vector of Product objects.
 @param fileName The name of the file to which to write.
 */
void saveData(vector<Product> store, string fileName);

/**
 Writes a report to a file named report.txt.
 
 @param store The vector of Product objects.
 @param fileName The name of the file to which to write.
 */
void writeReport(vector<Product> store, string fileName);

int main () {
    vector<Product> list;
    loadData(list, "products.txt");
    
    bool running = true;
    while (running) {
        int choice;
        cout << "Please choose one of the following operations:\n";
        cout << "0. Exit program\n1. Report inventory\n";
        cout << "2. Add a new product\n3. Delete a product\n";
        cout << "4. Sell a product\n5. Restock a product\n";
        cout << "6. Write store report\n";
        cout << "Choice (0-6): ";
        cin >> choice;
        
        Product p;
        switch (choice) {
            case 0:
                running = false;
                break;
            case 1:
                report(list);
                cout << endl;
                break;
            case 2:
                p.read();
                list.push_back(p);
                break;
            case 3:
                int toDelete;
                do {
                    ci();
                    cout << "Delete which product(0-" << list.size() - 1 
                         << "): ";
                    cin >> toDelete;
                } while (cin.fail() || toDelete < 0 
                                    || toDelete >= (int)list.size());
                deleteProdcutNumber(list, toDelete);
                break;
            case 4:
                int toSell;
                do {
                    ci();
                    cout << "Sell which product(0-" << list.size() - 1 
                            << "): ";
                    cin >> toSell;
                } while (cin.fail() || toSell < 0 
                                    || toSell >= (int)list.size());
                int numToSell;
                do {
                    ci();
                    cout << "Sell how many " << list[toSell].getName() 
                         << "?: ";
                    cin >> numToSell;
                    sellProducts(list, toSell, numToSell);
                } while (cin.fail() || numToSell < 0);
                break;
            case 5:
                int toStock;
                do {
                    ci();
                    cout << "Restock which product(0-" << list.size() - 1
                         << "): ";
                    cin >> toStock;
                } while (cin.fail() || toStock < 0 
                                    || toStock >= (int)list.size());
                
                int numToStock;
                do {
                    ci();
                    cout << "Restock how many " << list[toStock].getName() << ": ";
                    cin >> numToStock;
                    restockProducts(list, toStock, numToStock);
                } while (cin.fail() || numToStock < 0);
                break;
            case 6:
                writeReport(list, "report.txt");
                break;
        }
    }
    
    saveData(list, "products.txt");
    cout << "Goodbye!\n";
    
    return 0;
}

void report(vector<Product>& v)   {
    for ( unsigned i = 0 ; i < v.size() ; i++)   {
        cout << i << ". " << v[i].toString();
    }
}

void deleteProdcutNumber(vector<Product>& v, int i)   {
    for (unsigned j = i + 1; j < v.size() ; j++)  {
        v[j - 1] = v[j];
    }
    v.pop_back();
}

void sellProducts(vector<Product>& v, int id, int num)  {
    if (v[id].getQuantity() > 0) {
        int smallest = min(v[id].getQuantity(), num);
        v[id].setQuantity(v[id].getQuantity() - smallest);
        
        string prodName = v[id].getName();
        if (smallest > 1) prodName = prodName + "s";
        
        cout << "Sold " << smallest << " " << prodName << endl;
    }
    else    {
        cout << "No " << v[id].getName() << "s left to sell, restock first.\n";
    }
}

void restockProducts(vector<Product>& v, int id, int num)    {
    v[id].setQuantity(v[id].getQuantity() + num);
    cout << "Added " << num << " " << v[id].getName() << " to sheleves\n";
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

void Product::print() {
    cout << fixed << setprecision(2);
    cout << setw(COL1_WIDTH) << left << name;
    cout << setw(COL_WIDTH) << left << price;
    cout << setw(COL_WIDTH) << left << quantity;
    cout << setw(COL_WIDTH) << left << getValue();
    cout << endl;
}

string Product::toString() {
    stringstream out;
    out << fixed << setprecision(2);
    out << setw(COL1_WIDTH) << left << name;
    out << setw(COL_WIDTH) << left << price;
    out << setw(COL_WIDTH) << left << quantity;
    out << setw(COL_WIDTH) << left << getValue();
    out << endl;
    return out.str();
}

void Product::read() {
    cout << "Enter the name of the product: ";
    cin >> ws;
    getline(cin, name);
    
    do {
        ci();
        cout << "Enter the price for a " << name << ": ";
        cin >> price;
    } while (cin.fail());
    do {
        ci();
        cout << "Enter the initial invintory: ";
        cin >> quantity;
    } while (cin.fail());

}

void Product::read(ifstream& fin)  {
    string s;
    getline(fin, s);
    name = s;
    getline(fin, s);
    price = strtod(s.c_str(), (char**)NULL);
    getline(fin, s);
    quantity = atoi(s.c_str());
}

void Product::write(ofstream& fout)  {
    fout << name << endl;
    fout << price << endl;
    fout << quantity << endl;
}

void ci()   {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void saveData(vector<Product> store, string fileName)   {
    ofstream fout(fileName.c_str());
    if (fout.fail()) {
        cout << "Output stream failed to connect to " << fileName << endl;
        exit(-1);
    }
    for (unsigned i = 0 ; i < store.size() ; i++)    {
        store.at(i).write(fout);
    }
    fout.close();
}

void loadData(vector<Product>& list, string fileName)   {
    ifstream fin(fileName.c_str());
    if (fin.fail()) {
        cout << "Could not load products, cannot find " << fileName << endl;
        exit(-1);
    }
    while (fin.good())  {
        Product p;
        p.read(fin);
        if (fin.good()) {
            list.push_back(p);
        }
    }
}

void writeReport(vector<Product> store, string fileName)    {
    ofstream fout(fileName.c_str());
    if (fout.fail()) {
        cout << "Output stream failed to connect to " << fileName << endl;
        exit(-1);
    }
    
    fout << "Report for my store:\n";
    fout << fixed << setprecision(2);
    fout << setw(2) << left << "#";
    fout << setw(COL1_WIDTH) << left << "Name";
    fout << setw(COL_WIDTH) << left << "Price";
    fout << setw(COL_WIDTH) << left << "Qty";
    fout << setw(COL_WIDTH) << left << "Value";
    fout << endl;
    
    double totalValue = 0;
    
    for (unsigned i = 0; i < store.size() ; i++)    {
        fout << i + 1 << " " << store.at(i).toString();
        totalValue += store.at(i).getValue();
    }
    
    fout << endl << "Total inventory value: " << totalValue;
    fout.close();
}

