/***********************************************************************
* Program:
*    Assignment 12, Input and Variables
*    Sister Hansen, CS124
* Author:
*    Sterling Jensen
* Summary: 
*    Take a person's imcome and then puke it back out.
*
*    Estimated:  10 minutes
*    Actual:     3 minutes
*   
*    Most difficult part:
*        I had no difficulty.
************************************************************************/


// Libraries
#include <iostream>  // Default Library
#include <iomanip>   // IO Manipulator
using namespace std;

/**********************************************************************
 * Take the income input and do nothing with it.
 * Just print it.
 ***********************************************************************/
int main()
{
   // Number output config
   cout.setf(ios::fixed);     // Nix sci notation
   cout.setf(ios::showpoint); // Always have decimal
   cout.precision(2);         // Two decimals for money

   float income;
   cout << "\tYour monthly income: ";
   cin >> income;
   cout << "Your income is: $" << setw(9) << income << endl;
   return 0;
}
