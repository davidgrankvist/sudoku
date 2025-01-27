#ifndef sudoku_io_h
#define sudoku_io_h

#include <stdio.h>
#include <stddef.h>
#include "sudoku.h"

/*
 * Read a Sudoku from STDIN.
 */
int read_sudoku(Sudoku sudoku);

/*
 * Print filled in or empty cells.
 *
 * Cells with multiple candidates
 * are shown as empty.
 */
void print_sudoku(Sudoku sudoku);

#endif
