// Ryan Gelling
// rxg220046

/*This program asks the user for a file name. It then asks the user if they would like to reserve
seats or exit the program. Choosing to reserve seats starts a loop. From there, the program will
display the auditorium to the user. It will then ask the user which row the user wants to reserve on.
It then asks the user which seat they want to start the reservation on. The program then asks the user
for the amount of adult/child/senior tickets in that order. If during any of this an invalid character is
entered, the program will repeat the question. The program will then check to see if the seats are available.
If they are available, the program will reserve them and loop back to the menu screen. If they are not available,
the program will check for seats on the same row and show the user the best (closest to middle) seats in that row.
The user will have the option to take those seats or not. If they accept, the program will reserve those seats, give
a confirmation, and then loop back to the menu. If the user decides to exit the program, the program will display
a report containing the total amount of seats, of each type of ticket, total amount of tickets, and the amount of
revenue from all the tickets.*/

#include <iostream>
#include<fstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

/* Declares const file name for use by whole program because of zylabs*/

const string filename = "A1.txt";  //file to edit for ticket reservations

/* This function tests inputs from the user to verify they are valid. It takes an integer and character argument, 
and another int argument to tell the function which type of input to verify. It return true if the input is valid,
or false if it is not.*/

bool inputVal(int valInt, char valChar, int type)
{
    bool valid = false;
    
    /* If the test case passed is type 1, an int, test to see if the int is 0 or greater. Sets valid to true
    if it is.*/
    
    if(type == 1)
    {
        if(valInt >= 0)
        {
            valid = true;
        }
        
    }
    
    /*If the test case passed is type 2, a character, check to see if it is a capital letter of the alphabet.
    Sets valid to true if it is.*/
    
    else if(type == 2)
    {
        if(isalpha(valChar))
        {
            if(isupper(valChar))
            {
                valid = true;
            }
        }
    }
    
    return valid;
}

/* This function takes the amount of rows and columns by reference and returns nothing. The function opens
the const A1.txt file. It then reads a line from the file to get the length of the auditorium. The function then
loops and displays the columns (A-Z) of the theater to the user. The function then loops again, reading every
character from the file and displays to the user, along with the rows, the seats that are already taken; displayed
with #'s. It loops until the whole file is read. The function also tells the main function the amount of columns
and rows in the function.*/

void displayAud(int &rowAmt, int &colAmt)
{
    /* Sets file stream name, string that will pull from the file, and opens the file in read mode*/
    
    fstream file;
    string aud = "";
    file.open("A1.txt", ios::in);
    
    /* Checks if the file opened.*/
    
    if(file)
    {
        /* Pulls a line from the file and grabs the length of the string. Then reset bthe cursor back to
        the beginning of the file.*/
        
        getline(file, aud);
        long long int audLen = aud.length();
        file.seekg(0, ios::beg);
        
        /* Sets a counter to 0 and reassigns the aud string the column names (the alphabet). Then loops
        to displays the column names. Accounts for two blank spaces to align with rest of display below.*/
        
        int counter = 0;
        aud = "  ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        
        do
        {
            cout << aud[counter];
            counter++;
            
        }while(counter < audLen + 2);
        
        /* Creates a newline for the display and assigns by reference the amount of columns to colAmt
        based on the amount of letters output by the above loop*/
        
        cout << "\n";
        colAmt = counter - 2;
        
        /* Loops while there are rows to pull from the file*/
        
        while(getline(file, aud))
        {
            /* Resets counter to 0 and loops while the aud (the row) pulled from the file has data. If
            the file has a reserved seat (A/C/S) the program assigns a # instead in place of the letter
            in the string. If the seat is empty (a '.'), leaves it alone.*/
            
            counter = 0;
            do
            {
                if(aud[counter] == 'A' || aud[counter] == 'C' || aud[counter] == 'S')
                {
                    aud[counter] = '#';
                }
                
                counter++;
                
            }while(counter < audLen);
            
            /* A check to see if the file row reader has reached the end of the file. If it has
            not reached the end, increases the reference value of rowAmt and displays to the user 
            the row number and a space before the file loops back to display the seats.*/
            
            if(aud[0] != '\n')
            {
                rowAmt++;
                cout << rowAmt << " " << aud << endl;
            }
            
            /* Resets the aud string*/
            
            aud = "";
        }
        
        /* Displays a newline and closes the file*/
        
        cout << '\n';
        file.close();
    }
    
    return;
}

