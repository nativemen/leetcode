#include <limits.h>
#include <stdio.h>

void rotate(int **matrix, int matrixSize, int *matrixColSize) {
    int mark[matrixSize * matrixColSize[0]];
    for (int i = 0; i < matrixSize * matrixColSize[0]; i++) {
        mark[i] = INT_MIN;
    }

    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < matrixColSize[row]; col++) {
            int index = row * matrixSize + col;
            if (mark[index] == INT_MIN) {
                mark[index] = matrix[row][col];
            }

            index = (matrixSize - 1 - col) * matrixSize + row;
            if (mark[index] == INT_MIN) {
                matrix[row][col] = matrix[matrixSize - 1 - col][row];
            } else {
                matrix[row][col] = mark[index];
            }
        }
    }
}

void rotate(int **matrix, int matrixSize, int *matrixColSize) {
    /* Transpose */
    for (int row = 0; row < matrixSize; row++) {
        for (int col = row; col < matrixColSize[row]; col++) {
            int temp = matrix[row][col];
            matrix[row][col] = matrix[col][row];
            matrix[col][row] = temp;
        }
    }

    /* Flip left and right along the vertical center line */
    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < (matrixColSize[row] + 1) / 2; col++) {
            int temp = matrix[row][col];
            matrix[row][col] = matrix[row][matrixSize - 1 - col];
            matrix[row][matrixSize - 1 - col] = temp;
        }
    }
}
