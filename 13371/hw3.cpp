#include <iostream>
#include <string>
using namespace std;

int OddSum(int array[], int arraySize, int i = 1)
{
    if (arraySize <= i)
    {
        return 0;
    }

    return array[i] + OddSum(array, arraySize, i + 2);
}

string Backwards(string str, long unsigned int i = 0)
{
    if ((str.length() - 1) == i)
    {
        str = str[i];
        return str;
    }

    str = Backwards(str, i + 1) + str[i];
    return str;
}

int main()
{
    int arraySize=0;
    int num=0;
    int array[100];
    OddSum(array, arraySize);

    string str;
    cout<<Backwards(str);
    return Backwards(str), num;
}