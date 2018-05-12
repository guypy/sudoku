//
// Created by Yuval Barzam on 5/12/18.
//

#include "sudoku_board.h"

#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

int slvr_isValid(SudokuBoard* sudokuBoard, int i, int j);
SudokuBoard* SolveBoardRec(SudokuBoard* sudokuBoard, int i);
int checkBlock(SudokuBoard* sudokuBoard, int i, int j);
int checkColumn(SudokuBoard* sudokuBoard, int i, int j);
int checkRow(SudokuBoard* sudokuBoard, int i, int j);

#endif //SUDOKU_SOLVER_H
