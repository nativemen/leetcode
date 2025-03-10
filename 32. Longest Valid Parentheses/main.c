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