/******************************************************************************
* Program:
*    Assignment 42, String Class
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    Create a function that will write out the verses of a song using an array
*
*    Estimated:  30 Minutes
*    Actual:     30 Minutes
*
*    Please describe briefly the most difficult part.
*     I got a weird error from trying to access the 9th index and it took me a
*     while to find.
*
******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/********************************************************************
 * GENERATE SONG
 * This function will generate one long string that constitutes the
 * complete song "Dem Bones."  Note that the list of bones is provided
 * by the parameter list
 ********************************************************************/
string generateSong(string list[], int num)
{
   string output;

   for (int i = 1; i < num; i++)
      output += list[i - 1] + " bone connected to the " + list[i] + " bone\n";

   return output;
}

/**********************************************************************
 * MAIN
 * In this program, MAIN is a driver program.  It will feed to generateSong()
 * the list of bones and get back the complete song as a string.  MAIN will
 * then display the song
 ***********************************************************************/
int main()
{
   string list[9] = {
      "toe",
      "foot",
      "leg",
      "knee",
      "hip",
      "back",
      "neck",
      "jaw",
      "head" };

   // generate the song
   string song = generateSong(list, 9);

   // display the results
   cout << song;

   return 0;
}
