/******************************************************************************
* Program:
*    Assignment 11, Output
*    Sister Hansen, CS124
* Author:
*    Sterling Jensen
* Summary: 
*    Print a monthly budget to the screen with columns and right-aligned 
*    numbers.
*
*    Estimated:  30 minutes
*    Actual:     30 minutes
*   
*    Most difficult part:
*       Realizing I was using integers and that was why my decimals weren't 
*       showing up.
******************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/******************************************************************************
 * My main() man here will do all of the printing and columning and right
 * aligning by himself.
 *****************************************************************************/
int main()
{
   // Money output config
   cout.setf(ios::fixed);     // Nix sci notation
   cout.setf(ios::showpoint); // Always have decimal
   cout.precision(2);         // Two decimals for money

   // Actual Output
   cout << "\tItem           Projected\n";
   cout << "\t=============  ==========\n";
   cout << "\tIncome         $" << setw(9) << 1000.0 << endl;
   cout << "\tTaxes          $" << setw(9) << 100.0  << endl;
   cout << "\tTithing        $" << setw(9) << 100.0  << endl;
   cout << "\tLiving         $" << setw(9) << 650.0  << endl;
   cout << "\tOther          $" << setw(9) << 90.0   << endl;
   cout << "\t=============  ==========\n";
   cout << "\tDelta          $" << setw(9) << 60.0 << endl;

   // Get outta here!
   return 0;
}
