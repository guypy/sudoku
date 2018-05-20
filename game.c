#include "game.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sudoku_board.h"
#include "solver.h"

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
    slvr_SolveBoard(sb);
//    sb_print(sb);
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
    idx = (N*M)*y + x;
    if (game_sb->cells[idx]->fixed){
        printf("Error: cell is fixed\n");
        return 1;
    }
    if (slvr_isValid(game_sb, idx, z)){
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
    int hint = solved_sb->cells[N*M*y + x]->value;
    printf("Hint: set cell to %d\n", hint);
}

void gm_validate(){
}

void gm_restart(){
}

void gm_exit(){
}

int gm_StartGame(){
    int solved_puzzle = 0;
    int num_of_fixed;
    char* cmd;
    int action_vars[3] = {-1, -1, -1}; /* array to pass to the parser which will update X,Y,Z accordingly */
    num_of_fixed = gm_Initialize();
    SudokuBoard* solved_sb = gm_Generate_solution();
    SudokuBoard* game_sb = sb_DeepCloneBoard(solved_sb);
    game_sb = gm_Generate_puzzle(game_sb, num_of_fixed);
    sb_print(solved_sb);
    sb_print(game_sb);
    while (solved_puzzle == 0){
        printf("in\n");
        cmd = parse_cmd(action_vars);
        if (strcmp(cmd, SET) == 0){
            gm_set(action_vars[0], action_vars[1], action_vars[2], game_sb);
        }
        if (strcmp(cmd, HINT) == 0){
            gm_hint(action_vars[0], action_vars[1], solved_sb);
            printf("hint\n");
        }
        if (strcmp(cmd, VALIDATE) == 0){
            printf("validate\n");
        }
        if (strcmp(cmd, RESTART) == 0){
            printf("restart\n");
        }
        if (strcmp(cmd, EXIT) == 0){
            printf("exit\n");

        }
        solved_puzzle = 1;
    }
    printf("end");
    return 0;
}

