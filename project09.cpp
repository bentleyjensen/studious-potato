/******************************************************************************
* Program:
*    Project 09, Mad Lib
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    Dissect a madLib file and prompt the user for words based on tokens.
*
*    Estimated:  90 Minutes
*    Actual:     90 Minutes
*
*    Please describe briefly the most difficult part.
*     I deleted the file on accident just before I was finished with it. Had to
*     re-do the whole thing.
*
******************************************************************************/

// Libraries
#include <iostream>  // I/O Streams (cin, cout)
#include <iomanip>   // IO Manipulator (setw)
#include <fstream>   // File streams (ofstream, ifstream)
#include <cassert>   // Error Handling (assert)
using namespace std;


//Prototypes

void readFile(char story[256][32], int * length);
void prompt(char story[256][32], int * length);
void display(char story[256][32], int * length);
void syntax(char story[256][32], int index);
void playAgain(bool *replay);



/******************************************************************************
 * FUNCTION: MAIN
 * Begin the game, delegate tasks, hold pointers, and then repeat if necessary.
 *****************************************************************************/
int main()
{
   // Pointers and variables
   int wordCount = 0;
   int * length = &wordCount;
   bool playAgain = false;
   bool * replay = &playAgain;
   char story[256][32];

   readFile(story, length);

   if (*length != -1)
   {
      prompt(story, length);
      // TODO: project 10: display
      // TODO: project 10: playAgain
   }

   cout << "Thank you for playing.\n";

   return 0;
}

/******************************************************************************
 * FUNCTION: READ FILE
 * Get the filename from the user, and populate the story array.
 *****************************************************************************/
void readFile(char story[256][32], int *length)
{
   // This is the only function that needs or uses this data
   // Thus it is declared here and never passed anywhere
   char filename[80];

   // Get info from user
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> filename;
   cin.ignore();

   // Access and open the file referred to
   ifstream fin(filename);

   // File error contingency Plan
   if (fin.fail())
   {
      cout << "Unable to open file " << filename << endl;
      // no file, no length (not even zero words)
      // communicate error
      *length = -1;
      return;
   }

   // Populate story array
   int counter = 0;
   while (fin >> story[counter])
   {
      counter++;
   }

   // Set length to the number of words we populated
   *length = counter;

   return;
}

/******************************************************************************
 * FUNCTION: PROMPT
 * If a word is a token, prompt the user for filler or pass it to syntax
 *****************************************************************************/
void prompt(char story[256][32], int * length)
{
   for (int i = 0; i < *length; i++)
   {
      // True if the word is a token
      if (story[i][0] == '<')
      {
         // True if a prompt instead of punctuation
         if (isalpha(story[i][1]))
         {
            cout << "\t";
            // Sentence case
            story[i][1] -= 32;

            // Print one letter at a time, replace spaces
            for (int j = 1; story[i][j] != '>'; j++)
               if (story[i][j] == '_')
                  cout << ' ';
               else
                  cout << story[i][j];

            cout << ": ";
            cin.getline(story[i], 32);
         }
         // It's a token but not a prompt
         else
         {
            syntax(story, i);
         }
      }
   }

   return;
}

/******************************************************************************
 * FUNCTION: SYNTAX
 * Determine which punctuation character the token refers to
 *****************************************************************************/
void syntax(char story[256][32], int index)
{
   return;
}

/******************************************************************************
 * FUNCTION: DISPLAY
 * Walk through the story array, print words, add spaces, replace syntax tokens
 *****************************************************************************/
void display(char story[256][32], int *length)
{
   return;
}

/******************************************************************************
 * FUNCTION: PLAY AGAIN
 * Prompt the user to know if they want to replay.
 *****************************************************************************/
void playAgain(bool *replay)
{
   return;
}
