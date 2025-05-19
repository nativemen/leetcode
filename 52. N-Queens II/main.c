#include <stdbool.h>
#include <stdio.h>

static bool isValid(int *line, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (line[i] == col || abs(row - i) == abs(col - line[i])) {
            return false;
        }
    }

    return true;
}

static int getCount(int *line, int size, int row) {
    if (row == size) {
        return 1;
    }

    int count = 0;

    for (int col = 0; col < size; col++) {
        line[row] = col;
        if (isValid(line, row, col)) {
            count += getCount(line, size, row + 1);
        }
    }

    return count;
}

int totalNQueens(int n) {
    if (n <= 0) {
        return 0;
    }

    int line[n];
    return getCount(line, n, 0);
}