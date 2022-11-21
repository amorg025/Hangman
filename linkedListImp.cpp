/*
 * CSC 210 Programming Assignment #4
 * Author: Alysha Morgan
 * Date: 04/25/22
 *
 * Implementation file: linkedListImp.cpp
 *
 * This file contains the definitions and functions
 * to implement the operations of the class
 * linkedList.h.
 */

#include <iostream>       // Allow C++ to read input and display output
#include <cstdlib>        // Allow C++ to access general purpose functions
#include <string>         // Allow C++ to store sequences of characters

#include "node.h"         // Allow C++ to access "node.h"
#include "linkedList.h"   // Allow C++ to access "linkedList.h"

using namespace std;      // Use C++ standard library

/***** linkedList Default Constructor *****/
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
linkedList::linkedList()
{
    // Initialize pointer to null pointer
    this->head = nullptr;

    // Initialize pointer to null pointer
    this->rear = nullptr;

    // Initialize pointer to null integer
    this->size = 0;
}

/***** linkedList Overloaded Constructor *****/
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
linkedList::linkedList(node* head, node* rear, int size)
{
    // Set pointer to next head* parameter
    this->head = head;

    // Set pointer to next rear* parameter
    this->rear = rear;

    // Set pointer to size integer parameter
    this->size = size;
}

/***** setHead Member Function *****/
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
void linkedList::setHead(node* head)
{
    // Set pointer to head node* parameter
    this->head = head;
}

/***** getHead Member Function *****/
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
node* linkedList::getHead()
{
    // Return head pointer
    return this->head;
}

/***** setRear Member Function *****/
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
void linkedList::setRear(node* rear)
{
    // Set pointer to rear node* parameter
    this->rear = rear;
}

/***** getRear Member Function *****/
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
node* linkedList::getRear()
{
    // Return rear pointer
    return this->rear;
}

/***** setSize Member Function *****/
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
void linkedList::setSize(int size)
{
    // Set pointer to size integer parameter
    this->size = size;
}

/***** getSize Member Function *****/
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
int linkedList::getSize()
{
    // Return size pointer
    return this->size;
}

/***** add Member Function *****/
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
void linkedList::add(node* newNode)
{
    // If the head is a null pointer
    if (head == nullptr)
    {
        // Set head to the newNode
        head = newNode;

        // Set rear to the newNode
        rear = newNode;
    }
    // Else
    else
    {
        // Set the rear pointer to newNode's next node
        rear->setNext(newNode);

        // Set rear to the newNode
        rear = newNode;
    }

    // Increment the size of the linked list
    size++;
}
