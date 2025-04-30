#include <stdbool.h>
#include <stdio.h>

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target) {
    if (matrix == NULL || matrixSize <= 0 || matrixColSize[0] <= 0) {
        return false;
    }

    int left = 0;
    int right = matrixSize * matrixColSize[0] - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int row = mid / matrixColSize[0];
        int col = mid % matrixColSize[0];

        if (matrix[row][col] < target) {
            left = mid + 1;
        } else if (matrix[row][col] > target) {
            right = mid - 1;
        } else {
            return true;
        }
    }

    return false;
}