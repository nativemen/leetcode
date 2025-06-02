#include <stdbool.h>
#include <stdio.h>

static bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowels(char *s, int k) {
    int sLen = strlen(s);
    int count = 0;

    for (int i = 0; i < k; i++) {
        if (isVowel(s[i])) {
            count++;
        }
    }

    int maxCount = count;

    for (int i = k; i < sLen; i++) {
        if (isVowel(s[i - k])) {
            count--;
        }

        if (isVowel(s[i])) {
            count++;
        }

        if (count > maxCount) {
            maxCount = count;
        }
    }

    return maxCount;
}

static int vowelCheck(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1;
    }

    return 0;
}

int maxVowels(char *s, int k) {
    int sLen = strlen(s);
    int count = 0;

    for (int i = 0; i < k; i++) {
        count += vowelCheck(s[i]);
    }

    int maxCount = count;

    for (int i = k; i < sLen; i++) {
        count -= vowelCheck(s[i - k]);
        count += vowelCheck(s[i]);

        if (count > maxCount) {
            maxCount = count;
        }
    }

    return maxCount;
}

int maxVowels(char *s, int k) {
    int vowels[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    int sLen = strlen(s);
    int count = 0;

    for (int i = 0; i < k; i++) {
        count += vowels[s[i] - 'a'];
    }

    int maxCount = count;

    for (int i = k; i < sLen; i++) {
        count -= vowels[s[i - k] - 'a'];
        count += vowels[s[i] - 'a'];

        if (count > maxCount) {
            maxCount = count;
        }
    }

    return maxCount;
}

int maxVowels(char *s, int k) {
    int vowels[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    int sLen = strlen(s);
    int count = 0;
    int maxCount = 0;

    for (int i = 0; i < sLen; i++) {
        count += vowels[s[i] - 'a'];
        if (i >= k) {
            count -= vowels[s[i - k] - 'a'];
        }

        if (count > maxCount) {
            maxCount = count;
        }
    }

    return maxCount;
}