int removeDuplicates(int *nums, int numsSize) {
    int count = 1;
    int repeat = 0;
    int prev = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == prev) {
            repeat++;
        } else {
            repeat = 0;
            prev = nums[i];
        }

        if (repeat <= 1) {
            nums[count++] = nums[i];
        }
    }

    return count;
}

int removeDuplicates(int *nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize;
    }

    int count = 2;
    for (int i = 2; i < numsSize; i++) {
        if (nums[i] != nums[count - 2]) {
            nums[count++] = nums[i];
        }
    }

    return count;
}