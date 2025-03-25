#include <stdio.h>

int evalRPN(char **tokens, int tokensSize) {
    int nums[tokensSize];
    size_t top = 0;
    for (size_t i = 0; i < tokensSize; i++) {
        if (strcmp(tokens[i], "+") == 0) {
            nums[top - 2] += nums[top - 1];
            top--;
        } else if (strcmp(tokens[i], "-") == 0) {
            nums[top - 2] -= nums[top - 1];
            top--;
        } else if (strcmp(tokens[i], "*") == 0) {
            nums[top - 2] *= nums[top - 1];
            top--;
        } else if (strcmp(tokens[i], "/") == 0) {
            nums[top - 2] /= nums[top - 1];
            top--;
        } else {
            nums[top++] = strtol(tokens[i], NULL, 0);
        }
    }

    return nums[top - 1];
}