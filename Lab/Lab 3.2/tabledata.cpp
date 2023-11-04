// This program will bring in two prices and two quantities of items
// from the keyboard and print those numbers in a formatted chart.

// Yisak Worku

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float price1, price2;     // The price of 2 items
    int quantity1, quantity2; // The quantity of 2 items

    cout << setprecision(2) << fixed << showpoint << endl; // formatted output
    cout << "Please input the price and quantity of the first item."
         << endl;               // prompt for price and quantity of the first item
    cin >> price1 >> quantity1; // item one input

    cout << "Please input the price and quantity of the second item."
         << endl;               // prompt for priceand quantity of the second item
    cin >> price2 >> quantity2; // item 2 input

    cout << setw(15) << "PRICE" << setw(12) << "QUANTITY\n\n";  // formatted output
    cout << setw(15) << price1 << setw(7) << quantity1 << endl; // output item one price and quantity
    cout << setw(15) << price2 << setw(7) << quantity2 << endl; // output item two price and quantity

    return 0;
}