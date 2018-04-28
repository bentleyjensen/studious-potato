/******************************************************************************
* Program:
*    Project 04, Monthly Budget
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    This monthly budget program will take expected and actual income and
*    expenses and will perform calculations before it outputs the difference.
*
*    Estimated:  30 Minutes
*    Actual:     30 Minutes
*
*    Please describe briefly the most difficult part.
*     following the diffent numbers down the if ladder. I kept switching them.
*
******************************************************************************/

// Libraries
#include <iostream>  // Default Library
#include <iomanip>   // IO Manipulator
using namespace std;


// BEGIN FUNCTION DEFINITIONS //


/******************************************************************************
 * PROMPT INCOME
 * Prompt for income
 *****************************************************************************/
double promptIncome()
{

   double income;

   cout << "\tYour monthly income: ";
   cin >> income;

   return income;
}


/******************************************************************************
 * PROMPT BUD LIVING
 * Prompt for budgeted living expenses
 *****************************************************************************/
double promptBudLiving()
{

   double budLiving;;

   cout << "\tYour budgeted living expenses: ";
   cin >> budLiving;


   return budLiving;
}


/******************************************************************************
 * PROMPT ACT LIVING
 * Prompt for actual living expenses
 *****************************************************************************/
double promptActLiving()
{

   double actLiving;

   cout << "\tYour actual living expenses: ";
   cin >> actLiving;

   return actLiving;
}


/******************************************************************************
 * CALCULATE TAX
 * Calculate tax based on income
 * Lower bounds of brackets caught by previous statement
 *****************************************************************************/
double calcTax(double mIncome)
{

   double yIncome = mIncome * 12;
   double yTax;;

   if (yIncome < 0.0)
   {
      cerr << "INCOME LESS THAN ZERO WHAT DO\n";
      return 0;
   }
   else if (yIncome < 15100.0)
   {
      yTax = yIncome * 0.10;
   }
   else if (yIncome < 61300.0)
   {
      yTax = 1510.0 + ((yIncome - 15100) * 0.15);
   }
   else if (yIncome < 123700.0)
   {
      yTax = 8440.0 + ((yIncome - 61300) * 0.25);
   }
   else if (yIncome < 188450.0)
   {
      yTax = 24040.0 + ((yIncome - 123700) * 0.28);
   }
   else if (yIncome < 336550.0)
   {
      yTax = 42170.0 + ((yIncome - 188450) * 0.33);
   }
   else
   {
      yTax = 91043.0 + ((yIncome - 336550) * 0.35);
   }

   double mTax = yTax / 12.0;
   return mTax;
}


/******************************************************************************
 * PROMPT TAX
 * Prompt for taxes withheld
 *****************************************************************************/
double promptTax()
{

   double taxes;

   cout << "\tYour actual taxes withheld: ";
   cin >> taxes;

   return taxes;
}


/******************************************************************************
 * CALCULATE TITHING
 * Calculate minimum to qualify as a full tithe payer (used as budget value)
 *****************************************************************************/
double calcTithe(double income)
{
   return income * 0.1;
}


/******************************************************************************
 * PROMPT TITHING
 * Prompt for tithes offered
 *****************************************************************************/
double promptTithing()
{

   double tithing;
   
   cout << "\tYour actual tithe offerings: ";
   cin >> tithing;

   return tithing;
}


/******************************************************************************
 * CALCULATE OTHER
 * Income minus budgeted items is budgeted other
 *****************************************************************************/
double calcOther (double income, double budLiving,
                  double budTax, double budTithing)
{
   return income - budLiving - budTax - budTithing;
}


/******************************************************************************
 * PROMPT OTHER
 * Prompt for other expenses
 *****************************************************************************/
double promptOther()
{

   double other;

   cout << "\tYour actual other expenses: ";
   cin >> other;

   return other;
}


/******************************************************************************
 * BUDGET DIFFERENCE
 * Calculate if you've budgeted below your income
 * This will continue to return zero until project 04
 *****************************************************************************/
double calcBudDiff(double income, double budLiving, double budTax,
                   double budTithing, double budOther)
{
   double calc = income - budLiving - budTax - budTithing - budOther;

   // Fix negative zero
   double diff = ((calc == (-0.00)) ? calc : 0.00);

   return diff;
}


/******************************************************************************
 * ACTUAL DIFFERENCE
 * Calculate if you've spent more than your income
 *****************************************************************************/
double calcActDiff(double income, double actLiving, double actTax,
                   double actTithing, double actOther)
{

   return income - actLiving - actTax - actTithing - actOther;
}


/******************************************************************************
 * PRINT
 * Print like a BOSS.
 *****************************************************************************/
void print(double income, double budTax, double actTax, double budTithing,
           double actTithing, double budLiving, double actLiving,
           double budOther, double actOther, double budDiff, double actDiff)
{

   cout << "\nThe following is a report on your monthly expenses\n";
   cout << "\tItem                  Budget          Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome          $" << setw(11) << income;
   cout << "    $" << setw(11) << income << endl;
   cout << "\tTaxes           $" << setw(11) << budTax;
   cout << "    $" << setw(11) << actTax << endl;
   cout << "\tTithing         $" << setw(11) << budTithing;
   cout << "    $" << setw(11) << actTithing << endl;
   cout << "\tLiving          $" << setw(11) << budLiving;
   cout << "    $" << setw(11) << actLiving << endl;
   cout << "\tOther           $" << setw(11) << budOther;
   cout << "    $" << setw(11) << actOther << endl;
   cout << "\t=============== =============== ===============\n";
   cout << "\tDifference      $" << setw(11) << budDiff;
   cout << "    $" << setw(11) << actDiff << endl;
}


// MAIN FUNCTION //


/******************************************************************************
 * MAIN
 * Make the prompt calls, then the calc calls, then the print. Call it a day.
 *****************************************************************************/
int main()
{
   // Number output config
   cout.setf(ios::fixed);     // Nix sci notation
   cout.setf(ios::showpoint); // Always have decimal
   cout.precision(2);         // Two decimals for money

   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";

   // COME ON! DOUBLE TIME NOW!
   double income = promptIncome();
   double budLiving = promptBudLiving();
   double actLiving = promptActLiving();
   double actTax = promptTax();
   double actTithing = promptTithing();
   double actOther = promptOther();
   double budTithing = calcTithe(income);
   double budTax = calcTax(income);
   double budOther = calcOther(income, budTax, budTithing, budLiving);
   double budDiff = calcBudDiff(income, budLiving, budTax,
                    budTithing, budOther);
   double actDiff = calcActDiff(income, actLiving, actTax,
                    actTithing, actOther);

   print(income, budTax, actTax, budTithing, actTithing, budLiving, actLiving,
         budOther, actOther, budDiff, actDiff);
}
