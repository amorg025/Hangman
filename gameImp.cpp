/*
 * CSC 210 Programming Assignment #4
 * Author: Alysha Morgan
 * Date: 04/25/22
 *
 * Implementation file: gameImp.cpp
 *
 * This file contains the function to implement
 * the operations of the class game.h.
 */

#include <iostream>       // Allow C++ to read input and display output
#include <unistd.h>       // Allow C++ to access the POSIX operating system API
#include <cstdlib>        // Allow C++ to access general purpose functions
#include <string>         // Allow C++ to store sequences of characters
#include <map>            // Allow C++ to store elements in a mapped fashion

#include "game.h"         // Allow C++ to access "game.h"
#include "node.h"         // Allow C++ to access "node.h"
#include "linkedList.h"   // Allow C++ to access "linkedList.h"

using namespace std;      // Use C++ standard library

/***** game Default Constructor *****/
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
game::game()
{
    // Declare local variables and pointers
    string playerOneWord;                   // Player one's word for player two to guess or quit
    node* temp;                             // Temp node used to add to hangList

    // Prompt player one to enter a word for the game or quit if they wish to exit
    cout << "Player One, please enter a word for the game (type quit if you wish to exit): " << endl;
    cin >> playerOneWord;

    // Loop through the length of player one's word
    for (long unsigned int i = 0; i < playerOneWord.length(); i++)
    {
        // Convert all of the characters in player one's word to uppercase
        playerOneWord[i] = toupper(playerOneWord[i]);
    }

    // If player one entered quit
    if (playerOneWord == "QUIT")
    {
        // Clear the screen
        system("cls");

        // Display a salutation
        cout << "Ok! Goodbye." << endl;

        // End program
        exit(1);
    }

    // Clear the screen
    system("cls");

    // Map each of the following enum states to their respective strings
    MAP[START] = "START";
    MAP[PLATFORM] = "PLATFORM";
    MAP[HEAD] = "HEAD";
    MAP[BODY] = "BODY";
    MAP[LEFT_ARM] = "LEFT ARM";
    MAP[RIGHT_ARM] = "RIGHT ARM";
    MAP[LEFT_LEG] = "LEFT LEG";
    MAP[RIGHT_LEG] = "RIGHT LEG";
    MAP[HUNG] = "HUNG";

    // Set currentState pointer to start enum state since it is the beginning of the game
    this->currentState = START;

    // Set guessList and hangList to linkedList function
    // (Setting up the pointers for both lists)
    guessList = linkedList();
    hangList = linkedList();

    // Loop through the size of player one's word
    for (long unsigned int i = 0; i < playerOneWord.size(); i++)
    {
        // If the characters in player one's are not alphabetical characters
        if (!isalpha(playerOneWord[i]))
        {
            // Throw "Invalid State" for the main function to catch and verify
            throw "Invalid State";
        }

        // Create a new node by setting temp to node constructor
        temp = new node(playerOneWord[i], false, nullptr);

        // Add temp node to hangList
        hangList.add(temp);
    }
}

