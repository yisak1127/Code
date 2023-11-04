// This program demonstrates the use of dynamic variables

// Yisak Worku

#include <iostream>
using namespace std;
const int MAXNAME = 10;

int main()
{
    int pos;
    char *name = nullptr;
    int *one = nullptr;
    int *two = nullptr;
    int *three = nullptr;
    int result;

    // Fill in code to allocate the integer variable one here
    one = new int;
    // Fill in code to allocate the integer variable two here
    two = new int;
    // Fill in code to allocate the integer variable three here
    three = new int;
    // Fill in code to allocate the character array pointed to by name
    name = new char[10];

    cout << "Enter your last name with exactly 10 characters." << endl;
    cout << "If your name has < 10 characters, repeat last letter. " << endl
         << "Blanks at the end do not count." << endl;
    for (pos = 0; pos < MAXNAME; pos++)
        cin >> *(name + pos); // Fill in code to read a character into the name array
                              // WITHOUT USING a bracketed subscript
    cout << "Hi ";

    for (pos = 0; pos < MAXNAME; pos++)
        cout << *(name + pos); // Fill in code to a print a character from the name array
                               // WITHOUT USING a bracketed subscript
    cout << endl
         << "Enter three integer numbers separated by blanks" << endl;

    cin >> *one >> *two >> *three; // Fill in code to input three numbers and store them in the
                                   // dynamic variables pointed to by pointers one, two, and three.
                                   // You are working only with pointer variables
                                   // echo print
    cout << "The three numbers are " << endl;
    cout << *one << endl << *two << endl << *three << endl; // Fill in code to output those numbers
    result = *one + *two + *three;  // Fill in code to calculate the sum of the three numbers

    cout << "The sum of the three values is " << result << endl;
    delete one, two, three; // Fill in code to deallocate one, two, three and name
    delete[] name;

    return 0;
}