#include <stdio.h>
#include <stdlib.h>
#include "sudoku_board.h"
#include "solver.h"

int main() {
    SudokuBoard* sb = sb_CreateSudokuBoard(9,9);
    slvr_SolveBoard(sb);
    sb_print(sb);


    return 0;
}