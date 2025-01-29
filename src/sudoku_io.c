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

            if (buffer[i] == BLANK) {
                sudoku[row][i] = ALL_CANDIDATES;
            } else {
                int candidate_index = CHAR_TO_INDEX(buffer[i]);
                sudoku[row][i] = SINGLE_BIT(candidate_index);
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
            if (HAS_SINGLE_BIT(sudoku[i][j])) {
                buffer[j] = INDEX_TO_CHAR(BIT_INDEX(sudoku[i][j]));
            } else {
                buffer[j] = BLANK;
            }
        }
        printf("%s\n", buffer);
    }
}
