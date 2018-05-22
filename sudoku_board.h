#ifndef SUDOKU_SUDOKU_BOARD_H
#define SUDOKU_SUDOKU_BOARD_H

#define N 3 /* number of lines in a single block */
#define M 3 /* number of columns in a single block */
#define BOARD_SIZE N*M*N*M

typedef struct {
    int value;
    int fixed; /* boolean value depicting whether the cell on the board is fixed or not */
    int impossible_values[N*M];
} Cell;

typedef struct{
    int rows;
    int columns;
    Cell* cells[BOARD_SIZE];
} SudokuBoard;

SudokuBoard* sb_createSudokuBoard(int rows, int columns);
void sb_print(SudokuBoard* sb);
void sb_removeUnfixedCells(SudokuBoard *sb);
void sb_destroyBoard(SudokuBoard* sb);
SudokuBoard* sb_deepCloneBoard(SudokuBoard *template_sb);
int sb_isFull(SudokuBoard *sb);


#endif
