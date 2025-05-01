#include <stdio.h>

int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    int numsSize = nums1Size + nums2Size;
    int nums[numsSize];
    for (int i = 0; i < nums1Size; i++) {
        nums[i] = nums1[i];
    }

    for (int i = 0; i < nums2Size; i++) {
        nums[i + nums1Size] = nums2[i];
    }

    qsort(nums, numsSize, sizeof(int), compare);

    if (numsSize % 2 == 0) {
        return (double)(nums[numsSize / 2 - 1] + nums[numsSize / 2]) / 2.0;
    } else {
        return (double)nums[numsSize / 2];
    }
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    int numsSize = nums1Size + nums2Size;
    int i = 0;
    int j = 0;
    int m1 = 0;
    int m2 = 0;

    for (int count = 0; count <= numsSize / 2; count++) {
        m1 = m2;

        if (i == nums1Size) {
            m2 = nums2[j++];
        } else if (j == nums2Size) {
            m2 = nums1[i++];
        } else if (nums1[i] < nums2[j]) {
            m2 = nums1[i++];
        } else {
            m2 = nums2[j++];
        }
    }

    if (numsSize % 2 != 0) {
        return (double)m2;
    } else {
        return (double)(m1 + m2) / 2.0;
    }
}