// yisak worku yxw190038

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Members

{
    int Row = 0;
    char Seat;
    char TicketType;
    Members *Next = nullptr;
};

void Linkedlist(Members *&head, ifstream &in, int &row, int &columnNum)
{
    int i = 0;
    head = new Members;
    Members *cur = head;
    while (in.get(cur->TicketType))
    {
        cur->Row = row;
        cur->Seat = char(i + 65);
        i++;
        if (cur->TicketType == '\n')
        {
            columnNum = i - 1;
            i = 0;
            row++;
        }
        cur->Next = new Members;
        cur = cur->Next;
    }
}

void clearCin() // input loop
{
    cin.clear();
    cin.ignore(1000, '\n');
}

void move(Members *head, Members *&cur, char column, int seats) // reset cursor after use
{
    cur = head;
    while (cur->Seat != column || cur->Row != seats)
    {
        cur = cur->Next;
    }
}

void count(int tickets[], Members *cur) // count tickets by type
{

    if (cur->TicketType == 'A') // if adult ticket count it
    {
        tickets[0]++;
    }
    if (cur->TicketType == 'C') // if child ticket count it
    {
        tickets[1]++;
    }
    if (cur->TicketType == 'S') // if senior ticket count it
    {
        tickets[2]++;
    }
}

void printAuditorium(int tickets[], Members *cur) // print censored Auditorium line by line
{
    // reset tickets for counting
    tickets[0] = 0;
    tickets[1] = 0;
    tickets[2] = 0;

    while (cur) // loop through lines of file
    {
        if (isalpha(cur->TicketType)) // if its a sold ticket count and censore it
        {
            count(tickets, cur);
            cout << '*';
        }

        else
        {
            cout << cur->TicketType; // print censored Auditorium)
        }
        cur = cur->Next;
    }
}

