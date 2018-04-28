/******************************************************************************
* Program:
*    Assignment 25, Loop Design
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    Display the month with a user-defined day offset.
*
*    Estimated:  45 Minutes
*    Actual:     0 Minutes
*
*    Please describe briefly the most difficult part.
*     Trying to get the new line to print at the right time.
*
******************************************************************************/

// Libraries
#include <iostream>  // Default Library
#include <iomanip>   // IO Manipulator
using namespace std;


/******************************************************************************
 * MAIN
 * Do all the things!
 *****************************************************************************/
int main()
{

   // Number of days in the month
   int numDays;

   // Day of week numbers start on
   int offset;

   cout << "Number of days: ";
   cin >> numDays;
   cout << "Offset: ";
   cin >> offset;


   // Print header
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   // Make sunday print no
   if (offset == 6)
   {
      offset = -1;
   }

   // Day of week tracker
   int dow = 0;

   // Walk through the days of the month
   // Use -offset to print blanks as we walk up to 0, then print numbers
   // Sunday == -1, dom == 1, will print no blanks
   for (int dom = -offset; dom <= numDays; dom++)
   {
      if (dom <= 0)
      {
         // Filler blanks for offset
         cout << "    ";
      }
      else
      {
         // Print actual value if above 0;
         cout << setw(4) << dom;
      }

      // We printed a day, so advance the day of the week
      dow++;

      // Print newline after Saturday
      if (dow % 7 == 0)
      {
         cout << endl;
      }

      // Print a newline on the last day if we didn't already
      else if (dom == numDays)
      {
         cout << endl;
      }
   }


   return 0;
}
