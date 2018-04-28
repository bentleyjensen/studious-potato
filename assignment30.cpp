/******************************************************************************
* Program:
*    Assignment 30, Arrays
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    Get 10 grades from the user, put them in an array and print the average
*
*    Estimated:  15 Minutes
*    Actual:     20 Minutes
*
*    Please describe briefly the most difficult part.
*     I tried to pass the array by reference and got really weird errors. I
*     didn't realize it would work without the reference.
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
   cout << "Average Grade: " << average << "%\n";

   return 0;
}


/******************************************************************************
 * Function: GET GRADES
 * Prompt for all 10 grades, put them in the array
 *****************************************************************************/
void getGrades(int grades[])
{
   for ( int i = 0; i < 10; i++)
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
   for ( int i = 0; i < 10; i++)
   {
      total += grades[i];
   }
   return (int)(total / 10.0);
}
