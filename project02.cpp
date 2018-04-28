/******************************************************************************
* Program:
*    Project 02, Monthly Budget
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    This monthly budget program will take expected and actual income and
*    expenses and will perform calculations before it outputs the difference.
*
*    Estimated:  30 Minutes
*    Actual:     70 Minutes
*
*    Please describe briefly the most difficult part.
*        It took me 20 minutes to figure out the spaces because the tabs placed
*     everything perfectly when I ran it mayself, but stupid testbed wanted me
*     to use a million spaces to get it to pass. The printouts for "expected"
*     didn't have proper alignment for what it wanted, so I spent a lot of time
*     guessing.
*        I also had to forget about to 80 limit on lines so I could understand
*     each line I was printing, then edited it once it passed testbed so it
*     would pass the style checker.
*
******************************************************************************/

// Libraries
#include <iostream>  // Default Library
#include <iomanip>   // IO Manipulator
using namespace std;




/******************************************************************************
 * main() will prompt for all of the amounts in the budget, then print them
 * really pretty like.
 *****************************************************************************/
int main()
{
   // Number output config
   cout.setf(ios::fixed);     // Nix sci notation
   cout.setf(ios::showpoint); // Always have decimal
   cout.precision(2);         // Two decimals for money

   // Declare ALL THE FLOATS! ROOT BEER FLOATS  D
   float income,
         budLiving,
         actLiving,
         taxes,
         tithing,
         other;

   // Prompt for ALL THE MONEYS
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";
   cout << "\tYour monthly income: ";
   cin >> income;
   cout << "\tYour budgeted living expenses: ";
   cin >> budLiving;
   cout << "\tYour actual living expenses: ";
   cin >> actLiving;
   cout << "\tYour actual taxes withheld: ";
   cin >> taxes;
   cout << "\tYour actual tithe offerings: ";
   cin >> tithing;
   cout << "\tYour actual other expenses: ";
   cin >> other;

   //Print LIKE A BOSS.
   cout << "\nThe following is a report on your monthly expenses\n";
   cout << "\tItem                  Budget          Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome          $" << setw(11) << income    << "    $"
        << setw(11) << income << endl;
   cout << "\tTaxes           $" << setw(11) << 0.0       << "    $"
        << setw(11) << taxes << endl;
   cout << "\tTithing         $" << setw(11) << 0.0       << "    $"
        << setw(11) << tithing << endl;
   cout << "\tLiving          $" << setw(11) << budLiving << "    $"
        << setw(11) << actLiving << endl;
   cout << "\tOther           $" << setw(11) << 0.0       << "    $" 
        << setw(11) << other << endl;
   cout << "\t=============== =============== ===============\n";
   cout << "\tDifference      $" << setw(11) << 0.0       << "    $" 
        << setw(11) << 0.0 << endl;

   return 0;
}
