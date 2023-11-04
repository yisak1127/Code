//Yisak Worku   yxw190038
//Ryan Gelling  rxg220046

#include <iostream>
#include <string>
using namespace std;

int search(int array[], int arraySize, int num, int i)
{
    if (array[i] == num)
    {
        return array[i];
    }

    else if ((arraySize - 1) == i)
    {
        return 0;
    }

    search(array, arraySize, num, ++i);
    return 0;
}

int binaryConv(int num)
{
    if (num / 2 != 0)
    {
        binaryConv(num / 2);
    }

    cout << num % 2;
    return 0;
}

int main()
{
    int i = 0;
    int arraySize = 15;
    int num = 0;
    int array[15];
    cin >> num;

    if (search(array, arraySize, num, i))
    {
        binaryConv(num);
    }

    else
        cout << "fail";
}