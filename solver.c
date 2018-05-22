#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "solver.h"
#include "sudoku_board.h"
#include "main_aux.h"

int getNextValue(int *possible_values, int num_of_pos_vals, int is_random) {
    int val;
    if (is_random)
        val = possible_values[rand() % num_of_pos_vals];
    else
        val = possible_values[0];
    return val;
}

/*
 * @param: pointer to cell
 * @param: pointer to a boolean array of possible values, initialized to '1' in all cells
 * @params: index of cell, pointer to sudoku board.
 *
 * This function updates the possible values array for the given cell, according to the rules of the game,
 *
 * @return: number of possible values.
 *
 */
int calcPossibleValues(Cell* current, int *possible_values, int idx, SudokuBoard* sb){
    int column = idx % (N*M);
    int row = idx / (N*M);
    int column_block = column / M;
    int row_block = row / N;
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
    for (i = 0; i < N; ++i){
        for(j = 0; j < M; ++j) {
            value = sb->cells[(row_block * N + i) * N*M + column_block * M + j]->value;
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

SudokuBoard* slvr_SolveBoard(SudokuBoard* sudokuBoard, int is_random){
    int i = 0;
    while (i < BOARD_SIZE && sudokuBoard->cells[i]->fixed){
        ++i;
    }
    return SolveBoardRec(sudokuBoard, i, is_random);
}

SudokuBoard* SolveBoardRec(SudokuBoard* sudokuBoard, int i, int is_random) {
    int j, num_of_pos_vals;
    Cell* currentCell;
    int possible_values[N*M];
    if (i == -1) {
        printf("asdfkjasldjflkasdf");
        sb_destroyBoard(sudokuBoard);
        return NULL;
    }
    if (i == BOARD_SIZE) {
        return sudokuBoard;
    }
    currentCell= sudokuBoard->cells[i];
    if (currentCell->fixed){
        return SolveBoardRec(sudokuBoard, --i, is_random);
    }
    if (currentCell->value){
        currentCell->impossible_values[currentCell->value - 1] = 1; /* make value impossible */
    }
    for (j = 0; j < N*M; ++j)
        possible_values[j] = 1;
    num_of_pos_vals = calcPossibleValues(currentCell, &possible_values[0], i, sudokuBoard);
    switch (num_of_pos_vals) {
        case 0:
            aux_empty_array(currentCell->impossible_values);
            currentCell->value = 0;
            return SolveBoardRec(sudokuBoard, --i, is_random);
        case 1:
            currentCell->value = possible_values[0];
        default:
            currentCell->value = getNextValue(&possible_values[0], num_of_pos_vals, is_random);
    }
    ++i;
    while (i < BOARD_SIZE && sudokuBoard->cells[i]->fixed){
        ++i;
    }
    return SolveBoardRec(sudokuBoard, i, is_random);

}
/*
 * This function checks whether value z is valid to enter to the cell in index 'idx'
 * @return: 1 if valid is valid in cell idx, 0 otherwise.
 */
int slvr_isValid(SudokuBoard* sudokuBoard, int idx, int value) {
    int j;
    Cell* currentCell;
    int* possible_values = calloc(N*M, sizeof(int));
    if (!possible_values){ /* allocation failed */
        printf("Error: %s has failed\n", "slvr_isValid");
        exit(1);
    }
    for (j = 0; j < N*M; ++j)
        possible_values[j] = 1;
    currentCell = sudokuBoard->cells[idx];
    calcPossibleValues(currentCell, possible_values, idx, sudokuBoard);
    for (j = 0; j < (N*M); ++j){
        if (possible_values[j] == value){
            free(possible_values);
            return 1;
        }
    }
    free(possible_values);
    return 0;
}



