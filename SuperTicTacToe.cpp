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

/*
void PrintGame(void) {
  using namespace std

  cout << "" << endl;

  return;
}
*/

/*
void SelectBoard(uint8_t Choice) {
  switch(Choice) {
    case 1:
      Something to do with the board
  }
  return;
};

void CheckMiniBoard(void) {
  return;
}

void CheckMainBoard(void) {
  return;
}

void MarkBoard(void) {
  return;
}
*/

int main(void) {

  // Code Here

  return 0;
}
