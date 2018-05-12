#include <stdlib.h>
#include "sudoku_board.h"

SudokuBoard* sb_CreateSudokuBoard(int rows, int columns){
    int i, j;
    SudokuBoard* res = (SudokuBoard*) malloc(sizeof(SudokuBoard));
    if (!res){ // allocation failed
        return NULL;
    }
    res->rows = rows;
    res->columns = columns;
    for (i = 0; i < BOARD_SIZE; ++i){
        res->cells[i]->value = 0;
        res->cells[i]->fixed = 0; // false
        for (j = 0; j < N*M; ++j) {
            res->cells[i]->impossible_values[j] = 1;
        }
    }

}
