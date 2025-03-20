#include <stdio.h>

static int compare(const void *a, const void *b) {
    int m = *(const int *)a;
    int n = *(const int *)b;

    if (m < n) {
        return -1;
    } else if (m == n) {
        return 0;
    } else {
        return 1;
    }
}

int singleNumber(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int i = 0;
    while (i < numsSize - 2) {
        if (nums[i] != nums[i + 1]) {
            return nums[i];
        }

        i += 3;
    }

    return nums[numsSize - 1];
}

static int compare(const void *a, const void *b) {
    int m = *(const int *)a;
    int n = *(const int *)b;

    if (m < n) {
        return -1;
    } else if (m == n) {
        return 0;
    } else {
        return 1;
    }
}

int singleNumber(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 1; i < numsSize; i += 3) {
        if (nums[i] != nums[i - 1]) {
            return nums[i - 1];
        }
    }

    return nums[numsSize - 1];
}

int singleNumber(int *nums, int numsSize) {
    int result = 0;

    for (size_t i = 0; i < 32; i++) {
        size_t mask = 1U << i;
        int count = 0;

        for (int j = 0; j < numsSize; j++) {
            if ((nums[j] & mask) != 0) {
                count++;
            }
        }

        if (count % 3 != 0) {
            result |= mask;
        }
    }

    return result;
}

int singleNumber(int *nums, int numsSize) {
    int ones = 0;
    int twos = 0;

    for (size_t i = 0; i < numsSize; i++) {
        twos |= ones & nums[i];
        ones ^= nums[i];

        int mask = ~(ones & twos);
        ones &= mask;
        twos &= mask;
    }

    return ones;
}

int singleNumber(int *nums, int numsSize) {
    int ones = 0;
    int multi = 0;

    for (size_t i = 0; i < numsSize; i++) {
        ones = (ones ^ nums[i]) & (~multi);
        multi = (multi ^ nums[i]) & (~ones);
    }

    return ones;
}

int singleNumber(int *nums, int numsSize) {
    int ones = 0;
    int twos = 0;

    for (size_t i = 0; i < numsSize; i++) {
        ones ^= (nums[i] & ~twos);
        twos ^= (nums[i] & ~ones);
    }

    return ones;
}