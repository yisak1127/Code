// Yisak Worku YXW190038

#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Dock.h"
#include "Ticket.h"
#include "Ticket.cpp"
#include <fstream>
using namespace std;

int main()
{
    string into;
    fstream in("tic.dat");
    ofstream out("Tickets.txt");
    string k;
    Dock s[10] = {};
    Ship *s1 = nullptr;
    LinkedList shipList;

    while (in >> k)
    {
        int i = 0;

        if (k == "enter")
        {
            in >> k;
            int hourIn = stoi(k.substr(0, 2));
            int minutesIn = stoi(k.substr(3));
            in >> k;
            string name = k;
            in >> k;
            string shipId = k;
            in >> k;
            int credit = stoi(k);

            s1 = new Ship(name, shipId, credit);
            s[i].getMooring();
            while (i < 10 && s[i].getMooring())
            {
                i++;
            }
            if (i < 10)
            {
                s[i].setHour_In(hourIn);
                s[i].setMinutes_In(minutesIn);

                s[i].setMooring(s1);
            }
            else
            {
                shipList += s1;
            }
        }
        else
        {

            in >> k;

            while (!(s[i].getMooring()) || k != s[i].getMooring()->getShip_ID())
            {
                i++;
            }
            in >> k;
            int hourOut = stoi(k.substr(0, 2));
            int minutesOut = stoi(k.substr(3));
            Ticket ticket(s[i].getMooring(), &s[i], hourOut, minutesOut);
            if (ticket.getFine())
            {
                out << ticket << endl;
            }
            s[i].setMooring(nullptr);
        }
    }

    in.close();
    out.close();

    return 0;
}
