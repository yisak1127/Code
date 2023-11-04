// This program will output the perimeter and area
// of the rectangle with a given radius.

// Yisak Worku

#include <iostream>
using namespace std;

const double Length = 8;
const double Width = 3;

int main()

{

    float Area;                             // Definition of area of rectangle
    float perimeter;                        // Definition of perimeter
    perimeter = (Length * 2) + (2 * Width); // Computes perimeter
    Area = Length * Width;                  // Computes Area

    cout << "The area of the rectangle is " << Area << endl;           // The area of the rectangle
    cout << "The perimeter of the rectangle is " << perimeter << endl; // The perimeter

    return 0;
}