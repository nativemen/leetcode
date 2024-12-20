#include <stdbool.h>

#define ARRAY_SIZE 9

bool isValidSudoku(char **board, int boardSize, int *boardColSize) {
    int rows[ARRAY_SIZE] = {0};
    int cols[ARRAY_SIZE] = {0};
    int boxes[ARRAY_SIZE] = {0};

    for (int row = 0; row < ARRAY_SIZE; row++) {
        for (int col = 0; col < ARRAY_SIZE; col++) {
            if (board[row][col] == '.') {
                continue;
            }

            int shift = board[row][col] - '1';
            int mask = 1 << shift;
            int box = ((int)(row / 3)) * 3 + (int)(col / 3);

            if ((rows[row] & mask) != 0 || (cols[col] & mask) != 0 || (boxes[box] & mask) != 0) {
                return false;
            }

            rows[row] |= mask;
            cols[col] |= mask;
            boxes[box] |= mask;
        }
    }

    return true;
}