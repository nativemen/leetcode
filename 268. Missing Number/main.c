int missingNumber(int *nums, int numsSize) {
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    return (numsSize + 1) * numsSize / 2 - sum;
}

int missingNumber(int *nums, int numsSize) {
    int result = numsSize;

    for (int i = 0; i < numsSize; i++) {
        result ^= i ^ nums[i];
    }

    return result;
}


int missingNumber(int *nums, int numsSize) {
    int result = numsSize;

    for (int i = 0; i < numsSize; i++) {
        result += i - nums[i];
    }

    return result;
}