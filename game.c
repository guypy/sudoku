#include "game.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "solver.h"
#include "sudoku_board.h"

int gm_Initialize(){
    int num_of_fixed;
    printf("Please enter the number of cells to fill [0-%d]:\n", BOARD_SIZE - 1);
    num_of_fixed = prs_ReadInt();
    while (num_of_fixed < 0 || num_of_fixed >= BOARD_SIZE){
        printf("Error: Invalid number of cells to fill (should be between 0 and %d)\n", BOARD_SIZE - 1);
        printf("Please enter the number of cells to fill [0-%d]:\n", BOARD_SIZE - 1);
        num_of_fixed = prs_ReadInt();
    }
    return num_of_fixed;
}

SudokuBoard* gm_Generate_solution(){
    SudokuBoard* sb = sb_CreateSudokuBoard(N,M);
    int is_random = 1;
    slvr_SolveBoard(sb, is_random);
    return sb;
}

/*
 * This function receives a pointer to a game board, selects h fixed values within it, and deletes the remaining values
 */
SudokuBoard* gm_Generate_puzzle(SudokuBoard* game_sb, int h){
    int i, x, y, idx;
    for (i = 0; i < h; ++i){
        x = rand() % (N*M); /* random column */
        y = rand() % (N*M); /* random row */
        idx = y*(N*M) + x;
        if (!game_sb->cells[idx]->fixed){ /* if cell is not yet fixed, make it fixed */
            game_sb->cells[idx]->fixed = 1;
        }
        else{
            i--;
        }
    }
    sb_RemoveUnfixedCells(game_sb);
    return game_sb;
}

/*
 * This functions sets the value of cell <x,y> to z (x = col, y = row).
 * If <x,y> is fixed, an error is printed out.
 * If value z is invalid for cell <x,y> by the rules of the game, an error is printed out.
 * If puzzle is solved, a message is printed out.
 * @pre: x,y,z are legal values. 1 <= x,y <= N*M  0 <= z <= N*M
 */
int gm_set(int x, int y, int z, SudokuBoard* game_sb){
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
    if (sb_IsFull(game_sb)){
        printf("Puzzle solved successfully\n");
        return 2;
    }
    return 0;
}

void gm_hint(int x, int y, SudokuBoard* solved_sb){
    int hint;
    if (x == -1 || y == -1){
        printf("Error: invalid command\n");
        return;
    }
    hint = solved_sb->cells[N*M*(y + 1) + (x + 1)]->value;
    printf("Hint: set cell to %d\n", hint);
}

SudokuBoard* gm_validate(SudokuBoard* game_sb){
    int is_random = 0;
    SudokuBoard* res;
    setAllCellsFixed(game_sb);
    res = slvr_SolveBoard(game_sb, is_random);
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

int gm_restart(SudokuBoard* solved_sb, SudokuBoard* game_sb){
    sb_destroyBoard(solved_sb);
    sb_destroyBoard(game_sb);
    return gm_StartGame();
}

int gm_StartGame(){
    int is_solved = 0;
    int num_of_fixed;
    char* cmd;
    int action_vars[3] = {-1, -1, -1}; /* array to pass to the parser which will update X,Y,Z accordingly */
    SudokuBoard* solved_sb = gm_Generate_solution();
    SudokuBoard* game_sb = sb_DeepCloneBoard(solved_sb);
    num_of_fixed = gm_Initialize();
    game_sb = gm_Generate_puzzle(game_sb, num_of_fixed);
    while (1){
        sb_print(game_sb);
        cmd = parse_cmd(action_vars);
        if (is_solved == 0) {
            if (strcmp(cmd, SET) == 0){
                if (gm_set(action_vars[0], action_vars[1], action_vars[2], game_sb) == 2)
                    is_solved = 1;
                continue;
            }
            if (strcmp(cmd, HINT) == 0){
                gm_hint(action_vars[0], action_vars[1], solved_sb);
                continue;
            }
            if (strcmp(cmd, VALIDATE) == 0){
                solved_sb = gm_validate(sb_DeepCloneBoard(game_sb));
                if (solved_sb == NULL){
                    free(solved_sb);
                    solved_sb = sb_CreateSudokuBoard(N, M);
                    is_solved = 1;
                }
                continue;
            }
        }
        if (strcmp(cmd, "rosebud") == 0) {
            sb_print(solved_sb);
            continue;
        }
        if (strcmp(cmd, RESTART) == 0){
            return gm_restart(solved_sb, game_sb);
        }
        if (strcmp(cmd, EXIT) == 0){
            sb_destroyBoard(solved_sb);
            sb_destroyBoard(game_sb);
            exit(1);
        }
        printf("Error: invalid command\n");

    }
}

