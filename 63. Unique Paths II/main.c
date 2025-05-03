#include <stdio.h>

int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize) {
    obstacleGrid[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;

    for (int i = 1; i < obstacleGridSize; i++) {
        obstacleGrid[i][0] = (obstacleGrid[i][0] == 1) ? 0 : obstacleGrid[i - 1][0];
    }

    for (int j = 1; j < obstacleGridColSize[0]; j++) {
        obstacleGrid[0][j] = (obstacleGrid[0][j] == 1) ? 0 : obstacleGrid[0][j - 1];
    }

    for (int i = 1; i < obstacleGridSize; i++) {
        for (int j = 1; j < obstacleGridColSize[i]; j++) {
            obstacleGrid[i][j] = (obstacleGrid[i][j] == 1) ? 0 : obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
        }
    }

    return obstacleGrid[obstacleGridSize - 1][obstacleGridColSize[obstacleGridSize - 1] - 1];
}