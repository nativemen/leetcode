#include <stdio.h>

static int gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

char *gcdOfStrings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char s1[len1 + len2 + 1];
    char s2[len1 + len2 + 1];

    strcpy(s1, str1);
    strcpy(s2, str2);
    strcat(s1, str2);
    strcat(s2, str1);

    char *result = (char *)calloc(len1 + 1, sizeof(char));

    if (strcmp(s1, s2) != 0) {
        return result;
    }

    int gcdLen = gcd(len1, len2);
    strncpy(result, str1, gcdLen);

    return result;
}

static int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

char *gcdOfStrings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char s1[len1 + len2 + 1];
    char s2[len1 + len2 + 1];

    strcpy(s1, str1);
    strcpy(s2, str2);
    strcat(s1, str2);
    strcat(s2, str1);

    char *result = (char *)calloc(len1 + 1, sizeof(char));

    if (strcmp(s1, s2) != 0) {
        return result;
    }

    int gcdLen = gcd(len1, len2);
    strncpy(result, str1, gcdLen);

    return result;
}