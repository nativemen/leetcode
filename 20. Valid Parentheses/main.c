#include <stdbool.h>

#define ARRAY_SIZE 10000

bool isValid(char *s) {
    char stack[ARRAY_SIZE] = {0};
    int top = 0;

    while (*s != '\0') {
        if (*s == '{' || *s == '[' || *s == '(') {
            stack[top] = *s;
            top++;
        } else {
            if (top <= 0) {
                return false;
            }

            if ((top <= 0) || (*s == '}' && stack[top - 1] != '{') || (*s == ']' && stack[top - 1] != '[') ||
                (*s == ')' && stack[top - 1] != '(')) {
                return false;
            }

            top--;
        }

        s += 1;
    }

    return top == 0;
}