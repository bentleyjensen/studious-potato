/******************************************************************************
* Program:
*    Assignment 40, Tic-Tac-Toe
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    Get a board file from the user, display it, then save it to a new location
*
*    Estimated:  60 Minutes
*    Actual:     38 Minutes
*
*    Please describe briefly the most difficult part.
*     I was super confused about saving the file and what that was about or
*     what I was supposed to do to the data prior, and it was a good ways into
*     it that I figured out we were literally saving the exact same thing we
*     read from the file in the first place.
*
******************************************************************************/

// Libraries
#include <iostream>  // I/O Streams (cin, cout)
#include <iomanip>   // IO Manipulator (setw)
#include <fstream>   // File streams (ofstream, ifstream)
#include <cassert>   // Error Handling (assert)
using namespace std;


//Prototypes
void readFile (char filename[32], char board[3][3]);
void print (char board[3][3]);
void writeFile (char filename[32], char board[3][3]);


/******************************************************************************
 * FUNCTION: MAIN
 * Call the functions to get the file, print, then write the file.
 *****************************************************************************/
int main()
{
   char filename[32];
   char board[3][3];

   cout << "Enter source filename: ";
   cin >> filename;

   readFile(filename, board);
   print(board);

   cout << "Enter destination filename: ";
   cin >> filename;

   writeFile(filename, board);

   return 0;
}

/******************************************************************************
 * FUNCTION: READ FILE
 * Open the file and use it to populate the board
 *****************************************************************************/
void readFile (char filename[32], char board[3][3])
{
   ifstream fin(filename);

   if (fin.fail())
   {
      cout << "Error opening file " << filename << ".\n";
      return;
   }

   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
         fin >> board[i][j];

   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
         board[i][j] = (board[i][j] == '.') ? ' ' : board[i][j];

   return;
}


/******************************************************************************
 * FUNCTION: PRINT
 * Print the board all pretty
 *****************************************************************************/
void print (char board[3][3])
{
   cout << " " << board[0][0] << " | " << board [0][1] << " | " << board[0][2];
   cout << " \n---+---+---\n";
   cout << " " << board[1][0] << " | " << board [1][1] << " | " << board[1][2];
   cout << " \n---+---+---\n";
   cout << " " << board[2][0] << " | " << board [2][1] << " | " << board[2][2];
   cout << " \n";

   return;
}


/******************************************************************************
 * FUNCTION: WRITE FILE
 * Use the filename to write the new board to the file
 *****************************************************************************/
void writeFile (char filename[32], char board[3][3])
{
   ofstream fout(filename);

   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         board[i][j] = (board[i][j] == ' ') ? '.' : board[i][j];
         fout << ' ' << board[i][j];
      }
      fout << endl;
   }

   fout.close();

   cout << "File written\n";
   return;
}

