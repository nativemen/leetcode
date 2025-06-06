int totalHammingDistance(int *nums, int numsSize) {
    int total = 0;

    for (int i = 0; i < 32; i++) {
        int bitCount = 0;
        for (int j = 0; j < numsSize; j++) {
            bitCount += (nums[j] >> i) & 1;
        }
        total += bitCount * (numsSize - bitCount);
    }

    return total;
}

int totalHammingDistance(int *nums, int numsSize) {
    int total = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            total += __builtin_popcount(nums[i] ^ nums[j]);
        }
    }

    return total;
}