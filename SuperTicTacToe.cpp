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
The game's visual

So that the developer can easily imagine the boards
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

void PrintGame(void) {
  using namespace std

  // Preparing the boards

  cout << "" << endl;
  cout << "" << endl;
  cout << "" << endl;
  cout << "" << endl;
  cout << "" << endl;

  cout << "" << endl;
  cout << "" << endl;
  cout << "" << endl;

  cout << "" << endl;
  cout << "" << endl;
  cout << "" << endl;
  cout << "" << endl;
  cout << "" << endl;

  cout << "" << endl;
  cout << "" << endl;
  cout << "" << endl;

  cout << "" << endl;
  cout << "" << endl;
  cout << "" << endl;
  cout << "" << endl;
  cout << "" << endl;

  cout << "" << endl;
  cout << "" << endl;

  cout << "" << endl;
  cout << "" << endl;
  cout << "" << endl;
  cout << "" << endl;
  cout << "" << endl;

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

  // Code here

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

void MarkMiniBoard(void) {
  
  // Code here

  return;
}

void MarkMainBoard(uint8_t Choice) {
  
  // Code here

  return;
}

int main(void) {

  // Code here

  return 0;
}
