#include <stdbool.h>
#include <stdio.h>

static bool isFull(int *len, int start, int end, int maxWidth) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        if (i > start) {
            sum++;
        }
        sum += len[i];
        if (sum > maxWidth) {
            return true;
        }
    }

    return false;
}

static void fillArray(char *array, int arraySize, char **words, int count, bool isLastLine) {
    if (count <= 0) {
        return;
    }

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += strlen(words[i]);
    }

    int blankCnt = (count == 1) ? 1 : count - 1;
    int extra = arraySize - sum - 1;
    int num = 0;
    while (extra >= blankCnt) {
        extra -= blankCnt;
        num++;
    }
    array[0] = '\0';
    int cnt = 0;
    for (int i = 0; i < count; i++) {
        strcat(array, words[i]);
        if (cnt < blankCnt) {
            int additional = 0;
            if (isLastLine) {
                additional = (count > 1) ? 1 : 0;
            } else if (extra > 0) {
                additional = num + 1;
                extra--;
            } else {
                additional = num;
            }

            for (int j = 0; j < additional; j++) {
                strcat(array, " ");
            }
            cnt++;
        }
    }

    int size = strlen(array);
    for (int i = 0; i < arraySize - 1 - size; i++) {
        strcat(array, " ");
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fullJustify(char **words, int wordsSize, int maxWidth, int *returnSize) {
    int len[wordsSize];
    for (int i = 0; i < wordsSize; i++) {
        len[i] = strlen(words[i]);
    }

    char **result = (char **)calloc(wordsSize, sizeof(char *));
    if (result == NULL) {
        goto exit1;
    }

    *returnSize = 0;
    int start = 0;
    for (int end = 0; end <= wordsSize; end++) {
        if (end != wordsSize && !isFull(len, start, end, maxWidth)) {
            continue;
        }

        result[*returnSize] = calloc(maxWidth + 1, sizeof(char));
        if (result[*returnSize] == NULL) {
            goto exit2;
        }
        fillArray(result[*returnSize], maxWidth + 1, words + start, end - start, end == wordsSize);
        start = end;
        *returnSize += 1;
    }

    return result;

exit2:
    for (int i = 0; i < *returnSize; i++) {
        if (result[i] != NULL) {
            free(result[i]);
            result[i] = NULL;
        }
    }
    free(result);
exit1:
    return NULL;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fullJustify(char **words, int wordsSize, int maxWidth, int *returnSize) {
    *returnSize = 0;

    int wordLens[wordsSize];

    for (int i = 0; i < wordsSize; i++) {
        wordLens[i] = strlen(words[i]);
    }

    char **result = (char **)calloc(wordsSize, sizeof(char *));
    if (result == NULL) {
        goto exit1;
    }

    int count = 0;
    int end = 0;

    while (end < wordsSize) {
        int lineLen = 0;
        int start = end;

        while (end < wordsSize && lineLen + wordLens[end] + end - start <= maxWidth) {
            lineLen += wordLens[end];
            end++;
        }

        int numWords = end - start;
        int totalSpace = maxWidth - lineLen;
        int spaceSlots = numWords - 1;

        result[count] = (char *)malloc(maxWidth * sizeof(char));
        if (result[count] == NULL) {
            goto exit2;
        }
        result[count][0] = '\0';

        if (end == wordsSize || spaceSlots == 0) {
            for (int i = start; i < end; i++) {
                strcat(result[count], words[i]);
                if (start < end - 1) {
                    strcat(result[count], " ");
                }
            }

            while (strlen(result[count]) < maxWidth) {
                strcat(result[count], " ");
            }
        } else {
            int baseSpaces = totalSpace / spaceSlots;
            int extraSpaces = totalSpace % spaceSlots;

            for (int i = start; i < end; i++) {
                strcat(result[count], words[i]);
                if (i < end - 1) {
                    int currentSpaces = (i - start < extraSpaces) ? baseSpaces + 1 : baseSpaces;
                    for (int j = 0; j < currentSpaces; j++) {
                        strcat(result[count], " ");
                    }
                }
            }
        }
        count++;
    }

    *returnSize = count;
    return result;

exit2:
    for (int i = 0; i <= count; i++) {
        if (result[i] != NULL) {
            free(result[i]);
        }
    }

    free(result);
exit1:
    return NULL;
}