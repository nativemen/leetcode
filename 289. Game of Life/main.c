static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

static inline int min(int a, int b) {
    return (a < b) ? a : b;
}

void gameOfLife(int **board, int boardSize, int *boardColSize) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            int count = 0;

            for (int m = max(0, i - 1); m <= min(boardSize - 1, i + 1); m++) {
                for (int n = max(0, j - 1); n <= min(boardColSize[0] - 1, j + 1); n++) {
                    if (m != i || n != j) {
                        count += board[m][n] & 1;
                    }
                }
            }

            if (((board[i][j] & 1) == 1 && count == 2) || count == 3) {
                board[i][j] |= 1 << 1;
            }
        }
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            board[i][j] >>= 1;
        }
    }
}