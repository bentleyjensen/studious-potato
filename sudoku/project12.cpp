/******************************************************************************
* Program:
*    Project 12, Sudoku
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    An interactive sudoku game. (Non-verifying on input)
*
*    Estimated:  90 Minutes
*    Actual:     190 Minutes
*
*    Please describe briefly the most difficult part.
*     Getting the edit function to convert the char ascii to the right int
*     so that it would edit the board at the right index and with the right int
*     value and therefore save correctly.
*
******************************************************************************/

// Libraries
#include <iostream>  // I/O Streams (cin, cout)
#include <iomanip>   // IO Manipulator (setw)
#include <fstream>   // File streams (ofstream, ifstream)
#include <string>    // String Class
#include <cstdlib>   // Standard Library (atof)
#include <cassert>   // Error Handling (assert)
using namespace std;


//Prototypes
bool getBoard(int board[9][9]);
bool getArgBoard(int board[9][9], char filename[]);
void prompt(int board[9][9]);
void printOpts();
void dispBoard(int board[9][9]);
void possValues(int board[9][9]);
bool validValue(int board[9][9], int row, int col, int value);
void edit(int board[9][9]);
bool quit(int board[9][9]);



/******************************************************************************
 * FUNCTION: MAIN
 * Get the board file if one is not given, then start the game.
 *****************************************************************************/
int main(int argc, char *argv[])
{
   // Declare and init sudoku board
   int board[9][9] = {};

   // File Fail Load Fail Safe
   bool loadSuccess;

   // Load the board in
   // If we got enough arguments for a filename, use it
   if (argc > 1)
   {
      char * filename = argv[1];
      loadSuccess = getArgBoard(board, filename);
   }
   else
      loadSuccess = getBoard(board);

   if (loadSuccess)
   {
      printOpts();
      dispBoard(board);
      prompt(board);
   }


   return 0;
}

/******************************************************************************
 * FUNCTION: MAIN
 * Get the board file if one is not given, then start the game.
 *****************************************************************************/
bool getBoard(int board[9][9])
{
   char filename[256];
   cout << "Where is your board located? ";
   cin >> filename;
   cin.ignore();

   bool loadSuccess = getArgBoard(board, filename);

   return loadSuccess;
}



/******************************************************************************
 * FUNCTION: GET BOARD
 * 1.) Possibly prompt for a new file
 * 2.) Load the file given into the board array
 *****************************************************************************/
bool getArgBoard(int board[9][9], char filename[])
{

   ifstream fin;
   fin.open(filename);

   if (fin.fail())
   {
      cout << "ERROR: Cannot open file " << filename << endl;
      return false;
   }

   int iterations = 0;
   int num = 0;
   int col = 0;
   int row = 0;

   while (fin >> num)
   {
      board[row][col] = num;

      col++;
      iterations++;

      // ENTER BUTTON
      // If we're at the last column...
      if (col == 9)
      {
         // Advance row
         row++;
         // Carriage return
         col = 0;
      }
   }

   if (iterations != 81)
   {
      cout << "ERROR: Corrupt file: Does not contain 81 numbers\n";
      return false;
   }

   return true;
}


/******************************************************************************
 * FUNCTION: PROMPT
 * Prompt the user for the next move
 * Delegate tasks accordingly.
 *****************************************************************************/
void prompt(int board[9][9])
{
   bool exit = false;
   char next;

   // Continue prompting until they enter q
   while (!exit)
   {
      cout << "> ";
      cin >> next;

      switch (next)
      {
         case 'e':
         case 'E':
            edit(board);
            break;
         case '?':
            printOpts();
            cout << endl;
            break;
         case 'd':
         case 'D':
            dispBoard(board);
            break;
         case 's':
         case 'S':
            possValues(board);
            break;
         case 'q':
         case 'Q':
            exit = quit(board);
      }

   }

   return;
}


/******************************************************************************
 * FUNCTION: PRINT OPTIONS
 * Display the options available to the users
 *****************************************************************************/
void printOpts()
{
   cout << "Options:\n";
   cout << "   ?  Show these instructions\n";
   cout << "   D  Display the board\n";
   cout << "   E  Edit one square\n";
   cout << "   S  Show the possible values for a square\n";
   cout << "   Q  Save and Quit\n\n";

   return;
}


/******************************************************************************
 * FUNCTION: DISPLAY BOARD
 * Print the board!
 *****************************************************************************/
