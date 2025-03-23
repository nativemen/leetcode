#include <stdbool.h>
#include <stdio.h>

void setZeroes(int **matrix, int matrixSize, int *matrixColSize) {
    bool rows[matrixSize];
    for (size_t i = 0; i < matrixSize; i++) {
        rows[i] = false;
    }

    bool cols[matrixColSize[0]];
    for (size_t i = 0; i < matrixColSize[0]; i++) {
        cols[i] = false;
    }

    for (size_t i = 0; i < matrixSize; i++) {
        for (size_t j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    for (size_t i = 0; i < matrixSize; i++) {
        if (rows[i]) {
            for (size_t j = 0; j < matrixColSize[i]; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for (size_t i = 0; i < matrixColSize[0]; i++) {
        if (cols[i]) {
            for (size_t j = 0; j < matrixSize; j++) {
                matrix[j][i] = 0;
            }
        }
    }
}

void setZeroes(int **matrix, int matrixSize, int *matrixColSize) {
    bool rows[matrixSize];
    for (size_t i = 0; i < matrixSize; i++) {
        rows[i] = false;
    }

    bool cols[matrixColSize[0]];
    for (size_t i = 0; i < matrixColSize[0]; i++) {
        cols[i] = false;
    }

    for (size_t i = 0; i < matrixSize; i++) {
        for (size_t j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    for (size_t i = 0; i < matrixSize; i++) {
        for (size_t j = 0; j < matrixColSize[i]; j++) {
            if (rows[i] || cols[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

void setZeroes(int **matrix, int matrixSize, int *matrixColSize) {
    bool firstRowHasZero = false;
    bool firstColHasZero = false;

    for (size_t j = 0; j < matrixColSize[0]; j++) {
        if (matrix[0][j] == 0) {
            firstRowHasZero = true;
        }
    }

    for (size_t i = 0; i < matrixSize; i++) {
        if (matrix[i][0] == 0) {
            firstColHasZero = true;
        }
    }

    for (size_t i = 1; i < matrixSize; i++) {
        for (size_t j = 1; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (size_t i = 1; i < matrixSize; i++) {
        if (matrix[i][0] == 0) {
            for (size_t j = 1; j < matrixColSize[i]; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for (size_t j = 1; j < matrixColSize[0]; j++) {
        if (matrix[0][j] == 0) {
            for (size_t i = 1; i < matrixSize; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRowHasZero) {
        for (size_t j = 0; j < matrixColSize[0]; j++) {
            matrix[0][j] = 0;
        }
    }

    if (firstColHasZero) {
        for (size_t i = 0; i < matrixSize; i++) {
            matrix[i][0] = 0;
        }
    }
}

void setZeroes(int **matrix, int matrixSize, int *matrixColSize) {
    bool firstRowHasZero = false;
    bool firstColHasZero = false;

    for (size_t i = 0; i < matrixSize; i++) {
        for (size_t j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;

                if (i == 0) {
                    firstRowHasZero = true;
                }

                if (j == 0) {
                    firstColHasZero = true;
                }
            }
        }
    }

    for (size_t i = 1; i < matrixSize; i++) {
        for (size_t j = 1; j < matrixColSize[i]; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRowHasZero) {
        for (size_t j = 0; j < matrixColSize[0]; j++) {
            matrix[0][j] = 0;
        }
    }

    if (firstColHasZero) {
        for (size_t i = 0; i < matrixSize; i++) {
            matrix[i][0] = 0;
        }
    }
}