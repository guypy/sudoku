#include "game.h"
#include "parser.h"
#include <stdio.h>
#include "sudoku_board.h"

int gm_StartGame(){
    return 0;
}

int gm_Initialize(){
    int num_of_fixed;
    printf("Please enter the number of cells to fill [0-%d]:\n", BOARD_SIZE - 1);
    num_of_fixed = prs_ReadInt();
    while (num_of_fixed < 0 || num_of_fixed >= BOARD_SIZE){
        printf("Error: Invalid number of cells to fill (should be between 0 and %d)\n", BOARD_SIZE - 1);
        printf("Please enter the number of cells to fill [0-%d]:\n", BOARD_SIZE - 1);
        num_of_fixed = prs_ReadInt();
    }
    return 0;
}

int gm_Generate_Puzzle(){



    return 0;
}

