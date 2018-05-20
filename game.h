#ifndef SUDOKU_GAME_H
#define SUDOKU_GAME_H

#define SET "set"
#define HINT "hint"
#define VALIDATE  "validate"
#define RESTART  "restart"
#define EXIT  "exit"
#include "sudoku_board.h"

int gm_StartGame();
void setAllCellsFixed(SudokuBoard *game_sb);

#endif
