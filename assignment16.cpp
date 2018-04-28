/******************************************************************************
* Program:
*    Assignment 16, If statements
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    This program will tell the user their tax bracket based on their income.
*
*    Estimated:  30 Minutes
*    Actual:     10 Minutes
*
*    Please describe briefly the most difficult part.
*     Reading the compile error for accidentally switching the >> direction
*     for the cin statement.
*
******************************************************************************/

// Libraries
#include <iostream>  // Default Library
#include <iomanip>   // IO Manipulator
using namespace std;


/******************************************************************************
 * Return percent taxes due based on income with a fun if ladder.
 * Lower bounds of brackets are caught by preceeding statement.
 *****************************************************************************/
int computeTax(double income)
{
   if (income < 0.0)
   {
      cout << "INCOME LESS THAN ZERO WHAT DO\n";
      cerr << "INCOME LESS THAN ZERO WHAT DO\n";
      return 0;
   }
   else if (income < 15100.0)
   {
      return 10;
   }
   else if (income < 61300.0)
   {
      return 15;
   }
   else if (income < 123700.0)
   {
      return 25;
   }
   else if (income < 188450.0)
   {
      return 28;
   }
   else if (income < 336550.0)
   {
      return 33;
   }
   else
   {
      return 35;
   }
}

/******************************************************************************
 * main will prompt the user for income, then print their respective tax
 * bracket.
 *****************************************************************************/
int main()
{
   // Number output config
   cout.setf(ios::fixed);     // Nix sci notation
   cout.setf(ios::showpoint); // Always have decimal
   cout.precision(2);         // Two decimals for money

   double income;
   cout << "Income: ";
   cin >> income;

   cout << "Your tax bracket is " << computeTax(income) << "%\n";
   return 0;
}
