#include <limits.h>
#include <stdio.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    int size = nums1Size > nums2Size ? nums2Size : nums1Size;
    int *result = (int *)malloc(size * sizeof(int));
    if (result == NULL) {
        return NULL;
    }

    int i = 0;
    int j = 0;
    *returnSize = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            result[*returnSize] = nums1[i];
            *returnSize += 1;
            i++;
            j++;
        }
    }

    return result;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
    int size = nums1Size > nums2Size ? nums2Size : nums1Size;
    int *result = (int *)malloc(size * sizeof(int));
    if (result == NULL) {
        return NULL;
    }

    *returnSize = 0;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                result[*returnSize] = nums1[i];
                *returnSize += 1;
                nums2[j] = INT_MIN;
                break;
            }
        }
    }

    return result;
}
