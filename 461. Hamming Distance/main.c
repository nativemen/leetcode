int hammingDistance(int x, int y) {
    int n = x ^ y;
    int count = 0;

    while (n != 0) {
        count += n & 1;
        n >>= 1;
    }

    return count;
}

int hammingDistance(int x, int y) {
    return __builtin_popcount(x ^ y);
}