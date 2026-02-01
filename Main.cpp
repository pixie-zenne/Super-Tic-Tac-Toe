#include <iostream>
#include <cstring>

uint8_t Board1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
uint8_t Board2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
uint8_t Board3[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
uint8_t Board4[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
uint8_t Board5[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
uint8_t Board6[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
uint8_t Board7[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
uint8_t Board8[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
uint8_t Board9[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
uint8_t BoardBuffer[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

uint8_t Player1Mark = 11;
uint8_t Player2Mark = 22;

uint8_t CheckCurrentPlayer = 0;

uint8_t TotalTurnsPlayed = 0;
uint8_t MaximumPlayableTurns = 81;

void CurrentBoard(uint8_t Board) {
  for(uint8_t i = 0; i < 9; i++)
    BoardBuffer[i] = Board[i];
  return;
}

void PrintBoard(void) {
  return;
}

void MoveValidity(uint8_t Mark) {
  if(Mark > 10) { TotalTurnsPlayed--; }
  return;
}
void PlayerMove(uint8_t CurrentPlayer) {

  return;
}

int main(void) {

  for(; TotalTurnsPlayed < MaximumPlayableTurns; TotalTurnsPlayed++) {
    CheckCurrentPlayer = TotalTurnsPlayed % 2;
    PlayerMove(CheckCurrentPlayer);
  }

  return 0;
}
