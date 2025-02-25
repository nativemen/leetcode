

#include <stdbool.h>

bool isPowerOfThree(int n) {
    long long val = 1;

    while (val < n) {
        val *= 3;
    }

    if (val == n) {
        return true;
    }

    return false;
}

bool isPowerOfThree(int n) {
    if (n < 1 || n == 2) {
        return false;
    } else if (n == 1) {
        return true;
    } else if (n % 3 == 0) {
        return isPowerOfThree(n / 3);
    } else {
        return false;
    }
}

bool isPowerOfThree(int n) {
    if (n == 1) {
        return true;
    }

    if (n < 1 || n % 3 != 0) {
        return false;
    }

    return isPowerOfThree(n / 3);
}

bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
}