#include <stdbool.h>
#include <stdio.h>

static int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

int maxOperations(int *nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);

    int count = 0;
    int left = 0;
    int right = numsSize - 1;

    while (right >= 0 && nums[right] >= k) {
        right--;
    }

    while (left < right) {
        int target = k - nums[left];

        if (target == nums[right]) {
            count++;
            left++;
            right--;
        } else if (target < nums[right]) {
            right--;
        } else {
            left++;
        }
    }

    return count;
}

int maxOperations(int *nums, int numsSize, int k) {
    int *array = (int *)calloc(k, sizeof(int));
    if (array == NULL) {
        return -1;
    }

    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < k) {
            int target = k - nums[i];

            if (array[target] == 0) {
                array[nums[i]]++;
            } else {
                count++;
                array[target]--;
            }
        }
    }

    free(array);

    return count;
}