#include <stdio.h>

int lengthOfLIS(int *nums, int numsSize) {
    int result = 1;
    int dp[numsSize];

    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = (dp[i] >= dp[j] + 1) ? dp[i] : dp[j] + 1;
                result = (result >= dp[i]) ? result : dp[i];
            }
        }
    }

    return result;
}

static int binarySearch(int *seq, int seqSize, int num) {
    int left = 0;
    int right = seqSize;

    while (left < right) {
        int mid = (left + right) / 2;

        if (seq[mid] < num) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int lengthOfLIS(int *nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int len = 0;
    int seq[numsSize];

    for (int i = 0; i < numsSize; i++) {
        int index = binarySearch(seq, len, nums[i]);
        seq[index] = nums[i];
        if (index == len) {
            len++;
        }
    }

    return len;
}