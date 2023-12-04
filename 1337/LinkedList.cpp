#include "LinkedList.h"
#include "Ship.h"
#include "Dock.h"

// Default constructor
LinkedList::LinkedList() { Head = nullptr; }

// Overloaded constructor
LinkedList::LinkedList(Ship *ship)
{
    if (ship != nullptr)
    {
        Head = new Ship(*ship);
        Ship *current = Head;
        Ship *originalCurrent = ship->Next;

        while (originalCurrent != nullptr)
        {
            current->Next = new Ship(*originalCurrent);
            current = current->Next;
            originalCurrent = originalCurrent->Next;
        }
    }
}

// Overloaded += operator
LinkedList &LinkedList::operator+=(Ship *ship)
{
    if (Head == nullptr)
    {
        Head = ship;
    }
    else
    {
        Ship *current = Head;
        while (current->getNext() != nullptr)
        {
            current = current->getNext();
        }
        current->setNext(ship);
    }
    return *this;
}

// Overloaded -- operator (prefix notation)
Ship* LinkedList::operator--()
{
    if (Head != nullptr)
    {
        Ship* removedShip = Head;
        Head = Head->getNext();
        // Note: Make sure to delete the removed ship if necessary
        // delete removedShip;

        return removedShip;
    }

    return Head;  // Return nullptr if the list is empty
}

std::ostream &operator<<(std::ostream &os, const Ship *ship)
{
    os << "Ship ID: " << ship->getShip_ID() << "\n"
       << "Name: " << ship->getName();
    return os;
}

std::ostream &operator<<(std::ostream &os, const Dock &dock)
{
    os << "Time In: " << dock.getHour_In() << ":" << dock.getMinutes_In();
    return os;
}