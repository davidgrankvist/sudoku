#include <time.h>
#include "sudoku.h"
#include "sudoku_io.h"

int main() {
    Sudoku sudoku = {{{0}}};
    int status = read_sudoku(sudoku);
    if (status != 1) {
        return 1;
    }
    print_sudoku(sudoku);

    clock_t start = clock();
    int success = solve_sudoku(sudoku);
    double ellapsed = (clock() - start) * 1000.0 / CLOCKS_PER_SEC;
    if (!success) {
       printf("Failed to solve sudoku. The input or algorithm is broken..\n"); 
       return 1;
    }
    printf("\nSolved in %.3f ms\n\n", ellapsed);
    print_sudoku(sudoku);
    return 0;
}
