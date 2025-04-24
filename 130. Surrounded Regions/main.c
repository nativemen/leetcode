#include <stdio.h>

static void makeOToY(char **board, int boardSize, int boardColSize, int i, int j) {
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize || board[i][j] == 'X' || board[i][j] == 'Y') {
        return;
    }

    board[i][j] = 'Y';

    makeOToY(board, boardSize, boardColSize, i - 1, j);
    makeOToY(board, boardSize, boardColSize, i + 1, j);
    makeOToY(board, boardSize, boardColSize, i, j - 1);
    makeOToY(board, boardSize, boardColSize, i, j + 1);
}

void solve(char **board, int boardSize, int *boardColSize) {
    for (int i = 0; i < boardSize; i++) {
        if (board[i][0] == 'O') {
            makeOToY(board, boardSize, boardColSize[0], i, 0);
        }

        if (board[i][boardColSize[0] - 1] == 'O') {
            makeOToY(board, boardSize, boardColSize[0], i, boardColSize[0] - 1);
        }
    }

    for (int j = 0; j < boardColSize[0]; j++) {
        if (board[0][j] == 'O') {
            makeOToY(board, boardSize, boardColSize[0], 0, j);
        }

        if (board[boardSize - 1][j] == 'O') {
            makeOToY(board, boardSize, boardColSize[0], boardSize - 1, j);
        }
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            if (board[i][j] == 'Y') {
                board[i][j] = 'O';
            } else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}

static void makeOToY(char **board, int boardSize, int boardColSize, int i, int j) {
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize || board[i][j] == 'X' || board[i][j] == 'Y') {
        return;
    }

    board[i][j] = 'Y';

    makeOToY(board, boardSize, boardColSize, i - 1, j);
    makeOToY(board, boardSize, boardColSize, i + 1, j);
    makeOToY(board, boardSize, boardColSize, i, j - 1);
    makeOToY(board, boardSize, boardColSize, i, j + 1);
}

void solve(char **board, int boardSize, int *boardColSize) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            if (i == 0 || i == boardSize - 1 || j == 0 || j == boardColSize[0] - 1) {
                if (board[i][j] == 'O') {
                    makeOToY(board, boardSize, boardColSize[0], i, j);
                }
            }
        }
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            if (board[i][j] == 'Y') {
                board[i][j] = 'O';
            } else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}