#include <ctype.h>
#include <stdio.h>

#define STACK_SIZE 1024

int calculate(char *s) {
    int stack[STACK_SIZE];
    int num = 0;
    int sign = 1;
    int result = 0;
    int top = -1;

    while (*s != '\0') {
        if (isdigit(*s)) {
            num *= 10;
            num += *s - '0';
        } else if (*s == '+') {
            result += sign * num;
            num = 0;
            sign = 1;
        } else if (*s == '-') {
            result += sign * num;
            num = 0;
            sign = -1;
        } else if (*s == '(') {
            stack[++top] = result;
            stack[++top] = sign;
            result = 0;
            num = 0;
            sign = 1;
        } else if (*s == ')') {
            result += sign * num;
            num = 0;
            sign = 1;
            result *= stack[top--];
            result += stack[top--];
        }
        s++;
    }

    return result + sign * num;
}