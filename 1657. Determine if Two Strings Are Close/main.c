#include <stdbool.h>
#include <stdio.h>

#define ALPHABET_SIZE 26

static int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

bool closeStrings(char *word1, char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if (len1 != len2) {
        return false;
    }

    int freq1[ALPHABET_SIZE] = {0};
    int freq2[ALPHABET_SIZE] = {0};

    for (int i = 0; i < len1; i++) {
        freq1[word1[i] - 'a']++;
    }

    for (int i = 0; i < len2; i++) {
        freq2[word2[i] - 'a']++;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (freq1[i] != freq2[i] && (freq1[i] == 0 || freq2[i] == 0)) {
            return false;
        }
    }

    qsort(freq1, ALPHABET_SIZE, sizeof(int), compare);
    qsort(freq2, ALPHABET_SIZE, sizeof(int), compare);

    return memcmp(freq1, freq2, ALPHABET_SIZE * sizeof(int)) == 0;
}