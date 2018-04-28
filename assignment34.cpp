/******************************************************************************
* Program:
*    Assignment 34, Pointer Arithmetic
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    Take a single letter and a text from the user. Using a loop and advancing
*    a pointer address, find the number of matching letters in the given string
*    and print it to the user.
*
*    Estimated:  10 Minutes
*    Actual:     5 Minutes
*
*    Please describe briefly the most difficult part.
*     I had to go back through the slides to figure out what I was supposed to
*     be doing, I wasn't sure which part was supposed to be pointers.
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
   for (char * i = string; *i; i++)
      if (*i == letter[0])
         counter++;

   return counter;
}
