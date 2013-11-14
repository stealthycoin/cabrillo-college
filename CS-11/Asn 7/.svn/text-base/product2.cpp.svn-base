#include <iostream>
#include <string>

using namepsace std;

class Product
{
public:
    void read();
    bool is_better_than(Product b) const;
    void print() const;
private:
    string name;
    double price;
    int score;
};

Product::Product()
{
    price = 1;
    score = 0;
}

void Product::read()
{
    cout << "Please enter the model name: ";
    getline(cin, name);
    cout << "Please enter the price: ";
    cin >> price;
    cout << "Please enter the score: ";
    cin >> score;
    string remainder;
    getline(cin, remainder);
}

bool Product::is_beis_better_than(Product b) const
{
    if (b.price == 0) return false;
    if (price == 0) return false;
    return score / price > b.score / b.price;
}

void Product::print() const
{
    cout << name 
        << " Price: " << price
        << " Score: " << score << "\n";
}

int main()
{
    Product best;
    bool more = true;
    while (more)
    {
        Product next;
        next.read();
        if (next.is_better_than(best)) best = next;
        cout << "More data? (y/n)";
        string answer;
        getline(cin, answer);
        if (answer != "y") more = false;
    }
    
    cout << "The best value is ";
    best.print();
    return 0;
}