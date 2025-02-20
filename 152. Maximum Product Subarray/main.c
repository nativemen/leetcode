#include <limits.h>

int maxProduct(int *nums, int numsSize) {
    int max_product = INT_MIN;
    int product = 1;

    for (int i = 0; i < numsSize; i++) {
        product *= nums[i];
        max_product = (max_product > product) ? max_product : product;
        if (product == 0) {
            product = 1;
        }
    }

    product = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        product *= nums[i];
        max_product = (max_product > product) ? max_product : product;
        if (product == 0) {
            product = 1;
        }
    }

    return max_product;
}

int maxProduct(int *nums, int numsSize) {
    int max_product = INT_MIN;
    int left_product = 1;
    int right_product = 1;

    for (int i = 0; i < numsSize; i++) {
        left_product *= nums[i];
        right_product *= nums[numsSize - 1 - i];
        max_product = (max_product > left_product) ? max_product : left_product;
        max_product = (max_product > right_product) ? max_product : right_product;
        left_product = (left_product == 0) ? 1 : left_product;
        right_product = (right_product == 0) ? 1 : right_product;
    }

    return max_product;
}

int maxProduct(int *nums, int numsSize) {
    int max_product = INT_MIN;
    int cur_max = 1;
    int cur_min = 1;

    for (int i = 0; i < numsSize; i++) {
        int temp1 = cur_max * nums[i];
        int temp2 = cur_min * nums[i];
        cur_max = (temp1 > temp2) ? temp1 : temp2;
        cur_max = (cur_max > nums[i]) ? cur_max : nums[i];
        cur_min = (temp1 < temp2) ? temp1 : temp2;
        cur_min = (cur_min < nums[i]) ? cur_min : nums[i];
        max_product = (max_product > cur_max) ? max_product : cur_max;
    }

    return max_product;
}