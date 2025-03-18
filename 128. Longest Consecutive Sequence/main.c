static int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), compare);

    int count = 1;
    int maxCount = 1;

    for (size_t i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            continue;
        } else if (nums[i] == nums[i - 1] + 1) {
            count++;
        } else {
            count = 1;
        }
        maxCount = (maxCount > count) ? maxCount : count;
    }

    return maxCount;
}