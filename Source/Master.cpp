#define master main

#include <cstdint>
#include <cstring>
#include <iostream>

unsigned char BufferBoard[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
unsigned char MainBoard[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
unsigned char MiniBoard[9][9] = {
  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},

  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},

  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
};

// The marks for the two players
unsigned char PlayerOneMark = 'X';
unsigned char PlayerTwoMark = 'O';

// GameState
uint8_t GS_Winner = 0;
uint8_t GS_CurrentPlayer = 0;

uint8_t TurnsPlayed = 0;
uint8_t MaximumPossiblePlayableTurns = 81;

/*
The visual aid for the game.

So that the developer can easily imagine the boards if they are having a hard time doing so.
*/ /*
 1 | 2 | 3   |   1 | 2 | 3   |   1 | 2 | 3
--- --- ---  |  --- --- ---  |  --- --- ---
 4 | 5 | 6   |   4 | 5 | 6   |   4 | 5 | 6
--- --- ---  |  --- --- ---  |  --- --- ---
 7 | 8 | 9   |   7 | 8 | 9   |   7 | 8 | 9

-----------     -----------     -----------

 1 | 2 | 3   |   1 | 2 | 3   |   1 | 2 | 3
--- --- ---  |  --- --- ---  |  --- --- ---
 4 | 5 | 6   |   4 | 5 | 6   |   4 | 5 | 6
--- --- ---  |  --- --- ---  |  --- --- ---
 7 | 8 | 9   |   7 | 8 | 9   |   7 | 8 | 9

-----------     -----------     -----------

 1 | 2 | 3   |   1 | 2 | 3   |   1 | 2 | 3
--- --- ---  |  --- --- ---  |  --- --- ---
 4 | 5 | 6   |   4 | 5 | 6   |   4 | 5 | 6
--- --- ---  |  --- --- ---  |  --- --- ---
 7 | 8 | 9   |   7 | 8 | 9   |   7 | 8 | 9


 1 | 2 | 3    Current Player : Player Number
--- --- ---   Current Board  : Board Number
 4 | 5 | 6
--- --- ---
 7 | 8 | 9
*/

void SelectFirstMiniBoard(void) {
  using namespace std

  cout << "   |   |     |     |   |     |     |   |   " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << "   | 1 |     |     | 2 |     |     | 3 |   " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << "   |   |     |     |   |     |     |   |   " << endl;

  cout << endl;
  cout << "-----------     -----------     -----------" << endl;
  cout <<  endl;

  cout << "   |   |     |     |   |     |     |   |   " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << "   | 3 |     |     | 4 |     |     | 5 |   " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << "   |   |     |     |   |     |     |   |   " << endl;

  cout << endl;
  cout << "-----------     -----------     -----------" << endl;
  cout << endl;

  cout << "   |   |     |     |   |     |     |   |   " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << "   | 6 |     |     | 7 |     |     | 8 |   " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << "   |   |     |     |   |     |     |   |   " << endl;

  cout << endl;
  cout << endl;

  cout << "   |   |      Current Player : Player One" << endl;
  cout << "--- --- ---   Current Mini Board  : None" << endl;
  cout << "   |   |   " << endl;
  cout << "--- --- ---" << endl;
  cout << "   |   |   " << endl;

  return;
}

