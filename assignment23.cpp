/******************************************************************************
* Program:
*    Assignment 23, Loop syntax
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    This program will add all the multiples of a number below 100.
*
*    Estimated:  20 Minutes
*    Actual:     20 Minutes
*
*    Please describe briefly the most difficult part.
*     I was adding the given number to the total instead of to the current
*     multiple and it took me a while to see it. Also, the grammar in the last
*     statement is incorrect and it gave me an error because I fixed it in my
*     program without realizing it. Lol. It should be "is" and
*     not "are". "The sum... is" not "The sum... are".
*
******************************************************************************/

// Libraries
#include <iostream>
using namespace std;

/******************************************************************************
 * MAIN
 * Get a number, find all its multiples under 100, create a total!
 *****************************************************************************/
int main()
{
   // Current multiple
   int count = 0;

   // The number we want multiples of
   int multi;

   // Running total of all multiples
   int run = 0;

   // Get multiplier value from user
   cout << "What multiples are we adding? ";
   cin >> multi;

   // Use count as our validator
   // Stop when current multiple (count) passes 100
   // Add multi to count (move to next multiple)
   for (count; count < 100; count += multi)
   {
      // Add the current multiple to the total
      run += count;
   }

   cout << "The sum of multiples of " << multi << " less than 100 are: ";
   cout << run << endl;

   return 0;
}
