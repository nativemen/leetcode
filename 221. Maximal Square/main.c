#include <stdbool.h>
#include <stdio.h>

static int min(int a, int b, int c) {
    int d = (a < b) ? a : b;

    return (d < c) ? d : c;
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

int maximalSquare(char **matrix, int matrixSize, int *matrixColSize) {
    if (matrix == NULL || matrixSize <= 0 || matrixColSize[0] <= 0) {
        return 0;
    }

    int dp[matrixSize][matrixColSize[0]];
    memset(dp, 0, matrixSize * matrixColSize[0] * sizeof(int));
    int maxSize = 0;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
                }

                maxSize = max(maxSize, dp[i][j]);
            }
        }
    }

    return maxSize * maxSize;
}