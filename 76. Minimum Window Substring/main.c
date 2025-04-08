#include <limits.h>
#include <stdio.h>

#define ARRAY_SIZE 128

char *minWindow(char *s, char *t) {
    int sLen = strlen(s);
    int tLen = strlen(t);

    if (sLen < tLen) {
        return "";
    }

    int tCount[ARRAY_SIZE] = {0};

    for (int i = 0; i < tLen; i++) {
        tCount[t[i]]++;
    }

    int left = 0;
    int right = 0;
    int minLeft = 0;
    int minLen = INT_MAX;
    int matched = 0;
    int sCount[ARRAY_SIZE] = {0};

    for (right = 0; right < sLen; right++) {
        if (tCount[s[right]] == 0) {
            continue;
        }

        sCount[s[right]]++;

        if (sCount[s[right]] <= tCount[s[right]]) {
            matched++;
        }

        if (matched == tLen) {
            while (tCount[s[left]] == 0 || sCount[s[left]] > tCount[s[left]]) {
                if (tCount[s[left]] != 0) {
                    sCount[s[left]]--;
                }
                left++;
            }

            int size = right - left + 1;
            if (size < minLen) {
                minLeft = left;
                minLen = size;
            }
        }
    }

    if (minLen == INT_MAX) {
        return "";
    }

    s[minLeft + minLen] = '\0';

    return s + minLeft;
}

#define ARRAY_SIZE 128

char *minWindow(char *s, char *t) {
    int sLen = strlen(s);
    int tLen = strlen(t);

    int count[ARRAY_SIZE] = {0};

    for (int i = 0; i < tLen; i++) {
        count[t[i]]++;
    }

    int left = 0;
    int right = 0;
    int minLeft = 0;
    int minLen = INT_MAX;
    int matched = 0;

    for (right = 0; right < sLen; right++) {
        if (count[s[right]] > 0) {
            matched++;
        }

        count[s[right]]--;

        while (matched == tLen) {
            int size = right - left + 1;
            if (size < minLen) {
                minLeft = left;
                minLen = size;
            }

            count[s[left]]++;
            if (count[s[left]] > 0) {
                matched--;
            }

            left++;
        }
    }

    if (minLen == INT_MAX) {
        return "";
    }

    s[minLeft + minLen] = '\0';

    return s + minLeft;
}

#define ARRAY_SIZE 128

char *minWindow(char *s, char *t) {
    int tLen = strlen(t);
    int count[ARRAY_SIZE] = {0};

    for (int i = 0; i < tLen; i++) {
        count[t[i]]++;
    }

    int left = 0;
    int right = 0;
    int needed = tLen;
    int minLeft = 0;
    int minLen = INT_MAX;

    while (s[left] != '\0') {
        if (s[right] == '\0' && needed > 0) {
            break;
        }

        if (needed > 0) {
            if (count[s[right++]]-- > 0) {
                needed--;
            }
        } else {
            int size = right - left;
            if (size < minLen) {
                minLen = size;
                minLeft = left;
            }

            if (++count[s[left++]] > 0) {
                needed++;
            }
        }
    }

    if (minLen == INT_MAX) {
        return "";
    }

    s[minLeft + minLen] = '\0';

    return s + minLeft;
}