/* This function takes the total amount of tickets trying to be reserved and the cursor
location within the file. The function tests the file to see if all the seats the user
wants to reserve are available. Returns true if they are, false if not.*/

bool checkAvail(int totRes, long int cursLoc)
{
    /* Sets available bool to true and then creates and opens the file*/
    
    bool available = true;
    
    fstream file;
    file.open("A1.txt", ios::in);
    
    /* Checks if file was opened successfully in read mode. If it did, continues*/
    
    if(file)
    {
        /* Moves file cursor to where the user is trying to reserve their seats. Then
        Intializes the counter for the below loop, and the current seat the file is 
        reading from*/
        
        file.seekp(cursLoc, ios::beg);
        
        int counter = 0;
        char curSeat = '0';
        
        /* Loops while the counter is less than the total reservation. Gets the current seat
        from the file and checks to see if it is reserved (A/C/S) or not. If it is reserved,
        sets available to false and breaks the loop*/
        
        do
        {
            file.get(curSeat);
            counter++;
            
            if(curSeat != '.')
            {
                available = false;
                break;
            }
            
        }while(counter < totRes);
        
        // Closes file then returns available
        
        file.close();
    }
    
    return available;
}

/* This function takes the row of the reservation, total tickets, and the amount of columns
in the auditorium. It test the row of the file to find the best seats for the user. The
best seats are closest to the middle. The function returns the best avilable seat's file
position or returns -1 if there are no seats available.*/

long int bestAvail(int row, int totTick, int colAmt)
{
    /* Initializes variables for function and creates file stream*/
    
    fstream file;
    long int startSeat1 = -1;
    long int startSeat2 = 0;
    int availCount = 0;
    long int seat1Avg = 0;
    long int seat2Avg = 0;
    char seat = '0';
    
    /* Opens file in and checks to make sure file opened*/
    
    file.open("A1.txt", ios::in);
    
    if(file)
    {
        /* Sets cursor to file position of the start of the row the reservation
        is on*/
        
        file.seekp((row - 1) * (colAmt) + (row - 1), ios::beg);
        
        /* Loops as long as the counter is less than or equal to the amount of columns
        in the theater.*/
        
        for(int counter = 1; counter <= colAmt; counter++)
        {
            /* Gets a seat from the file and tests to see if it is available. If it is,
            increase the availCount counter until it is equal to the total reservation.
            If a seat is not available, resets said counter*/
            
            file.get(seat);
            
            if(seat == '.')
            {
                availCount++;
            }
            
            else if(seat != '.')
            {
                availCount = 0;
            }
            
            /* If the total resevration of free seats is met*/
            
            if(availCount == totTick)
            {
                /* The first time the reservation is met, assigns the file position of the
                first available seat to startSeat1 and then resets the file pointer to one
                position after startSeat1. Lowers the counter for the overarching for loop
                the same amount*/
                
                if(startSeat1 == -1)
                {
                    file.seekp(- totTick, ios::cur);
                    startSeat1 = file.tellp();
                    availCount = 0;
                    file.seekp(+ 1, ios::cur);
                    counter -= (totTick - 1);
                }
                
                /* If it is the 2nd or greater time that the function found enough seats free,
                assigns the file position of the first seat to startSeat2 and then reduces the
                overarching for loop by the amount of the reservation - 1, and sets the file's
                cursor to 1 after startSeat1*/
                
                else
                {
                    file.seekp(- totTick, ios::cur);
                    startSeat2 = file.tellp();
                    availCount = 0;
                    file.seekp(+ 1, ios::cur);
                    counter -= (totTick - 1);
                    
                    /*Assigns resets values for future loops*/
                    
                    seat1Avg = 0;
                    seat2Avg = 0;
                    
                    /* Finds the absolute value distance away from the center of the auditorium for
                    the both the startSeat1 and startSeat2 potential reservations. Loops and adds the
                    values for each set of tickets. Loops as long as the counter is less than the total
                    reservation amount*/
                    
                    for(int counter2 = 0; counter2 < totTick; counter2++)
                    {
                        seat1Avg += abs((colAmt / 2) - (startSeat1 - (colAmt * (row - 1)) + counter2) + (row - 1) * 1);
                        seat2Avg += abs((colAmt / 2) - (startSeat2 - (colAmt * (row - 1)) + counter2) + (row - 1) * 1);
                    }
                    
                    /* If the average of the 2nd set of seats is less than the 1st, assigns the value
                    of the 2nd starting seat to the 1st*/
                    
                    if((seat1Avg) > (seat2Avg))
                    {
                        startSeat1 = startSeat2;
                    }
                }
            }
            
        }
        
        /* Closes file*/
        
        file.close();
    }
    
    /* Returns startSeat1 value of -1 by default or the new seat location if the function
    found a better seat*/
    
    if(startSeat1 != -1)
    {
        return startSeat1;
    }
    
    else
    {
        return startSeat1;
    }
}

