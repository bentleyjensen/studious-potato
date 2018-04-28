/******************************************************************************
* Program:
*    Project Extra, Sudoku w/ Robust Error Checking
*    Sister Hansen, CS 124
* Author:
*    Sterling Jensen
* Summary:
*    An interactive sudoku game that verifies input, differentiates the board
*     provided numbers from user ones, and is persistent through saves.
*
*    Estimated:  120 Minutes
*    Actual:     10 Hours, 40 Minutes
*
*    Please describe briefly the most difficult part.
*     I had a *ton* of little things that needed adjusted to pass testBed. The
*     worst was getting the coordinates to come in and read correctly.
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
void getCoords(char coords[3], int *row, int *col);
bool quit(int board[9][9]);



/******************************************************************************
 * FUNCTION: MAIN
 * Get the board file if one is not given, then start the game.
 *****************************************************************************/
int main(int argc, char* argv[])
{
   // Declare and init sudoku board
   int board[9][9] = {};

   // File Fail Load Fail Safe
   bool loadSuccess = false;

   // Load the board in
   // If there are enough arguments for a filename, use it
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
 * 1.) Possibly prompt for a int file
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

   // Loop through array to check if the board is even real
   col = 0;
   row = 0;
   bool valid = true;

   while (valid && row != 9)
   {
      if (board[row][col] != 0)
         valid = validValue(board, row, col, board[row][col]);

      if (!valid)
         break;

      // ENTER BUTTON
      // If we're at the last column...
      if (col == 8)
      {
         // Advance row
         row++;
         // Carriage return
         col = 0;
      }
      else
         col++;
   }


   if (!valid)
   {
      // Convert to board coordinates
      char letter = 'A' + col;
      int cRow = row + 1;

      cout << "ERROR: Duplicate value '" << board[row][col]
           << "' in inside square represented by '" << letter << cRow << "'\n";
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
            break;
         default:
            cout << "ERROR: Invalid command\n";
      }
      cout << endl;

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
      if (rowI != 0 && rowI % 3 == 0)
         cout << "   -----+-----+-----\n";

      // Begin row with a label
      cout << rowI + 1 << " ";

      for (int colI = 0; colI < 9; colI++)
      {
         int current = board[rowI][colI];

         // Print a pipe instead of a space every third column
         // Vertical box separators
         if (colI != 0 && colI % 3 == 0)
            cout << "|";
         else
            cout << " ";

         // Print spaces for zeroes
         if (current == 0)
            cout << ' ';
         // Or print the number
         else
         {
            // Greater than zero is board constant, so print green.
            if (current > 0)
               cout << "\E[22;32m";

            cout << abs(current);

            if (current > 0)
               cout << "\E[0m";
         }

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
 * Input:
 *    board:   [array] the sudoku board in its current state
 * Output:
 *    Print to the console which numbers are not present
 *
 * Determine which numbers are options for the provided coordinates by marking
 * false any number that exists in the respective row, col, and box, then print
 * to user
 *****************************************************************************/
void possValues(int board[9][9])
{
   // For output
   // And Sparta
   char coords[3] = "\0\0";

   // Indices!
   int row = -1;
   int col = -1;

   // Put real stuff in these indices
   getCoords(coords, &row, &col);


   // Start the prompt even is we don't find any true
   cout << "The possible values for '" << coords << "' are: ";


   // Be fancy and print commas if we found more than one
   bool comma = false;

   // Check if each value is valid in the given square
   for (int i = 1; i <= 9; i++)
   {
      if (validValue(board, row, col, i))
      {
         if (comma)
            cout << ", ";

         cout << i;
         comma = true;
      }
   }
   cout << "\n";

   return;
}


/******************************************************************************
 * FUNCTION: EDIT
 * Input:
 *    board:   [array] sudoku board in current state
 * Output:
 *    board will have a single index changed
 * Retrieve coordinates, verify for read only and repeat values
 *****************************************************************************/
void edit(int board[9][9])
{
   // Array to display back square value
   char coords[3] = "\0\0";

   // Integers for index
   int row = -1;
   int col = -1;

   // Get come coordinates to use
   getCoords(coords, &row, &col);

   // Hopefully this never fires since getCoords re-prompts
   if (row < 0 || col < 0)
      cout << "ERROR: row or col not set by getCoords";

   // Error if the square is read only
   if (board[row][col] > 0)
      cout << "ERROR: Square '" << coords << "' is read-only\n";
   // Make the change if we're good to go
   else
   {
      bool inRange = false;
      int value;
      cout << "What is the value at '" << coords << "': ";
      cin >> value;

      int iValue = value;

      inRange = (iValue > 0 && iValue < 10);


      // The input must have been a digit, and not have any repeats
      if (inRange && validValue(board, row, col, iValue) )
      {
         // Negative so as to diff user input from board constant
         iValue = -iValue;

         board[row][col] = iValue;
      }
      else
         cout << "ERROR: Value '" << value << "' in square '"
              << coords << "' is invalid\n";
   }

   return;
}


/******************************************************************************
 * FUNCTION: VALID VALUE
 * Input:
 *    board:   [array] the sudoku board in its current state
 *    row:     [int] the index of the row iValue will go in
 *    col:     [int] the index of the column iValue will go in
 *    iValue:  [int] the value to check for occurrences of
 * Output:
 *    valid:   [bool] false only if iValue already exists
 *
 * Determine if iValue exists in the row, column or box already
 *****************************************************************************/
bool validValue(int board[9][9], int row, int col, int iValue)
{
   // Any occurrence of iValue in the row/col/box will switch this to false
   // Because valid is assessed between every index advance
   bool valid = true;

   // The index of the culprit invalidating value
   int badR = -1;
   int badC = -1;

   // Check if any number is equal to iValue already
   // If any index's value == value, then valid = false
   // If valid is ever turned off, the proceeding while loops do not run
   // Every index is verified *after* i = 8 is used to determine validity


   // COLUMN
   // Traverse by incrementing row index
   int i = 0;
   while (valid && i < 9)
   {
      // Check for i as row
      // col is consistent
      if (i != row)
         valid = (board[i][col] != iValue);
      i++;
   }


   // ROW
   // Traverse by incrementing column index
   i = 0;
   while (valid && i < 9)
   {
      // Check for i as row
      // col is consistent
      if (i != col)
         valid = (board[row][i] != iValue);
      i++;
   }


   // Determine which box iValue is in
   // Think of the *whole* board as a 3x3 (indices 0,1,2)
   // (row or col) / 3 is the index of the 3x3 it's in (b/c int division)
   // That x3 is the first index of your single box
   // Note that this will work for row or col


   // Example:
   //        index   index/3       box Index
   // Box 0  0,1,2 :    0    * 3  =   0
   // Box 1  3,4,5 :    1    * 3  =   3
   // Box 2  6,7,8 :    2    * 3  =   6



   // Don't do *any* box calculations if valid is already false

   // BOX
   if (valid)
   {
      // Box lower bound
      int bRow = (row / 3) * 3;
      int bCol = (col / 3) * 3;

      // Box higher bound
      int rMax = bRow + 2;
      int cMax = bCol + 2;

      // Three counters:
      // Iterations in this box
      i = 0;

      // Row index
      int r = bRow;

      // Column index
      int c = bCol;


      // The latter two ought to fail simultaneously
      while (valid && i < 9 && r <= rMax)
      {
         // Only traverse 3 columns in each of 3 rows
         // bRow +2, bRow + 1, bRow
         // BUT skip the specific index that was provided
         // This is essentially the else to a (r = row && c = column) statement
         if (r != row && c != col)
            valid = (board[r][c] != iValue);

         // When the loop hits the last column
         if (c == cMax)
         {
            // Advance to next row
            r++;
            // Reset column
            c = bCol;
         }
         else
         {
            // Increment column if we didn't have to reset it
            c++;
         }

         // Increment iterations every time
         i++;
      }
   }


   // Cool stuff that could be added not for class
   // Not enabled or written so the program passes testBed:
   // FEATURE:
   // report which square has the value already in it
   // ENHANCEMENT:
   // Mark it red on the board for one display
   // ENHANCEMENT:
   // Mark multiple invalidating values
   // The max possible is 3 (one for box, row, and column)

   // After every loop has made its run, or was skipped
   return valid;
}


/******************************************************************************
 * FUNCTION: GET COORDINATES
 * Input:
 *    coords:  [array][3] that will contain exact user input
 *    *row:    [int] used as row index by caller
 *    *col:    [int] used as column index by caller
 * Output:
 *    bool:    true if file saved properly, false if not
 *    coords, *row and *col will be populated
 *
 * Prompt the user for some coordinates, check to see if they're valid, then
 * either re-prompt or assign and return
 *****************************************************************************/
void getCoords(char coords[3], int *row, int *col)
{

   // Cleanup before we make a mess
   char cdRow = '\0';
   char cdCol = '\0';
   char cdBoth[3] = "\0\0";
   coords[0] = '\0';
   coords[1] = '\0';

   // A valid square needs to have both a letter and a number
   bool haveNum = false;
   bool haveAlpha = false;


   cout << "What are the coordinates of the square: ";

   // Iterate twice, consuming only 1 character at a time
   for (int i = 0; i < 2; i++)
   {
      // cdOne will only contain/consume one character from cin
      // Used this way for individual coordinate validation
      char* cdOne = new char();

      cin >> *cdOne;

      // Do this to print straight an invalid coordinate
      cdBoth[i] = *cdOne;

      // Check for a letter (for column)
      // Symbols will fail both checks and will error invalid
      if (isalpha(*cdOne))
      {
         // toupper for consistency
         *cdOne = toupper(*cdOne);

         // Only valid column labels will make it through
         if (*cdOne <= 'I')
         {
            // Translate 17 ASCII characters down
            // This gets 'A' to be '0' for index count
            char colI = *cdOne - 17;
            // Make it a real number
            *col = atoi(&colI);
            haveAlpha = true;
         }

         // Make the coordinate print right
         // Account for bad coordinates
         if (!cdCol)
            // Take proper slot if open
            cdCol = *cdOne;
         else
         {
            // Take the row if col is filled already
            // Only happens if two letters come by
            cdRow = *cdOne;
         }
      }

      // Check for digit
      else if (isdigit(*cdOne))
      {
         haveNum = true;
         // Convert from row number char to row number
         int iRow = atoi(cdOne);
         // Take one to make it an index
         *row = iRow - 1;

         // Digits sit on the right
         if (!cdRow)
            cdRow = *cdOne;
         else
         {
            // Unless some guy got there first
            // Scoot the him back to the left where he belongs
            cdCol = cdRow;
            // Now sit
            cdRow = *cdOne;
         }
      }
   }


   // If either of haveNum or haveAlpha is missing,
   // Complain and repeat
   if (!haveNum || !haveAlpha)
   {
      // Use normal so it matches input
      cout << "ERROR: Square '" << cdBoth << "' is invalid\n";
      getCoords(coords, row, col);
   }
   else
   {
      // If all is well, set the coordinate values in  proper order
      // Don't use cdBoth because it had no verification
      coords[0] = cdCol;
      coords[1] = cdRow;
   }

   if (*col > 9)
   {
      *col = *col - *row;
      *col = *col / 10;
   }


   return;
}

/******************************************************************************
 * FUNCTION: QUIT
 * Input:
 *    board:   the sudoku board in its current state
 * Output:
 *    bool:    true if file saved properly, false if not
 *
 * The actual exiting of the game loop is in prompt() based on this return
 * Thus, that needs done is:
 * Prompt for a save location, save the board, and return
 *****************************************************************************/
bool quit(int board[9][9])
{
   char filename[256];
   cout << "What file would you like to write your board to: ";
   cin >> filename;

   // Open outward stream
   ofstream fout(filename);

   // If open fails, don't exit game and lose all the user's work
   if (fout.fail())
   {
      cout << "ERROR: Cannot open file '" << filename << "'\n";

      // False will continue game loop
      // Brought back to prompt, the user can try again
      return false;
   }

   // Write the board to the file
   for (int r = 0; r < 9; r++)
   {
      for (int c = 0; c < 9; c++)
      {
         // Spaces between values, but not before the first column
         if (c != 0)
            fout << " ";

         fout << board[r][c];
      }

      // Newline after every column
      fout << "\n";
   }

   fout.close();
   cout << "Board written successfully";

   return true;
}
