#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define ARRAY_SIZE 16

int reverse(int x) {
    char str[ARRAY_SIZE] = {0};

    snprintf(str, ARRAY_SIZE, "%d", x);

    int left = 0;
    int right = strlen(str) - 1;
    bool minus = false;
    if (str[0] == '-') {
        left++;
        minus = true;
    }

    int result = 0;
    while (right >= left) {
        int digit = str[right] - '0';
        if ((!minus && ((INT_MAX - digit) / 10 < result)) || (minus && ((INT_MAX - 1 - digit) / 10 < result))) {
            return false;
        }
        result = result * 10 + digit;
        right--;
    }

    if (minus) {
        return -result;
    }

    return result;
}

int reverse(int x) {
    int result = 0;
    while (x != 0) {
        int digit = x % 10;
        if (((result > INT_MAX / 10) || ((result == INT_MAX / 10) && (digit > INT_MAX % 10))) ||
            ((result < INT_MIN / 10) || ((result == INT_MIN / 10) && (digit < INT_MIN % 10)))) {
            return false;
        }

        result = result * 10 + digit;
        x /= 10;
    }

    return result;
}