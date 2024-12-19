#include <stdio.h>
#include <stdlib.h>

int add(int *digit, int addition) {
    int sum = *digit + addition;
    if (sum < 10) {
        *digit += addition;
        return 0;
    } else {
        *digit = sum % 10;
        return sum / 10;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize) {
    int addition = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        addition = add(&digits[i], addition);
    }

    *returnSize = digitsSize + addition;
    int *returnArray = (int *)malloc((*returnSize) * sizeof(int));
    if (returnSize == NULL) {
        return NULL;
    }

    int start = 0;
    if (addition == 1) {
        returnArray[0] = addition;
        start = 1;
    }

    (void)memcpy(returnArray + start, digits, digitsSize * sizeof(int));

    return returnArray;
}