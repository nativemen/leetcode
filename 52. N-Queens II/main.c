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

static bool isValid(bool **board, int size, int row, int col) {
    for (int i = 0; i <= row; i++) {
        if (board[i][col] || (row >= i && col >= i && board[row - i][col - i]) ||
            (row >= i && col + i < size && board[row - i][col + i])) {
            return false;
        }
    }

    return true;
}

static int getCount(bool **board, int size, int row) {
    if (row == size) {
        return 1;
    }

    int count = 0;

    for (int col = 0; col < size; col++) {
        if (isValid(board, size, row, col)) {
            board[row][col] = true;
            count += getCount(board, size, row + 1);
            board[row][col] = false;
        }
    }

    return count;
}

int totalNQueens(int n) {
    if (n <= 0) {
        return 0;
    }

    bool **board = (bool **)calloc(n, sizeof(bool *));
    for (int i = 0; i < n; i++) {
        board[i] = (bool *)malloc(n * sizeof(bool));
        for (int j = 0; j < n; j++) {
            board[i][j] = false;
        }
    }

    int count = getCount(board, n, 0);

    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);

    return count;
}