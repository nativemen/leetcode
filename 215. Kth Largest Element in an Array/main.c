#include <stdio.h>

static int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

int findKthLargest(int *nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);

    return nums[numsSize - k];
}

#define ARRAY_SIZE 20001
#define INDEX_OFFSET 10000

int findKthLargest(int *nums, int numsSize, int k) {
    int count[ARRAY_SIZE];
    memset(count, 0, ARRAY_SIZE * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        count[nums[i] + INDEX_OFFSET]++;
    }

    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        if (k <= count[i]) {
            return i - INDEX_OFFSET;
        }

        k -= count[i];
    }

    return 0 - INDEX_OFFSET;
}