#include "sudoku.h"

int is_only_candidate_at(Sudoku sudoku, int row, int col, int val_index) {
    int count = 0;
    for (int k = 0; k < SIZE && count < 1; k++) {
        if (k != val_index && sudoku[row][col][k]) {
            count++;
        }
    }
    return count == 0;
}

int is_valid_at(Sudoku sudoku, int row, int col, int val_index) {
    // self
    if (!sudoku[row][col][val_index]) {
        return 0;
    }
    // row
    for (int i = 0; i < SIZE; i++) {
        if (i != col && is_only_candidate_at(sudoku, row, i, val_index)) {
            return 0;
        }
    }
    // column
    for (int i = 0; i < SIZE; i++) {
        if (i != row && is_only_candidate_at(sudoku, i, col, val_index)) {
            return 0;
        }
    }
    // block
    int block_y = row / 3;
    int block_x = col / 3;
    for (int i = block_y * 3; i < block_y * 3 + 3; i++) {
        for (int j = block_x * 3; j < block_x * 3 + 3; j++) {
            if (!(i == row && j == col) && is_only_candidate_at(sudoku, i, j, val_index)) {
                return 0;
            }
        }
    }
    return 1;
}

int solve_sudoku_rec(Sudoku sudoku, int row) {
    for (int i = row; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // simple undo stack - only one cell for now
            int backup[9];

            // if only 1 candidate, then the cell is done
            int candidates = 0;
            for (int k = 0; k < SIZE ; k++) {
                backup[k] = sudoku[i][j][k];
                if (sudoku[i][j][k]) {
                    candidates++;
                }
            }
            if (candidates == 1) {
                continue;
            }

            // backtrack
            for (int k = 0; k < SIZE ; k++) {
                if (!is_valid_at(sudoku, i, j, k)) {
                    continue;
                }
                // try k
                for (int kk = 0; kk < SIZE; kk++) {
                   sudoku[i][j][kk] = 0;
                }
                sudoku[i][j][k] = 1;

                if (solve_sudoku_rec(sudoku, i)) {
                    return 1;
                } else {
                    // undo
                    for (int kk = 0; kk < SIZE; kk++) {
                       sudoku[i][j][kk] = backup[kk];
                    }
                }
            }
            return 0;
        }
    }
    return 1;
}

int solve_sudoku(Sudoku sudoku) {
   return solve_sudoku_rec(sudoku, 0);
}
