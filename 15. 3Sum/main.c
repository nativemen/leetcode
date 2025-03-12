#include <limits.h>
#include <stdio.h>

#define ARRAY_SIZE 3

static int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    *returnColumnSizes = (int *)calloc(numsSize * (numsSize - 1), sizeof(int));
    if (*returnColumnSizes == NULL) {
        goto exit1;
    }

    int **result = (int **)calloc(numsSize * (numsSize - 1), sizeof(int *));
    if (result == NULL) {
        goto exit2;
    }

    *returnSize = 0;
    int prev = INT_MIN;
    for (int i = 0; i < numsSize - 2; i++) {
        if (nums[i] == prev) {
            continue;
        }
        prev = nums[i];
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum + nums[i] < 0) {
                left++;
            } else if (sum + nums[i] > 0) {
                right--;
            } else {
                int m;
                for (m = 0; m < *returnSize; m++) {
                    if (nums[i] == result[m][0] && nums[left] == result[m][1] && nums[right] == result[m][2]) {
                        break;
                    }
                }
                if (m == *returnSize) {
                    result[m] = (int *)calloc(ARRAY_SIZE, sizeof(int));
                    if (result[m] == NULL) {
                        goto exit3;
                    }

                    result[m][0] = nums[i];
                    result[m][1] = nums[left];
                    result[m][2] = nums[right];
                    (*returnColumnSizes)[m] = ARRAY_SIZE;
                    *returnSize += 1;
                }
                left++;
                right--;
            }
        }
    }

    return result;

exit3:
    for (int i = 0; i < *returnSize; i++) {
        if (result[i] != NULL) {
            free(result[i]);
            result[i] = NULL;
        }
    }

    *returnSize = 0;
    free(result);
exit2:
    free(*returnColumnSizes);
    *returnColumnSizes = NULL;
exit1:
    return NULL;
}

#define ARRAY_SIZE 3

static int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    *returnColumnSizes = (int *)calloc(numsSize * (numsSize - 1), sizeof(int));
    if (*returnColumnSizes == NULL) {
        goto exit1;
    }

    int **result = (int **)calloc(numsSize * (numsSize - 1), sizeof(int *));
    if (result == NULL) {
        goto exit2;
    }

    *returnSize = 0;
    int prev = INT_MIN;
    for (int cur = 0; cur < numsSize - 2; cur++) {
        if (nums[cur] == prev) {
            continue;
        }
        prev = nums[cur];
        int left = cur + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[left] + nums[right] + nums[cur];
            if (sum == 0) {
                int m = *returnSize;
                printf("m=%d\n", m);
                result[m] = (int *)calloc(ARRAY_SIZE, sizeof(int));
                if (result[m] == NULL) {
                    goto exit3;
                }

                result[m][0] = nums[cur];
                result[m][1] = nums[left];
                result[m][2] = nums[right];
                (*returnColumnSizes)[m] = ARRAY_SIZE;
                *returnSize += 1;
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                left++;
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;

exit3:
    for (int i = 0; i < *returnSize; i++) {
        if (result[i] != NULL) {
            free(result[i]);
            result[i] = NULL;
        }
    }

    *returnSize = 0;
    free(result);
exit2:
    free(*returnColumnSizes);
    *returnColumnSizes = NULL;
exit1:
    return NULL;
}