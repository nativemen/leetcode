#include <stdbool.h>

#define ARRAY_SIZE 10

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    if (x == 0) {
        return true;
    }

    int count = 0;
    int digit[ARRAY_SIZE];

    while (x != 0) {
        digit[count++] = x % 10;
        x /= 10;
    }

    int left = 0;
    int right = count - 1;

    while (left < right) {
        if (digit[left] != digit[right]) {
            return false;
        }
    }

    return true;
}

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    if (x == 0) {
        return true;
    }

    long long reverse = 0;
    long long original = x;

    while (x != 0) {
        reverse *= 10;
        reverse += x % 10;
        x /= 10;
    }

    return original == reverse;
}