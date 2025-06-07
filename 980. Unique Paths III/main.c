#include <stdbool.h>
#include <stdio.h>

static int dfs(int **grid, int rowSize, int colSize, int i, int j, int spaces) {
    if (i < 0 || i >= rowSize || j < 0 || j >= colSize || grid[i][j] == -1) {
        return 0;
    }

    int result = 0;

    if (grid[i][j] == 2) {
        return (spaces == 0) ? 1 : 0;
    }

    grid[i][j] = -1;

    result += dfs(grid, rowSize, colSize, i + 1, j, spaces - 1);
    result += dfs(grid, rowSize, colSize, i - 1, j, spaces - 1);
    result += dfs(grid, rowSize, colSize, i, j + 1, spaces - 1);
    result += dfs(grid, rowSize, colSize, i, j - 1, spaces - 1);

    grid[i][j] = 0;

    return result;
}

int uniquePathsIII(int **grid, int gridSize, int *gridColSize) {
    int startX = 0;
    int startY = 0;
    int spaces = 1;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                startX = i;
                startY = j;
            } else if (grid[i][j] == 0) {
                spaces++;
            }
        }
    }

    return dfs(grid, gridSize, gridColSize[0], startX, startY, spaces);
}