/* Takes the row and column of the reservation, the amount of each ticket reserved, and the
amount of columns in the program. The function will then open the file and search for the
position of the seat for the reservation. Then it will call checkAvail to see if the
reservation is available. If it is avilable, it will reserve the seats and loop to change
the file's contents to the tickets reserved by the user. If not avilable, will call bestAvail
to see if there are other (or better) seats available on the same row. If there are, ask the user
if they want to reserve those seats and reserve them. If not, display there are no seats available
and end the function, looping back to the main menu. The function returns nothing*/

void reserveSeat(int row, char col, int adTick, int chTick, int seTick, int colAmt)
{
    /* Sets the file stream variable, defaults the cursLoc to 0, and opens the main file for
    input and output to not erase contents*/
    
    fstream file;
    long int cursLoc = 0;
    file.open("A1.txt", ios::in | ios::out);
    
    /* Checks if file was opened successfully. If it was, gets the location of the start of
    the reservation the user wants. Then closes the file*/
    
    if(file)
    {
        file.seekp(((row - 1) * (colAmt) + (col - 65)) + (row - 1));
        cursLoc = file.tellp();
        file.close();
    }
    
    /* Calls available function to see if the seats the user wants are available. Sends
    the amount of each ticket and the location of the starting seat that the user wants. 
    Returns true or false if the seats are available.*/
    
    bool available = checkAvail(adTick + chTick + seTick, cursLoc);
    
    /* Initializes and set counter to 0 for below loop*/
    
    int counter = 0;
    
    /* If available returns true*/
    
    if(available == true)
    {
        /* Opens file in input and output*/
        
        file.open("A1.txt", ios::in | ios::out);
        
        /* If the file opens properly*/
        
        if(file)
        {
            /* Goes to the cursor location in the file of where the user wants to
            start their reservation*/
            
            file.seekp(cursLoc, ios::beg);
            
            /*Replaces file content with 'A' for each adult ticket the user wants*/
            
            if(adTick > 0)
            {
                do
                {
                    file << 'A';
                    counter++;
                    
                }while(adTick > counter);
            }
            
            /* Replaces file content with 'C' for each child ticket the user wants*/
            
            if(chTick > 0)
            {
                counter = 0;
                
                do
                {
                    file << 'C';
                    counter++;
                    
                }while(chTick > counter);
            }
            
            /* Replaces file content with a 'S' for each senior ticket the user wants*/
            
            if(seTick > 0)
            {
                counter = 0;
                 
                do
                {
                    file << 'S';
                    counter++;
                    
                }while(seTick > counter);
            }
            
            /* Closes file and gives user reservation confirmation*/
            
            cout << "\nConfirmed reservation.\n";
            file.close();
        }
    }
    
    
    /* If available returns false*/
    
    else if (available == false)
    {
        /* Calls bestSeatPos and send the row the user wants, the amount of each ticket,
        and the amount of columns in the adutiorium. Returns the position of the best
        alternative seat, or -1 if there is none*/
        
        long int bestSeatPos = bestAvail(row, adTick + chTick + seTick, colAmt);
        
        /*If -1 was returned and there was no other seat(s) available. Tells user
        that no seats were available*/
        
        if(bestSeatPos == -1)
        {
            cout << "\nno seats available\n";
        }
        
        /* If there is another seat(s) available*/
        
        else
        {
            /*Assigns and creates user choice and the auditorium columns*/
            
            char choice = '0';
            string aud = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            
            /*Asks the user if they would like to reserve a new set of seats in the auditorium.
            Displays to the user the new seats and asks them for a Y or N input to reserve or not*/
            
            cout << "\nWould you like to reserve seats " << row 
                    << aud[bestSeatPos - ((row - 1) * colAmt) - ((row - 1) * 1)] << " - "
                    << row << aud[bestSeatPos - ((row - 1) * colAmt) - ((row - 1) * 1) + adTick + chTick + seTick - 1] 
                    << ". (Y/N)\n";
            cin >> choice;
            
            /* If user wants to reserve the new seats*/
            
            if(choice == 'Y')
            {
                /* Opens file once again in input and output and checks to see if the
                file opened successfully*/
                
                file.open("A1.txt", ios::in | ios::out);
                if(file)
                {
                    /* Goes to the position of the best seat inside the file*/
                    
                    file.seekp(bestSeatPos, ios::beg);
                    
                    /* Outputs to file 'A' equal to the amount of adult tickets requested*/
                    
                    if(adTick > 0)
                    {
                        do
                        {
                            file << 'A';
                            counter++;
                            
                        }while(adTick > counter);
                    }
                    
                    /* Outputs to file 'C' equal to the amount of child tickets requested*/
                    
                    if(chTick > 0)
                    {
                        counter = 0;
                        
                        do
                        {
                            file << 'C';
                            counter++;
                            
                        }while(chTick > counter);
                    }
                    
                    /* Outputs to file 'S' equal to number of child tickets requested*/
                    
                    if(seTick > 0)
                    {
                        counter = 0;
                         
                        do
                        {
                            file << 'S';
                            counter++;
                            
                        }while(seTick > counter);
                            
                    }
                    /* Closes file and gives confirmation of reservation to the user*/
                    
                    cout << "\nConfirmed reservation.\n";
                    file.close();
                }
            }
        }
    }
    
    return;
}

