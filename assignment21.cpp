/******************************************************************************
* Program:
*    Assignment 21, Debugging
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    Stub functions for the car cost program.
*
*    Estimated:  10 Minutes
*    Actual:     20 Minutes
*
*    Please describe briefly the most difficult part.
*     Lots of function skeletons to write. Lots of copy-pasta.
*
******************************************************************************/

// Libraries
#include <iostream>  // Default Library
#include <iomanip>   // IO Manipulator
using namespace std;

// Prototypes
double getPeriodicCost();
double promptDevalue();
double promptInsurance();
double promptParking();

double getUsageCost();
double promptMileage();
double promptGas();
double promptRepairs();
double promptTires();

void display(double costUsage, double costPeriodic);


/******************************************************************************
 * main
 * stub
 *****************************************************************************/
int main()
{

   double costPeriodic = getPeriodicCost();
   double costUsage = getUsageCost();
   display(costPeriodic, costUsage);
   return 0;
}


/******************************************************************************
 * GET PERIODIC COST
 * stub
 *****************************************************************************/
double getPeriodicCost()
{
   double costPeriodic = 0;
   promptDevalue();
   promptInsurance();
   promptParking();
   return costPeriodic;
}

/******************************************************************************
 * PROMPT DEVALUE
 * stub
 *****************************************************************************/
double promptDevalue()
{
   double devalue = 0;
   promptMileage();
   promptGas();
   promptRepairs();
   promptTires();
   return devalue;
}

/******************************************************************************
 * PROMPT INSURANCE
 * stub
 *****************************************************************************/
double promptInsurance()
{
   double insurance = 0;
   return insurance;
}

/******************************************************************************
 * PROMPT PARKING
 * stub
 *****************************************************************************/
double promptParking()
{
   double parking = 0;
   return parking;
}

/******************************************************************************
 * GET USAGE COST
 * stub
 *****************************************************************************/
double getUsageCost()
{
   double usageCost = 0;
   return usageCost;
}

/******************************************************************************
 * PROMPT MILEAGE
 * stub
 *****************************************************************************/
double promptMileage()
{
   double mileage = 0;
   return mileage;
}

/******************************************************************************
 * PROMPT GAS
 * stub
 *****************************************************************************/
double promptGas()
{
   double gas = 0;
   return gas;
}

/******************************************************************************
 * PROMPT REPAIRS
 * stub
 *****************************************************************************/
double promptRepairs()
{
   double repairs = 0;
   return repairs;
}

/******************************************************************************
 * PROMPT TIRES
 * stub
 *****************************************************************************/
double promptTires()
{
   double tires = 0;
   return tires;
}

/******************************************************************************
 * DISPLAY
 * stub
 *****************************************************************************/
void display(double costPeriodic, double costUsage)
{
   cout << "Success\n";
   return;
}

