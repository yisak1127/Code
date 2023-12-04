#include "Ticket.h"
#include "Dock.h"
#include <iomanip>

// Default constructor
Ticket::Ticket() : Ship_Info(nullptr), Dock_Info(nullptr), Hour_Out(0), Minutes_Out(0) {}

// Overloaded constructor
Ticket::Ticket(Ship *shipInfo, Dock *dockInfo, int hourOut, int minutesOut)
    : Ship_Info(shipInfo), Dock_Info(dockInfo), Hour_Out(hourOut), Minutes_Out(minutesOut) {}

// Copy constructor
Ticket::Ticket(const Ticket &other)
    : Ship_Info(new Ship(*(other.Ship_Info))), Dock_Info(new Dock(*(other.Dock_Info))),
      Hour_Out(other.Hour_Out), Minutes_Out(other.Minutes_Out) {}

// Overloaded << operator
std::ostream &operator<<(std::ostream &os, const Ticket &ticket)
{
    os << ticket.Ship_Info << "\n";
    os << "Time In: " << (ticket.Dock_Info->getHour_In()) << ":" << std::setw(2) << std::setfill('0') <<  (ticket.Dock_Info->getMinutes_In())<<"\n";
    os << "Time Out: " << std::setw(2) << std::setfill('0') << ticket.getHour_Out() << ":" << std::setw(2) << std::setfill('0') << ticket.getMinutes_Out() << "\n";
    os << "Credited Minutes: " << ticket.Ship_Info->getCredit() << "\n";
    os << "Extra Minutes: " << (ticket.Hour_Out * 60 + ticket.Minutes_Out) - ((ticket.Dock_Info->getHour_In() * 60) + (ticket.Dock_Info->getMinutes_In())) - (ticket.Ship_Info->getCredit()) << "\n";
    os << "Fine: " << ticket.getFine() << " units\n";
    return os;
}

// Method to calculate and return the fine assessed
double Ticket::getFine() const
{
    double fine;
    // Your fine calculation logic here
    if (((Hour_Out * 60 + Minutes_Out) - ((Dock_Info->Hour_In * 60) + (Dock_Info->Minutes_In)) - (Ship_Info->getCredit())) > 60)
    {
        fine = ((Hour_Out * 60 + Minutes_Out) - ((Dock_Info->Hour_In * 60) + (Dock_Info->Minutes_In)) - (Ship_Info->getCredit())-60) * 500 + 12000;
    }
    else
    {
        fine = ((Hour_Out * 60 + Minutes_Out) - ((Dock_Info->Hour_In * 60) + (Dock_Info->Minutes_In)) - (Ship_Info->getCredit())) * 200;
    }

    return fine; // Placeholder, replace with actual calculation
}

// Accessors
Ship *Ticket::getShip_Info() const { return Ship_Info; }
Dock *Ticket::getDock_Info() const { return Dock_Info; }
int Ticket::getHour_Out() const { return Hour_Out; }
int Ticket::getMinutes_Out() const { return Minutes_Out; }

// Mutators
void Ticket::setShip_Info(Ship *shipInfo) { Ship_Info = shipInfo; }
void Ticket::setDock_Info(Dock *dockInfo) { Dock_Info = dockInfo; }
void Ticket::setHour_Out(int hourOut) { Hour_Out = hourOut; }
void Ticket::setMinutes_Out(int minutesOut) { Minutes_Out = minutesOut; }
