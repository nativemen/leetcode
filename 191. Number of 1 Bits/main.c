int hammingWeight(int n) {
    int count = 0;

    while (n != 0) {
        if (n & 0x1 != 0) {
            count++;
        }

        n >>= 1;
    }

    return count;
}

int hammingWeight(int n) {
    int count = 0;

    while (n != 0) {
        count += n & 1;
        n >>= 1;
    }

    return count;
}

int hammingWeight(int n) {
    return __builtin_popcount(n);
}