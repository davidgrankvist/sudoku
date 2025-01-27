#ifndef sudoku_h
#define sudoku_h

#define SIZE 9

/* 
 * Sudoku represented as a 3D candidate array.
 *
 * 9 rows, 9 columns, 9 candidates
 * 1 = possible, 0 = ruled out
 */
typedef int Sudoku[SIZE][SIZE][SIZE];

int solve_sudoku(Sudoku sudoku);

#endif
