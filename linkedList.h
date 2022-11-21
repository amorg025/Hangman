/*
 * CSC 210 Programming Assignment #4
 * Author: Alysha Morgan
 * Date: 04/25/22
 *
 * Implementation file: linkedList.h
 *
 * This class specifies the pointers, variables, and members
 * to manipulate a linked list.
 */

#ifndef LINKEDLIST_H      // Header Guard
#define LINKEDLIST_H      // Header Guard

#include <iostream>       // Allow C++ to read input and display output
#include <cstdlib>        // Allow C++ to access general purpose functions
#include <string>         // Allow C++ to store sequences of characters

#include "node.h"         // Allow C++ to access "node.h"

using namespace std;      // Use C++ standard library

/***** linkedList Class *****/
class linkedList
{
// Declare private data member variables
private:
    // Pointer to the head (first) node in the linked list
    node* head;

    // Pointer to the rear (last) node in the linked list
    node* rear;

    // The total size (amount of characters) in the linked list
    int size;

// Declare the constructors and data member functions
public:
    // Default Constructor
    // Description:   Initializes all pointers (pointing to private data members) to null values.
    //
    // Signature:     linkedList default constructor returns no value.
    //
    // Parameters:    There are no parameters.
    //
    // Precondition:  There are no preconditions.
    //
    // Postcondition: All pointers have been initialized to null values.
    //
    // Return:        No value is returned.
    linkedList();

    // Overloaded Constructor
    // Description:   Initializes all private variables of the node class to this pointers.
    //
    // Signature:     linkedList overloaded constructor returns no value; it takes
    //                two node* parameters and a integer parameter as input.
    //
    // Parameters:    The node variable contains the head or first node.
    //                The node variable contains the rear or last node.
    //                The integer variable contains the size of the linked list.
    //
    // Precondition:  All this pointers have been initialized in the default constructor.
    //
    // Postcondition: All variables are set to their respective this pointers.
    //
    // Return:        No value is returned.
    linkedList(node* head, node* rear, int size);

    // Description:   Member to set a pointer to its head or first node.
    //
    // Signature:     setHead returns no value; it takes a head* parameter as input.
    //
    // Parameters:    The node variable points to the head or first node.
    //
    // Precondition:  head is pointing towards a valid value.
    //
    // Postcondition: Set pointer to head node* parameter.
    //
    // Return:        No value is returned.
    void setHead(node* head);

    // Description:   Member to get the position of the first node. Returns this head pointer.
    //
    // Signature:     getHead returns a pointer to its head or first node.
    //
    // Parameters:    There are no parameters.
    //
    // Precondition:  There are no preconditions.
    //
    // Postcondition: A valid pointer is returned.
    //
    // Return:        Return this->head.
    node* getHead();

    // Description:   Member to set a pointer to its rear or last node.
    //
    // Signature:     setRear returns no value; it takes a rear* parameter as input.
    //
    // Parameters:    The node variable points to the rear or last node.
    //
    // Precondition:  rear is pointing towards a valid value.
    //
    // Postcondition: Set pointer to rear node* parameter.
    //
    // Return:        No value is returned.
    void setRear(node* rear);

    // Description:   Member to get the position of the last node. Returns this rear pointer.
    //
    // Signature:     getRear returns a pointer to its rear or last node.
    //
    // Parameters:    There are no parameters.
    //
    // Precondition:  There are no preconditions.
    //
    // Postcondition: A valid pointer is returned.
    //
    // Return:        Return this->rear.
    node* getRear();

    // Description:   Member to set the size of the linked list.
    //
    // Signature:     setSize returns no value; it takes a integer parameter as input.
    //
    // Parameters:    The integer variable points to the size of the linked list.
    //
    // Precondition:  size contains a valid value.
    //
    // Postcondition: Set pointer to size integer parameter.
    //
    // Return:        No value is returned.
    void setSize(int size);

    // Description:   Member to get the size of the linked list. Returns this size pointer.
    //
    // Signature:     getSize returns a pointer to the size of the linked list.
    //
    // Parameters:    There are no parameters.
    //
    // Precondition:  There are no preconditions.
    //
    // Postcondition: A valid pointer is returned.
    //
    // Return:        Return this->size.
    int getSize();

    // Description:   Member to insert a node into a linked list and increment the size
    //                of the linked list.
    //
    // Signature:     add returns no value; it takes a node* parameter as input.
    //
    // Parameters:    The node variable points to the node to be inserted in the linked list.
    //
    // Precondition:  newNode points to a valid value.
    //
    // Postcondition: newNode is added to the list and the size of the list has been updated.
    //
    // Return:        No value is returned.
    void add(node* newNode);
};

#endif // LINKEDLIST_H
