#include <stdbool.h>

static bool isEqual(char *s, int left, int right, bool skipped) {
    if (left >= right) {
        return true;
    }

    if (s[left] != s[right]) {
        if (skipped) {
            return false;
        }

        return isEqual(s, left + 1, right, true) || isEqual(s, left, right - 1, true);
    }

    return isEqual(s, left + 1, right - 1, skipped);
}

bool validPalindrome(char *s) {
    return isEqual(s, 0, strlen(s) - 1, false);
}

static bool isEqual(char *s, int left, int right) {
    if (left >= right) {
        return true;
    }

    if (s[left] != s[right]) {
        return false;
    }

    return isEqual(s, left + 1, right - 1);
}

bool validPalindrome(char *s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return isEqual(s, left + 1, right) || isEqual(s, left, right - 1);
        }

        left += 1;
        right -= 1;
    }

    return true;
}

static bool isEqual(char *s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }

        left += 1;
        right -= 1;
    }

    return true;
}

bool validPalindrome(char *s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return isEqual(s, left + 1, right) || isEqual(s, left, right - 1);
        }

        left += 1;
        right -= 1;
    }

    return true;
}