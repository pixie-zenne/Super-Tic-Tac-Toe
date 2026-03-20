#define master main

#include <cstdbool>
#include <cstdint>
#include <cstring>
#include <iostream>

unsigned char Buffer_Board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
unsigned char Main_Board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
unsigned char Mini_Board[9][9] = {
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
unsigned char Player_One_Mark = 'X';
unsigned char Player_Two_Mark = 'O';

// GameState
uint8_t Game_State-Winner = 0;
uint8_t Game_State-Current_Player = 0;
bool Game_State-Running = true;

uint8_t Turns_Played = 0;
uint8_t Maximum_Possible_Playable_Turns = 81;

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
--- --- ---   Current Mini Board  : Board Number
 4 | 5 | 6
--- --- ---
 7 | 8 | 9
*/

void Select_First_Mini_Board(void) {
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

void Print_The_Game(void) {
  using namespace std

  cout << " " << Mini_Board[0][0] << " | " << Mini_Board[0][1] << " | " << Mini_Board[0][2] << "   |   " << Mini_Board[1][0] << " | " << Mini_Board[1][1] << " | " << Mini_Board[1][2] << "   |   " << Mini_Board[2][0] << " | " << Mini_Board[2][1] << " | " << Mini_Board[2][2] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << Mini_Board[0][3] << " | " << Mini_Board[0][4] << " | " << Mini_Board[0][5] << "   |   " << Mini_Board[1][3] << " | " << Mini_Board[1][4] << " | " << Mini_Board[1][5] << "   |   " << Mini_Board[2][3] << " | " << Mini_Board[2][4] << " | " << Mini_Board[2][5] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << Mini_Board[0][6] << " | " << Mini_Board[0][7] << " | " << Mini_Board[0][8] << "   |   " << Mini_Board[1][6] << " | " << Mini_Board[1][7] << " | " << Mini_Board[1][8] << "   |   " << Mini_Board[2][6] << " | " << Mini_Board[2][7] << " | " << Mini_Board[2][8] << " " << endl;

  cout << endl;
  cout << "-----------     -----------     -----------" << endl;
  cout << endl;

  cout << " " << Mini_Board[3][0] << " | " << Mini_Board[3][1] << " | " << Mini_Board[3][2] << "   |   " << Mini_Board[4][0] << " | " << Mini_Board[4][1] << " | " << Mini_Board[4][2] << "   |   " << Mini_Board[5][0] << " | " << Mini_Board[5][1] << " | " << Mini_Board[5][2] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << Mini_Board[3][3] << " | " << Mini_Board[3][4] << " | " << Mini_Board[3][5] << "   |   " << Mini_Board[4][3] << " | " << Mini_Board[4][4] << " | " << Mini_Board[4][5] << "   |   " << Mini_Board[5][3] << " | " << Mini_Board[5][4] << " | " << Mini_Board[5][5] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << Mini_Board[3][6] << " | " << Mini_Board[3][7] << " | " << Mini_Board[3][8] << "   |   " << Mini_Board[4][6] << " | " << Mini_Board[4][7] << " | " << Mini_Board[4][8] << "   |   " << Mini_Board[5][6] << " | " << Mini_Board[5][7] << " | " << Mini_Board[5][8] << " " << endl;

  cout << endl;
  cout << "-----------     -----------     -----------" << endl;
  cout << endl;

  cout << " " << Mini_Board[6][0] << " | " << Mini_Board[6][1] << " | " << Mini_Board[6][2] << "   |   " << Mini_Board[7][0] << " | " << Mini_Board[7][1] << " | " << Mini_Board[7][2] << "   |   " << Mini_Board[8][0] << " | " << Mini_Board[8][1] << " | " << Mini_Board[8][2] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << Mini_Board[6][3] << " | " << Mini_Board[6][4] << " | " << Mini_Board[6][5] << "   |   " << Mini_Board[7][3] << " | " << Mini_Board[7][4] << " | " << Mini_Board[7][5] << "   |   " << Mini_Board[8][3] << " | " << Mini_Board[8][4] << " | " << Mini_Board[8][5] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << Mini_Board[6][6] << " | " << Mini_Board[6][7] << " | " << Mini_Board[6][8] << "   |   " << Mini_Board[7][6] << " | " << Mini_Board[7][7] << " | " << Mini_Board[7][8] << "   |   " << Mini_Board[8][6] << " | " << Mini_Board[8][7] << " | " << Mini_Board[8][8] << " " << endl;

  cout << endl;
  cout << endl;

  cout << " " << Main_Board[0] << " | " << Main_Board[1] << " | " << Main_Board[2] << "    Current Player : Player [Insert Number]" << endl;
  cout << "--- --- ---   Current Mini Board  : [Insert Number]" << endl;
  cout << " " << Main_Board[3] << " | " << Main_Board[4] << " | " << Main_Board[5] << endl;
  cout << "--- --- ---" << endl;
  cout << " " << Main_Board[6] << " | " << Main_Board[7] << " | " << Main_Board[8] << endl;

  return;
}

void Check_Mini_Board(void) {
  return;
}

void Check_Main_Board(void) {
  // FOR PLAYER ONE
  if ( // Check for matching marks in a row
    (Main_Board[0] == 'X' && Main_Board[1] == 'X' && Main_Board[2] == 'X') ||
    (Main_Board[3] == 'X' && Main_Board[4] == 'X' && Main_Board[5] == 'X') ||
    (Main_Board[7] == 'X' && Main_Board[7] == 'X' && Main_Board[8] == 'X')
  ) { Game_State-Winner = 1; }
  else if ( // Check for matching marks in a column
    (Main_Board[0] == 'X' && Main_Board[3] == 'X' && Main_Board[6] == 'X') ||
    (Main_Board[1] == 'X' && Main_Board[4] == 'X' && Main_Board[7] == 'X') ||
    (Main_Board[2] == 'X' && Main_Board[5] == 'X' && Main_Board[8] == 'X')
  ) { Game_State-Winner = 1; }
  else if ( // Check for matching marks in a diagonal
    (Main_Board[0] == 'X' && Main_Board[4] == 'X' && Main_Board[8] == 'X') ||
    (Main_Board[2] == 'X' && Main_Board[4] == 'X' && Main_Board[6] == 'X')
  ) { Game_State-Winner = 1; }

  // FOR PLAYER TWO
  else if ( // Check for matching marks in a row
    (Main_Board[0] == 'O' && Main_Board[1] == 'O' && Main_Board[2] == 'O') ||
    (Main_Board[3] == 'O' && Main_Board[4] == 'O' && Main_Board[5] == 'O') ||
    (Main_Board[7] == 'O' && Main_Board[7] == 'O' && Main_Board[8] == 'O')
  ) { Game_State-Winner = 2; }
  else if ( // Check for matching marks in a column
    (Main_Board[0] == 'O' && Main_Board[3] == 'O' && Main_Board[6] == 'O') ||
    (Main_Board[1] == 'O' && Main_Board[4] == 'O' && Main_Board[7] == 'O') ||
    (Main_Board[2] == 'O' && Main_Board[5] == 'O' && Main_Board[8] == 'O')
  ) { Game_State-Winner = 2; }
  else if ( // Check for matching marks in a diagonal
    (Main_Board[0] == 'O' && Main_Board[4] == 'O' && Main_Board[8] == 'O') ||
    (Main_Board[2] == 'O' && Main_Board[4] == 'O' && Main_Board[6] == 'O')
  ) { Game_State-Winner = 2; }

  return;
}

void Select_Mini_Board(void) {
  // To select the board properly
  // Because players are using 1 to 9
  // While he program uses 0 to 8
  Choice--;

  // More code here
  // Buffer = MiniBoard[Choice]
  return;
};

void Mark_Mini_Board(void) {
  // More code here
  return;
}

void Mark_Main_Board(void) {
  // More code here
  return;
}

int master(void) {
  Select_First_Mini_Board();
  uint8_t selection = 0;

  for (; Turns_Played <= Maximum_Possible_Playable_Turns; Turns_Played++) {
    if (Game_State-Winner == 1) {
      std::cout << "Player One Wins!" << std::endl;
      Game_State-Running = false;
    }
    else if (Game_State-Winner == 2) {
      std::cout << "Player Two Wins!" << std::endl;
      Game_State-Running = false;
    }

    Game_State-Current_Player = (i % 2) + 1;
    Mark_Mini_Board();
    Mark_Main_Board();
  }

  return 0;
}
