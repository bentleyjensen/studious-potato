/******************************************************************************
* Program:
*    Assignment 35, Advanced COnditionals
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    Based on a user-provided number grade, assign a letter and sign (+ or -)
*    to that grade. Use switch cases because they're fancy.
*
*    Estimated:  20 Minutes
*    Actual:     40 Minutes
*
*    Please describe briefly the most difficult part.
*     I had some weird type errors because I didn't understand when I'm using
*     constant strings, character pointers or just a letter.
*
******************************************************************************/

// Libraries
#include <iostream>  // I/O Streams (cin, cout)
#include <iomanip>   // IO Manipulator (setw)
using namespace std;


//Prototypes

void computeGradeLetter(int gradeNum, char fullGrade[3]);
void computeGradeSign(int gradeNum, char fullGrade[3]);


/******************************************************************************
 * FUNCTION: MAIN
 * get the grade, push to assignment functions, and print it all the right way.
 *****************************************************************************/
int main()
{
   // Number output config

   char fullGrade[3] = "**";

   int gradeNum;
   cout << "Enter number grade: ";
   cin >> gradeNum;

   computeGradeSign(gradeNum, fullGrade);
   computeGradeLetter(gradeNum, fullGrade);


   cout << gradeNum << "\% is " << fullGrade[0];

   if (fullGrade[1] != '*')
      cout << fullGrade[1];

   cout << endl;
   return 0;
}

/******************************************************************************
 * FUNCTION: COMPUTE GRADE SIGN
 * calculate appropriate '+', '-', or '*' to grade
 *****************************************************************************/
void computeGradeSign(int gradeNum, char fullGrade[3])
{
   gradeNum %= 10;

   switch (gradeNum)
   {
      case 9:
      case 8:
      case 7:
         fullGrade[1] = '+';
         break;
      case 6:
      case 5:
      case 4:
      case 3:
         fullGrade[1] = '*';
         break;
      case 2:
      case 1:
      case 0:
         fullGrade[1] = '-';
         break;
   }

   // Skip the A's and F's
   if (gradeNum >= 90 || gradeNum < 60)
      return;

   return;
}


/******************************************************************************
 * FUNCTION: COMPUTE GRADE LETTER
 * calculate appropriate letter that corresponds to the number grade provided
 *****************************************************************************/
void computeGradeLetter(int gradeNum, char fullGrade[3])
{
   // Integer division effectively groups into tens
   gradeNum /= 10;

   switch (gradeNum)
   {
      case 10:
      case 9:
         fullGrade[0] = 'A';
         break;
      case 8:
         fullGrade[0] = 'B';
         break;
      case 7:
         fullGrade[0] = 'C';
         break;
      case 6:
         fullGrade[0] = 'D';
         break;
      default:
         fullGrade[0] = 'F';
         break;
   }

   return;
}
