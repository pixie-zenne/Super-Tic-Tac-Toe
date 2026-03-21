#define master main

#include <cstdbool>
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

// Game State
int Winner = 0;
int Current_Player = 0;
int Current_Mini_Board = 0;
int Previous_Mini_Board = 0;

int Legal_Turns_Played = 0;
int Maximum_Possible_Playable_Turns = 81;

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
--- --- ---		Select a mini board to mark
 7 | 8 | 9		:: 
*/

void Select_First_Mini_Board(void) {
  using namespace std;

	cout << endl;

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
  cout << "--- --- ---   Please select the first board" << endl;
  cout << "   |   |      :: ";

  return;
}

void Print_The_Game(void) {
  using namespace std;

	cout << endl;

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
  cout << "--- --- ---   Select a mini board to mark" << endl;
  cout << " " << Main_Board[6] << " | " << Main_Board[7] << " | " << Main_Board[8] << "    :: ";

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
  ) { Winner = 1; }
  else if ( // Check for matching marks in a column
    (Main_Board[0] == 'X' && Main_Board[3] == 'X' && Main_Board[6] == 'X') ||
    (Main_Board[1] == 'X' && Main_Board[4] == 'X' && Main_Board[7] == 'X') ||
    (Main_Board[2] == 'X' && Main_Board[5] == 'X' && Main_Board[8] == 'X')
  ) { Winner = 1; }
  else if ( // Check for matching marks in a diagonal
    (Main_Board[0] == 'X' && Main_Board[4] == 'X' && Main_Board[8] == 'X') ||
    (Main_Board[2] == 'X' && Main_Board[4] == 'X' && Main_Board[6] == 'X')
  ) { Winner = 1; }

  // FOR PLAYER TWO
  else if ( // Check for matching marks in a row
    (Main_Board[0] == 'O' && Main_Board[1] == 'O' && Main_Board[2] == 'O') ||
    (Main_Board[3] == 'O' && Main_Board[4] == 'O' && Main_Board[5] == 'O') ||
    (Main_Board[7] == 'O' && Main_Board[7] == 'O' && Main_Board[8] == 'O')
  ) { Winner = 2; }
  else if ( // Check for matching marks in a column
    (Main_Board[0] == 'O' && Main_Board[3] == 'O' && Main_Board[6] == 'O') ||
    (Main_Board[1] == 'O' && Main_Board[4] == 'O' && Main_Board[7] == 'O') ||
    (Main_Board[2] == 'O' && Main_Board[5] == 'O' && Main_Board[8] == 'O')
  ) { Winner = 2; }
  else if ( // Check for matching marks in a diagonal
    (Main_Board[0] == 'O' && Main_Board[4] == 'O' && Main_Board[8] == 'O') ||
    (Main_Board[2] == 'O' && Main_Board[4] == 'O' && Main_Board[6] == 'O')
  ) { Winner = 2; }

  return;
}

void Select_Mini_Board(void) {
  return;
};

void Mark_Mini_Board(void) {
	int Mark = 0;

	std::cin >> Mark;

	if (Mark > 9 || Mark < 1 || std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();

		std::cout << std::endl << "Invalid mark" << std::endl;
		Legal_Turns_Played--;

		return;
	}

	Previous_Mini_Board = Current_Mini_Board;
	Current_Mini_Board = Mark;

  return;
}

void Mark_Main_Board(void) {
  return;
}

int master(void) {

  Select_First_Mini_Board();
	std::cin >> Current_Mini_Board;
	std::cout << Current_Mini_Board;

	if (Current_Mini_Board < 1 || Current_Mini_Board > 9) {
		std::cerr << std::endl << "Mini board selection is invalid" << std::endl;
		std::cerr << "Please select one of the following numbers next time:" << std::endl;
		std::cerr << "1, 2, 3, 4, 5, 6, 7, 8, or 9" << std::endl;
		std::cerr << std::endl << "Exiting" << std::endl;
		return 1;
	}

	// The players input are 1 to 9 while the software uses 0 to 8
	Current_Mini_Board--;

	// The actual game
  for (; Legal_Turns_Played <= Maximum_Possible_Playable_Turns; Legal_Turns_Played++) {
    // Show the winner of the game
    if (Winner == 1)  { std::cout << "Player One Wins!" << std::endl; }
    else if (Winner == 2) { std::cout << "Player Two Wins!" << std::endl; }

    Current_Player = (Legal_Turns_Played % 2) + 1;

		Print_The_Game();
	  Mark_Mini_Board();
  }

  std::cout << std::endl << "Its a draw!" << std::endl;

  return 0;
}
