#include "ConnectFour.h"

/**
* Function name : init_board
* Date Created  : 2 May 2018
* Usage         : void init_board(Cell board[][MAX_COL], int rows, int cols)
* Definition    : This function initializes the game board
* Pre-condition : Game board is of Cell struct type
* Post-condition: Game board initialized
*/

void init_board(Cell board[][MAX_COL], int rows, int cols)
{
	int row_index = 0, col_index = 0;

	for (; row_index < rows; ++row_index)
	{
		for (col_index = 0; col_index < cols; ++col_index)
		{
			board[row_index][col_index].color = '\0';
			board[row_index][col_index].isOccupied = False;
			board[row_index][col_index].place.row = row_index;
			board[row_index][col_index].place.col = col_index;
		}
	}
}

/**
* Function name : draw_board
* Date Created  : 2 May 2018
* Usage         : void draw_board(Cell board[][MAX_COL], int rows, int cols)
* Definition    : This function prints the game board on to the console
* Pre-condition : Game board is of Cell struct type
* Post-condition: Game board printed on to the screen
*/

void draw_board(Cell board[][MAX_COL], int rows, int cols) {

	int row_index = 0, col_index = 0;

	printf_s(" 0  1  2  3  4  5  6	\n");

	for (; row_index < rows; row_index++) {

		for (col_index = 0; col_index < cols; col_index++) {

			if (board[row_index][col_index].isOccupied == False) {
				printf_s(" O ");
			}
			else {
				printf_s("%c ", board[row_index][col_index].color);
			}

		}

		putchar('\n');

	}

}

/**
* Function name : place_piece
* Date Created  : 2 May 2018
* Usage         : void place_piece(Cell board[][MAX_COL], int choice, Player player)
* Definition    : This function places the respective player's color onto the board
* Pre-condition : Game board is of Cell struct type, the player has chosen where to place his piece, and there is a player
* Post-condition: Player color placed on the board
*/

void place_piece(Cell board[][MAX_COL], int choice, Player player) {

	for (int rows = MAX_ROW - 1; rows >= 0; rows--) {

		if (board[rows][choice].isOccupied == False) {

			board[rows][choice].color = player.color;
			board[rows][choice].isOccupied = True;
			break;

		}

	}

}

/**
* Function name : check_win(
* Date Created  : 2 May 2018
* Usage         : int check_win(Cell board[][MAX_COL], Player player)
* Definition    : This function checks if a player has connected 4 of his own colors either vertically, horizontally or diagonally.
* Pre-condition : Game board is of Cell struct type, and there is a player
* Post-condition: Result shows if the player has won or not
*/

int check_win(Cell board[][MAX_COL], Player player) {

	char color = player.color;

	for (int row = 0; row < MAX_ROW; row++) {

		for (int col = 0; col < MAX_COL; col++) {

			if (board[row][col].color == color) {

				// Vertical Check

				if (board[row + 1][col].color == color) {

					if (board[row + 2][col].color == color) {

						if (board[row + 3][col].color == color) {

							return 1;

						}

					}

				}

				// End Vertical Check

				// Horizontal Check

				else if (board[row][col + 1].color == color) {

					if (board[row][col + 2].color == color) {

						if (board[row][col + 3].color == color) {

							return 1;

						}

					}

				}

				// End Horizontal Check

				// Diagonal Check Left

				else if (board[row + 1][col - 1].color == color) {

					if (board[row + 2][col - 2].color == color) {

						if (board[row + 3][col - 3].color == color) {

							return 1;

						}

					}

				}

				// End Left Diagonal Check

				else if (board[row + 1][col - 1].color == color) {

					if (board[row + 2][col - 2].color == color) {

						if (board[row + 3][col - 3].color == color) {

							return 1;

						}

					}

				}

				// Diagonal Check Right

				else if (board[row + 1][col + 1].color == color) {

					if (board[row + 2][col + 2].color == color) {

						if (board[row + 3][col + 3].color == color) {

							return 1;

						}

					}

				}

				// End Right Diagonal Check

				else {

					return 0;

				}

			}

		}

	}

}