void PrintTheGame(void) {
  using namespace std

  cout << " " << MiniBoard[0][0] << " | " << MiniBoard[0][1] << " | " << MiniBoard[0][2] << "   |   " << MiniBoard[1][0] << " | " << MiniBoard[1][1] << " | " << MiniBoard[1][2] << "   |   " << MiniBoard[2][0] << " | " << MiniBoard[2][1] << " | " << MiniBoard[2][2] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << MiniBoard[0][3] << " | " << MiniBoard[0][4] << " | " << MiniBoard[0][5] << "   |   " << MiniBoard[1][3] << " | " << MiniBoard[1][4] << " | " << MiniBoard[1][5] << "   |   " << MiniBoard[2][3] << " | " << MiniBoard[2][4] << " | " << MiniBoard[2][5] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << MiniBoard[0][6] << " | " << MiniBoard[0][7] << " | " << MiniBoard[0][8] << "   |   " << MiniBoard[1][6] << " | " << MiniBoard[1][7] << " | " << MiniBoard[1][8] << "   |   " << MiniBoard[2][6] << " | " << MiniBoard[2][7] << " | " << MiniBoard[2][8] << " " << endl;

  cout << endl;
  cout << "-----------     -----------     -----------" << endl;
  cout << endl;

  cout << " " << MiniBoard[3][0] << " | " << MiniBoard[3][1] << " | " << MiniBoard[3][2] << "   |   " << MiniBoard[4][0] << " | " << MiniBoard[4][1] << " | " << MiniBoard[4][2] << "   |   " << MiniBoard[5][0] << " | " << MiniBoard[5][1] << " | " << MiniBoard[5][2] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << MiniBoard[3][3] << " | " << MiniBoard[3][4] << " | " << MiniBoard[3][5] << "   |   " << MiniBoard[4][3] << " | " << MiniBoard[4][4] << " | " << MiniBoard[4][5] << "   |   " << MiniBoard[5][3] << " | " << MiniBoard[5][4] << " | " << MiniBoard[5][5] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << MiniBoard[3][6] << " | " << MiniBoard[3][7] << " | " << MiniBoard[3][8] << "   |   " << MiniBoard[4][6] << " | " << MiniBoard[4][7] << " | " << MiniBoard[4][8] << "   |   " << MiniBoard[5][6] << " | " << MiniBoard[5][7] << " | " << MiniBoard[5][8] << " " << endl;

  cout << endl;
  cout << "-----------     -----------     -----------" << endl;
  cout << endl;

  cout << " " << MiniBoard[6][0] << " | " << MiniBoard[6][1] << " | " << MiniBoard[6][2] << "   |   " << MiniBoard[7][0] << " | " << MiniBoard[7][1] << " | " << MiniBoard[7][2] << "   |   " << MiniBoard[8][0] << " | " << MiniBoard[8][1] << " | " << MiniBoard[8][2] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << MiniBoard[6][3] << " | " << MiniBoard[6][4] << " | " << MiniBoard[6][5] << "   |   " << MiniBoard[7][3] << " | " << MiniBoard[7][4] << " | " << MiniBoard[7][5] << "   |   " << MiniBoard[8][3] << " | " << MiniBoard[8][4] << " | " << MiniBoard[8][5] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << MiniBoard[6][6] << " | " << MiniBoard[6][7] << " | " << MiniBoard[6][8] << "   |   " << MiniBoard[7][6] << " | " << MiniBoard[7][7] << " | " << MiniBoard[7][8] << "   |   " << MiniBoard[8][6] << " | " << MiniBoard[8][7] << " | " << MiniBoard[8][8] << " " << endl;

  cout << endl;
  cout << endl;

  cout << " " << MainBoard[0] << " | " << MainBoard[1] << " | " << MainBoard[2] << "    Current Player : Player [Insert Number]" << endl;
  cout << "--- --- ---   Current Mini Board  : [Insert Number]" << endl;
  cout << " " << MainBoard[3] << " | " << MainBoard[4] << " | " << MainBoard[5] << endl;
  cout << "--- --- ---" << endl;
  cout << " " << MainBoard[6] << " | " << MainBoard[7] << " | " << MainBoard[8] << endl;

  return;
}

void SelectBoard(uint8_t Choice) {
  // To select the board properly
  // Because players are using 1 to 9
  // While he program uses 0 to 8
  Choice--;

  // More code here
  // Buffer = MiniBoard[Choice]
  return;
};

