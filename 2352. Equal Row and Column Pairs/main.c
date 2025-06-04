#include <stdbool.h>
#include <stdio.h>

int equalPairs(int **grid, int gridSize, int *gridColSize) {
    int column[gridSize];
    int count = 0;

    for (int c = 0; c < gridColSize[0]; c++) {
        for (int r = 0; r < gridSize; r++) {
            column[r] = grid[r][c];
        }

        for (int r = 0; r < gridSize; r++) {
            if (memcmp(grid[r], column, gridSize * sizeof(int)) == 0) {
                count++;
            }
        }
    }

    return count;
}

#define PRIME_BASE 301
#define PRIME_MOD 100001

int equalPairs(int **grid, int gridSize, int *gridColSize) {
    int hash = 0;
    int rowHash[gridSize];
    int colHash[gridSize];

    for (int i = 0; i < gridSize; i++) {
        hash = 0;
        for (int j = 0; j < gridColSize[i]; j++) {
            hash = (hash * PRIME_BASE + grid[i][j]) % PRIME_MOD;
        }
        rowHash[i] = hash;
    }

    for (int j = 0; j < gridColSize[0]; j++) {
        hash = 0;
        for (int i = 0; i < gridSize; i++) {
            hash = (hash * PRIME_BASE + grid[i][j]) % PRIME_MOD;
        }
        colHash[j] = hash;
    }

    int count = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (rowHash[i] == colHash[j]) {
                count++;
            }
        }
    }

    return count;
}