#include <stdbool.h>
#include <stdio.h>

int countNegatives(int **grid, int gridSize, int *gridColSize) {
    int count = 0;

    for (int i = 0; i < gridSize; i++) {
        int left = 0;
        int right = gridColSize[i] - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (grid[i][mid] >= 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        count += gridColSize[i] - left;
    }

    return count;
}