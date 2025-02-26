#include <stdbool.h>

bool isPowerOfTwo(int n) {
    long long val = 1;

    while (val < n) {
        val *= 2;
    }

    if (val == n) {
        return true;
    }

    return false;
}

bool isPowerOfTwo(int n) {
    if (n == 1) {
        return true;
    } else if (n < 1) {
        return false;
    } else if (n % 2 == 0) {
        return isPowerOfTwo(n / 2);
    } else {
        return false;
    }
}

bool isPowerOfTwo(int n) {
    if (n == 1) {
        return true;
    }

    if (n < 1 || n % 2 != 0) {
        return false;
    }

    return isPowerOfTwo(n / 2);
}

bool isPowerOfTwo(int n) {
    return n > 0 && 1073741824 % n == 0;
}

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}