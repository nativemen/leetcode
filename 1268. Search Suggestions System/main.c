#include <stdbool.h>
#include <stdio.h>

#define MATCHED_WORDS_MAX_NUM 3

static int compare(const void *a, const void *b) {
    const char *x = *(const char **)a;
    const char *y = *(const char **)b;

    return strcmp(x, y);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***suggestedProducts(
        char **products, int productsSize, char *searchWord, int *returnSize, int **returnColumnSizes) {
    size_t wordSize = strlen(searchWord);
    *returnSize = 0;
    char ***result = (char ***)malloc(wordSize * sizeof(char **));
    if (result == NULL) {
        goto exit1;
    }

    *returnColumnSizes = (int *)calloc(wordSize, sizeof(int));
    if (*returnColumnSizes == NULL) {
        goto exit2;
    }

    qsort(products, productsSize, sizeof(char *), compare);

    for (int i = 0; i < wordSize; i++) {
        result[i] = (char **)calloc(MATCHED_WORDS_MAX_NUM, sizeof(char *));
        if (result[i] == NULL) {
            goto exit3;
        }

        int count = 0;
        for (int j = 0; j < productsSize && count < MATCHED_WORDS_MAX_NUM; j++) {
            if (strncmp(products[j], searchWord, i + 1) == 0) {
                result[i][count++] = strdup(products[j]);
            }
        }

        (*returnColumnSizes)[i] = count;
    }

    *returnSize = wordSize;

    return result;

exit3:
    for (int i = 0; i < wordSize; i++) {
        if (result[i] != NULL) {
            for (int j = 0; j < (*returnColumnSizes)[i]; j++) {
                if (result[i][j] != NULL) {
                    free(result[i][j]);
                    result[i][j] = NULL;
                }
            }
            free(result[i]);
            result[i] = NULL;
        }
    }

    free(*returnColumnSizes);

exit2:
    free(result);

exit1:
    return NULL;
}

#define MATCHED_WORDS_MAX_NUM 3

static inline int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

static inline bool startWith(const char *str, const char *prefix) {
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***suggestedProducts(
        char **products, int productsSize, char *searchWord, int *returnSize, int **returnColumnSizes) {
    size_t wordSize = strlen(searchWord);
    *returnSize = 0;
    char ***result = (char ***)malloc(wordSize * sizeof(char **));
    if (result == NULL) {
        goto exit1;
    }

    *returnColumnSizes = (int *)calloc(wordSize, sizeof(int));
    if (*returnColumnSizes == NULL) {
        goto exit2;
    }

    qsort(products, productsSize, sizeof(char *), compare);
    char *prefix = (char *)malloc((wordSize + 1) * sizeof(char));
    if (prefix == NULL) {
        goto exit3;
    }

    for (int i = 0; i < wordSize; i++) {
        result[i] = (char **)calloc(MATCHED_WORDS_MAX_NUM, sizeof(char *));
        if (result[i] == NULL) {
            goto exit4;
        }

        prefix[i] = searchWord[i];
        prefix[i + 1] = '\0';
        int count = 0;
        int left = 0;
        int right = productsSize - 1;
        int target = productsSize;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (strcmp(products[mid], prefix) >= 0) {
                target = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        for (int j = target; j < productsSize && count < MATCHED_WORDS_MAX_NUM; j++) {
            if (!startWith(products[j], prefix)) {
                break;
            }
            result[i][count++] = strdup(products[j]);
        }

        (*returnColumnSizes)[i] = count;
    }

    *returnSize = wordSize;

    return result;

exit4:
    for (int i = 0; i < wordSize; i++) {
        if (result[i] != NULL) {
            for (int j = 0; j < (*returnColumnSizes)[i]; j++) {
                if (result[i][j] != NULL) {
                    free(result[i][j]);
                    result[i][j] = NULL;
                }
            }
            free(result[i]);
            result[i] = NULL;
        }
    }

exit3:
    free(*returnColumnSizes);

exit2:
    free(result);

exit1:
    return NULL;
}

#define MATCHED_WORDS_MAX_NUM 3

static inline int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***suggestedProducts(
        char **products, int productsSize, char *searchWord, int *returnSize, int **returnColumnSizes) {
    size_t wordSize = strlen(searchWord);
    qsort(products, productsSize, sizeof(char *), compare);

    *returnSize = 0;
    char ***result = (char ***)malloc(wordSize * sizeof(char **));
    if (result == NULL) {
        goto exit1;
    }

    *returnColumnSizes = (int *)calloc(wordSize, sizeof(int));
    if (*returnColumnSizes == NULL) {
        goto exit2;
    }

    int left = 0;
    int right = productsSize - 1;

    for (int i = 0; i < wordSize; i++) {
        while (left <= right && (strlen(products[left]) < i || products[left][i] != searchWord[i])) {
            left += 1;
        }

        while (left <= right && (strlen(products[right]) < i || products[right][i] != searchWord[i])) {
            right -= 1;
        }

        int remain = right - left + 1;
        int count = 0;
        result[i] = (char **)calloc(MATCHED_WORDS_MAX_NUM, sizeof(char *));
        if (result[i] == NULL) {
            goto exit4;
        }

        for (int j = 0; j < remain && j < MATCHED_WORDS_MAX_NUM; j++) {
            result[i][count++] = strdup(products[left + j]);
        }

        (*returnColumnSizes)[i] = count;
    }

    *returnSize = wordSize;

    return result;

exit4:
    for (int i = 0; i < wordSize; i++) {
        if (result[i] != NULL) {
            for (int j = 0; j < (*returnColumnSizes)[i]; j++) {
                if (result[i][j] != NULL) {
                    free(result[i][j]);
                    result[i][j] = NULL;
                }
            }
            free(result[i]);
            result[i] = NULL;
        }
    }

exit3:
    free(*returnColumnSizes);

exit2:
    free(result);

exit1:
    return NULL;
}