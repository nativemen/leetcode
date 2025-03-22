#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize) {
    int left = 0;
    int right = matrixColSize[0] - 1;
    int top = 0;
    int bottom = matrixSize - 1;
    int *result = (int *)malloc(matrixSize * matrixColSize[0] * sizeof(int));
    int count = 0;

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
            result[count++] = matrix[top][i];
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            result[count++] = matrix[i][right];
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[count++] = matrix[bottom][i];
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[count++] = matrix[i][left];
            }
            left++;
        }
    }

    *returnSize = count;

    return result;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize) {
    int left = 0;
    int right = matrixColSize[0] - 1;
    int top = 0;
    int bottom = matrixSize - 1;
    int num = matrixSize * matrixColSize[0];
    int *result = (int *)malloc(num * sizeof(int));
    int count = 0;
    int direction = 1;

    while (count < num) {
        switch (direction) {
            case 1: {
                for (int i = left; i <= right; i++) {
                    result[count++] = matrix[top][i];
                }
                top++;
                direction = 2;
                break;
            }
            case 2: {
                for (int i = top; i <= bottom; i++) {
                    result[count++] = matrix[i][right];
                }
                right--;
                direction = 3;
                break;
            }
            case 3: {
                for (int i = right; i >= left; i--) {
                    result[count++] = matrix[bottom][i];
                }
                bottom--;
                direction = 4;
                break;
            }
            case 4: {
                for (int i = bottom; i >= top; i--) {
                    result[count++] = matrix[i][left];
                }
                left++;
                direction = 1;
                break;
            }
        }
    }

    *returnSize = count;

    return result;
}