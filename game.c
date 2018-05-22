#include "game.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "solver.h"
#include "sudoku_board.h"

int initialize(){
    int num_of_fixed;
    printf("Please enter the number of cells to fill [0-%d]:\n", BOARD_SIZE - 1);
    num_of_fixed = prsr_readInt();
    while (num_of_fixed < 0 || num_of_fixed >= BOARD_SIZE){
        printf("Error: Invalid number of cells to fill (should be between 0 and %d)\n", BOARD_SIZE - 1);
        printf("Please enter the number of cells to fill [0-%d]:\n", BOARD_SIZE - 1);
        num_of_fixed = prsr_readInt();
    }
    return num_of_fixed;
}

SudokuBoard* generateSolution(){
    SudokuBoard* sb = sb_createSudokuBoard(N, M);
    int is_random = 1;
    slvr_SolveBoard(sb, is_random);
    return sb;
}

/*
 * This function receives a pointer to a game board, selects h fixed values within it, and deletes the remaining values
 */
SudokuBoard* generatePuzzle(SudokuBoard *game_sb, int h){
    int i, x, y, idx;
    for (i = 0; i < h; ++i){
        y = rand() % (N*M); /* random row */
        x = rand() % (N*M); /* random column */
        idx = y*(N*M) + x;
        if (!game_sb->cells[idx]->fixed){ /* if cell is not yet fixed, make it fixed */
            game_sb->cells[idx]->fixed = 1;
        }
        else{
            i--;
        }
    }
    sb_removeUnfixedCells(game_sb);
    return game_sb;
}

/*
 * This functions sets the value of cell <x,y> to z (x = col, y = row).
 * If <x,y> is fixed, an error is printed out.
 * If value z is invalid for cell <x,y> by the rules of the game, an error is printed out.
 * If puzzle is solved, a message is printed out.
 * @pre: x,y,z are legal values. 1 <= x,y <= N*M  0 <= z <= N*M
 */
int set(int x, int y, int z, SudokuBoard *game_sb){
    int idx;
    if (x == -1 || y == -1 || z == -1) {
        printf("Error: invalid command\n");
        return 1;
    }
    idx = (N*M)*(y - 1) + (x - 1);
    if (game_sb->cells[idx]->fixed){
        printf("Error: cell is fixed\n");
        return 1;
    }
    if (z == 0 || slvr_isValid(game_sb, idx, z)){
        game_sb->cells[idx]->value = z;
    }
    else{
        printf("Error: value is invalid\n");
        return 1;
    }
    if (sb_isFull(game_sb)){
        printf("Puzzle solved successfully\n");
        return 2;
    }
    return 0;
}

void hint(int x, int y, SudokuBoard *solved_sb){
    int hint;
    if (x == -1 || y == -1){
        printf("Error: invalid command\n");
        return;
    }
    hint = solved_sb->cells[N*M*(y - 1) + (x - 1)]->value;
    printf("Hint: set cell to %d\n", hint);
}

SudokuBoard* validate(SudokuBoard *cloned_game_sb){
    int is_random = 0;
    SudokuBoard* res;
    setAllCellsFixed(cloned_game_sb);
    res = slvr_SolveBoard(cloned_game_sb, is_random);
    if (res == NULL)
        printf("Validation failed: board is unsolvable\n");
    else {
        printf("Validation passed: board is solvable\n");
        return res;
    }
    return NULL;
}

void setAllCellsFixed(SudokuBoard* game_sb) {
    int i;
    for (i=0; i < BOARD_SIZE; i++) {
        if (game_sb->cells[i]->value != 0)
            game_sb->cells[i]->fixed = 1;
    }
}

int restart(SudokuBoard *solved_sb, SudokuBoard *game_sb){
    sb_destroyBoard(solved_sb);
    sb_destroyBoard(game_sb);
    return gm_play();
}

int gm_play(){
    int is_solved = 0;
    int num_of_fixed, res;
    char* cmd = NULL;
    int action_vars[3] = {-1, -1, -1}; /* array to pass to the parser which will update X,Y,Z accordingly */
    SudokuBoard* solved_sb = generateSolution();
    SudokuBoard* game_sb = sb_deepCloneBoard(solved_sb);
    num_of_fixed = initialize();
    game_sb = generatePuzzle(game_sb, num_of_fixed);
    while (1){
        if (cmd != NULL)
            free(cmd);
        cmd = prsr_fetchCmd(action_vars);
        if (is_solved == 0) {
            if (strcmp(cmd, SET) == 0){
                res = set(action_vars[0], action_vars[1], action_vars[2], game_sb);
                if (res == 2)
                    is_solved = 1;
                else if (res == 0)
                    sb_print(game_sb);
                continue;
            }
            if (strcmp(cmd, HINT) == 0){
                hint(action_vars[0], action_vars[1], solved_sb);
                continue;
            }
            if (strcmp(cmd, VALIDATE) == 0){
                sb_destroyBoard(solved_sb);
                solved_sb = validate(sb_deepCloneBoard(game_sb));
                if (solved_sb == NULL){
                    solved_sb = sb_createSudokuBoard(N, M);
                    is_solved = 1;
                }
                continue;
            }
        }
        if (strcmp(cmd, RESTART) == 0){
            free(cmd);
            return restart(solved_sb, game_sb);
        }
        if (strcmp(cmd, EXIT) == 0){
            sb_destroyBoard(solved_sb);
            sb_destroyBoard(game_sb);
            free(cmd);
            exit(1);
        }
        printf("Error: invalid command\n");

    }
}
