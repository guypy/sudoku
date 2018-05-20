#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "solver.h"
#include "sudoku_board.h"
#include "main_aux.h"

int getRandValue(int* possible_values, int num_of_pos_vals) {
    int val = possible_values[rand() % num_of_pos_vals];
    return val;
}

int calcPossibleValues(Cell* current, int *possible_values, int idx, SudokuBoard* sb){
    int column = idx % (N*M);
    int row = idx / (N*M);
    /* mark values in the same column as impossible */
    int i, j, pos_val_count, value;
    for (i = 0; i < (N*M); ++i){
        value = sb->cells[i*(N*M) + column]->value;
        if (value > 0) {
            possible_values[value - 1] = 0;
        }
    }
    /* mark values in the same row as impossible */
    for (i = 0; i < (N*M); ++i){
        value = sb->cells[row*(N*M) + i]->value;
        if (value > 0) {
            possible_values[value - 1] = 0;
        }
    }
    /* mark values in the same block as impossible */
    int column_block = column / M; //0
    int row_block = row / N; //0
    for (i = 0; i < N; ++i){
        for(j = 0; j < M; ++j) {
            value = sb->cells[(row_block * N + i) * N*M + column_block * M + j]->value; //0, 1, 2, 9, 10, 11
            if (value > 0) {
                possible_values[value - 1] = 0;
            }
        }
    }
    /* change possible values to contain the actual possible values */
    pos_val_count = 0;
    for (i = 0; i < N*M; ++i){
        if (possible_values[i] == 1 && current->impossible_values[i] == 0){
            possible_values[pos_val_count] = i + 1;
            pos_val_count++;
        }
    }
    return pos_val_count;
}

SudokuBoard* slvr_SolveBoard(SudokuBoard* sudokuBoard){
    return SolveBoardRec(sudokuBoard, 0);
}

SudokuBoard* SolveBoardRec(SudokuBoard* sudokuBoard, int i) {
    sb_print(sudokuBoard);
    printf("ITERATION NUMBER %d\n\n", i);

    int j;
    if (i == -1) {
        return NULL;
    }
    if (i == BOARD_SIZE) {
        return sudokuBoard;
    }
    Cell* current= sudokuBoard->cells[i];
    if (current->fixed){
        return SolveBoardRec(sudokuBoard, --i);
    }
    if (current->value){
        current->impossible_values[current->value - 1] = 1; /* make value impossible */
    }
    int* possible_values = calloc(N*M, sizeof(int));
    for (j = 0; j < N*M; ++j)
        possible_values[j] = 1;
    int num_of_pos_vals = calcPossibleValues(current, possible_values, i, sudokuBoard);
    if (num_of_pos_vals == 0){
        aux_empty_array(current->impossible_values);
        current->value = 0;
        return SolveBoardRec(sudokuBoard, --i);
    }
    if (num_of_pos_vals == 1){
        current->value = possible_values[0];
    }
    else{
        current->value = getRandValue(possible_values, num_of_pos_vals);
    }
    ++i;
    while (i < BOARD_SIZE && sudokuBoard->cells[i]->fixed){
        ++i;
    }
    free(possible_values);
    return SolveBoardRec(sudokuBoard, i);

}

int slvr_isValid(SudokuBoard* sudokuBoard, int i, int j) {
    return checkRow(sudokuBoard, i, j) && checkColumn(sudokuBoard, i, j) && checkBlock(sudokuBoard, i, j);
}

int checkBlock(SudokuBoard* sudokuBoard, int i, int j) {
    return 0;
}

int checkColumn(SudokuBoard* sudokuBoard, int i, int j) {
    return 0;
}

int checkRow(SudokuBoard* sudokuBoard, int i, int j) {
    return 0;
}


