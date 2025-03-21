
#define ARRAY_SIZE 2

static int compare(const void *a, const void *b) {
    const int *m = *(const int **)a;
    const int *n = *(const int **)b;

    return (m[0] == n[0]) ? (m[1] - n[1]) : (m[0] - n[0]);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int *), compare);

    int left = intervals[0][0];
    int right = intervals[0][1];
    int **result = (int **)calloc(intervalsSize, sizeof(int *));
    *returnColumnSizes = (int *)calloc(intervalsSize, sizeof(int));
    int count = 0;
    int i = 0;

    while (i <= intervalsSize) {
        if (i == intervalsSize || right < intervals[i][0]) {
            result[count] = (int *)malloc(ARRAY_SIZE * sizeof(int));
            result[count][0] = left;
            result[count][1] = right;
            (*returnColumnSizes)[count] = ARRAY_SIZE;
            count++;
            if (i < intervalsSize) {
                left = intervals[i][0];
                right = intervals[i][1];
            }
        } else {
            right = (right > intervals[i][1]) ? right : intervals[i][1];
        }

        i++;
    }

    *returnSize = count;
    return result;
}

#define ARRAY_SIZE 2

static int compare(const void *a, const void *b) {
    return **(const int **)a - **(const int **)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int *), compare);

    int left = intervals[0][0];
    int right = intervals[0][1];
    int **result = (int **)calloc(intervalsSize, sizeof(int *));
    *returnColumnSizes = (int *)calloc(intervalsSize, sizeof(int));
    int count = 0;
    int i = 0;

    while (i <= intervalsSize) {
        if (i == intervalsSize || right < intervals[i][0]) {
            result[count] = (int *)malloc(ARRAY_SIZE * sizeof(int));
            result[count][0] = left;
            result[count][1] = right;
            (*returnColumnSizes)[count] = ARRAY_SIZE;
            count++;
            if (i < intervalsSize) {
                left = intervals[i][0];
                right = intervals[i][1];
            }
        } else {
            right = (right > intervals[i][1]) ? right : intervals[i][1];
        }

        i++;
    }

    *returnSize = count;
    return result;
}