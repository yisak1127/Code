// This program will read in prices and store them into a two-dimensional array.
// It will print those prices in a table form.
// It will also determine and print the highest and lowest price in the array.

/*Look at the following table containing prices of certain items:

12.78	23.78	45.67	12.67
7.83	4.89	5.99	56.84
13.67	34.84	16.71	50.89

These numbers can be read into a two-dimensional array.

*/

#include <iostream>
#include <iomanip>
using namespace std;

const  int MAXROWS = 10;
const  int MAXCOLS = 10;

//typedef float PriceType[MAXROWS][MAXCOLS];    // creates a new data type
                                              // of a 2D array of floats
void   getPrices(float[][MAXCOLS], int&, int&);      // gets the prices into the array
void   printPrices(float[][MAXCOLS], int, int);      // prints data as a table
float  findHighestPrice(float[][MAXCOLS], int, int); // finds the highest price in the array
float  findLowestPrice(float[][MAXCOLS], int, int);  // finds the lowest price in the array

int main()
{
    int rowsUsed;                               // holds the number of rows used
    int colsUsed;                               // holds the number of columns used
    float priceTable[MAXROWS][MAXCOLS];                       // a 2D array holding the prices

    getPrices(priceTable, rowsUsed, colsUsed);  // calls getPrices to fill the array
    printPrices(priceTable, rowsUsed, colsUsed);// calls printPrices to display array

    cout << endl << "The highest price is "
        << findHighestPrice(priceTable, rowsUsed, colsUsed)
        << endl;                     // prints highest price which it receives
                                     // from calling the function findHighestPrice

   //COMPLETE CODE TO MAKE A CALL TO findLowestPrice FUNCTION HERE

   cout << endl << "The lowest price is "
        << findLowestPrice(priceTable, rowsUsed, colsUsed)
        << endl; 

    return 0;
}

//****************************************************************************************
//
//                          getPrices
//
//  task:    This procedure asks the ser to input the numer of rows and
//           columns used.  It then asks the user to input (rows * columns)
//           number of prices where x = rows * columns.  The data is placed in the array.
//  datain:  an empty array of float
//  dataout: an array filled with numbers and the number of rows
//           and columns used.
//
//****************************************************************************************
void   getPrices(float table[][MAXCOLS], int& numOfRows, int& numOfCols)
{

    cout << "Please input the number of rows from 1 to " << MAXROWS << endl;
    cin >> numOfRows;

    cout << "Please input the number of columns from 1 to " << MAXCOLS << endl;
    cin >> numOfCols;


    for (int row = 0; row < numOfRows; row++)
    {
        for (int col = 0; col < numOfCols; col++)
        {
            cout << "Please input the price of an item with 2 decimal places" << endl;
            cin >> table[row][col];
        }
    }
}

//***************************************************************************
//
//                          printPrices
//
//  task:    This procedure prints the table of prices
//  datain:  an array of floating point numbers and the number of rows
//           and columns used.
//  dataout: none
//
//****************************************************************************
void   printPrices(float table[][MAXCOLS], int numOfRows, int numOfCols)
{
    cout << fixed << showpoint << setprecision(2);

    for (int row = 0; row < numOfRows; row++)
    {
        for (int col = 0; col < numOfCols; col++)
            cout << setw(10) << table[row][col];
        cout << endl;
    }
}

//***************************************************************************
//
//                               findHighestPrice
//
//  task:         This function finds the highest value in a 2D array
//  datain:       an array of floating point numbers and the number of rows
//                and columns used.
//  datareturned: the highest value in the array (highest price)
//
//****************************************************************************

//WRITE THE DEFINITION OF findHighestPrice HERE
float findHighestPrice(float table[][MAXCOLS], int numOfRows, int numOfCols)
{
    float highestPrice;

    highestPrice = table[0][0];   // make first element the lowest price

    for (int row = 0; row < numOfRows; row++)
        for (int col = 0; col < numOfCols; col++)
            if (highestPrice < table[row][col])
                highestPrice = table[row][col];

    return highestPrice;
}

//***************************************************************************
//
//                               findLowestPrice
//
//  task:         This function finds the lowest value in a 2D array
//  datain:       an array of floating point numbers and the number of rows
//                and columns used.
//  datareturned: the lowest value in the array (lowest price)
//
//****************************************************************************
float findLowestPrice(float table[][MAXCOLS], int numOfRows, int numOfCols)
{
    float lowestPrice;

    lowestPrice = table[0][0];   // make first element the lowest price

    for (int row = 0; row < numOfRows; row++)
        for (int col = 0; col < numOfCols; col++)
            if (lowestPrice > table[row][col])
                lowestPrice = table[row][col];

    return lowestPrice;
}