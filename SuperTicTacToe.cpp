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
uint8_t MaximumPossiblePlayerbleTurns = 81;

void PrintGame(void) {
  using namespace std

  cout << "" << endl;

  // More code here

  return;
}

void SelectBoard(uint8_t Choice) {
  switch(Choice) {
    case 1:
      
  // Code here

  }
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

void MarkBoard(void) {
  
  // Code here

  return;
}

int main(void) {

  // Code here

  return 0;
}
