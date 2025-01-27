#include "sudoku_io.h"

#define BLANK '_'
#define CHAR_TO_INDEX(c) c - '0' - 1
#define INDEX_TO_CHAR(i) i + '0' + 1

int read_sudoku(Sudoku sudoku) {
    char buffer[SIZE + 3] = {0};
    int valid = 1;
    int row = 0;

    // consume one line at a time and initialize the sudoku
    while(valid && fgets(buffer, sizeof(buffer), stdin) != NULL) {
        for (int i = 0; i < SIZE; i++) {
            valid = buffer[i] == BLANK || (buffer[i] >= '1' && buffer[i] <= '9');
            if (!valid) {
                printf("Parse error - Encountered invalid character %c\n", buffer[i]);
                break;
            }

            int candidate_index = CHAR_TO_INDEX(buffer[i]);
            int init_val = buffer[i] == BLANK ? 1 : 0;
            for (int j = 0; j < SIZE; j++) {
                sudoku[row][i][j] = j == candidate_index ? 1 : init_val;
            }
        }
        row++;
    }

    return valid;
}

void print_sudoku(Sudoku sudoku)
{
    char buffer[SIZE];
    for (int i = 0; i < SIZE; i++) {
        int buffer_index = 0;
        for (int j = 0; j < SIZE; j++) {
            int candidates = 0;
            int candidate_index = -1;
            for (int k = 0; k < SIZE && candidates < 2; k++) {
               if (sudoku[i][j][k]) {
                   candidates++;
                   candidate_index = k;
               }
            }
            buffer[j] = candidates == 1 ? INDEX_TO_CHAR(candidate_index) : BLANK;
        }
        printf("%s\n", buffer);
    }
}
