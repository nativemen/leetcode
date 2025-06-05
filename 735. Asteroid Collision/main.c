#include <stdbool.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *asteroidCollision(int *asteroids, int asteroidsSize, int *returnSize) {
    *returnSize = 0;
    int *result = (int *)malloc(asteroidsSize * sizeof(int));
    if (result == NULL) {
        return NULL;
    }

    int count = 0;
    int i = 0;

    while (i < asteroidsSize) {
        if (count > 0) {
            if (result[count - 1] < 0) {
                result[count++] = asteroids[i++];
            } else {
                if (asteroids[i] < 0) {
                    if (result[count - 1] + asteroids[i] < 0) {
                        count--;
                    } else if (result[count - 1] + asteroids[i] == 0) {
                        count--;
                        i++;
                    } else {
                        i++;
                    }
                } else {
                    result[count++] = asteroids[i++];
                }
            }
        } else {
            result[count++] = asteroids[i++];
        }
    }

    *returnSize = count;

    return result;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *asteroidCollision(int *asteroids, int asteroidsSize, int *returnSize) {
    *returnSize = 0;
    int *result = (int *)malloc(asteroidsSize * sizeof(int));
    if (result == NULL) {
        return NULL;
    }

    int count = 0;
    int i = 0;

    while (i < asteroidsSize) {
        if (count == 0 || result[count - 1] < 0 || asteroids[i] >= 0) {
            result[count++] = asteroids[i++];
        } else if (result[count - 1] + asteroids[i] < 0) {
            count--;
        } else if (result[count - 1] + asteroids[i] == 0) {
            count--;
            i++;
        } else {
            i++;
        }
    }

    *returnSize = count;

    return result;
}