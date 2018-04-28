/******************************************************************************
* Program:
*    Assignment 26, Files
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    Retrieve, read, and calculate the average grade from a grades file.
*
*    Estimated:  45 Minutes
*    Actual:     75 Minutes
*
*    Please describe briefly the most difficult part.
*     I used a for loop that really didn't work too well and had to go back to
*     the book and switch to a while loop. I don't know why, but I thought it
*     would be useful to cast the average to an int instead of using
*     cout.precision, and that took a little while to figure out how to get it
*     to pass testBed since my rounding was wonky.
*
******************************************************************************/

// Libraries
#include <iostream>  // IO Streams
#include <iomanip>   // IO Manipulator
#include <fstream>   // File streams
using namespace std;

// Prototypes
void getFileName(char fileName[]);
float readFile(char fileName[]);
void display(float average);

/******************************************************************************
 * Function: MAIN
 * Get the grade file info, push to average calculator, and then push average
 * to display.
 *****************************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.precision(0);

   char fileName[256];
   float average;

   getFileName(fileName);

   average = readFile(fileName);

   if (average == -0.0)
      cout << "Error reading file \"" << fileName << "\"\n";
   else
      display(average);

   return 0;
}


/******************************************************************************
 * Function: GET FILENAME
 * Prompt the user for the filename, return nothing because it acts as though
 * it was passed by reference.
 *****************************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName;
   return;
}

/******************************************************************************
 * Function: READ FILE
 * Walk through the file and retrieve data. Calculate the average using it.
 *****************************************************************************/
float readFile(char fileName[])
{
   float maxReads = 10.0;
   int readCount = 0;

   float average = 0;
   int grade;

   ifstream fin(fileName);

   while (fin >> grade)
   {
      average += grade;
      readCount++;
   }

   fin.close();

   if (readCount != maxReads || !fin.fail())
      return -0.0;
   else
      return average / maxReads;
}

/******************************************************************************
 * Function: DISPLAY
 * Print the average grade to the console.
 *****************************************************************************/
void display(float average)
{
   cout << "Average Grade: " << average << "%\n";
}
