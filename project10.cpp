/******************************************************************************
* Program:
*    Project 10, Mad Lib
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    Dissect a madLib file and prompt the user for words based on tokens, then
*    print the resulting story and prompt to play again.
*
*    Estimated:  90 Minutes
*    Actual:     60 Minutes
*
*    Please describe briefly the most difficult part.
*     Getting the spaces to print at the right time. I kept adding a new test
*     every time I ran testBed to take out a different group that lacked spaces
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
void syntax(char word[32]);
bool playAgain();



/******************************************************************************
 * FUNCTION: MAIN
 * Begin the game, delegate tasks, hold pointers, and then repeat if necessary.
 *****************************************************************************/
int main()
{
   // Pointers and variables
   int wordCount = 0;
   int * length = &wordCount;
   char story[256][32];
   bool replay = true;

   while (replay == true)
   {
      readFile(story, length);

      if (*length != -1)
      {
         prompt(story, length);
         display(story, length);
         replay = playAgain();
      }
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
      }
   }
   cout << endl;

   return;
}

/******************************************************************************
 * FUNCTION: SYNTAX
 * Print spaces when needed, print puctuation when given tokens, or just print.
 *****************************************************************************/
void syntax(char story[256][32], int index)
{
   // Last (ie previous) index
   int l = index - 1;

   // Print space before?
   bool spaceB = true;

   // If it's the first word, no space
   if (index == 0)
      spaceB = false;


   // Check previous index for no-space tokens
   switch (story[l][1])
   {
      case '{':
      case '[':
      case '#':
         spaceB = false;
         break;
   }


   // Check current index for no-space tokens
   switch (story[index][1])
   {
      case ']':
      case '}':
      case '#':
         spaceB = false;
         break;
   }


   // When the current index is neither a token or alphabet, no space
   if (story[index][0] != '<' && !isalpha(story[index][0]))
      spaceB = false;


   // Print the space if we need it
   if (spaceB == true)
   {
      cout << " ";
   }


   // If we currently have a token, print its character
   if (story[index][0] == '<')
   {
      switch (story[index][1])
      {
         case '#':
            cout << "\n";
            break;
         case '{':
         case '}':
            cout << "\"";
            break;
         case '[':
         case ']':
            cout << "'";
            break;
      }
   }
   else
   {
      cout << story[index];
   }


   return;
}

/******************************************************************************
 * FUNCTION: DISPLAY
 * Walk through the story array, but actually make syntax do all the work.
 *****************************************************************************/
void display(char story[256][32], int *length)
{
   for (int i = 0; i < *length; i++)
      syntax(story, i);

   cout << endl;

   return;
}

/******************************************************************************
 * FUNCTION: PLAY AGAIN
 * Prompt the user to know if they want to replay.
 *****************************************************************************/
bool playAgain()
{
   char play[2];

   cout << "Do you want to play again (y/n)? ";
   cin >> play;
   cin.ignore();

   if (play[0] == 'y' || play[0] == 'Y')
      return true;
   else if (play[0] == 'n' || play[0] == 'N')
      return false;

   return false;
}
