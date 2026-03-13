#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

// COMSC 210 | Lab 20 | Martha Stephanie Villalta
// Changes I need to make:
// 1. Change Default Constructor: Change the null values to a random selection between 3 - 4 legs and prices
// 2. Change Parameter Constructor: Current parameters 1- number of legs. Add 2nd parameter. array of 3 doubles
//    for prices.
// 3. In 3rd Code Block: (line 67). Use default constructors to populate the objects.

using namespace std;
const int SIZE = 3;
const int MIN = 10000, MAX = 99999;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        legs = rand() % 2 + 3; // Code amended for random selection between 3 - 4 legs.
        for (int i = 0; i < SIZE; i++)
            // Need to amend so that it selects random prices.
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / (double)100; 
    }
    Chair(int l, double p[SIZE]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {

    srand(time(0));
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    Chair *livingChair = new Chair(3, prices);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    collection[0].setLegs(4);
    collection[0].setPrices(441.41, 552.52, 663.63);
    collection[1].setLegs(4);
    collection[1].setPrices(484.84, 959.59, 868.68);
    collection[2].setLegs(4);
    collection[2].setPrices(626.26, 515.15, 757.57);
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    return 0;
}