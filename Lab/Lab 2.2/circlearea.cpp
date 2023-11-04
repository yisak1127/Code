// This program will output the circumference and area
// of the circle with a given radius.

// Yisak Worku

#include <iostream>
using namespace std;

const double Pi = 3.14;
const double RADIUS = 5.4;

int main()

{

    float Area;                      // Definition of area of circle
    float Circumference;             // Definition of Circumference
    Circumference = Pi * 2 * RADIUS; // Computes Circumference
    Area = Pi * RADIUS * RADIUS;     // Computes Area

    cout << "The Circumference of the circle is " << Circumference << endl; // The Circumference
    cout << "The area of the circle is " << Area << endl;                   // The area of the circle

    return 0;
}