/* Function takes no arguments and returns nothing. The function reads from the file
at the end of the program to show the amount of total seats in the auditorium, the total
tickets reserved amount of each ticket, and the total amount of revenue. It displays
these in aligned columns*/

void displayReport()
{
    
    /*Creates file stream, opens it in read mode, and checks if the file was opened */
    
    fstream file;
    file.open("A1.txt", ios::in);
    if(file)
    {
        /* Creates and clears out a character fChar for the file reading and the total amount of
        each ticket reserved*/
        
        char fChar = '0';
        int totAd = 0;
        int totCh = 0;
        int totSe = 0;
        int totSeats = 0;
        
        /*Loops while fChar is assigned a character from the file. When fChar reads
        A, S, or C the counter for the total amount of that ticket type is ticked up
        along with the total amount of seats. If only a '.' is read, it will only tick
        up totSeat*/
        
        while(file.get(fChar))
        {
            if(fChar == 'A')
            {
                totAd++;
                totSeats++;
            }
            
            else if(fChar == 'S')
            {
                totSe++;
                totSeats++;
            }
            
            else if(fChar == 'C')
            {
                totCh++;
                totSeats++;
            }
            
            else if (fChar == '.')
            {
                totSeats++;
            }
            
            /* Displays the final report, showing the amount of seats, tickets of each type
            sold, the total amount of tickets, and the total sales from those tickets. Displays
            in a column aligned fashion. Then closes the file.*/
        }
        cout << left << "\nReport\n";
        cout << setw(16) << "Total Seats" << setw(3) << totSeats << "\n";
        cout << setw(16) << "Total Tickets" << setw(3) << totAd + totCh + totSe << "\n";
        cout << setw(16) << "Adult Tickets" << setw(3) << totAd << "\n";
        cout << setw(16) << "Child Tickets" << setw(3) << totCh << "\n";
        cout << setw(16) << "Senior Tickets" << setw(3) << totSe << "\n";
        cout << setw(16) << "Total Sales" << fixed << showpoint << setprecision(2) 
        << setw(1) << "$" << setw(6) << (totAd * 10) + (totCh * 5) + (totSe * 7.50) << "\n";
        
        file.close();
    }
}

