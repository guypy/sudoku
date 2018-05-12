cmake_minimum_required(VERSION 3.9.6)
project(sudoku C)

set(CMAKE_C_STANDARD 90)

add_executable(sudoku main.c parser.c parser.h game.c game.h solver.c solver.h main_aux.c main_aux.h sudoku_board.c sudoku_board.h)