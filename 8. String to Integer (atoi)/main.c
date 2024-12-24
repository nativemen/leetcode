#include <limits.h>
#include <stdio.h>

int myAtoi(char *s) {
    int start = 0;
    int len = (int)strlen(s);
    for (int i = start; i < len; i++) {
        if (s[i] != ' ') {
            start = i;
            break;
        }
    }

    int sign = 1;
    if (s[start] == '-') {
        sign = -1;
        start++;
    } else if (s[start] == '+') {
        start++;
    }

    int num = 0;
    for (int i = start; i < len; i++) {
        if (!isdigit(s[i])) {
            return num;
        }

        int digit = sign * (int)(s[i] - '0');
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return INT_MAX;
        } else if (num < INT_MIN / 10 || (num == INT_MIN / 10 && digit < INT_MIN % 10)) {
            return INT_MIN;
        } else {
            num *= 10;
        }
        num += digit;
    }

    return num;
}

int myAtoi(char *s) {
    int start = 0;
    int len = (int)strlen(s);
    while (s[start] == ' ') {
        start++;
    }

    long long sign = 1;
    if (s[start] == '-') {
        sign = -1;
        start++;
    } else if (s[start] == '+') {
        start++;
    }

    long long num = 0;
    for (int i = start; i < len; i++) {
        if (!isdigit(s[i])) {
            break;
        }

        num = num * 10 + sign * (long long)(s[i] - '0');
        if (num > INT_MAX) {
            return INT_MAX;
        } else if (num < INT_MIN) {
            return INT_MIN;
        }
    }

    return (int)num;
}