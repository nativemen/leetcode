#include <stdio.h>

#define ARRAY_SIZE 2

static int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {
    int *result = (int *)malloc(ARRAY_SIZE * sizeof(int));
    if (result == NULL) {
        return NULL;
    }

    *returnSize = ARRAY_SIZE;
    for (int first = 0; first < numbersSize - 1; first++) {
        int object = target - numbers[first];
        if (numbers[first] > object) {
            break;
        }

        int *found = bsearch(&object, numbers + first + 1, numbersSize - first - 1, sizeof(int), compare);
        if (found != NULL) {
            result[0] = first + 1;
            result[1] = found - numbers + 1;
            return result;
        }
    }

    free(result);
    return NULL;
}

#define ARRAY_SIZE 2

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {
    int left = 0;
    int right = numbersSize - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum > target) {
            right--;
        } else if (sum < target) {
            left++;
        } else {
            break;
        }
    }

    int *result = (int *)malloc(ARRAY_SIZE * sizeof(int));
    if (result == NULL) {
        return NULL;
    }

    *returnSize = ARRAY_SIZE;
    result[0] = left + 1;
    result[1] = right + 1;

    return result;
}