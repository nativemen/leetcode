#define ARRAY_SIZE 2

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **spiralMatrixIII(int rows, int cols, int rStart, int cStart, int *returnSize, int **returnColumnSizes) {
    int count = 0;
    int turnCount = 0;
    int turn = 0;
    int turnTotal = 1;
    int total = rows * cols;
    int row = rStart;
    int col = cStart;
    int left = cStart;
    int right = cStart;
    int top = rStart;
    int bottom = rStart;
    int direction = 0;
    int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int **result = (int **)calloc(total, sizeof(int *));
    *returnColumnSizes = (int *)malloc(total * sizeof(int));
    *returnSize = total;

    while (count < total) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            result[count] = (int *)malloc(ARRAY_SIZE * sizeof(int));
            result[count][0] = row;
            result[count][1] = col;
            (*returnColumnSizes)[count] = ARRAY_SIZE;
            count++;
        }

        turnCount++;
        if (turnCount == turnTotal) {
            turnCount = 0;
            turn++;
            turnTotal = 8 * turn;
            left = cStart - turn;
            right = cStart + turn;
            top = rStart - turn;
            bottom = rStart + turn;
        }

        int nextRow = row + dirs[direction][0];
        int nextCol = col + dirs[direction][1];

        if (nextRow < top || nextRow > bottom || nextCol < left || nextCol > right) {
            direction = (direction + 1) % 4;
            nextRow = row + dirs[direction][0];
            nextCol = col + dirs[direction][1];
        }

        row = nextRow;
        col = nextCol;
    }

    return result;
}

#define ARRAY_SIZE 2

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **spiralMatrixIII(int rows, int cols, int rStart, int cStart, int *returnSize, int **returnColumnSizes) {
    int count = 0;
    int total = rows * cols;
    int row = rStart;
    int col = cStart;
    int step = 1;
    int direction = 0;
    int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int **result = (int **)calloc(total, sizeof(int *));
    *returnColumnSizes = (int *)malloc(total * sizeof(int));
    *returnSize = total;

    while (count < total) {
        for (int repeat = 0; repeat < 2; repeat++) {
            for (int s = 0; s < step; s++) {
                if (row >= 0 && row < rows && col >= 0 && col < cols) {
                    result[count] = (int *)malloc(ARRAY_SIZE * sizeof(int));
                    result[count][0] = row;
                    result[count][1] = col;
                    (*returnColumnSizes)[count++] = ARRAY_SIZE;
                }

                row += dirs[direction][0];
                col += dirs[direction][1];
            }
            direction = (direction + 1) % 4;
        }
        step++;
    }

    return result;
}