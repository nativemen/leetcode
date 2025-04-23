#include <stdio.h>

static void makeIslandsZero(char **grid, int rowSize, int colSize, int i, int j) {
    if (i < 0 || i >= rowSize || j < 0 || j >= colSize || grid[i][j] == '0') {
        return;
    }

    grid[i][j] = '0';

    makeIslandsZero(grid, rowSize, colSize, i - 1, j);
    makeIslandsZero(grid, rowSize, colSize, i + 1, j);
    makeIslandsZero(grid, rowSize, colSize, i, j - 1);
    makeIslandsZero(grid, rowSize, colSize, i, j + 1);
}

int numIslands(char **grid, int gridSize, int *gridColSize) {
    int count = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == '1') {
                count++;
                makeIslandsZero(grid, gridSize, gridColSize[0], i, j);
            }
        }
    }

    return count;
}