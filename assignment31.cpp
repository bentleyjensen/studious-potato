/******************************************************************************
* Program:
*    Assignment 31, Array Design
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    Get 10 grades from the user, put them in an array and print the average
*
*    Estimated:  10 Minutes
*    Actual:      5 Minutes
*
*    Please describe briefly the most difficult part.
*     Realizing that I had to track how many grades I skipped so I could adjust
*     the denominator for calculating the average
*
*
*
******************************************************************************/

// Libraries
#include <iostream>  // I/O Streams (cin, cout)
using namespace std;

// Prototypes
void getGrades(int grades[]);
int averageGrades(int grades[]);


/******************************************************************************
 * Function: MAIN
 * Hold the array variable and pass it to other functions
 *****************************************************************************/
int main()
{
   cout.precision(0);

   int grades[10];

   getGrades(grades);
   int average = averageGrades(grades);
   if (average != -1)
      cout << "Average Grade: " << average << "%\n";
   else
      cout << "Average Grade: ---%\n";
   return 0;
}


/******************************************************************************
 * Function: GET GRADES
 * Prompt for all 10 grades, put them in the array
 *****************************************************************************/
void getGrades(int grades[])
{
   for (int i = 0; i < 10; i++)
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> grades[i];
   }
}


/******************************************************************************
 * Function: AVERAGE GRADES
 * Walk through the array and compute the average of its grades.
 *****************************************************************************/
int averageGrades(int grades[])
{
   int total = 0;
   int arrSize = 10;

   for ( int i = 0; i < 10; i++)
   {
      if (grades[i] != -1)
         total += grades[i];
      else
         arrSize--;
   }
   if (total == 0)
      return -1;
   else
      return total / arrSize;
}
