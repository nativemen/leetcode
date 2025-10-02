#include <stdbool.h>
#include <stdio.h>

static int compare(const void *a, const void *b) {
    int *intervalA = *(int **)a;
    int *intervalB = *(int **)b;

    return intervalA[0]-intervalB[0];
}

int eraseOverlapIntervals(int **intervals, int intervalsSize, int *intervalsColSize) {
    qsort(intervals, intervalsSize, sizeof(int *), compare);

    int count = 0;
    int preEnd = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] >= preEnd) {
            preEnd = intervals[i][1];
        } else {
            count++;
            if (intervals[i][1] <= preEnd) {
                preEnd = intervals[i][1];
            }
        }
    }

    return count;
}