// yisak worku yxw190038

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const string filename = "A1.txt"; // file to edit for ticket reservations

void clearCin() // input loop
{
   cin.clear();
   cin.ignore(1000, '\n');
}

void clearFile(fstream &in) // reset cursor after use
{
   in.clear(); // clear bad state after eof
   in.seekg(0);
}

void count(long unsigned int i, string line, int tickets[]) // count tickets by type
{

   if (line[i] == 'A') // if adult ticket count it
   {
      tickets[0]++;
   }
   if (line[i] == 'C') // if child ticket count it
   {
      tickets[1]++;
   }
   if (line[i] == 'S') // if senior ticket count it
   {
      tickets[2]++;
   }
}

void printAuditorium(fstream &in, string line, int tickets[]) // print censored Auditorium line by line
{
   // reset tickets for counting
   tickets[0] = 0;
   tickets[1] = 0;
   tickets[2] = 0;

   while (getline(in, line)) // loop through lines of file
   {
      for (long unsigned int i = 0; i < line.size(); i++) // loop through characters
      {
         if (isalpha(line[i])) // if its a sold ticket count and censore it
         {
            count(i, line, tickets);
            line.replace(i, 1, "#");
         }
      }
      cout << line << endl; // print censored Auditorium
   }
   clearFile(in); // reset cursor function
}

int main()
{
   /////////////////////////////////////////////////////////////////////////////////////////
   ////////////////////          DO  NOT CHANGE CODE BELOW THIS               //////////////
   /////////////////////////////////////////////////////////////////////////////////////////
   string temp, line;

   cout << "Enter File Name: ";
   cin >> temp;

   ifstream infile(temp);
   ofstream outfile(filename);
   if (infile)
      while (getline(infile, line))
         outfile << line << "\n";

   infile.close();
   outfile.close();

   /////////////////////////////////////////////////////////////////////////////////////////
   ////////////////////          DO  NOT CHANGE CODE ABOVE THIS               //////////////
   /////////////////////////////////////////////////////////////////////////////////////////

   int row = 0;          // row
   int tickets[3] = {0}; // ticket array

   fstream in(filename, ios::trunc | ios::out | ios::app); // open to read and write file

   if (in.is_open()) // check file is open
   {

      cout << "\n1.Reserve seats\n2.Exit\n"; // print menu

      while (!(cin >> row) || (row != 1 && row != 2)) // loop till valid user selection
      {
         clearCin();
         cout << "no\n";
      }

      while (row != 2) // loop while user wants seats
      {
         string column = "";        // column
         int seats = 0;             // number of seats
         long unsigned int pos = 0; // current writing postion

         printAuditorium(in, line, tickets); // print Auditorium founction

         seats = 0;

         while (getline(in, line))
         {
            seats++;
         }

         clearFile(in);

         while (!(cin >> row) || row <= 0 || row >= seats) // loop till vaild row input
         {
            clearCin();
            cout << "no\n";
         }

         getline(in, line); // get line so string line can be messured

         while (!(cin >> column) || (int(column[0]) - 65) >= int(line.length()) || !(isalpha(column[0]))) // loop till valid column input
         {
            clearCin();
            cout << "no\n";
         }

         clearFile(in); // reset cursor after use
         int j = 0;     // while loop counter

         // get line for every line in the file
         while (getline(in, line)) // lopp through all rows
         {
            row--; // go down a row
            j++;

            pos = (int(column[0]) - 65); // set write postion to column acsii convert

            // modify the correct line
            if (row == 0)
            {
               char types[3] = {'A', 'C', 'S'}; // types of tickets

               for (int i = 0; i < 3; i++) // loop for each type of ticket
               {

                  while (!(cin >> seats) || seats < 0) // loop till you get vaild ticket number
                  {
                     clearCin();
                     cout << "no\n";
                  }
                  tickets[i] = seats; // count each type of ticket
               }

               for (int i = 0; i < tickets[0] + tickets[1] + tickets[2]; i++) // loop till all input seats are reserved
               {
                  column = "";                                                   // column reset
                  for (int i = 0; i < tickets[0] + tickets[1] + tickets[2]; i++) // make a string of . the same lenght as user desired seats
                  {
                     column += ".";
                  }

                  if (pos + i >= line.size() || isalpha(line[pos + i])) // if seats taken or out of bounds
                  {
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
                  }
               }

            finish: // loop broken

               for (int i = 0; i < 3; i++) // loop for each type of ticket
               {
                  line.replace(pos, tickets[i], tickets[i], types[i]); // modify orginal line with users seats
                  pos += tickets[i];                                   // update write postion
               }

            finish2: // loop broken unmodified

               in.seekp(-(line.length() + 1), ios::cur); // move cursor up 1 line
               in << line << "\n";                       // over write line with modifactions if made
            }
         }

         clearFile(in); // reset file cursor

         cout << "\n1.Reserve seats\n2.Exit\n"; // promt for loop

         while (!(cin >> row)) // loop till vaild input
         {
            clearCin();
         }
      }

      row = 0; // reset row

      printAuditorium(in, line, tickets); // print updated Auditorium & count tickets
      clearFile(in);
      while (getline(in, line)) // loop to count rows
      {
         row++;
      }
      clearFile(in);
      getline(in, line); // get line for Auditorium size

      // output report
      cout << "Total Seats " << setw(6) << row * line.size()
           << "\nTotal Tickets " << setw(3) << tickets[0] + tickets[1] + tickets[2]
           << "\nAdult Tickets " << setw(3) << tickets[0]
           << "\nChild Tickets " << setw(3) << tickets[1]
           << "\nSenior Tickets " << setw(1) << tickets[2]
           << "\nTotal Sales " << setw(4)
           << "$" << fixed << setprecision(2) << tickets[0] * 10 + tickets[1] * 5 + tickets[2] * 7.50 << endl;

      in.close(); // close file
   }
}