// This program will read in the quantity of a particular item and its price.
// It will then print out the total price.
// The input will come from the keyboard and the output will go to
// the screen.

// Yisak Worku

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int quantity;    // contains the amount of items purchased
    float itemPrice; // contains the price of each item
    float totalBill; // contains the total bill.

    cout << setprecision(2) << fixed << showpoint;              // formatted output
    
    cout << "Please input the number of items bought." << endl; // prompt for number of items
    cin >> quantity;                                            // number of items input
    
    cout << "Please input the price each item." << endl;        // prompt for price
    cin >> itemPrice;                                           // price input
    
    totalBill = quantity * itemPrice;                           // calculate bill
    
    cout << "The total bill is $" << totalBill << endl;         // output the bill

    return 0;
}