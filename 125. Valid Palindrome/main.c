#include <stdbool.h>

bool isPalindrome(char *s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        if (!isalnum(s[left])) {
            left++;
            continue;
        }

        if (!isalnum(s[right])) {
            right--;
            continue;
        }

        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

static bool isEqual(char *s, int left, int right) {
    if (left >= right) {
        return true;
    }

    if (!isalnum(s[left])) {
        return isEqual(s, left + 1, right);
    }

    if (!isalnum(s[right])) {
        return isEqual(s, left, right - 1);
    }

    if (tolower(s[left]) == tolower(s[right])) {
        return isEqual(s, left + 1, right - 1);
    }

    return false;
}

bool isPalindrome(char *s) {
    return isEqual(s, 0, strlen(s) - 1);
}