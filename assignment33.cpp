/******************************************************************************
* Program:
*    Assignment 33, Pointers
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    Prompt the user for the balances of two accounts, and use the one with
*    more money to pay for the date, whose costs will also be collected from
*    the user.
*
*    Estimated:  25 Minutes
*    Actual:     35 Minutes
*
*    Please describe briefly the most difficult part.
*     I got a seg fault because I tried to use *account = balFoo and I didn't
*     know how to fix it, so it took a little while before I thought about how
*     pointers work exactly and switched it to account = &balFoo.
*
******************************************************************************/

// Libraries
#include <iostream>  // I/O Streams (cin, cout)
#include <iomanip>   // IO Manipulator (setw)
using namespace std;

// Prototypes
float getBal();
void date(float *pAccount);

/******************************************************************************
 * FUNCTION: MAIN
 * delegate prompts, then calculations, and use pointers
 *****************************************************************************/
int main()
{
   // Number output config
   cout.setf(ios::fixed);     // Nix sci notation
   cout.setf(ios::showpoint); // Always have decimal
   cout.precision(2);         // Two decimals for money

   float * account;
   float balSam;
   float balSue;
   cout << "What is Sam's balance? ";
   cin >> balSam;
   cout << "What is Sue's balance? ";
   cin >> balSue;

   if (balSam > balSue)
      account = &balSam;
   else
      account = &balSue;

   date(account);

   cout << "Sam's balance: $" << balSam << endl;
   cout << "Sue's balance: $" << balSue << endl;

   return 0;
}


/******************************************************************************
 * FUNCTION: DATE
 * Prompt for date expenses, adjust the account given, return void because
 * pointers are "passd by reference"
 *****************************************************************************/
void date(float * pAccount)
{
   float iceCream;
   float dinner;
   float movie;
   cout << "Cost of the date:\n";
   cout << "\tDinner:    ";
   cin >> dinner;
   cout << "\tMovie:     ";
   cin >> movie;
   cout << "\tIce cream: ";
   cin >> iceCream;

   *pAccount -= dinner;
   *pAccount -= iceCream;
   *pAccount -= movie;

   return;
}
