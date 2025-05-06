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

static int quickSelect(int *nums, int numsSize, int k) {
    int pivot = nums[rand() % numsSize];
    int left[numsSize];
    int right[numsSize];
    int mid[numsSize];
    int l = 0;
    int r = 0;
    int m = 0;
    int i = 0;

    while (i < numsSize) {
        if (nums[i] < pivot) {
            left[l++] = nums[i++];
        } else if (nums[i] > pivot) {
            right[r++] = nums[i++];
        } else {
            mid[m++] = nums[i++];
        }
    }

    if (r >= k) {
        return quickSelect(right, r, k);
    } else if ((r + m) < k) {
        return quickSelect(left, l, k - r - m);
    } else {
        return pivot;
    }
}

int findKthLargest(int *nums, int numsSize, int k) {
    if (nums == NULL || numsSize <= 0 || k < 0 || k > numsSize) {
        return -1;
    }

    return quickSelect(nums, numsSize, k);
}