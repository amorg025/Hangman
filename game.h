/*
 * CSC 210 Programming Assignment #4
 * Author: Alysha Morgan
 * Date: 04/25/22
 *
 * Implementation file: game.h
 *
 * This class specifies the variables and members
 * to run the hangman game logic.
 */

#ifndef GAME_H            // Header Guard
#define GAME_H            // Header Guard

#include <iostream>       // Allow C++ to read input and display output
#include <cstdlib>        // Allow C++ to access general purpose functions
#include <string>         // Allow C++ to store sequences of characters
#include <map>            // Allow C++ to store elements in a mapped fashion

#include "node.h"         // Allow C++ to access "node.h"
#include "linkedList.h"   // Allow C++ to access "linkedList.h"

using namespace std;      // Use C++ standard library

/***** game Class *****/
class game
{
// Declare private data member variables
private:
    // States of the hangman game as an enum
    enum State {START, PLATFORM, HEAD, BODY, LEFT_ARM, RIGHT_ARM, LEFT_LEG, RIGHT_LEG, HUNG};

    // Map container to convert enums to strings
    // Learned this method through these links:
    // https://stackoverflow.com/questions/207976/how-to-easily-map-c-enums-to-strings
    // https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
    map<State, string> MAP;

    // Current state/enum of the hangman game
    State currentState;

    // Linked list to represent the list of letters for the word to guess
    linkedList guessList;

    // Linked list to represent the letters that have already been guessed
    linkedList hangList;

// Declare the constructors and data member functions
public:
    // Default Constructor
    // Description:   game constructor that essentially sets up the first stages
    //                of the game by prompting player one for a word (also giving
    //                (the player to enter quit), converting the enum states of
    //                the game, setting up the linked lists, and storing the
    //                characters of the word in the hangList.
    //
    // Signature:     game default constructor returns no value.
    //
    // Parameters:    There are no parameters.
    //
    // Precondition:  There are no preconditions.
    //
    // Postcondition: Player one has entered a valid word for player two to guess
    //                and the enum states of the game are mapped to strings.
    //
    // Return:        No value is returned.
    game();

    // Description:   print function displays the states, images, and blanks of the game.
    //                This function also shows that player two has lost if they reach the
    //                hung state.
    //
    // Signature:     print returns no value.
    //
    // Parameters:    There are no parameters.
    //
    // Precondition:  The first stages of the game (in game constructor) have been established.
    //
    // Postcondition: The states, images, and blanks of the game are displayed on the console.
    //                And if player two reaches the hung state, the game will inform they have
    //                lost.
    //
    // Return:        No value is returned.
    void print();

    // Description:   play function contains the main logic implementation of the game
    //                by traversing through the hangList and guessList to verify the
    //                correct and incorrect letters entered by player two. This
    //                function also shows that player two has won the game if they
    //                guess all of the correct characters.
    //
    // Signature:     play returns no value.
    //
    // Parameters:    There are no parameters.
    //
    // Precondition:  The first stages of the game (in game constructor) have been established.
    //                The print function is displaying the current states of the game.
    //
    // Postcondition: The characters in hangList and guessList have been read and at this point
    //                player two will either win the game (in this function) or lose the game
    //                (in the print function).
    //
    // Return:        No value is returned.
    void play();
};

 #endif // GAME_H
