#include <stdio.h>

int minPathSum(int **grid, int gridSize, int *gridColSize) {
    for (int row = 1; row < gridSize; row++) {
        grid[row][0] += grid[row - 1][0];
    }

    for (int col = 1; col < gridColSize[0]; col++) {
        grid[0][col] += grid[0][col - 1];
    }

    for (int row = 1; row < gridSize; row++) {
        for (int col = 1; col < gridColSize[0]; col++) {
            grid[row][col] += (grid[row - 1][col] < grid[row][col - 1]) ? grid[row - 1][col] : grid[row][col - 1];
        }
    }

    return grid[gridSize - 1][gridColSize[0] - 1];
}