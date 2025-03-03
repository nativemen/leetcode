static int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

int majorityElement(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    return nums[numsSize / 2];
}

int majorityElement(int *nums, int numsSize) {
    int major = 0;
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            major = nums[i];
            count++;
        } else {
            if (major == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
    }

    return major;
}