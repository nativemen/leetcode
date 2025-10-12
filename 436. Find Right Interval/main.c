#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int start;
    int end;
    int index;
} Interval;

static int compare(const void *a, const void *b) {
    return ((const Interval *)a)->start - ((const Interval *)b)->start;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findRightInterval(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize) {
    *returnSize = 0;
    Interval *intvl = (Interval *)malloc(intervalsSize * sizeof(Interval));
    if (intvl == NULL) {
        return NULL;
    }

    for (int i = 0; i < intervalsSize; i++) {
        intvl[i].start = intervals[i][0];
        intvl[i].end = intervals[i][1];
        intvl[i].index = i;
    }

    qsort(intvl, intervalsSize, sizeof(Interval), compare);

    int *result = (int *)malloc(intervalsSize * sizeof(int));
    if (result == NULL) {
        free(intvl);
        return NULL;
    }

    for (int i = 0; i < intervalsSize; i++) {
        int left = 0;
        int right = intervalsSize - 1;
        result[i] = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (intervals[i][1] <= intvl[mid].start) {
                result[i] = intvl[mid].index;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }

    *returnSize = intervalsSize;

    return result;
}

typedef struct {
    int start;
    int index;
} Interval;

static int compare(const void *a, const void *b) {
    return ((const Interval *)a)->start - ((const Interval *)b)->start;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findRightInterval(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize) {
    *returnSize = 0;
    Interval *intvl = (Interval *)malloc(intervalsSize * sizeof(Interval));
    if (intvl == NULL) {
        return NULL;
    }

    for (int i = 0; i < intervalsSize; i++) {
        intvl[i].start = intervals[i][0];
        intvl[i].index = i;
    }

    qsort(intvl, intervalsSize, sizeof(Interval), compare);

    int *result = (int *)malloc(intervalsSize * sizeof(int));
    if (result == NULL) {
        free(intvl);
        return NULL;
    }

    for (int i = 0; i < intervalsSize; i++) {
        int left = 0;
        int right = intervalsSize - 1;
        result[i] = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (intervals[i][1] <= intvl[mid].start) {
                result[i] = intvl[mid].index;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }

    *returnSize = intervalsSize;

    return result;
}