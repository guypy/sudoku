#include <stdio.h>
#include <stdlib.h>
#include "sudoku_board.h"
#include "solver.h"
#include "parser.h"
#include "game.h"

int main(int p, char *argv[]) {
    unsigned int seed = *argv[1] - '0';
    srand(seed);
    gm_StartGame();

    return 0;
}