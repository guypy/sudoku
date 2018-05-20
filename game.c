#include "game.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
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
    sb_print(sb);
    return sb;
}

SudokuBoard* gm_Generate_puzzle(SudokuBoard solved_sb, int h){
    int i, x, y, idx;
    SudokuBoard* game_sb = &solved_sb; /* address of the copy of solved_sb */
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

void gm_set(int x, int y, int z){
    printf("asdf");
}

void gm_hint(int x, int y){
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
    SudokuBoard* game_sb = gm_Generate_puzzle(*solved_sb, num_of_fixed);
    sb_print(game_sb);
    while (solved_puzzle == 0){
        printf("in\n");
        cmd = parse_cmd(action_vars);
        printf("%s",cmd);
        if (cmd == SET){
            gm_set(action_vars[0], action_vars[1], action_vars[2]);
        }
        if (cmd == HINT){

        }
        if (cmd == VALIDATE){

        }
        if (cmd == RESTART){

        }
        if (cmd == EXIT){

        }
        solved_puzzle = 1;
    }
    printf("end");
    return 0;
}

