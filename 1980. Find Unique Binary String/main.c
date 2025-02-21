#include <stdbool.h>
#include <stdio.h>

char *findDifferentBinaryString(char **nums, int numsSize) {
    char *res = (char *)malloc(numsSize + 1);
    if (res == NULL) {
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        res[i] = (nums[i][i] == '0') ? '1' : '0';
    }

    res[numsSize] = '\0';

    return res;
}

#include <errno.h>

#define ARRAY_SIZE 16

static void binaryToString(char *num, int numSize, int val) {
    for (int i = 0; i < numSize - 1; i++) {
        num[numSize - 2 - i] = ((val >> i) & 0x1) + '0';
    }
    num[numSize - 1] = '\0';
}

char *findDifferentBinaryString(char **nums, int numsSize) {
    bool exists[1 << ARRAY_SIZE] = {false};

    for (int i = 0; i < numsSize; i++) {
        errno = 0;
        char *endptr;
        long value = strtol(nums[i], &endptr, 2);
        if (errno != 0 || endptr == nums[i] || value < 0 || value >= 1 << numsSize) {
            return NULL;
        }
        exists[value] = true;
    }

    int val = 0;
    while (val < (1 << ARRAY_SIZE)) {
        if (!exists[val]) {
            break;
        }
        val++;
    }

    char res[ARRAY_SIZE + 1];
    binaryToString(res, numsSize + 1, val);

    return strdup(res);
}