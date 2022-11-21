/*
 * CSC 210 Programming Assignment #4
 * Main file: main.cpp
 * Implementation file(s): node.h, linkedList.h, game.h
 * Header file(s): nodeImp.cpp, linkedListImp.cpp, gameImp.cpp
 * Author: Alysha Morgan
 * Date: 04/25/22
 *
 * Input: Requests player one to enter a word, and requests player two
 * to guess player one's word through a game of hangman.
 *
 * Output: Displays the states of the game (PLATORM, HEAD, BODY, LEFT_ARM,
 * RIGHT_ARM, LEFT_LEG, RIGHT_LEG, and HUNG) total amount of guesses,
 * wins, and losses.
 *
 * Description: A program that simulates a game of hangman through
 * the use of classes. The game will require one player to enter a
 * string and another player to guess the string that was entered
 * by the first player. The second player will then have 8 guesses
 * to guess the correct word. The game will end when one of the
 * players enters "quit" as the input.
 */

#include <iostream>       // Allow C++ to read input and display output
#include <cstdlib>        // Allow C++ to access general purpose functions
#include <string>         // Allow C++ to store sequences of characters

#include "game.h"         // Allow C++ to access "game.h"
#include "node.h"         // Allow C++ to access "node.h"
#include "linkedList.h"   // Allow C++ to access "linkedList.h"

using namespace std;      // Use C++ standard library

/***** Main Function *****/
int main()
{
    // Declare local variable
    char userChoice;          // Character (Y or N) read from user to continue or break hangman game

    // While true
    // (Running the program until there is a break or exit in the block)
    while (true)
    {
        // Testing the following block of code for errors
        try
        {
            // Create and set game object g to game member function/constructor
            game g = game();

            // Call the play data member function to activate the game
            g.play();

            // Line of space
            cout << endl;

            // Prompt the user if they would like to play hangman again
            cout << "Do you want to play again (Y or N): " << endl;
            cin >> userChoice;

            // Set character to uppercase
            userChoice = toupper(userChoice);

            // If the user entered Y (Yes)
            if (userChoice == 'Y')
            {
                // Clear the screen
                system("cls");

                // Run the game again
                continue;
            }
            // Else if the user entered N (No)
            else if (userChoice == 'N')
            {
                // Clear the screen
                system("cls");

                // Display a salutation
                cout << "Ok! Goodbye." << endl;

                // End program
                break;
            }
        }
        // If an error appears in the try block, catch the exception message
        // "Invalid State" from gameImp.cpp (view game default constructor)
        catch (const char *a)
        {
            // Inform player one that their input was invalid
            cout << "Error! You need to enter a valid string/character." << endl << endl;

            // Clear the istream fail state
            cin.clear();

            // Remove left over characters in istream
            cin.ignore(100, '\n');

            // Break the iteration when player one inputs a valid string
            continue;
        }
    }

    // End program
    return 0;
}
