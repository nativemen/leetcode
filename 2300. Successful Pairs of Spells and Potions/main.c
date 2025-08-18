#include <stdbool.h>
#include <stdio.h>

static int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *successfulPairs(int *spells, int spellsSize, int *potions, int potionsSize, long long success, int *returnSize) {
    qsort(potions, potionsSize, sizeof(int), compare);

    int *result = (int *)malloc(spellsSize * sizeof(int));
    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i < spellsSize; i++) {
        int left = 0;
        int right = potionsSize - 1;
        int target = potionsSize;

        if ((long long)spells[i] * (long long)potions[left] >= (long long)success) {
            result[i] = potionsSize;
        } else if ((long long)spells[i] * (long long)potions[right] < (long long)success) {
            result[i] = 0;
        } else {
            while (left <= right) {
                int mid = (left + right) / 2;

                if ((long long)spells[i] * (long long)potions[mid] < (long long)success) {
                    if (mid + 1 == potionsSize) {
                        target = potionsSize;
                        break;
                    } else if (mid + 1 < potionsSize &&
                               (long long)spells[i] * (long long)potions[mid + 1] >= (long long)success) {
                        target = mid + 1;
                        break;
                    }
                    left = mid + 1;
                } else {
                    if (mid - 1 < 0) {
                        target = 0;
                        break;
                    } else if (mid - 1 >= 0 &&
                               (long long)spells[i] * (long long)potions[mid - 1] < (long long)success) {
                        target = mid;
                        break;
                    }
                    right = mid - 1;
                }
            }

            result[i] = potionsSize - target;
        }
    }

    *returnSize = spellsSize;

    return result;
}

static int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

static int binarySearch(int *potions, int potionsSize, int minPotion) {
    int left = 0;
    int right = potionsSize;

    while (left < right) {
        int mid = (left + right) / 2;

        if (potions[mid] < minPotion) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *successfulPairs(int *spells, int spellsSize, int *potions, int potionsSize, long long success, int *returnSize) {
    qsort(potions, potionsSize, sizeof(int), compare);

    int *result = (int *)malloc(spellsSize * sizeof(int));
    if (result == NULL) {
        return NULL;
    }

    int minSpell = 1;
    int maxSpell = 100000;

    for (int i = 0; i < spellsSize; i++) {
        if (spells[i] < minSpell) {
            result[i] = 0;
            continue;
        }

        if (spells[i] > maxSpell) {
            result[i] = potionsSize;
            continue;
        }

        int minPotion = (success + spells[i] - 1) / spells[i];
        int index = binarySearch(potions, potionsSize, minPotion);
        result[i] = potionsSize - index;

        if (result[i] == 0) {
            if (spells[i] > minSpell) {
                minSpell = spells[i];
            }
        } else if (result[i] == potionsSize) {
            if (spells[i] < maxSpell) {
                maxSpell = spells[i];
            }
        }
    }

    *returnSize = spellsSize;

    return result;
}

static int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *successfulPairs(int *spells, int spellsSize, int *potions, int potionsSize, long long success, int *returnSize) {
    qsort(potions, potionsSize, sizeof(int), compare);
    *returnSize = 0;

    int *result = (int *)malloc(spellsSize * sizeof(int));
    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i < spellsSize; i++) {
        int left = 0;
        int right = potionsSize;

        while (left < right) {
            int mid = (left + right) / 2;

            if ((long long)spells[i] * (long long)potions[mid] < success) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        result[i] = potionsSize - left;
    }

    *returnSize = spellsSize;

    return result;
}