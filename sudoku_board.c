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
        res->cells[i] = (Cell*)calloc(1, sizeof(Cell));
    }
    return res;
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

void sb_RemoveUnfixedCells(SudokuBoard* sb){
    int i;
    for (i = 0; i < BOARD_SIZE; ++i){
        if (sb->cells[i]->fixed == 0){
            sb->cells[i]->value = 0;
        }
    }
}