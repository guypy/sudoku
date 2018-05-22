#include <stdio.h>
#include <stdlib.h>
#include "sudoku_board.h"
#include "solver.h"
#include "parser.h"
#include "game.h"

int main(int argc, char *argv[]) {
    unsigned int seed = 5;
    if (argc == 2)
        seed = atoi(argv[1]);
    srand(seed);
    gm_play();

    return 0;
}
