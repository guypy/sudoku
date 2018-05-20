#include <stdio.h>
#include <stdlib.h>
#include "sudoku_board.h"
#include "solver.h"
#include "parser.h"
#include "game.h"

int main(int p, char *argv[]) {
    char * c =argv[1];
    unsigned int seed = atoi(argv[1]);
    srand(seed);
    gm_StartGame();

    return 0;
}