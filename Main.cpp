#include <iostream>
#include <cstring>

char Board1[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char Board2[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char Board3[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char Board4[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char Board5[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char Board6[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char Board7[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char Board8[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char Board9[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char MainBoard[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char BoardBuffer[9] = {'0', '0', '0', '0', '0', '0', '0', '0', '0'};

char Mark[2] = {'X', 'O'};

uint8_t CurrentPlayer = 0;

uint8_t TotalTurnsPlayed = 0;
uint8_t MaximumPlayableTurns = 81;

uint8_t CheckWinner(void) {
  return 0;
}

void InitGame(void) {
  return;
}

void PrintGame(void) {
  return;
}

void PlayerMove(uint8_t CurrentPlayer) {

  return;
}

int main(void) {

  InitGame();

  for(; TotalTurnsPlayed < MaximumPlayableTurns; TotalTurnsPlayed++) {
    CurrentPlayer = TotalTurnsPlayed % 2;
    PlayerMove(CurrentPlayer);
  }

  return 0;
}