void CheckMiniBoard(void) {
/*
  To be changed later
*/ /*
  // FOR PLAYER ONE
  if ( // Check for matching marks in a row
    (MainBoard[0] == 'X' && MainBoard[1] == 'X' && MainBoard[2] == 'X') ||
    (MainBoard[3] == 'X' && MainBoard[4] == 'X' && MainBoard[5] == 'X') ||
    (MainBoard[7] == 'X' && MainBoard[7] == 'X' && MainBoard[8] == 'X')
  ) { GS_Winner = 1; }
  else if ( // Check for matching marks in a column
    (MainBoard[0] == 'X' && MainBoard[3] == 'X' && MainBoard[6] == 'X') ||
    (MainBoard[1] == 'X' && MainBoard[4] == 'X' && MainBoard[7] == 'X') ||
    (MainBoard[2] == 'X' && MainBoard[5] == 'X' && MainBoard[8] == 'X')
  ) { GS_Winner = 1; }
  else if ( // Check for matching marks in a diagonal
    (MainBoard[0] == 'X' && MainBoard[4] == 'X' && MainBoard[8] == 'X') ||
    (MainBoard[2] == 'X' && MainBoard[4] == 'X' && MainBoard[6] == 'X')
  ) { GS_Winner = 1; }

  // FOR PLAYER TWO
  else if ( // Check for matching marks in a row
    (MainBoard[0] == 'O' && MainBoard[1] == 'O' && MainBoard[2] == 'O') ||
    (MainBoard[3] == 'O' && MainBoard[4] == 'O' && MainBoard[5] == 'O') ||
    (MainBoard[7] == 'O' && MainBoard[7] == 'O' && MainBoard[8] == 'O')
  ) { GS_Winner = 2; }
  else if ( // Check for matching marks in a column
    (MainBoard[0] == 'O' && MainBoard[3] == 'O' && MainBoard[6] == 'O') ||
    (MainBoard[1] == 'O' && MainBoard[4] == 'O' && MainBoard[7] == 'O') ||
    (MainBoard[2] == 'O' && MainBoard[5] == 'O' && MainBoard[8] == 'O')
  ) { GS_Winner = 2; }
  else if ( // Check for matching marks in a diagonal
    (MainBoard[0] == 'O' && MainBoard[4] == 'O' && MainBoard[8] == 'O') ||
    (MainBoard[2] == 'O' && MainBoard[4] == 'O' && MainBoard[6] == 'O')
  ) { GS_Winner = 2; }
*/
  return;
}

void CheckMainBoard(void) {
  // FOR PLAYER ONE
  if ( // Check for matching marks in a row
    (MainBoard[0] == 'X' && MainBoard[1] == 'X' && MainBoard[2] == 'X') ||
    (MainBoard[3] == 'X' && MainBoard[4] == 'X' && MainBoard[5] == 'X') ||
    (MainBoard[7] == 'X' && MainBoard[7] == 'X' && MainBoard[8] == 'X')
  ) { GS_Winner = 1; }
  else if ( // Check for matching marks in a column
    (MainBoard[0] == 'X' && MainBoard[3] == 'X' && MainBoard[6] == 'X') ||
    (MainBoard[1] == 'X' && MainBoard[4] == 'X' && MainBoard[7] == 'X') ||
    (MainBoard[2] == 'X' && MainBoard[5] == 'X' && MainBoard[8] == 'X')
  ) { GS_Winner = 1; }
  else if ( // Check for matching marks in a diagonal
    (MainBoard[0] == 'X' && MainBoard[4] == 'X' && MainBoard[8] == 'X') ||
    (MainBoard[2] == 'X' && MainBoard[4] == 'X' && MainBoard[6] == 'X')
  ) { GS_Winner = 1; }

  // FOR PLAYER TWO
  else if ( // Check for matching marks in a row
    (MainBoard[0] == 'O' && MainBoard[1] == 'O' && MainBoard[2] == 'O') ||
    (MainBoard[3] == 'O' && MainBoard[4] == 'O' && MainBoard[5] == 'O') ||
    (MainBoard[7] == 'O' && MainBoard[7] == 'O' && MainBoard[8] == 'O')
  ) { GS_Winner = 2; }
  else if ( // Check for matching marks in a column
    (MainBoard[0] == 'O' && MainBoard[3] == 'O' && MainBoard[6] == 'O') ||
    (MainBoard[1] == 'O' && MainBoard[4] == 'O' && MainBoard[7] == 'O') ||
    (MainBoard[2] == 'O' && MainBoard[5] == 'O' && MainBoard[8] == 'O')
  ) { GS_Winner = 2; }
  else if ( // Check for matching marks in a diagonal
    (MainBoard[0] == 'O' && MainBoard[4] == 'O' && MainBoard[8] == 'O') ||
    (MainBoard[2] == 'O' && MainBoard[4] == 'O' && MainBoard[6] == 'O')
  ) { GS_Winner = 2; }

  return;
}

