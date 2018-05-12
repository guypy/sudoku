#include <stdlib.h>
#include <stdio.h>
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

void sb_print(SudokuBoard* sb) {
    int i;
    for (i = 0; i < BOARD_SIZE; ++i){
        if (i % (N*M*M) == 0 && i != 0)
            printf("|\n----------------------------------\n| ");
        else if (i % (N*M) == 0 && i != 0)
            printf("|\n| ");
        else if (i % N == 0) {
            printf("| ");
        }
        if (sb->cells[i]->value) {
            printf("%d. ", sb->cells[i]->value);
        } else {
            printf("   ");
        }
    }
    printf("|\n----------------------------------\n");

}