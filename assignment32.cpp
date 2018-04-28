/******************************************************************************
* Program:
*    Assignment 32, Strings
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    Take a single letter and a text from the user, use a loop to find the
*    number of matching letters in it, and print it to the user.
*
*    Estimated:  10 Minutes
*    Actual:     15 Minutes
*
*    Please describe briefly the most difficult part.
*     I forgot to use cin.ignore and it took me a few minutes to figure out why
*     testbed was failing.
*
******************************************************************************/

// Libraries
#include <iostream>  // I/O Streams (cin, cout)
#include <cctype>    // Types Library
#include <iomanip>   // IO Manipulator (setw)
using namespace std;


// Prototypes
int countLetters(char letter[2], char string[256]);


/******************************************************************************
 * FUNCTION: MAIN
 * prompt the user, delegate tasks, display to user
 *****************************************************************************/
int main()
{

   char letter[2];
   char string[256];

   cout << "Enter a letter: ";
   cin >> letter;
   cout << "Enter text: ";
   cin.ignore();
   cin.getline(string, 256);

   int numLetters = countLetters(letter, string);

   cout << "Number of \'" << letter << "\'s: " << numLetters << endl;

   return 0;
}


/******************************************************************************
 * FUNCTION: COUNT LETTERS
 * search by walking through a string and return number of matching letters
 *****************************************************************************/
int countLetters(char letter[2], char string[256])
{
   int counter = 0;
   for (int i = 0; string[i]; i++)
      if (string[i] == letter[0])
         counter++;

   return counter;
}