/***** print Member Function *****/
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
void game::print()
{
    // Declare local pointer
    node* head;              // Pointer to the head (first) node in the linked list

    // Clear the screen
    system("cls");

    // Display the current state/enum of the game
    cout << "CURRENT STATE: " << MAP[currentState] << endl << endl;

    // Set head node to the head of hangList
    head = (node*)hangList.getHead();

    // While the head node is not a null pointer print the blank lines for each character
    while (head != nullptr)
    {
        // Display white characters
        cout << " ";

        // If the head points to a true boolean (pointing to the correct character)
        if (head->getShowBlank())
        {
            // Get each correct letter and convert its decimal to characters
            cout << (char)head->getLetter() << "";
        }
        // Else
        else
        {
            // Display a empty blank
            cout << "_";
        }

        // Set head to head's next node
        head = (node*)head->getNext();
    }

    // Line of space
    cout << endl;

    // If the second player guesses incorrectly for the first time
    // print a image of the platform
    if (currentState == PLATFORM)
    {
        // Update the image
        cout << "       ______  " << endl;
        cout << "       |     | " << endl;
        cout << "       |       " << endl;
        cout << "       |       " << endl;
        cout << "       |       " << endl;
        cout << "       |       " << endl;
        cout << "  _____|______ " << endl;
        cout << " /_____=_____/ " << endl;

    }
    // Else if the second player guesses incorrectly for the second time
    // update the image to add the stick figure's head
    else if (currentState == HEAD)
    {
        // Update the image
        cout << "       ______  " << endl;
        cout << "       |     | " << endl;
        cout << "       |     O " << endl;
        cout << "       |       " << endl;
        cout << "       |       " << endl;
        cout << "       |       " << endl;
        cout << "  _____|______ " << endl;
        cout << " /_____=_____/ " << endl;
    }
    // Else if the second player guesses incorrectly for the third time
    // update the image to add the stick figure's body
    else if (currentState == BODY)
    {
        // Update the image
        cout << "       ______  " << endl;
        cout << "       |     | " << endl;
        cout << "       |     O " << endl;
        cout << "       |     I " << endl;
        cout << "       |     o " << endl;
        cout << "       |       " << endl;
        cout << "  _____|______ " << endl;
        cout << " /_____=_____/ " << endl;
    }
    // Else if the second player guesses incorrectly for the fourth time
    // update the image to add the stick figure's left arm
    else if (currentState == LEFT_ARM)
    {
        // Update the image
        cout << "       ______  " << endl;
        cout << "       |     | " << endl;
        cout << "       |     O " << endl;
        cout << "       |    \\I" << endl;
        cout << "       |     o " << endl;
        cout << "       |       " << endl;
        cout << "  _____|______ " << endl;
        cout << " /_____=_____/ " << endl;
    }
    // Else if the second player guesses incorrectly for the fifth time
    // update the image to add the stick figure's right arm
    else if (currentState == RIGHT_ARM)
    {
        // Update the image
        cout << "       ______  " << endl;
        cout << "       |     | " << endl;
        cout << "       |     O " << endl;
        cout << "       |    \\I/" << endl;
        cout << "       |     o " << endl;
        cout << "       |       " << endl;
        cout << "  _____|______ " << endl;
        cout << " /_____=_____/ " << endl;

    }
    // Else if the second player guesses incorrectly for the sixth time
    // update the image to add the stick figure's left leg
    else if (currentState == LEFT_LEG)
    {
        // Update the image
        cout << "       ______  " << endl;
        cout << "       |     | " << endl;
        cout << "       |     O " << endl;
        cout << "       |    \\I/" << endl;
        cout << "       |     o " << endl;
        cout << "       |    /  " << endl;
        cout << "  _____|______ " << endl;
        cout << " /_____=_____/ " << endl;
    }
    // Else if the second player guesses incorrectly for the seventh time
    // update the image to add the stick figure's right leg
    else if (currentState == RIGHT_LEG)
    {
        // Update the image
        cout << "       ______  " << endl;
        cout << "       |     | " << endl;
        cout << "       |     O " << endl;
        cout << "       |    \\I/" << endl;
        cout << "       |     o " << endl;
        cout << "       |    / \\" << endl;
        cout << "  _____|______ " << endl;
        cout << " /_____=_____/ " << endl;
    }
    // Else if the second player guesses incorrectly for the eighth time
    // update the image to show the entirety of the stick figure hung on the platform
    else if (currentState == HUNG)
    {
        // Update the image
        cout << "       ______  " << endl;
        cout << "       |     | " << endl;
        cout << "       |     O " << endl;
        cout << "       |    \\I/" << endl;
        cout << "       |     o " << endl;
        cout << "       |    / \\" << endl;
        cout << "  _____|______ " << endl;
        cout << " /_____=_____/ " << endl;

        // Line of space
        cout << endl;

        // Inform player two that they have lost the hangman game
        cout << "PLAYER TWO LOSES!" << endl;

        // End program
        exit(1);
    }

    // Line of space
    cout << endl;

    // Prompt player two to enter a valid guess for player one's word
    cout << "Player Two, please enter one alphabetical letter (type quit if you wish to exit) " << endl;

    // Display the number of attempts player two has to guess the correct word
    cout << "" << 8 - (int)currentState << " guesses left: " << endl;
}

