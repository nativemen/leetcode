#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int n, int *returnSize) {
    int *counter = (int *)calloc(n + 1, sizeof(int));
    if (counter == NULL) {
        return NULL;
    }

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j <= n; j++) {
            counter[j] += (j >> i) & 1;
        }
    }

    *returnSize = n + 1;
    return counter;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int n, int *returnSize) {
    int *counter = (int *)calloc(n + 1, sizeof(int));
    if (counter == NULL) {
        return NULL;
    }

    for (int i = 0; i <= n; i++) {
        counter[i] += __builtin_popcount(i);
    }

    *returnSize = n + 1;
    return counter;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int n, int *returnSize) {
    int *counter = (int *)calloc(n + 1, sizeof(int));
    if (counter == NULL) {
        return NULL;
    }

    for (int i = 0; i <= n; i++) {
        counter[i] = counter[i >> 1] + (i & 1);
    }

    *returnSize = n + 1;
    return counter;
}