int main(){
   /////////////////////////////////////////////////////////////////////////////////////////
   ////////////////////          DO  NOT CHANGE CODE BELOW THIS               //////////////
   /////////////////////////////////////////////////////////////////////////////////////////
   string temp, line;
   
   cout<<"Enter File Name: ";
   cin>>temp;

   ifstream infile(temp);
   ofstream outfile(filename);
   if (infile)
      while (getline(infile,line))
         outfile << line << "\n";
        
   infile.close();
   outfile.close();
   
   /////////////////////////////////////////////////////////////////////////////////////////
   ////////////////////          DO  NOT CHANGE CODE ABOVE THIS               //////////////
   /////////////////////////////////////////////////////////////////////////////////////////
    
    /*Assigns and empties out menuSel*/
    
    char menuSel = '0';
    
    /* Loops while the user does not exit (type 2) on the menu displayed. */
    
    do
    {
        /* Displays the menu to the user and gets their input option*/
        
        cout << "\n1. Reserve Seats";
        cout << "\n2. Exit\n";
        cin >> menuSel;
        
        /* If the user enters 1, wanting to reserve seats*/
        
        if(menuSel == '1')
        {
            /* Assigns ints for the amount of rows and columns in the program and 0's
            them out*/
            
            int rowAmt = 0;
            int colAmt = 0;
            
            /* Calls displayAud to display the auditorium to the user. It passes the amount
            of rows and cols (function takes the reference value) to get the amount of rows and
            columns that are inside the theater*/
            
            displayAud(rowAmt, colAmt);
            
            /* Creates and 0's out ints for the amount of ticket, the row, and a charcter for the
            column the file is on. Also sets valid to false for tests just after*/
            
            int row = 0;
            char col = '0';
            int adTick = 0;
            int chTick = 0;
            int seTick = 0;
            bool valid = false;
            
            /* Loops while valid = false and the number input for the row is not an actual
            row number in the theater*/
            
            do
            {
                /* Asks the user which row they want to reserve on*/
                
                cout << "Please enter the row you would like to reserve on: ";
                cin >> row;
                
                /* If the row = 0 still, clears the inputs and ignores
                the last character put in*/
                
                if(row == 0)
                {
                    cin.clear();
                    cin.ignore(1);
                }
                
                /* Calls input validation to verify the input is a valid row. Sends
                the row number minus 1, a placeholder character '0', and int 1 to
                tell inputVal it is checking a number*/
                
                else
                {
                    valid = inputVal(row - 1, '0', 1);
                }
                
            }while (valid == false && row <= rowAmt);
            
            /* Resets valid to false for next test*/
            
            valid = false;
            
            /*Loops while valid = false. Will be false until the user inputs a valid letter
            inside the theater*/
            
            do
            {
                /*Asks the user to enter a seat letter and takes that letter*/
                cout << "\nPlease enter the seat you would like to start your reservation on: ";
                cin >> col;
                
                /* Calls inputVal, sending a 0 int placeholder, the col input by the user
                and an int 2 to tell the function to check the character. Returns true
                if the character is valid*/
                    
                valid = inputVal(0, col, 2);
                
            }while (valid == false);
            
            /* Resets valid to false*/
            
            valid = false;
            
            /* Loops while the user does not enter a valid input (any number at least 0).
            Also asks the user to enter a number for the amount of adult seats they want*/
            
            do
            {
                cout << "\nPlease enter the amount of adult seats you would like to reserve: ";
                cin >> adTick;
                
                if(adTick == 0)
                {
                    cin.clear();
                    cin.ignore(1);
                }
                
                /* Calls input val, sending the number the user entered, a placeholder character
                and the int 1 to tell the function it needs to check the int Returns true if the
                character is valid*/
                
                valid = inputVal(adTick, '0', 1);
                
            }while (valid == false);
            
            /* Resets valid to false*/
            
            valid = false;
            
            /* Loops while the input number is not at least 0*/
            
            do
            {
                /* Asks the user to enter the amount of child tickets they want, and then assigns
                that to chTick*/
                
                cout << "\nPlease enter the amount of child seats you would like to reserve: ";
                cin >> chTick;
                
                /*Calls input val, sending amount of child tickets the user wants, a placeholder
                '0' character and the int 1 to tell inputVal to check the int value*/
                
                valid = inputVal(chTick, '0', 1);
                    
            }while (valid == false);
            
            /* Reset valid to false*/
            
            valid = false;
            
            /* Loops while the number input by the user is not at least 0*/
            
            do
            {
                /* Asks the user to enter the amount of senior seats they want to reserve. Assigns
                that value to seTick*/
                
                cout << "\nPlease enter the amount of senior seats you would like to reserve: ";
                cin >> seTick;
                
                /*Calls inputVal and send the amount of tickets along with the an placeholder '0'
                character and an int 1 to signify that the function should check the int input*/
                
                valid = inputVal(seTick, '0', 1);
                    
            }while (valid == false);
            
            /*Outputs newline*/
            
            cout << "\n";
            
            /*Calls reserve seats, sending the row and col the user wants tor eserve on, and the amount
            of each ticket, along with the total amount of columns in the auditorium. Gets no value back*/
            reserveSeat(row, col, adTick, chTick, seTick, colAmt);
            
        }
        
    }while(menuSel == '1');
    
    /* Calls displayReport at program end. Does not take or return anything. Displays the
    amount of tickets sold, seats in the auditorium, and total sales*/
    
    displayReport();
    
    return 0;
}