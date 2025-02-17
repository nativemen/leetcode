#include <limits.h>
#include <stdbool.h>

bool isBadVersion(int version);

static int min(int a, int b) {
    return (a < b) ? a : b;
}

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    long long left = 1;
    long long right = n;
    long long first = -1;

    while (left <= right) {
        int mid = (left + right + 1) / 2;
        if (isBadVersion(mid)) {
            first = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return first;
}