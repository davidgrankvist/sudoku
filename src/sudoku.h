#ifndef sudoku_h
#define sudoku_h

#define SIZE 9
#define ALL_CANDIDATES 0x1FF

#define HAS_SINGLE_BIT(n) n != 0 && (n & (n - 1)) == 0
#define BIT_INDEX(n) __builtin_ctz(n)
#define SINGLE_BIT(n) (1 << n)
#define HAS_BIT_AT(n, i) (n & (1 << i)) != 0

/* 
 * Sudoku represented as a 3D candidate array.
 *
 * 9 rows, 9 columns, 9 candidates
 * 1 = possible, 0 = ruled out
 *
 * The candidates are packed into an integer using 1 bit each.
 */
typedef short Sudoku[SIZE][SIZE];

int solve_sudoku(Sudoku sudoku);

#endif
