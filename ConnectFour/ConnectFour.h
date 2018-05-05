#ifndef CONNECT_FOUR_H
#define CONNECT_FOUR_H

#include <stdio.h>
#include <Windows.h>
#include <math.h>

#define MAX_ROW 6
#define MAX_COL 7

typedef enum occupied
{
	False, 
	True
} Occupied;

typedef struct location
{
	int row;
	int col;
} Location;

typedef struct cell
{
	char color;
	Occupied isOccupied;
	Location place;
} Cell;

typedef struct player {
	char color;
} Player;

void init_board(Cell board[][MAX_COL], int rows, int cols);
void draw_board(Cell board[][MAX_COL], int rows, int cols);
void place_piece(Cell board[][MAX_COL], int choice, Player player);
int check_win(Cell board[][MAX_COL], Player player);

#endif