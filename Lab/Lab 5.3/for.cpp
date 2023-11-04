// This program has the user input a number n and then finds the
// mean of the first n positive integers

// Yisak Worku

#include <iostream>
using namespace std;

int main()
{
    int endValue;   // value is some positive number n
    int total = 0;  // total holds the sum of the first n positive numbers
    int startValue; // the amount of numbers
    float mean;     // the average of the first n positive numbers
    int num;

    cout << "Please enter a starting integer" << endl;
    cin >> startValue;
    cout << "Please enter a ending integer" << endl;
    cin >> endValue;
    num = startValue;

    if (startValue > 0)
    {
        for (startValue; startValue <= endValue; startValue++)
        {
            total = total + startValue;
        } // curly braces are optional since there is only one statement

        mean = static_cast<float>(total) / (endValue - num + 1); // note the use of the typecast
        // operator here

        cout << "The mean average of the intergers " << num << " to " << endValue
             << " is " << mean << endl;
    }

    else
        cout << "Invalid input - integer must be positive" << endl;

    return 0;
}