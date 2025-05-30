#include <stdbool.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool *kidsWithCandies(int *candies, int candiesSize, int extraCandies, int *returnSize) {
    *returnSize = 0;
    bool *result = (bool *)malloc(candiesSize * sizeof(bool));
    if (result == NULL) {
        return NULL;
    }

    int maxCandies = 0;

    for (int i = 0; i < candiesSize; i++) {
        if (maxCandies < candies[i]) {
            maxCandies = candies[i];
        }
    }

    for (int i = 0; i < candiesSize; i++) {
        result[i] = candies[i] + extraCandies >= maxCandies;
    }

    *returnSize = candiesSize;

    return result;
}