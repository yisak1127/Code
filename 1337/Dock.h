#ifndef DOCK_H
#define DOCK_H

#include <iostream>
#include "Ship.h"

class Dock
{
    friend class Ticket;
private:
    // Member variables
    int Hour_In;
    int Minutes_In;
    Ship *Mooring;

public:
    // Default constructor
    Dock() : Hour_In(0), Minutes_In(0), Mooring(nullptr) {}

    // Overloaded constructor
    Dock(const int hourIn, const int minutesIn, Ship *mooring)
        : Hour_In(hourIn), Minutes_In(minutesIn), Mooring(nullptr)
    {
        // Perform deep copy
        if (mooring != nullptr)
        {
            Mooring = new Ship(*mooring);
        }
    }

    // Copy constructor (deep copy)
    Dock(const Dock &other)
        : Hour_In(other.Hour_In), Minutes_In(other.Minutes_In), Mooring(nullptr)
    {
        // Perform deep copy
        if (other.Mooring != nullptr)
        {
            Mooring = new Ship(*other.Mooring);
        }
    }


    // Accessors
    int getHour_In() const { return Hour_In; }
    int getMinutes_In() const { return Minutes_In; }
    Ship*getMooring() const { return Mooring; }

    // Mutators
    void setHour_In(int hourIn) { Hour_In = hourIn; }
    void setMinutes_In(int minutesIn) { Minutes_In = minutesIn; }

    // Additional method for setting Mooring with deep copy
    void setMooring(Ship *mooring)
    {
        // Clean up existing Mooring
        delete Mooring;

        // Perform deep copy
        if (mooring != nullptr)
        {
            Mooring = new Ship(*mooring);
        }
        else
        {
            Mooring = nullptr;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Dock &dock);
};

#endif
