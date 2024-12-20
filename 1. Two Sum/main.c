#include <stdio.h>

#define ARRAY_SIZE 2

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int *array = (int *)malloc(ARRAY_SIZE * sizeof(int));
    if (array == NULL) {
        return NULL;
    }

    *returnSize = ARRAY_SIZE;
    for (int i = 0; i < numsSize - 1; i++) {
        int obj = target - nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == obj) {
                array[0] = i;
                array[1] = j;
                return array;
            }
        }
    }

    free(array);
    return NULL;
}

#define ARRAY_SIZE 2

typedef struct {
    int num;
    int index;
} num_info;

int compare(const void *a, const void *b) {
    const num_info *x = (const num_info *)a;
    const num_info *y = (const num_info *)b;
    return x->num - y->num;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    num_info *info = (num_info *)malloc(numsSize * sizeof(num_info));
    if (info == NULL) {
        return NULL;
    }
    for (int i = 0; i < numsSize; i++) {
        info[i].num = nums[i];
        info[i].index = i;
    }

    qsort(info, numsSize, sizeof(num_info), compare);

    int *array = (int *)malloc(ARRAY_SIZE * sizeof(int));
    if (array == NULL) {
        return NULL;
    }

    int left = 0;
    int right = numsSize - 1;
    while (left < right) {
        int sum = info[left].num + info[right].num;
        if (sum < target) {
            left++;
        } else if (sum > target) {
            right--;
        } else {
            array[0] = info[left].index;
            array[1] = info[right].index;
            *returnSize = 2;
            free(info);
            return array;
        }
    }

    free(array);
    free(info);
    return NULL;
}