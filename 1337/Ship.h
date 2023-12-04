#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <string>

class Ship
{
    friend class LinkedList;
private:

    // Member variables
    std::string Name;
    std::string Ship_ID;
    int Credit;
    Ship *Next;


public:
    // Default constructor
    Ship() : Name(""), Ship_ID(""), Credit(0), Next(nullptr) {}

    // Overloaded constructor
    Ship(const std::string &name, const std::string &shipID, int credit)
        : Name(name), Ship_ID(shipID), Credit(credit), Next(nullptr) {}

    // Copy constructor (deep copy)
    Ship(const Ship &other)
        : Name(other.Name), Ship_ID(other.Ship_ID), Credit(other.Credit), Next(nullptr)
    {
        // Deep copy for the Next pointer
        if (other.Next != nullptr)
        {
            Next = new Ship(*(other.Next));
        }
    }


    // Accessors
    std::string getName() const { return Name; }
    std::string getShip_ID() const { return Ship_ID; }
    int getCredit() const { return Credit; }
    Ship *getNext() const { return Next; }

    // Mutators
    void setName(const std::string &name) { Name = name; }
    void setShip_ID(const std::string &shipID) { Ship_ID = shipID; }
    void setCredit(int credit) { Credit = credit; }
    void setNext(Ship *next) { Next = next; }

    friend std::ostream &operator<<(std::ostream &os, const Ship *ship);
};

#endif
