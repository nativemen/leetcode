#include <stdbool.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize) {
    int *result = (int *)calloc(temperaturesSize, sizeof(int));
    if (result == NULL) {
        goto exit1;
    }

    int *stack = (int *)calloc(temperaturesSize, sizeof(int));
    if (stack == NULL) {
        goto exit2;
    }

    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {
        while (top != -1 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--];
            result[idx] = i - idx;
        }
        stack[++top] = i;
    }

    free(stack);
    *returnSize = temperaturesSize;

    return result;

exit2:
    free(result);

exit1:
    return NULL;
}