#include <stdbool.h>
#include <stdio.h>

static bool isAllMatched(int *checked, int size) {
    for (int i = 0; i < size; i++) {
        if (checked[i] == 0) {
            return false;
        }
    }

    return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findSubstring(char *s, char **words, int wordsSize, int *returnSize) {
    size_t sLen = strlen(s);
    size_t wordLen = strlen(words[0]);
    size_t total = wordLen * wordsSize;

    *returnSize = 0;
    if (sLen < total) {
        return NULL;
    }

    int checked[wordsSize];
    for (int i = 0; i < wordsSize; i++) {
        checked[i] = 0;
    }

    int *result = (int *)calloc(sLen, sizeof(int));

    size_t maxSize = sLen - total;
    for (size_t i = 0; i <= maxSize; i++) {
        size_t count = 0;
        char *id = s + i;

        while (!isAllMatched(checked, wordsSize)) {
            bool found = false;

            for (size_t j = 0; j < wordsSize; j++) {
                if (checked[j] == 1) {
                    continue;
                }

                if (memcmp(id, words[j], wordLen) == 0) {
                    checked[j] = 1;
                    id += wordLen;
                    count++;
                    found = true;
                }
            }

            if (!found) {
                break;
            }
        }

        if (count == wordsSize) {
            result[*returnSize] = i;
            *returnSize += 1;
        }

        for (int i = 0; i < wordsSize; i++) {
            checked[i] = 0;
        }
    }

    return result;
}

typedef struct {
    char *word;
    int count;
} WordCount;

static int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findSubstring(char *s, char **words, int wordsSize, int *returnSize) {
    *returnSize = 0;
    if (wordsSize == 0 || s == NULL || words == NULL) {
        return NULL;
    }

    size_t sLen = strlen(s);
    size_t wordLen = strlen(words[0]);
    size_t total = wordLen * wordsSize;

    if (sLen < total) {
        return NULL;
    }

    qsort(words, wordsSize, sizeof(char *), compare);

    WordCount *wordCount = (WordCount *)malloc(wordsSize * sizeof(WordCount));
    int uniqueCount = 0;

    for (size_t i = 0; i < wordsSize;) {
        size_t j = i + 1;
        while (j < wordsSize && strcmp(words[i], words[j]) == 0) {
            j++;
        }
        wordCount[uniqueCount].word = words[i];
        wordCount[uniqueCount].count = j - i;
        uniqueCount++;
        i = j;
    }

    int size = sLen - total + 1;
    int *result = (int *)malloc(size * sizeof(int));
    int *count = (int *)malloc(uniqueCount * sizeof(int));

    for (size_t i = 0; i < size; i++) {
        memset(count, 0, uniqueCount * sizeof(int));
        int matched = 0;

        for (size_t j = 0; j < wordsSize; j++) {
            char *current = s + i + j * wordLen;
            int foundIndex = -1;
            int left = 0;
            int right = uniqueCount - 1;

            while (left <= right) {
                int mid = (left + right) / 2;
                int cmp = memcmp(current, wordCount[mid].word, wordLen);
                if (cmp == 0) {
                    foundIndex = mid;
                    break;
                } else if (cmp > 0) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (foundIndex == -1) {
                break;
            }

            count[foundIndex]++;
            if (count[foundIndex] > wordCount[foundIndex].count) {
                break;
            }

            matched++;
        }

        if (matched == wordsSize) {
            result[*returnSize] = i;
            *returnSize += 1;
        }
    }

    free(count);
    free(wordCount);

    if (*returnSize == 0) {
        free(result);
        result = NULL;
    }

    return result;
}