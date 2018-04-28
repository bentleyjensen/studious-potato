/******************************************************************************
* Program:
*    Project 07, Calendar
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    Print an accurate calendar based on user provided year and month.
*
*    Estimated:  240 Minutes
*    Actual:     180 Minutes
*
*    Please describe briefly the most difficult part.
*     My offset was being really wonky and it took me the better part of an
*     hour to realize that it was because I was returning 366 days for normal
*     years and 365 for leap years.
*
******************************************************************************/

// Libraries
#include <iostream>  // I/O Streams (cin, cout)
#include <iomanip>   // IO Manipulator (setw)
using namespace std;

// Prototypes
int promptYear();
int promptMonth();
int calcOffset(int year, int month);
int calcYearDays(int year);
int calcMonDays(int year, int month);
bool isLeap(int year);
void display(int year, int month, int offset);
void displayHeader(int year, int month);
void displayTable(int numDays, int offset);

/******************************************************************************
 * Function: MAIN
 * Delegate tasks get the calendar to print
 *****************************************************************************/
int main()
{

   int year;
   int month;
   int offset;

   month = promptMonth();
   year = promptYear();
   offset = calcOffset(year, month);

   display(year, month, offset);

   return 0;
}


// FUNCTION DEFINITIONS //

/******************************************************************************
 * Function: PROMPT YEAR
 * Prompt the user for the year, repeat if invalid.
 *****************************************************************************/
int promptYear()
{
   int year = 0;

   // Accept only years after the Gregorian calendar was adopted
   while ( year < 1752)
   {
      cout << "Enter year: ";
      cin >> year;

      // If the loop will repeat, add the message
      if (1752 >= year)
         cout << "Year must be 1753 or later.\n";
   }

   return year;
}

/******************************************************************************
 * Function: PROMPT MONTH
 * Prompt the user for the month, repeat if invalid.
 *****************************************************************************/
int promptMonth()
{
   int month = -1;

   // Prompt while the month is invalid
   while (month <= 0 || 13 <= month)
   {
      cout << "Enter a month number: ";
      cin >> month;

      // If the month is no good, tell them why before the loop restarts.
      if (month <= 0 || 13 <= month)
         cout << "Month must be between 1 and 12.\n";
   }

   return month;
}

/******************************************************************************
 * Function: CALCULATE OFFSET
 * Based on month and year, return the first day of the month as a number
 *****************************************************************************/
int calcOffset(int year, int month)
{
   int numDays = 0;
   int offset;

   // Get the number of days in every year, and add to the total
   // Don't calculate for the year they gave you
   if (year != 1753)
   {
      for (int countYear = 1753; countYear < year; countYear++)
      {
         numDays += calcYearDays(countYear);
      }
   }

   // Get the number of days in every month that has passed, add to the total
   for (int countMonth = 1; countMonth < month; countMonth++)
   {
      numDays += calcMonDays(year, countMonth);
   }

   // This is the remaining number of days that need offset
   // (Seven is a whole week, so get rid of all of them, return remainder)
   offset = numDays % 7;

   // This is to compensate for Sunday being behind Monday, since Monday is
   // offset 0, and we don't want a blank line.
   if (offset == 6)
   {
      offset = -1;
   }

   return offset;
}

/******************************************************************************
 * Function: CALCULATE YEAR DAYS
 * Use isLeap() to determine if there are 365 or 366 days, and return.
 *****************************************************************************/
int calcYearDays(int year)
{
   if (isLeap(year))
      return 366;
   else
      return 365;
}

/******************************************************************************
 * Function: CALCULATE MONTH DAYS
 * Return the number of days in a given month, compensate Feb for leap year.
 *****************************************************************************/
int calcMonDays(int year, int month)
{
   int days = 0;

   switch (month)
   {
      // Compensate for leap year for Feb
      case 2 :
         if (isLeap(year))
            days = 29;
         else
            days = 28;
         break;
      // 30 days for Apr, Jun, Sep, Nov
      case 4 :
      case 6 :
      case 9 :
      case 11:
         days = 30;
         break;
      // The rest have 31 days
      default :
         days = 31;
         break;
   }

   return days;
}

/******************************************************************************
 * Function: IS LEAP YEAR
 * Figure out if the given year is a leap year, return.
 *****************************************************************************/
bool isLeap(int year)
{
   bool leap = false;

   // Leap years:
   // - Centennial years that are divisible by 400
   // - All non-centennial years divisible by 4
   if (year % 100 == 0)
   {
      if (year % 400 == 0)
         leap = true;
   }
   else if (year % 4 == 0)
      leap = true;

   return leap;
}

/******************************************************************************
 * Function: DISPLAY
 * Give parameters to displayHeader() and displayTable() to print stuff right
 *****************************************************************************/
void display(int year, int month, int offset)
{
   int days = calcMonDays(year, month);

   displayHeader(year, month);
   displayTable(days, offset);

   return;
}

/******************************************************************************
 * Function: DISPLAY HEADER
 * Print the year and month to the screen
 *****************************************************************************/
void displayHeader(int year, int month)
{
   // Scoot all the names over with a blank string
   // so I don't have to math in cout
   char months[13][12] = {"", "January", "February", "March", "April", "May",
                              "June", "July", "August", "September", "October",
                              "November", "December"};
   cout << endl << months[month] << ", " << year << endl;
}

/******************************************************************************
 * Function: DISPLAY TABLE
 * Display the table of days, do fancy loops so that we print a newline at them
 * right time
 *****************************************************************************/
void displayTable(int numDays, int offset)
{
   // Print header
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   // Day of week tracker
   int dow = 0;

   // Walk through the days of the month
   // Use -offset to print blanks as we walk up to 0, then print numbers
   // (Sunday) offset == -1, dom == 1, will print no blanks
   for (int dom = -offset; dom <= numDays; dom++)
   {
      // Fill with blanks for offset
      // Print actual value if above 0
      if (dom <= 0)
         cout << "    ";
      else
         cout << setw(4) << dom;

      // We printed a day, so advance the day of the week
      dow++;

      // Print newline after Saturday
      // Also print a newline on the last day, if we didn't already
      if (dow % 7 == 0)
         cout << endl;
      else if (dom == numDays)
         cout << endl;
   }

   return;
}

