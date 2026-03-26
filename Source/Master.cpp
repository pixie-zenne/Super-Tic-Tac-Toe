#define master main

#include <cstring>
#include <iostream>
#include <vector>

#define THEORETICALLY_MAXIMUM_PLAYABLE_TURNS 81

bool invalid_mark_flag = false;
int game_mode = 0;

char player_mark[2] = {'X', 'O'};
int current_player = 0;

int current_mini_board = 0;
int previous_mini_board = 0;

int legal_turns_played = 0;
int winner = 0;

char main_board[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
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

void select_game_mode(void) {
	bool is_selecting = true;

	system("clear");
	while (is_selecting == true) {
		std::cout << "Please select the game mode" << std::endl;
		std::cout << "[1] Classic" << std::endl;
		std::cout << "[2] Open" << std::endl;
		std::cout << ">> ";
		std::cin >> game_mode;

		if (game_mode > 2 || game_mode < 1) {
			std::cin.clear();
			std::cin.ignore();
		}
		else break;
	}

	return;
}

void select_first_mini_board(void) {
	using namespace std;

	bool is_selecting = true;

	while (is_selecting == true) {
		system("clear");

		cout << "   |   |     |     |   |     |     |   |   " << endl;
	  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
	  cout << "   | 1 |     |     | 2 |     |     | 3 |   " << endl;
	  cout << "--- --- ---  |  --- --- ---  |  --- --- ---" << endl;
	  cout << "   |   |     |     |   |     |     |   |   " << endl;
	  cout << endl;
	  cout << "-----------     -----------     -----------" << endl;
	  cout << endl;
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
	 	cout << "   |   |      Please select one of the following numbers:" << endl;
	  cout << "--- --- ---   1, 2, 3, 4, 5, 6, 7, 8, or 9" << endl;
	  cout << "   |   |" << endl;
	  cout << "--- --- ---   Please select the first board" << endl;
	  cout << "   |   |      >> ";
		cin >> current_mini_board;

		if (current_mini_board < 1 || current_mini_board > 9) {
			cin.clear();
			cin.ignore();
			}
		else break;
	}

	return;
}

void print_the_game(void) {
  using namespace std;

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

  cout << " " << main_board[0] << " | " << main_board[1] << " | " << main_board[2] << "    Current Player : " << (current_player + 1);
		if (current_player == 0) cout << " (X)";
		else cout << " (O)";
		cout << endl;
  cout << "--- --- ---   Current Mini Board  : " << (current_mini_board + 1) << endl;
  cout << " " << main_board[3] << " | " << main_board[4] << " | " << main_board[5] << "    Move " << legal_turns_played << " : ";
		if (invalid_mark_flag == true) cout << "Illegal ";
		else cout << "Legal ";
		cout << endl;
  cout << "--- --- ---   Select a mini board to mark" << endl;
  cout << " " << main_board[6] << " | " << main_board[7] << " | " << main_board[8] << "    >> ";

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
	int mark = 0;
	int mark_input = 0;
	std::cin >> mark_input;

	// The player's input are 1 to 9 while the software uses 0 to 8
	mark = mark_input - 1;

	if (
		mark_input > 9 ||
		mark_input < 1 ||
		mini_board[current_mini_board][mark] == 'X' ||
		mini_board[current_mini_board][mark] == 'O'
	) {
		std::cin.clear();
		std::cin.ignore();

		invalid_mark_flag = true;
		legal_turns_played--;

		return;
	}

	invalid_mark_flag = false;
	mini_board[current_mini_board][mark] = player_mark[current_player];

	mark_main_board();

	if (game_mode == 1) {
		if (main_board[mark] == '-') {
			previous_mini_board = current_mini_board;
			current_mini_board = mark;
		}
	}

	else if (game_mode == 2) {
		previous_mini_board = current_mini_board;
		current_mini_board = mark;
	}

  return;
}

void add_mini_board_highlight(void) {
	for (int i = 0; i < 9; i++)
		if ( mini_board[current_mini_board][i] == ' ')
			mini_board[current_mini_board][i] = static_cast<char>(i + '1');

	return;
}

void remove_mini_board_highlight(void) {
	for (int i = 0; i < 9; i++)
		if (mini_board[previous_mini_board][i] == static_cast<char>(i + '1'))
			mini_board[previous_mini_board][i] = ' ';

	return;
}

void game_conclusion(void) {
	remove_mini_board_highlight();
	print_the_game();
	return;
}

int master(void) {
	select_game_mode();
	select_first_mini_board();

	// The player's input are 1 to 9 while the software uses 0 to 8
	current_mini_board--;

  while (legal_turns_played <= THEORETICALLY_MAXIMUM_PLAYABLE_TURNS) {
		system("clear");

		check_main_board();

		switch (winner) {
			case 1:
				std::cout << "Player one win!" << std::endl;
				game_conclusion();
				return 0;
			case 2:
				std::cout << "Player two wins!" << std::endl;
				game_conclusion();
				return 0;
		}	

    current_player = legal_turns_played % 2;

		add_mini_board_highlight();

		print_the_game();
		mark_mini_board();

		remove_mini_board_highlight();

		legal_turns_played++;
	}

	std::cout << std::endl << "Its a draw!" << std::endl;
  return 0;
}
