// This program prints "You Pass" if a student's average is
//  60 or higher and prints "You Fail" otherwise

// Yisak worku

#include <iostream>
using namespace std;

int main()
{
    float average; // holds the grade average

    cout << "Input your average" << endl;
    cin >> average;

    if (average > 100)
    {
        cout << "You in" << endl;
    }

    else if (average <= 100 && average >= 90)
    {
        cout << "You got an A" << endl;
    }
    
    else if (average <= 89 && average >= 80)
    {
        cout << "You got an B" << endl;
    }

    else if (average >= 60 && average <= 79)
    {
        cout << "You Pass" << endl;
    }

    else
        cout << "You Fail" << endl;

    return 0;
}