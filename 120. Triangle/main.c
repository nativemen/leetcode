#include <limits.h>
#include <stdio.h>

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize) {
    if (triangle == NULL || triangleSize <= 0) {
        return 0;
    }

    int dp[2][triangleColSize[triangleSize - 1]];
    dp[0][0] = triangle[0][0];
    int current = 0;

    for (int i = 1; i < triangleSize; i++) {
        int prev = current;
        current = (current + 1) % 2;
        for (int j = 0; j < triangleColSize[i]; j++) {
            if (j == 0) {
                dp[current][0] = dp[prev][0] + triangle[i][0];
            } else if (j == triangleColSize[i] - 1) {
                dp[current][triangleColSize[i] - 1] =
                        dp[prev][triangleColSize[i - 1] - 1] + triangle[i][triangleColSize[i] - 1];
            } else {
                dp[current][j] = (dp[prev][j - 1] < dp[prev][j]) ? dp[prev][j - 1] : dp[prev][j];
                dp[current][j] += triangle[i][j];
            }
        }
    }

    int minVal = INT_MAX;
    for (int i = 0; i < triangleColSize[triangleSize - 1]; i++) {
        printf("%d ", dp[current][i]);
        if (minVal > dp[current][i]) {
            minVal = dp[current][i];
        }
    }

    return minVal;
}

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize) {
    if (triangle == NULL || triangleSize <= 0) {
        return 0;
    }

    for (int i = triangleSize - 2; i >= 0; i--) {
        for (int j = 0; j < triangleColSize[i]; j++) {
            triangle[i][j] +=
                    (triangle[i + 1][j] < triangle[i + 1][j + 1]) ? triangle[i + 1][j] : triangle[i + 1][j + 1];
        }
    }

    return triangle[0][0];
}