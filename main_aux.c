//
// Created by Yuval Barzam on 5/12/18.
//

#include "main_aux.h"
#include "sudoku_board.h"

void aux_empty_array(int* arr) {
    int i;
    for (i = 0; i < N*M; ++i) {
        arr[i] = 0;
    }
}
