int removeElement(int *nums, int numsSize, int val) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        if (nums[left] != val) {
            left++;
            continue;
        }

        if (nums[right] == val) {
            right--;
            continue;
        }

        nums[left] = nums[right];
        nums[right] = val;
    }

    return left + 1;
}

#define ARRAY_SIZE 100

int removeElement(int *nums, int numsSize, int val) {
    int array[ARRAY_SIZE] = {0};

    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            array[count++] = nums[i];
        }
    }

    for (int i = 0; i < count; i++) {
        nums[i] = array[i];
    }

    return count;
}

int removeElement(int *nums, int numsSize, int val) {
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[count++] = nums[i];
        }
    }

    return count;
}