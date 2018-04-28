/******************************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    This program will address Peter's question to the Lord in
*    Matthew 18:21-22
*
*    Estimated:  5 Minutes
*    Actual:     5 Minutes
*
*    Please describe briefly the most difficult part.
*     Nothing.
*
******************************************************************************/

// Libraries
#include <iostream>  // Default Library
#include <iomanip>   // IO Manipulator
using namespace std;


/******************************************************************************
* Print the question
******************************************************************************/
void questionPeter()
{
   cout << "Lord, how oft shall my brother sin against me, and I forgive him?";
   cout << "\nTill seven times?\n";
   return;
}


/******************************************************************************
* Return the answer
******************************************************************************/
int responseLord()
{
   return 7 * 70;
}


/**********************************************************************
* You are not allowed to change MAIN in any way; just implement the two
* functions: questionPeter() and responseLord()
***********************************************************************/
int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << ".\n";

   return 0;
}
