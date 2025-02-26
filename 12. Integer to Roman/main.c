#include <stdio.h>

#define ARRAY_SIZE 16

char *intToRoman(int num) {
    char *s = (char *)malloc(ARRAY_SIZE);
    if (s == NULL) {
        return NULL;
    }

    int i = 0;
    while (num > 0) {
        if (num >= 1000) {
            s[i++] = 'M';
            num -= 1000;
        } else if (num >= 900) {
            s[i++] = 'C';
            s[i++] = 'M';
            num -= 900;
        } else if (num >= 500) {
            s[i++] = 'D';
            num -= 500;
        } else if (num >= 400) {
            s[i++] = 'C';
            s[i++] = 'D';
            num -= 400;
        } else if (num >= 100) {
            s[i++] = 'C';
            num -= 100;
        } else if (num >= 90) {
            s[i++] = 'X';
            s[i++] = 'C';
            num -= 90;
        } else if (num >= 50) {
            s[i++] = 'L';
            num -= 50;
        } else if (num >= 40) {
            s[i++] = 'X';
            s[i++] = 'L';
            num -= 40;
        } else if (num >= 10) {
            s[i++] = 'X';
            num -= 10;
        } else if (num >= 9) {
            s[i++] = 'I';
            s[i++] = 'X';
            num -= 9;
        } else if (num >= 5) {
            s[i++] = 'V';
            num -= 5;
        } else if (num >= 4) {
            s[i++] = 'I';
            s[i++] = 'V';
            num -= 4;
        } else {
            s[i++] = 'I';
            num -= 1;
        }
    }
    s[i] = '\0';

    return s;
}

#define ARRAY_SIZE 16

char *intToRoman(int num) {
    const char *symbols[] = {
        "M",
        "CM",
        "D",
        "CD",
        "C",
        "XC",
        "L",
        "XL",
        "X",
        "IX",
        "V",
        "IV",
        "I",
    };
    const int values[] = {
        1000,
        900,
        500,
        400,
        100,
        90,
        50,
        40,
        10,
        9,
        5,
        4,
        1,
    };

    char *s = (char *)malloc(ARRAY_SIZE);
    if (s == NULL) {
        return NULL;
    }
    s[0] = '\0';
    int index = 0;

    while (num > 0) {
        while (num >= values[index]) {
            strcat(s, symbols[index]);
            num -= values[index];
        }
        index++;
    }

    return s;
}