#include <iostream>
#include <cstring>

char B[9][9] = { /* B is for Board */
  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
  {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
  {'1', '2', '3', '4', '5', '6', '7', '8', '9'}
};
char MainBoard[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char BufferBoard[9] = {'0', '0', '0', '0', '0', '0', '0', '0', '0'};

char Mark[2] = {'X', 'O'};

uint8_t CurrentPlayer = 0;

uint8_t TotalTurnsPlayed = 0;
uint8_t TheoreticallyMaximumPlayableTurns = 81;

uint8_t CheckWinner(void) {
  return 0;
}

/*
Here is the visual of the board

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
void InitGame(void) {
  std::cout << " " << std::endl;
  std::cout << "-" << std::endl;
  std::cout << " " << std::endl;
  std::cout << "-" << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  return;
}

void PrintGame(void) {
  return;
}

int main(void) {

  InitGame();

  for(; TotalTurnsPlayed < TheoreticallyMaximumPlayableTurns; TotalTurnsPlayed++) {
    CurrentPlayer = TotalTurnsPlayed % 2;
    PlayerMove(CurrentPlayer);
  }

  return 0;
}
