#include <stdbool.h>
#include <stdio.h>

int mySqrt(int x) {
    long long left = 0;
    long long right = x;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        if (square == (long long)x) {
            return mid;
        } else if (square < (long long)x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}

int mySqrt(int x) {
    long long i = 0;

    while (i * i <= (long long)x) {
        i++;
    }

    return (int)(i - 1);
}