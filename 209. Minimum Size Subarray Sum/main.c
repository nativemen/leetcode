#include <limits.h>

static inline int min(int a, int b) {
    return (a < b) ? a : b;
}

int minSubArrayLen(int target, int* nums, int numsSize) {
    int res = INT_MAX;
    int sum = 0;
    int left = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];

        while (sum >= target) {
            res = min(res, i - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return (res == INT_MAX) ? 0 : res;
}