/******************************************************************************
* Program:
*    Assignment 13, Temperature Conversion
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary: 
*    Enter a brief description of your program here!  
*
*    Estimated:  10 Minutes
*    Actual:     10 Minutes
*
*    Please describe briefly the most difficult part.
*     I was converting the celsius to integer because it was printing an int
*     and it made rounding weird. Once I made it a float, it worked.
*     
******************************************************************************/

// Libraries
#include <iostream>  // Default Library
#include <iomanip>   // IO Manipulator
using namespace std;




/******************************************************************************
 * Main() will take fahrenheit and print celsius.
 * 
 *****************************************************************************/
int main()
{
   // Number output config
   cout.setf(ios::fixed);     // Nix sci notation
   cout.precision(0);         // Two decimals for money

   float farDeg;
   float celDeg;

   // Prompt for Fahrenheit
   cout << "Please enter Fahrenheit degrees: ";
   cin >> farDeg;

   celDeg = (5.0/9.0) * (farDeg - 32.0);

   cout << "Celsius: " << celDeg << endl;

   return 0;
}
