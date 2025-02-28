#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getRow(int rowIndex, int *returnSize) {
    int *cur = (int *)calloc((rowIndex + 1), sizeof(int));
    if (cur == NULL) {
        return NULL;
    }

    int *prev = (int *)calloc((rowIndex + 1), sizeof(int));
    if (prev == NULL) {
        free(cur);
        return NULL;
    }

    prev[0] = 1;
    for (int i = 1; i < rowIndex + 1; i++) {
        cur[0] = 1;
        cur[i] = 1;
        for (int j = 1; j < rowIndex; j++) {
            cur[j] = prev[j - 1] + prev[j];
        }
        int *temp = prev;
        prev = cur;
        cur = temp;
    }

    *returnSize = rowIndex + 1;
    return prev;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getRow(int rowIndex, int *returnSize) {
    int *row = (int *)calloc((rowIndex + 1), sizeof(int));
    if (row == NULL) {
        return NULL;
    }

    long long val = 1;
    for (int i = 0; i < rowIndex + 1; i++) {
        row[i] = (int)val;
        val = val * (rowIndex - i) / (i + 1);
    }

    *returnSize = rowIndex + 1;
    return row;
}