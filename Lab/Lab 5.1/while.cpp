// Yisak Worku

#include <iostream>
using namespace std;
int main()
{
    char letter = 'a';

    do
    {
        cout << "Please enter a letter. If you would like to exit enter x" << endl;
        cin >> letter;
        cout << "The letter you entered is " << letter << endl;
    } while (letter != 'x');

    return 0;
}