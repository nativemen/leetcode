#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generateMatrix(int n, int *returnSize, int **returnColumnSizes) {
    int **result = (int **)calloc(n, sizeof(int *));
    *returnColumnSizes = (int *)malloc(n * sizeof(int));
    *returnSize = n;
    for (int i = 0; i < n; i++) {
        result[i] = (int *)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = n - 1;
    int num = 1;

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
            result[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            result[i][right] = num++;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[bottom][i] = num++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[i][left] = num++;
            }
            left++;
        }
    }

    return result;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generateMatrix(int n, int *returnSize, int **returnColumnSizes) {
    int **result = (int **)calloc(n, sizeof(int *));
    *returnColumnSizes = (int *)malloc(n * sizeof(int));
    *returnSize = n;
    for (int i = 0; i < n; i++) {
        result[i] = (int *)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = n - 1;
    int num = 1;
    int total = n * n;
    int direction = 1;

    while (num <= total) {
        switch (direction) {
            case 1: {
                for (int i = left; i <= right; i++) {
                    result[top][i] = num++;
                }
                top++;
                direction = 2;
                break;
            }
            case 2: {
                for (int i = top; i <= bottom; i++) {
                    result[i][right] = num++;
                }
                right--;
                direction = 3;
                break;
            }
            case 3: {
                for (int i = right; i >= left; i--) {
                    result[bottom][i] = num++;
                }
                bottom--;
                direction = 4;
                break;
            }
            default: {
                for (int i = bottom; i >= top; i--) {
                    result[i][left] = num++;
                }
                left++;
                direction = 1;
                break;
            }
        }
    }

    return result;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generateMatrix(int n, int *returnSize, int **returnColumnSizes) {
    int **result = (int **)calloc(n, sizeof(int *));
    *returnColumnSizes = (int *)malloc(n * sizeof(int));
    *returnSize = n;
    for (int i = 0; i < n; i++) {
        result[i] = (int *)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = n - 1;
    int num = 1;
    int total = n * n;

    while (num <= total) {
        for (int i = left; i <= right; i++) {
            result[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            result[i][right] = num++;
        }
        right--;

        for (int i = right; i >= left; i--) {
            result[bottom][i] = num++;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            result[i][left] = num++;
        }
        left++;
    }

    return result;
}