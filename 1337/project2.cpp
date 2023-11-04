// yisak worku yxw190038

#include <iostream>
#include <fstream>
#include <memory>
using namespace std;

// output the updated blobs
void output(int row, int column, unique_ptr<int[]> &ptr)
{
    // loop through the whole blob array
    for (int i = 0; i < (row * column); i++)
    {
        // if there's a blob output *
        if (*(ptr.get() + i) == 1)
        {
            cout << '*';
        }
        
        // if at the end of line output \n and go to next line
        else if ((i + 1) % column == 0)
        {
            cout << '\n';
        }

        // else output a space
        else
        {
            cout << ' ';
        }
    }
}

// blob game main function
int main()
{
    // file name & current line varible
    string filename = "", line = "";

    // char varible that stores blob character
    char blob = 'a';

    // row, column, & loop varibles
    int row = 1, loop = 0, column = 1;

    // input file name and open file
    cin >> filename;
    fstream f(filename);

    // check file is opened and run it it is
    if (f.is_open())
    {
        // get first line of file and count the character lengnth
        getline(f, line);
        column += int(line.size());

        // loop the counts the nummber of rows in the file
        while (getline(f, line))
        {
            row++;
        }

        // clear end of file flag and reset cursor
        f.clear();
        f.seekg(0);

        // dynamic int pointer stores blob map
        unique_ptr<int[]> ptr(new int[row * column]{});

        // loop that converts blob to 1 and nonblobs to 0
        for (int i = 0; i < (row * column) - 1; i++)
        {
            f.get(blob);
            if (blob == '*')
            {
                *(ptr.get() + i) = 1;
            }
        }

        // close file
        f.close();

        // loop till a valid row is input
        while (!(cin >> loop) || loop <= 0 || loop >= 11) // loop till vaild loop input
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        // do the blob game the number of times entered
        for (int i = 0; i < loop; i++)
        {
            // output turn  and turn number
                cout << "TURN " << i + 1 << endl << endl;

            // dynamic int pointer stores neighbor map
            unique_ptr<int[]> neighbors(new int[row * column]);

            // loop through blob arry
            for (int i = 0; i < (row * column); i++)
            {
                // if end of line don't calculate neighbors
                if ((i + 1) % column == 0)
                {
                    *(neighbors.get() + i) = 0;
                }

                // if postion 0 calculate right coner neighbors
                else if (i == 0)
                {
                    *(neighbors.get() + i) = *(ptr.get() + i + 1) + *(ptr.get() + i + column) + *(ptr.get() + i + column - 1) + *(ptr.get() + i + column + 1);
                }

                // if top row calculate top row neighbors
                else if (i < column)
                {
                    *(neighbors.get() + i) = *(ptr.get() + i - 1) + *(ptr.get() + i + 1) + *(ptr.get() + i + column) + *(ptr.get() + i + column - 1) + *(ptr.get() + i + column + 1);
                }

                // if bottom row calculate bottom row neighbors
                else if (i >= (row * column) - column)
                {
                    *(neighbors.get() + i) = *(ptr.get() + i - 1) + *(ptr.get() + i + 1) + *(ptr.get() + i - column) + *(ptr.get() + i - column - 1) + *(ptr.get() + i - column + 1);
                }

                // if  calculate neighbors
                else if (i == column)
                {
                    *(neighbors.get() + i) = *(ptr.get() + i - 1) + *(ptr.get() + i + 1) + *(ptr.get() + i - column) + *(ptr.get() + i - column + 1) + *(ptr.get() + i + column) + *(ptr.get() + i + column - 1) + *(ptr.get() + i + column + 1);
                }

                // else general calculate neighbors
                else
                {
                    *(neighbors.get() + i) = *(ptr.get() + i - 1) + *(ptr.get() + i + 1) + *(ptr.get() + i - column) + *(ptr.get() + i - column - 1) + *(ptr.get() + i - column + 1) + *(ptr.get() + i + column) + *(ptr.get() + i + column - 1) + *(ptr.get() + i + column + 1);
                }
            }

            // loop to up date blobs based on neighbors
            for (int i = 0; i < (row * column); i++)
            {
                // if theres a blob with less then 2 or more than 3 neighbors kill it
                if (*(ptr.get() + i) == 1 && (*(neighbors.get() + i) < 2 || *(neighbors.get() + i) > 3))
                {
                    *(ptr.get() + i) = 0;
                }

                // if it has 3 neighbors make a blob
                else if (*(neighbors.get() + i) == 3)
                {
                    *(ptr.get() + i) = 1;
                }
            }

            // output function
            output(row, column, ptr);

            // add a blank line
                cout << endl;
        }
    }
}