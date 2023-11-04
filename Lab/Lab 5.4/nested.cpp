// This program finds the average time spent programming by a student
// each day over a three day period.

// Yisak Worku

#include <iostream>
using namespace std;

int main()
{
     int numStudents, weekend;
     float bioHours, compHours, bioTotal, compTotal, average;
     int student, day = 0; // these are the counters for the loops

     cout << "This program will find the average number of hours a day"
          << " that a student spent programming over a long weekend\n\n";
     cout << "How many students are there?" << endl
          << endl;
     cin >> numStudents;
     cout << "Enter number of days in the long weekend." << endl
          << endl;
     cin >> weekend;

     for (student = 1; student <= numStudents; student++)
     {
          compTotal = 0;
          bioTotal = 0;

          for (day = 1; day <= weekend; day++)
          {
               cout << "Please enter the number of hours programming by the student "
                    << student << " on day " << day << "." << endl;
               cin >> compHours;
               compTotal = compTotal + compHours;

               cout << "Please enter the number of hours studing biology by the student "
                    << student << " on day " << day << "." << endl;
               cin >> bioHours;
               bioTotal = bioTotal + bioHours;
          }

          average = compTotal / weekend;
               cout << endl;
               cout << "The average number of hours per day spent programming by "
                    << "student " << student << " is " << average << endl
                    << endl
                    << endl;

          average = bioTotal / weekend;
          cout << endl;
          cout << "The average number of hours per day spent studing biology by "
               << "student " << student << " is " << average << endl
               << endl
               << endl;

          if (compTotal > bioTotal)
          {
               cout << "Student " << student << " studied more programming. "
                    << endl;
          }

          else if (bioTotal > compTotal)
          {
             cout << "Student " << student << " studied more biology. "
                    << endl;
          }
          
          else
               cout << "They studied both equally. \n";
     }

     return 0;
}