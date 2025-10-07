#include <stdbool.h>
#include <stdio.h>

char nextGreatestLetter(char *letters, int lettersSize, char target) {
    if (target < letters[0] || target >= letters[lettersSize - 1]) {
        return letters[0];
    }

    int left = 0;
    int right = lettersSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (letters[mid] == target) {
            if (letters[mid + 1] != target) {
                return letters[mid + 1];
            }
            left = mid + 1;
        } else if (letters[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return letters[left];
}

char nextGreatestLetter(char *letters, int lettersSize, char target) {
    int left = 0;
    int right = lettersSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (letters[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return letters[left % lettersSize];
}