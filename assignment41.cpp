/******************************************************************************
* Program:
*    Assignment 41, Allocating Memory
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    Practice allocate memory based on user input for size and string, then
*    release the memory.
*
*    Estimated:  30 Minutes
*    Actual:     9 Minutes
*
*    Please describe briefly the most difficult part.
*     Capitalization of prompts to pass testbed.
*
******************************************************************************/

// Libraries
#include <iostream>  // I/O Streams (cin, cout)
#include <iomanip>   // IO Manipulator (setw)
#include <fstream>   // File streams (ofstream, ifstream)
#include <cassert>   // Error Handling (assert)
using namespace std;


/******************************************************************************
 * FUNCTION: MAIN
 * Get an integer to allcate memory, put some stuff in it, and then print it.
 *****************************************************************************/
int main()
{
   int num;

   cout << "Number of characters: ";
   cin >> num;
   cin.ignore();

   if (num < 1)
   {
      cout << "Allocation failure!\n";
      return 0;
   }

   num++;

   char * text = new char[num];

   cout << "Enter Text: ";
   cin.getline(text, num);

   cout << "Text: " << text << endl;

   return 0;
}
