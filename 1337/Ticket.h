#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include "Ship.h"
#include "Dock.h"
#include "LinkedList.h"

class Ticket {
private:
    // Member variables
    Ship* Ship_Info;
    Dock* Dock_Info;
    int Hour_Out;
    int Minutes_Out;

public:
    // Default constructor
    Ticket();

    // Overloaded constructor
    Ticket(Ship* shipInfo, Dock* dockInfo, int hourOut, int minutesOut);

    // Copy constructor
    Ticket(const Ticket& other);

    // Overloaded << operator
    friend std::ostream& operator<<(std::ostream& os, const Ticket& ticket);

    // Method to calculate and return the fine assessed
    double getFine() const;

    // Accessors
    Ship* getShip_Info() const;
    Dock* getDock_Info() const;
    int getHour_Out() const;
    int getMinutes_Out() const;

    // Mutators
    void setShip_Info(Ship* shipInfo);
    void setDock_Info(Dock* dockInfo);
    void setHour_Out(int hourOut);
    void setMinutes_Out(int minutesOut);
};

#endif
