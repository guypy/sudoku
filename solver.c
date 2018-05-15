#include <stdbool.h>
#include <stdlib.h>
#include "solver.h"
#include "sudoku_board.h"



int getRandValue(int* possible_values, int num_of_pos_vals) {
    return possible_values[rand() % num_of_pos_vals];
}

int calcPossibleValues(Cell* current, int* possible_values, int idx){
    int column = idx % (N*M);
    int row = idx / (N*M);
    // mark values in the same column as impossible
    int i;
    for (i = 0; i < (N*M); ++i){
        possible_values[i*(N*M) + column] = 0;
    }
    // mark values in the same row as impossible
    for (i = 0; i < (N*M); ++i){
        possible_values[row*(N*M) + i] = 0;
    }
//    // mark values in the same block as impossible
//    int column_block = column / M;
//    int row_block = row / N;
//    for (i = 0; i < (N*M); ++i){
//        possible_values[????????] = 0;
//    }
}

SudokuBoard* slvr_SolveBoard(SudokuBoard* sudokuBoard){
    return SolveBoardRec(sudokuBoard, 0);
}

SudokuBoard* SolveBoardRec(SudokuBoard* sudokuBoard, int i) {
    if (i == -1) {
        return NULL;
    }
    if (i == BOARD_SIZE - 1) {
        return sudokuBoard;
    }
    Cell* current= sudokuBoard->cells[i];
    if (current->fixed){
        return SolveBoardRec(sudokuBoard, --i);
    }
    if (current->value){
        current->impossible_values[current->value - 1] = 1; // make value impossible
    }
    int possible_values[N*M] = {1};
    int num_of_pos_vals = calcPossibleValues(current, possible_values, i);
    if (num_of_pos_vals == 0){
        aux_empty_array(current->impossible_values);
        return SolveBoardRec(sudokuBoard, --i);
    }
    if (num_of_pos_vals == 1){
        current->value = possible_values[0];
    }
    else{
        current->value = getRandValue(possible_values, num_of_pos_vals);
    }
    ++i;
    while (sudokuBoard->cells[i]->fixed){
        ++i;
    }
    return SolveBoardRec(sudokuBoard, i);

}

int slvr_isValid(SudokuBoard* sudokuBoard, int i, int j) {
    return checkRow(sudokuBoard, i, j) && checkColumn(sudokuBoard, i, j) && checkBlock(sudokuBoard, i, j)
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


