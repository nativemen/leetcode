static int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestValidParentheses(char *s) {
    int result = 0;
    int size = strlen(s);
    int left = 0;
    int right = 0;

    for (int i = 0; i < size; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (left == right) {
            result = max(result, left + right);
        } else if (left < right) {
            left = 0;
            right = 0;
        }
    }

    left = 0;
    right = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (left == right) {
            result = max(result, left + right);
        } else if (left > right) {
            left = 0;
            right = 0;
        }
    }

    return result;
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestValidParentheses(char *s) {
    int size = strlen(s);
    if (size == 0) {
        return 0;
    }

    int result = 0;
    int top = 1;
    int *stack = (int *)malloc((size + 1) * sizeof(int));
    if (stack == NULL) {
        return 0;
    }
    stack[0] = -1;

    for (int i = 0; i < size; i++) {
        if (s[i] == '(') {
            stack[top++] = i;
        } else {
            if (top > 0) {
                top--;
            }

            if (top == 0) {
                stack[top++] = i;
            } else {
                result = max(result, i - stack[top - 1]);
            }
        }
    }

    free(stack);
    return result;
}