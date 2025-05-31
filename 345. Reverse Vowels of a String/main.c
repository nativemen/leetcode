#include <stdbool.h>
#include <stdio.h>

static bool isVowel(char c) {
    const char vowels[] = "aeiouAEIOU";
    size_t size = sizeof(vowels) / sizeof(char);

    for (size_t i = 0; i < size; i++) {
        if (c == vowels[i]) {
            return true;
        }
    }

    return false;
}

char *reverseVowels(char *s) {
    int len = strlen(s);
    int left = 0;
    int right = len - 1;

    while (left < right) {
        while (left < len && !isVowel(s[left])) {
            left++;
        }

        while (right >= 0 && !isVowel(s[right])) {
            right--;
        }

        if (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }

    return s;
}

static bool isVowel(char c) {
    const char vowels[] = "aeiouAEIOU";
    size_t size = sizeof(vowels) / sizeof(char);

    for (size_t i = 0; i < size; i++) {
        if (c == vowels[i]) {
            return true;
        }
    }

    return false;
}

char *reverseVowels(char *s) {
    int len = strlen(s);
    int left = 0;
    int right = len - 1;

    while (left < right) {
        if (!isVowel(s[left])) {
            left++;
        }

        if (!isVowel(s[right])) {
            right--;
        }

        if (isVowel(s[left]) && isVowel(s[right])) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }

    return s;
}