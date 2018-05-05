// Complete the game of Connect Four from this starter code to recieve
// bonus points!

#include "ConnectFour.h"

int main(void)
{
	Cell board[MAX_ROW][MAX_COL] = { {/*row 0*/{'\0', False, {0, 0}}} };
	Player player1 = { 'B' }, player2 = { 'Y' };
	int op_choice = 0, player1_choice = -1, player2_choice = -1, p1_win = 0, p2_win = 0;
	srand(time(NULL));

	printf_s("Welcome to the Connect Four game\n");
	printf_s("Please choose the opponent you would like to play against\n");
	printf_s("1. Computer\n");
	printf_s("2. Human\n");
	while (op_choice < 1 || op_choice > 2) {
		printf_s("Your choice: ");
		scanf_s("%d", &op_choice);
	}

	printf_s("\n\n");
	printf_s("Board: \n\n");

	init_board(board, MAX_ROW, MAX_COL);
	draw_board(board, MAX_ROW, MAX_COL);

	system("pause");

	// Against Computer
	if (op_choice == 1) {

		while (p1_win == 0 && p2_win == 0) {

			system("cls");
			printf_s("Player 1's turn\n");
			do {
				printf_s("Player 1 please select a column (between 0 - 6): ");
				scanf_s("%d", &player1_choice);
			} while (player1_choice > 6 || player1_choice < 0);

			place_piece(board, player1_choice, player1);
			draw_board(board, MAX_ROW, MAX_COL);
			p1_win = check_win(board, player1);

			system("pause");
			system("cls");
			printf_s("Player 2's turn\n");
			player2_choice = rand() % 7;

			place_piece(board, player2_choice, player2);
			draw_board(board, MAX_ROW, MAX_COL);
			p2_win = check_win(board, player2);

			system("pause");
			system("cls");

		}

	}

	// Against Human
	else {
		while (p1_win == 0 && p2_win == 0) {

			system("cls");
			printf_s("Player 1's turn\n");
			do {
				printf_s("Player 1 please select a column (between 0 - 6): ");
				scanf_s("%d", &player1_choice);
			} while (player1_choice > 6 || player1_choice < 0);

			place_piece(board, player1_choice, player1);
			draw_board(board, MAX_ROW, MAX_COL);
			p1_win = check_win(board, player1);

			system("pause");
			system("cls");
			printf_s("Player 2's turn\n");
			do {
				printf_s("Player 2 please select a column (between 0 - 6): ");
				scanf_s("%d", &player2_choice);
			} while (player2_choice > 6 || player2_choice < 0);

			place_piece(board, player2_choice, player2);
			draw_board(board, MAX_ROW, MAX_COL);
			p2_win = check_win(board, player2);

			system("pause");
			system("cls");

		}
	}
	
	// Print out winner of the game
	if (p1_win == 1) {
		printf_s("Player 1 wins!\n");
	}
	else if (p2_win == 1) {
		printf_s("Player 2 wins!\n");
	}

	system("pause");

	return 0;
}