void dispBoard(int board[9][9])
{
   int iterations = 0;

   // Top row labels
   cout << "   A B C D E F G H I\n";

   // The board itself (Plus side labels)
   for (int rowI = 0; rowI < 9; rowI++)
   {
      // Horizontal box separator every third line
      // But also not before the first row
      if (rowI % 3 == 0 && rowI != 0)
         cout << "   -----+-----+-----\n";

      // Begin row with a label
      cout << rowI + 1 << " ";

      for (int colI = 0; colI < 9; colI++)
      {
         // Print a pipe instead of a space every third column
         // Vertical box separators
         if (colI % 3 == 0 && colI != 0)
            cout << "|";
         else
            cout << " ";

         // Print spaces for zeroes, or the number
         // Single line if gives different type return error (char vs int)
         if (board[rowI][colI] == 0)
            cout << ' ';
         else
            cout << board[rowI][colI];

         // Count iterations over the array
         iterations++;
      }

      // Newline at the end of a row
      cout << endl;
   }

   // Newline after board is finished.
   cout << endl;



   if (iterations != 81)
   {
      cout << "ERROR: iterations on dispBoard() != 81\n";
   }

   return;
}


/******************************************************************************
 * FUNCTION: POSSIBLE VALUES
 * determine which numbers are options for the provided coordinates
 *****************************************************************************/
void possValues(int board[9][9])
{

   return;
}


/******************************************************************************
 * FUNCTION: EDIT
 * Edit a single square on the board
 *****************************************************************************/
void edit(int board[9][9])
{
   // Array to display back square value
   char coords[3] = "\0\0";

   // cdOne will only contain/consume one character from cin
   // Used for individual coordinate validation
   char cdOne;

   // A valid square needs to have both a letter and a number
   bool haveNum = false;
   bool haveAlpha = false;

   // Used as board index
   int row;
   int col;

   cout << "What are the coordinates of the square: ";

   // Iterate twice, consuming only 1 character at a time
   for (int i = 0; i < 2; i++)
   {
      cin >> cdOne;

      // Check for a letter in range
      // Digits will skip the range check
      if (isalpha(cdOne))
      {
         // The only valid alphas are an I or less (ASCII 73)
         if (toupper(cdOne) <= 73)
         {
            // Translate 17 ASCII characters down
            // That means I == ASCII 8 (last column == last index)
            // Convert to int for index use
            char colI = toupper(cdOne) - 17;
            col = atoi(&colI);
            haveAlpha = true;
         }
      }

      // Check for digit
      if (isdigit(cdOne))
      {
         haveNum = true;
         // Convert from row number char to row index
         row = atoi(&cdOne);
         row--;
      }

      coords[i] = cdOne;
   }


   // If either of haveNum or haveAlpha is false,
   // Complain and repeat
   if (!haveNum || !haveAlpha)
   {
      cout << "ERROR: Square '" << coords << "' is invalid\n";
      edit(board);
   }
   // Error if the square is filled
   else if (board[row][col] != 0)
      cout << "ERROR: Square '" << coords << "' is filled\n";
   // Make the change if we're good to go
   else
   {
      bool inRange = false;
      char value;
      cout << "What is the value at '" << coords << "': ";
      cin >> value;

      int iValue;

      if (isdigit(value))
      {
         iValue = value - 48;
         inRange = true;
      };

      if (inRange)   // Prj13: add validValue
         board[row][col] = iValue;
      else
         cout << "ERROR: Value '" << value << "' in square '"
              << coords << "' is invalid\n";
   }


   cout << endl;

   return;
}


/******************************************************************************
 * FUNCTION: VALID VALUE
 * Determine if the value exists in the row, column or box already
 *****************************************************************************/
bool validValue(int board[9][9], int row, int col, int iValue)
{
   // check if any number is equal to iValue already
   // For loop: Column
   // For loop: Row


   // Determine which box iValue is in
   // Think of it as a 3x3 (indices 0,1,2)
   // (row or col) / 3 will give the index of the 3x3 it's in (int division)
   // That x3 is the first index of your 3x3 box (row or col)

   // For loop: box
   // Only traverse 3 columns in each of 3 rows


   return true;
}

/******************************************************************************
 * FUNCTION: QUIT
 * The actual exiting of the loop is in prompt(), so all we have to do is:
 * Prompt for a save location, and save the board
 *****************************************************************************/
bool quit(int board[9][9])
{
   char filename[256];
   cout << "What file would you like to write your board to: ";
   cin >> filename;

   ofstream fout(filename);

   if (fout.fail())
   {
      cout << "ERROR: Cannot open file '" << filename << "'\n";
      return false;
   }

   for (int r = 0; r < 9; r++)
   {
      for (int c = 0; c < 9; c++)
      {
         if (c != 0)
            fout << " ";

         fout << board[r][c];
      }

      fout << "\n";
   }

   fout.close();
   cout << "Board written successfully\n";

   return true;
}
