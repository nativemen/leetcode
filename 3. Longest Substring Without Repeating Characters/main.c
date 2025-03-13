#include <stdio.h>

#define ARRAY_SIZE 256

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int lengthOfLongestSubstring(char *s) {
    int size = strlen(s);
    int result = 0;
    int left = 0;
    int count[ARRAY_SIZE] = {0};

    for (int right = 0; right < size; right++) {
        count[(size_t)s[right]]++;
        while (count[(size_t)s[right]] > 1) {
            count[(size_t)s[left++]]--;
        }
        result = max(result, right - left + 1);
    }

    return result;
}

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int lengthOfLongestSubstring(char *s) {
    int size = strlen(s);
    int result = 0;
    int left = 0;

    for (int right = 0; right < size; right++) {
        for (int start = left; start < right; start++) {
            if (s[start] == s[right]) {
                left = start + 1;
                break;
            }
        }
        result = max(result, right - left + 1);
    }

    return result;
}