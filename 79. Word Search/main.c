#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

static void dfs(char **board, int rowSize, int colSize, char *c, int i, int j, bool *result) {
    if (i < 0 || i >= rowSize || j < 0 || j >= colSize) {
        return;
    }

    if (board[i][j] == *c) {
        if (*(c + 1) == '\0') {
            *result = true;
            return;
        }
        board[i][j] = '0';
        dfs(board, rowSize, colSize, c + 1, i - 1, j, result);
        dfs(board, rowSize, colSize, c + 1, i + 1, j, result);
        dfs(board, rowSize, colSize, c + 1, i, j - 1, result);
        dfs(board, rowSize, colSize, c + 1, i, j + 1, result);
        board[i][j] = *c;
    }
}

bool exist(char **board, int boardSize, int *boardColSize, char *word) {
    bool result = false;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            dfs(board, boardSize, boardColSize[i], word, i, j, &result);
        }
    }

    return result;
}

static void dfs(char **board, int rowSize, int colSize, char *c, int i, int j, bool *result) {
    if (*c == '\0') {
        *result = true;
        return;
    }

    if (i < 0 || i >= rowSize || j < 0 || j >= colSize) {
        return;
    }

    if (board[i][j] == *c) {
        board[i][j] = '0';
        dfs(board, rowSize, colSize, c + 1, i - 1, j, result);
        dfs(board, rowSize, colSize, c + 1, i + 1, j, result);
        dfs(board, rowSize, colSize, c + 1, i, j - 1, result);
        dfs(board, rowSize, colSize, c + 1, i, j + 1, result);
        board[i][j] = *c;
    }
}

bool exist(char **board, int boardSize, int *boardColSize, char *word) {
    bool result = false;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            dfs(board, boardSize, boardColSize[i], word, i, j, &result);
        }
    }

    return result;
}