/***** play Member Function *****/
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
void game::play()
{
    // Declare local variables and pointers
    string playerTwoGuess;          // Player two's guess (as one character) or quit
    char character;                 // Character pulled from the string playerTwoGuess
    bool exists;                    // Boolean to determine if player two's guess is in guessList
    int matchCount;                 // Match count to check if a correct match/blank has been found
    int charCount;                  // Character count to check if the entire correct string is guessed
    node* head;                     // Pointer to the head (first) node in the linked list
    node* guessHead;                // Pointer to the head (first) node in the guessList

    // Do-while (true)
    // (Running the game until there is a break in the block)
    do
    {
        // Call the print function to display the states, blanks, and images of the game
        print();

        // Testing the following block of code for errors
        try
        {
            // Allow player two to enter their guess (character or the string, quit)
            cin >> playerTwoGuess;

            // Loop through the length of player two's character/word (quit if it's a word)
            for (long unsigned int i = 0; i < playerTwoGuess.length(); i++)
            {
                // Convert the character or characters in player two's guess to uppercase
                playerTwoGuess[i] = toupper(playerTwoGuess[i]);
            }

            // If player two entered quit
            if (playerTwoGuess == "QUIT")
            {
                // Clear the screen
                system("cls");

                // Display a salutation
                cout << "Ok! Goodbye." << endl;

                // End program
                exit(1);
            }
            // Else player two entered a guess other than quit
            else
            {
                // If player two entered a guess that has more than one char or
                // entered a guess that contains non-alphabetical characters
                if (playerTwoGuess.size() > 1 || !isalpha(playerTwoGuess[0]))
                {
                    // Line of space
                    cout << endl;

                    // Debugging purposes
                    // Display an error that player two has entered a invalid guess
                    // cout << "Error! You have entered a invalid guess. Please try again.";

                    // Throw "Invalid State" for the play member function to catch verify
                    // (Continue scrolling down to see the catch for this block)
                    throw "Invalid State";

                    // Debugging purposes
                    // Error message will be displayed for a couple of microseconds
                    // usleep(1000000);
                }
                // Else player two enters a valid guess
                else
                {
                    // Store characters from string playerTwoGuess into a character variable
                    character = (playerTwoGuess[0]);

                    // Set guessHead to the head of the guessList
                    guessHead = guessList.getHead();

                    // Set exists equal to boolean value false
                    exists = false;

                    // While guessHead is not a null pointer
                    while (guessHead != nullptr)
                    {
                        // If player two's input already exists in guessList
                        if (guessHead->getLetter() == character)
                        {
                            // Set boolean exists to true
                            exists = true;

                            // Terminate the block
                            break;
                        }

                        // Set guessHead node to the next node
                        guessHead = guessHead->getNext();
                    }

                    // If player two's input does not exist in guessList
                    if (!exists)
                    {
                        // Use node constructor to add a new node to guessList
                        guessList.add(new node(character, false, nullptr));

                        // Set head node to the head of hangList
                        head = (node*)hangList.getHead();

                        // Initializing counter variables for accurate results
                        matchCount = 0;
                        charCount = 0;

                        // While the head node is not a null pointer
                        // (Setting up the word in response to input characters)
                        while (head != nullptr)
                        {
                            // If the head pointer points to a correct character
                            if (head->getLetter() == character)
                            {
                                // The head pointer is set with a value of true
                                // to assist the print function
                                head->setShowBlank(true);

                                // Increment the matchCount
                                matchCount++;
                            }
                            // If the head pointer gets a value of true
                            if (head->getShowBlank())
                            {
                                // Increment the charCount
                                charCount++;
                            }

                            // Set head to head's next node
                            head = (node*)head->getNext();
                        }

                        // If the matchCount is equal to 0
                        if (matchCount == 0)
                        {
                            // Update the game state since there are no correct matches
                            currentState = State(currentState + 1);
                        }

                        // Debugging purposes
                        // cout << hangList.getSize();
                        // cout << charCount;
                        // cout << playerTwoGuess.size();

                        // If the charCount is equal to the size of the hangList
                        if (charCount == hangList.getSize())
                        {
                            // Call the print to function to display the last correct letter on a blank
                            // (Fixing a bug here for displaying all characters)
                            print();

                            // Line of space
                            cout << endl;

                            // Inform player two that they have won the hangman game
                            cout << "PLAYER TWO WINS!" << endl;

                            // Terminate the block
                            break;
                        }
                    }
                }
            }
        }
        // If an error appears in the try block, catch the exception message
        // "Invalid State" from the code above
        catch (const char *a)
        {
            // player two that their input was invalid
            cout << "Error! You need to enter a valid character." << endl;

            // // Error message will be displayed for a couple of microseconds
            usleep(1000000);

            // Clear the istream fail state
            cin.clear();

            // Remove left over characters in istream
            cin.ignore(100, '\n');
        }
    }
    while (true);
}
