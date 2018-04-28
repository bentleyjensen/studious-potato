/******************************************************************************
* Program:
*    Assignment 43, Command Line
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    Convert feet into meters from command line arguments
*
*    Estimated:  20 Minutes
*    Actual:     15 Minutes
*
*    Please describe briefly the most difficult part.
*     I didn't realize that I ought to print a decimal for the feet part of the
*     cout statement so I added brackets to the for loop and made a variable.
*
******************************************************************************/

// Libraries
#include <iostream>  // I/O Streams (cin, cout)
#include <iomanip>   // IO Manipulator (setw)
#include <fstream>   // File streams (ofstream, ifstream)
#include <string>    // String Class
#include <cassert>   // Error Handling (assert)
#include <cstdlib>   // Standard Library (atof)
using namespace std;


/******************************************************************************
 * FUNCTION: MAIN
 * Take command line arguments as feet and print meters
 *****************************************************************************/
int main(int argc, char **argv)
{
   // Number output config
   cout.setf(ios::fixed);     // Nix sci notation
   cout.precision(1);         // Show one decimal digit
   cout.setf(ios::showpoint); // Always show decimal
   const float CONVERT = 0.3048; // Conversion factor (feet ==> meters)


   for (int i = 1; i < argc; i++)
   {
      float feet = atof(argv[i]);
      cout << feet << " feet is " << feet *  CONVERT << " meters\n";
   }

   return 0;
}
