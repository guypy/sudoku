#ifndef SUDOKU_SUDOKU_BOARD_H
#define SUDOKU_SUDOKU_BOARD_H

#define N 3 // number of lines in a single block
#define M 3 // number of columns in a single block
#define BOARD_SIZE N*M*N*M

typedef struct {
    int value;
    int fixed; // boolean value depicting whether the cell on the board is fixed or not
    int impossible_values[N*M];
} Cell;

typedef struct{
    int rows;
    int columns;
    Cell* cells[BOARD_SIZE];
} SudokuBoard;

SudokuBoard* sb_CreateSudokuBoard(int rows, int columns);
void sb_print(SudokuBoard* sb);


#endif //SUDOKU_SUDOKU_BOARD_H