void MarkMiniBoard(uint8_t Choice) {
/*
  To be changed later
*/ /*
  // FOR PLAYER ONE
  if ( // Check for matching marks in a row
    (MainBoard[0] == 'X' && MainBoard[1] == 'X' && MainBoard[2] == 'X') ||
    (MainBoard[3] == 'X' && MainBoard[4] == 'X' && MainBoard[5] == 'X') ||
    (MainBoard[7] == 'X' && MainBoard[7] == 'X' && MainBoard[8] == 'X')
  ) { GS_Winner = 1; }
  else if ( // Check for matching marks in a column
    (MainBoard[0] == 'X' && MainBoard[3] == 'X' && MainBoard[6] == 'X') ||
    (MainBoard[1] == 'X' && MainBoard[4] == 'X' && MainBoard[7] == 'X') ||
    (MainBoard[2] == 'X' && MainBoard[5] == 'X' && MainBoard[8] == 'X')
  ) { GS_Winner = 1; }
  else if ( // Check for matching marks in a diagonal
    (MainBoard[0] == 'X' && MainBoard[4] == 'X' && MainBoard[8] == 'X') ||
    (MainBoard[2] == 'X' && MainBoard[4] == 'X' && MainBoard[6] == 'X')
  ) { GS_Winner = 1; }

  // FOR PLAYER TWO
  else if ( // Check for matching marks in a row
    (MainBoard[0] == 'O' && MainBoard[1] == 'O' && MainBoard[2] == 'O') ||
    (MainBoard[3] == 'O' && MainBoard[4] == 'O' && MainBoard[5] == 'O') ||
    (MainBoard[7] == 'O' && MainBoard[7] == 'O' && MainBoard[8] == 'O')
  ) { GS_Winner = 2; }
  else if ( // Check for matching marks in a column
    (MainBoard[0] == 'O' && MainBoard[3] == 'O' && MainBoard[6] == 'O') ||
    (MainBoard[1] == 'O' && MainBoard[4] == 'O' && MainBoard[7] == 'O') ||
    (MainBoard[2] == 'O' && MainBoard[5] == 'O' && MainBoard[8] == 'O')
  ) { GS_Winner = 2; }
  else if ( // Check for matching marks in a diagonal
    (MainBoard[0] == 'O' && MainBoard[4] == 'O' && MainBoard[8] == 'O') ||
    (MainBoard[2] == 'O' && MainBoard[4] == 'O' && MainBoard[6] == 'O')
  ) { GS_Winner = 2; }
*/
  return;
}

void MarkMainBoard(uint8_t Choice) {
/*
  To be changed later
*/ /*
  // FOR PLAYER ONE
  if ( // Check for matching marks in a row
    (MainBoard[0] == 'X' && MainBoard[1] == 'X' && MainBoard[2] == 'X') ||
    (MainBoard[3] == 'X' && MainBoard[4] == 'X' && MainBoard[5] == 'X') ||
    (MainBoard[7] == 'X' && MainBoard[7] == 'X' && MainBoard[8] == 'X')
  ) { GS_Winner = 1; }
  else if ( // Check for matching marks in a column
    (MainBoard[0] == 'X' && MainBoard[3] == 'X' && MainBoard[6] == 'X') ||
    (MainBoard[1] == 'X' && MainBoard[4] == 'X' && MainBoard[7] == 'X') ||
    (MainBoard[2] == 'X' && MainBoard[5] == 'X' && MainBoard[8] == 'X')
  ) { GS_Winner = 1; }
  else if ( // Check for matching marks in a diagonal
    (MainBoard[0] == 'X' && MainBoard[4] == 'X' && MainBoard[8] == 'X') ||
    (MainBoard[2] == 'X' && MainBoard[4] == 'X' && MainBoard[6] == 'X')
  ) { GS_Winner = 1; }

  // FOR PLAYER TWO
  else if ( // Check for matching marks in a row
    (MainBoard[0] == 'O' && MainBoard[1] == 'O' && MainBoard[2] == 'O') ||
    (MainBoard[3] == 'O' && MainBoard[4] == 'O' && MainBoard[5] == 'O') ||
    (MainBoard[7] == 'O' && MainBoard[7] == 'O' && MainBoard[8] == 'O')
  ) { GS_Winner = 2; }
  else if ( // Check for matching marks in a column
    (MainBoard[0] == 'O' && MainBoard[3] == 'O' && MainBoard[6] == 'O') ||
    (MainBoard[1] == 'O' && MainBoard[4] == 'O' && MainBoard[7] == 'O') ||
    (MainBoard[2] == 'O' && MainBoard[5] == 'O' && MainBoard[8] == 'O')
  ) { GS_Winner = 2; }
  else if ( // Check for matching marks in a diagonal
    (MainBoard[0] == 'O' && MainBoard[4] == 'O' && MainBoard[8] == 'O') ||
    (MainBoard[2] == 'O' && MainBoard[4] == 'O' && MainBoard[6] == 'O')
  ) { GS_Winner = 2; }
*/
  return;
}

int master(void) {

  SelectFirstMiniBoard(void);
  uint8_t selection = 0;

  // More code here
  return 0;
}
