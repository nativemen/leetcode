void moveZeroes(int *nums, int numsSize) {
    int non_zero_index = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            int temp = nums[i];
            nums[i] = nums[non_zero_index];
            nums[non_zero_index] = temp;
            non_zero_index++;
        }
    }
}

void moveZeroes(int *nums, int numsSize) {
    int zero_pos = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[zero_pos] = nums[i];
            zero_pos++;
        }
    }

    for (int i = zero_pos; i < numsSize; i++) {
        nums[i] = 0;
    }
}