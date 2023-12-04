#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Ship.h" // Assuming you have a Ship class

class LinkedList
{
private:
    
    // Member variables
    Ship *Head;

public:
    // Default constructor
    LinkedList();

    // Overloaded constructor
    LinkedList(Ship *ship);


    // Overloaded += operator
    LinkedList &operator+=(Ship *ship);

    // Overloaded -- operator (prefix notation)
    Ship *operator--();

    // Accessor
    Ship *getHead() const { return Head; }
};

#endif
