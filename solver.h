#include "sudoku_board.h"

#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

int slvr_isValid(SudokuBoard* sudokuBoard, int idx, int value);
SudokuBoard* slvr_SolveBoard(SudokuBoard* sudokuBoard, int is_random);
SudokuBoard* SolveBoardRec(SudokuBoard* sudokuBoard, int i, int is_random);
int checkBlock(SudokuBoard* sudokuBoard, int i, int j);
int checkColumn(SudokuBoard* sudokuBoard, int i, int j);
int checkRow(SudokuBoard* sudokuBoard, int i, int j);

#endif //SUDOKU_SOLVER_H
