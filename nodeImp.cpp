/*
 * CSC 210 Programming Assignment #4
 * Author: Alysha Morgan
 * Date: 04/25/22
 *
 * Implementation file: nodeImp.cpp
 *
 * This file contains the definitions and functions
 * to implement the operations of the class
 * node.h.
 */

#include <iostream>       // Allow C++ to read input and display output
#include <cstdlib>        // Allow C++ to access general purpose functions
#include <string>         // Allow C++ to store sequences of characters

#include "node.h"         // Allow C++ to access "node.h"

using namespace std;      // Use C++ standard library

/***** node Default Constructor *****/
// Description:   Initializes all pointers (pointing to private data members) to null values.
//
// Signature:     node default constructor returns no value.
//
// Parameters:    There are no parameters.
//
// Precondition:  There are no preconditions.
//
// Postcondition: All pointers have been initialized to null values.
//
// Return:        No value is returned.
node::node()
{
    // Initialize pointer to null character
    this->letter = ' ';

    // Initialize pointer to null boolean
    this->showBlank = NULL;

    // Initialize pointer to null pointer
    this->next = nullptr;
}

/***** node Overloaded Constructor *****/
// Description:   Initializes all private variables of the node class to this pointers.
//
// Signature:     node overloaded constructor returns no value; it takes
//                a character parameter, a boolean parameter,
//                and a node* parameter as input.
//
// Parameters:    The character variable contains a letter of a string.
//                The boolean variable contains a value of true or false.
//                The node variable points to the next or following node.
//
// Precondition:  All this pointers have been initialized in the default constructor.
//
// Postcondition: All variables are set to their respective this pointers.
//
// Return:        No value is returned.
node::node(char letter, bool showBlank, node* next)
{
    // Set pointer to letter character parameter
    this->letter = letter;

    // Set pointer to showBlank boolean parameter
    this->showBlank = showBlank;

    // Set pointer to next node* parameter
    this->next = next;
}

/***** setLetter Member Function *****/
// Description:   Member to set a letter/character.
//
// Signature:     setLetter returns no value; it takes a character parameter as input.
//
// Parameters:    The character variable contains a letter from a string.
//
// Precondition:  letter contains a valid character.
//
// Postcondition: Set pointer to letter character parameter.
//
// Return:        No value is returned.
void node::setLetter(char letter)
{
    // Set pointer to letter character parameter in uppercase
    this->letter = toupper(letter);
}

/***** getLetter Member Function *****/
// Description:   Member to get a letter's number place in an array. Returns this letter pointer.
//
// Signature:     getLetter returns a pointer to a integer object.
//
// Parameters:    There are no parameters.
//
// Precondition:  There are no preconditions.
//
// Postcondition: A valid pointer is returned.
//
// Return:        Return this->letter.
int node::getLetter()
{
    // Return letter pointer
    return this->letter;
}

/***** setShowBlank Member Function *****/
// Description:   Member to set a boolean (this will determine if a blank is shown on the screen).
//
// Signature:     setShowBlank returns no value; it takes a boolean parameter as input.
//
// Parameters:    The boolean variable contains a value of true or false.
//
// Precondition:  showBlank contains a valid boolean.
//
// Postcondition: Set pointer to showBlank boolean parameter.
//
// Return:        No value is returned.
void node::setShowBlank(bool showBlank)
{
    // Set pointer to showBlank boolean parameter
    this->showBlank = showBlank;
}

/***** getShowBlank Member Function *****/
// Description:   Member to get the current status of a blank. Returns this showBlank pointer.
//
// Signature:     getShowBlank returns a pointer to a boolean parameter.
//
// Parameters:    There are no parameters.
//
// Precondition:  There are no preconditions.
//
// Postcondition: A valid pointer is returned.
//
// Return:        Return this->showBlank.
bool node::getShowBlank()
{
    // Return showBlank pointer
    return this->showBlank;
}

/***** setNext Member Function *****/
// Description:   Member to set a pointer to its next node.
//
// Signature:     setNext returns no value; it takes a node* parameter as input.
//
// Parameters:    The node variable points to the next or following node.
//
// Precondition:  next is pointing towards a valid value.
//
// Postcondition: Set pointer to next node* parameter.
//
// Return:        No value is returned.
void node::setNext(node* next)
{
    // Set pointer to next node* parameter
    this->next = next;
}

/***** getNext Member Function *****/
// Description:   Member to get the position of the node next to the pointer.
//                Returns this next pointer.
//
// Signature:     getNext returns a pointer to its next node.
//
// Parameters:    There are no parameters.
//
// Precondition:  There are no preconditions.
//
// Postcondition: A valid pointer is returned.
//
// Return:        Return this->next.
node* node::getNext()
{
    // Return next pointer
    return this->next;
}
