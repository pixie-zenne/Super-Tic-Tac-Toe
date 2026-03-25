#define master main

#include <cstdbool>
#include <cstring>
#include <iostream>

char buffer_board[9] = {
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
};
char main_board[9] = {
	'1', '2', '3', '4', '5', '6', '7', '8', '9'
};
char mini_board[9][9] = {
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
};

// The marks for the two players
// char player_mark[2] = {'X', 'O'};

// Game State
int winner = 0;
int current_player = 0;
int current_mini_board = 0;
int previous_mini_board = 0;

int invalid_mark_flag = 0;
int legal_turns_played = 0;
int maximum_possible_playeble_turns = 81;

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


 1 | 2 | 3   :: Current Player : 0
--- --- ---  :: Current Mini Board  : 0
 4 | 5 | 6   :: Move : Legal
--- --- ---  Select a mini board to mark
 7 | 8 | 9   >> ...
*/

void select_first_mini_board(void) {
  using namespace std;

	system("clear");

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

void print_the_game(void) {
  using namespace std;

	cout << endl;

  cout << " " << mini_board[0][0] << " | " << mini_board[0][1] << " | " << mini_board[0][2] << "   |   " << mini_board[1][0] << " | " << mini_board[1][1] << " | " << mini_board[1][2] << "   |   " << mini_board[2][0] << " | " << mini_board[2][1] << " | " << mini_board[2][2] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << mini_board[0][3] << " | " << mini_board[0][4] << " | " << mini_board[0][5] << "   |   " << mini_board[1][3] << " | " << mini_board[1][4] << " | " << mini_board[1][5] << "   |   " << mini_board[2][3] << " | " << mini_board[2][4] << " | " << mini_board[2][5] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << mini_board[0][6] << " | " << mini_board[0][7] << " | " << mini_board[0][8] << "   |   " << mini_board[1][6] << " | " << mini_board[1][7] << " | " << mini_board[1][8] << "   |   " << mini_board[2][6] << " | " << mini_board[2][7] << " | " << mini_board[2][8] << " " << endl;

  cout << endl;
  cout << "-----------     -----------     -----------" << endl;
  cout << endl;

  cout << " " << mini_board[3][0] << " | " << mini_board[3][1] << " | " << mini_board[3][2] << "   |   " << mini_board[4][0] << " | " << mini_board[4][1] << " | " << mini_board[4][2] << "   |   " << mini_board[5][0] << " | " << mini_board[5][1] << " | " << mini_board[5][2] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << mini_board[3][3] << " | " << mini_board[3][4] << " | " << mini_board[3][5] << "   |   " << mini_board[4][3] << " | " << mini_board[4][4] << " | " << mini_board[4][5] << "   |   " << mini_board[5][3] << " | " << mini_board[5][4] << " | " << mini_board[5][5] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << mini_board[3][6] << " | " << mini_board[3][7] << " | " << mini_board[3][8] << "   |   " << mini_board[4][6] << " | " << mini_board[4][7] << " | " << mini_board[4][8] << "   |   " << mini_board[5][6] << " | " << mini_board[5][7] << " | " << mini_board[5][8] << " " << endl;

  cout << endl;
  cout << "-----------     -----------     -----------" << endl;
  cout << endl;

  cout << " " << mini_board[6][0] << " | " << mini_board[6][1] << " | " << mini_board[6][2] << "   |   " << mini_board[7][0] << " | " << mini_board[7][1] << " | " << mini_board[7][2] << "   |   " << mini_board[8][0] << " | " << mini_board[8][1] << " | " << mini_board[8][2] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << mini_board[6][3] << " | " << mini_board[6][4] << " | " << mini_board[6][5] << "   |   " << mini_board[7][3] << " | " << mini_board[7][4] << " | " << mini_board[7][5] << "   |   " << mini_board[8][3] << " | " << mini_board[8][4] << " | " << mini_board[8][5] << " " << endl;
  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
  cout << " " << mini_board[6][6] << " | " << mini_board[6][7] << " | " << mini_board[6][8] << "   |   " << mini_board[7][6] << " | " << mini_board[7][7] << " | " << mini_board[7][8] << "   |   " << mini_board[8][6] << " | " << mini_board[8][7] << " | " << mini_board[8][8] << " " << endl;

  cout << endl;
  cout << endl;

  cout << " " << main_board[0] << " | " << main_board[1] << " | " << main_board[2] << "    Current Player : Player " << (current_player + 1) << endl;
  cout << "--- --- ---   Current Mini Board  : " << (current_mini_board + 1) << endl;
  cout << " " << main_board[3] << " | " << main_board[4] << " | " << main_board[5] << endl;
  cout << "--- --- ---   Select a mini board to mark" << endl;
  cout << " " << main_board[6] << " | " << main_board[7] << " | " << main_board[8] << "    :: ";

  return;
}

void check_main_board(void) {
  if (
		// For player one
		// Check for matching marks in a row
    (main_board[0] == 'X' && main_board[1] == 'X' && main_board[2] == 'X') ||
    (main_board[3] == 'X' && main_board[4] == 'X' && main_board[5] == 'X') ||
    (main_board[6] == 'X' && main_board[7] == 'X' && main_board[8] == 'X') ||

		// Check for matching marks in a column
    (main_board[0] == 'X' && main_board[3] == 'X' && main_board[6] == 'X') ||
    (main_board[1] == 'X' && main_board[4] == 'X' && main_board[7] == 'X') ||
    (main_board[2] == 'X' && main_board[5] == 'X' && main_board[8] == 'X') ||

		// Check for matching marks in a diagonal
    (main_board[0] == 'X' && main_board[4] == 'X' && main_board[8] == 'X') ||
    (main_board[2] == 'X' && main_board[4] == 'X' && main_board[6] == 'X')
  ) {
		winner = 1;
	}

  else if (
		// For player two
		// Check for matching marks in a row
    (main_board[0] == 'O' && main_board[1] == 'O' && main_board[2] == 'O') ||
    (main_board[3] == 'O' && main_board[4] == 'O' && main_board[5] == 'O') ||
		(main_board[6] == 'O' && main_board[7] == 'O' && main_board[8] == 'O') ||

		// Check for matching marks in a column
    (main_board[0] == 'O' && main_board[3] == 'O' && main_board[6] == 'O') ||
    (main_board[1] == 'O' && main_board[4] == 'O' && main_board[7] == 'O') ||
    (main_board[2] == 'O' && main_board[5] == 'O' && main_board[8] == 'O') ||

		// Check for matching marks in a diagonal
    (main_board[0] == 'O' && main_board[4] == 'O' && main_board[8] == 'O') ||
    (main_board[2] == 'O' && main_board[4] == 'O' && main_board[6] == 'O')
  ) {
		winner = 2;
	}

  return;
}

void mark_main_board(void) {
  if (
		// For player one
		// Check for matching marks in a row
    (mini_board[current_mini_board][0] == 'X' && mini_board[current_mini_board][1] == 'X' && mini_board[current_mini_board][2] == 'X') ||
		(mini_board[current_mini_board][3] == 'X' && mini_board[current_mini_board][4] == 'X' && mini_board[current_mini_board][5] == 'X') ||
		(mini_board[current_mini_board][6] == 'X' && mini_board[current_mini_board][7] == 'X' && mini_board[current_mini_board][8] == 'X') ||

		// Check for matching marks in a column
		(mini_board[current_mini_board][0] == 'X' && mini_board[current_mini_board][3] == 'X' && mini_board[current_mini_board][6] == 'X') ||
		(mini_board[current_mini_board][1] == 'X' && mini_board[current_mini_board][4] == 'X' && mini_board[current_mini_board][7] == 'X') ||
		(mini_board[current_mini_board][2] == 'X' && mini_board[current_mini_board][5] == 'X' && mini_board[current_mini_board][8] == 'X') ||

		// Check for matching marks in a diagonal
		(mini_board[current_mini_board][0] == 'X' && mini_board[current_mini_board][4] == 'X' && mini_board[current_mini_board][8] == 'X') ||
		(mini_board[current_mini_board][2] == 'X' && mini_board[current_mini_board][4] == 'X' && mini_board[current_mini_board][6] == 'X')
  ) {
		main_board[current_mini_board] = 'X';
	}

  if (
		// For player two
		// Check for matching marks in a row
    (mini_board[current_mini_board][0] == 'O' && mini_board[current_mini_board][1] == 'O' && mini_board[current_mini_board][2] == 'O') ||
		(mini_board[current_mini_board][3] == 'O' && mini_board[current_mini_board][4] == 'O' && mini_board[current_mini_board][5] == 'O') ||
		(mini_board[current_mini_board][6] == 'O' && mini_board[current_mini_board][7] == 'O' && mini_board[current_mini_board][8] == 'O') ||

		// Check for matching marks in a column
		(mini_board[current_mini_board][0] == 'O' && mini_board[current_mini_board][3] == 'O' && mini_board[current_mini_board][6] == 'O') ||
		(mini_board[current_mini_board][1] == 'O' && mini_board[current_mini_board][4] == 'O' && mini_board[current_mini_board][7] == 'O') ||
		(mini_board[current_mini_board][2] == 'O' && mini_board[current_mini_board][5] == 'O' && mini_board[current_mini_board][8] == 'O') ||

		// Check for matching marks in a diagonal
		(mini_board[current_mini_board][0] == 'O' && mini_board[current_mini_board][4] == 'O' && mini_board[current_mini_board][8] == 'O') ||
		(mini_board[current_mini_board][2] == 'O' && mini_board[current_mini_board][4] == 'O' && mini_board[current_mini_board][6] == 'O')
  ) {
		main_board[current_mini_board] = 'O';
	}

  return;
}

void mark_mini_board(void) {
	int player_mark = 0;
	int system_mark = 0;

	std::cin >> player_mark;

	// The players input are 1 to 9 while the software uses 0 to 8
	system_mark = player_mark - 1;

	// Validate the user's input
	// - Handles input that goes over the number nine (9)
	// - Handles input that goes below the number one (1)
	// - Handles input on an area that is already marked
	if (
		player_mark > 9 ||
		player_mark < 1 ||
		mini_board[current_mini_board][system_mark] == 'X' ||
		mini_board[current_mini_board][system_mark] == 'O'
	) {
		std::cin.clear();
		std::cin.ignore();

		invalid_mark_flag = 1;
		legal_turns_played--;

		return;
	}

	invalid_mark_flag = 0;
	// mini_board[current_mini_board][system_mark] = player_mark[current_player];
	if (current_player == 0) {
		mini_board[current_mini_board][system_mark] = 'X';
	}
	else if (current_player == 1) {
		mini_board[current_mini_board][system_mark] = 'O';
	}

	mark_main_board();
	previous_mini_board = current_mini_board;
	current_mini_board = system_mark;

  return;
}

int master(void) {

  select_first_mini_board();
	std::cin >> current_mini_board;

	if (current_mini_board < 1 || current_mini_board > 9) {
		std::cerr << std::endl << "Mini board selection is invalid" << std::endl;
		std::cerr << "Please select one of the following numbers next time:" << std::endl;
		std::cerr << "1, 2, 3, 4, 5, 6, 7, 8, or 9" << std::endl;
		std::cerr << std::endl << "Exiting" << std::endl;
		return 1;
	}

	// The players input are 1 to 9 while the software uses 0 to 8
	current_mini_board--;

	// The actual game
  for (; legal_turns_played <= maximum_possible_playeble_turns; legal_turns_played++) {

		system("clear");

		check_main_board();

    // Show the winner of the game
    if (winner == 1)  {
			std::cout << "Player One Wins!" << std::endl;
			return 0;
		}
    else if (winner == 2) {
			std::cout << "Player Two Wins!" << std::endl;
			return 0;
		}

    current_player = legal_turns_played % 2;

		if (invalid_mark_flag == 1) {
			std::cout << "Invalid Mark" << std::endl;
		}

		// Highlight the mini board
		for (int i = 0; i < 9; i++) {
			if (
				mini_board[current_mini_board][i] == ' '
			) {
				mini_board[current_mini_board][i] = static_cast<char>(i + '1');
			}
		}

		print_the_game();
		mark_mini_board();
		mark_main_board();

		// Unhighlight mini board
		for (int i = 0; i < 9; i++) {
			if (
				mini_board[previous_mini_board][i] == static_cast<char>(i + '1')
			) {
				mini_board[previous_mini_board][i] = ' ';
			}
		}
	}

  std::cout << std::endl << "Its a draw!" << std::endl;

  return 0;
}
