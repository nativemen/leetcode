#include <stdio.h>

/*
 * I        1
 * II       2
 * III      3
 * IV       4
 * V        5
 * VI       6
 * VII      7
 * VIII     8
 * IX       9
 * X        10
 * XL       40
 * L        50
 * XC       90
 * C        100
 * CD       400
 * D        500
 * CM       900
 * M        1000
 */
int romanToInt(char *s) {
    int result = 0;
    char prev = '\0';

    for (size_t i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case 'I': {
                result += 1;
                break;
            }
            case 'V': {
                if (prev == 'I') {
                    result += 4 - 1;
                } else {
                    result += 5;
                }
                break;
            }
            case 'X': {
                if (prev == 'I') {
                    result += 9 - 1;
                } else {
                    result += 10;
                }
                break;
            }
            case 'L': {
                if (prev == 'X') {
                    result += 40 - 10;
                } else {
                    result += 50;
                }
                break;
            }
            case 'C': {
                if (prev == 'X') {
                    result += 90 - 10;
                } else {
                    result += 100;
                }
                break;
            }
            case 'D': {
                if (prev == 'C') {
                    result += 400 - 100;
                } else {
                    result += 500;
                }
                break;
            }
            case 'M': {
                if (prev == 'C') {
                    result += 900 - 100;
                } else {
                    result += 1000;
                }
                break;
            }
            default: {
                break;
            }
        }

        prev = s[i];
    }

    return result;
}

static int romanToValue(char c) {
    switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int romanToInt(char *s) {
    int size = strlen(s);
    int result = 0;
    int cur = 0;
    int prev = 0;

    for (int i = size - 1; i >= 0; i--) {
        cur = romanToValue(s[i]);
        if (cur >= prev) {
            result += cur;
        } else {
            result -= cur;
        }

        prev = cur;
    }

    return result;
}