int main()
{
    string filename = "", line = "", temp = "";
    int row = 1;          // row
    int tickets[3] = {0}; // ticket array
    int columnNum = 0;
    char column;               // column
    int seats = 0;             // number of seats
    long unsigned int pos = 0; // current writing postion

    cout << "Enter File Name: ";
    cin >> filename;

    ifstream in(filename); // open to read and write file

    if (in.is_open()) // check file is open
    {

        Members *head = nullptr;
        Members *cur = nullptr;

        Linkedlist(head, in, row, columnNum);
        in.close();                            // close file
        cout << "\n1.Reserve seats\n2.Exit\n"; // print menu

        while (!(cin >> seats) || (seats != 1 && seats != 2)) // loop till valid user selection
        {
            clearCin();
            cout << "no\n";
        }

        while (seats != 2) // loop while user wants seats
        {

            printAuditorium(tickets, head);                       // print Auditorium founction
            while (!(cin >> seats) || seats <= 0 || seats >= row) // loop till vaild row input
            {
                clearCin();
                cout << "no\n"
                     << row;
            }

            while (!(cin >> column) || (int(column) - 65) >= columnNum || !(isalpha(column))) // loop till valid column input
            {
                clearCin();
                cout << "no\n";
            }

            int j = 0; // while loop counter

            j++;

            pos = (int(column) - 65); // set write postion to column acsii convert

            // modify the correct line
            move(head, cur, column, seats);

            char types[3] = {'A', 'C', 'S'}; // types of tickets

            for (int i = 0; i < 3; i++) // loop for each type of ticket
            {

                while (!(cin >> j) || j < 0) // loop till you get vaild ticket number
                {
                    clearCin();
                    cout << "no\n";
                }
                tickets[i] = j; // count each type of ticket
            }

            for (int i = 0; i < tickets[0] + tickets[1] + tickets[2]; i++) // loop till all input seats are reserved
            {

                if (int(cur->Seat) - 65 > columnNum || isalpha(cur->TicketType)) // if seats taken or out of bounds
                {                                                                /*
                                                                                    // then try to find a new set
                                                               
                                                                                    // if theres and opening in the right half closer to the middle then the left half
                                                                                    if (line.find(column, ((line.length()) / 2 - (tickets[0] + tickets[1] + tickets[2]) / 2)) - ((line.length()) / 2 - (tickets[0] + tickets[1] + tickets[2]) / 2) < ((line.length()) / 2 - (tickets[0] + tickets[1] + tickets[2]) / 2) - line.rfind(column, ((line.length()) / 2 - (tickets[0] + tickets[1] + tickets[2]) / 2)))
                                                                                    {
                                                                                        // then offer it to the user
                                                                                        cout << j << char(line.find(column, ((line.length()) / 2 - (tickets[0] + tickets[1] + tickets[2]) / 2)) + 65) << " - " << j << char((line.find(column, ((line.length()) / 2 - (tickets[0] + tickets[1] + tickets[2]) / 2)) + 64 + tickets[0] + tickets[1] + tickets[2])) << endl;
                                                                                        cout << "Would you like to reserve these seats(Y/N)\n";
                                                               
                                                                                        cin >> temp; // take there choise
                                                                                        toupper(temp[0]);
                                                               
                                                                                        if (temp == "Y") // if yes then update write postion
                                                                                        {
                                                                                            pos = line.find(column, ((line.length()) / 2 - (tickets[0] + tickets[1] + tickets[2]) / 2));
                                                                                            goto finish; // else break loop
                                                                                        }
                                                               
                                                                                        goto finish2; // else break loop no cahnge
                                                                                    }
                                                               
                                                                                    // if theres and opening in the left half closer to the middle then the right half
                                                                                    else if (line.find(column, ((line.length()) / 2 - (tickets[0] + tickets[1] + tickets[2]) / 2)) - ((line.length()) / 2 - (tickets[0] + tickets[1] + tickets[2]) / 2) >= ((line.length()) / 2 - (tickets[0] + tickets[1] + tickets[2]) / 2) - line.rfind(column, ((line.length()) / 2 - (tickets[0] + tickets[1] + tickets[2]) / 2)) && int(line.rfind(column, ((line.length()) / 2 - (tickets[0] + tickets[1] + tickets[2]) / 2))) >= 0)
                                                                                    {
                                                                                        // then offer it to the user
                                                                                        cout << j << char((line.rfind(column, ((line.length()) / 2 - (tickets[0] + tickets[1] + tickets[2]) / 2)) + 65)) << " - " << j << char((line.rfind(column, ((line.length()) / 2 - (tickets[0] + tickets[1] + tickets[2]) / 2)) + 64 + tickets[0] + tickets[1] + tickets[2])) << endl;
                                                                                        cout << "Would you like to reserve these seats(Y/N)\n";
                                                               
                                                                                        cin >> temp; // take there choise
                                                                                        toupper(temp[0]);
                                                               
                                                                                        if (temp == "Y") // if yes then update write postion
                                                                                        {
                                                                                            pos = line.rfind(column, ((line.length()) / 2 - (tickets[0] + tickets[1] + tickets[2]) / 2));
                                                                                            goto finish; // else break loop
                                                                                        }
                                                                                        goto finish2; // else break loop no cahnge
                                                                                    }
                                                               
                                                                                    else
                                                                                    {
                                                                                        cout << "no seats available\n"; // print that an alteritve can't be found
                                                               
                                                                                        goto finish2; // else break loop no cahnge
                                                                                    }
                                                                                }*/
                    cout << "cat";
                    tickets[0] = 0;
                    tickets[1] = 0;
                    tickets[2] = 0;
                }
                cur = cur->Next;
            }

            move(head, cur, column, seats);
            for (int i = 0; i < 3; i++) // loop for each type of ticket
            {
                for (int j = 0; j < tickets[i]; j++)
                {
                    cur->TicketType = types[i];
                    cur = cur->Next;
                }
            }

            cout << "\n1.Reserve seats\n2.Exit\n"; // promt for loop

            while (!(cin >> seats) || (seats != 1 && seats != 2)) // loop till vaild input
            {
                clearCin();
            }
        }
        printAuditorium(tickets, head); // print updated Auditorium & count tickets

        // output report
        cout << "Total Seats: " << setw(6) << row * columnNum
             << "\nTotal Tickets: " << setw(3) << tickets[0] + tickets[1] + tickets[2]
             << "\nAdult Tickets: " << setw(3) << tickets[0]
             << "\nChild Tickets: " << setw(3) << tickets[1]
             << "\nSenior Tickets: " << setw(1) << tickets[2]
             << "\nTotal Sales: " << setw(4)
             << "$" << fixed << setprecision(2) << tickets[0] * 10 + tickets[1] * 5 + tickets[2] * 7.50 << endl;

        ofstream out("A1.txt");
        cur = head;
        while (cur->Next)
        {
            out << cur->TicketType;
            cur = cur->Next;
        }
        out.close(); // close file
    }
}