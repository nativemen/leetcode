int strStr(char *haystack, char *needle) {
    int len1 = strlen(haystack);
    int len2 = strlen(needle);

    for (int i = 0; i < len1; i++) {
        if (strncmp(haystack + i, needle, len2) == 0) {
            return i;
        }
    }

    return -1;
}

int strStr(char *haystack, char *needle) {
    int len1 = strlen(haystack);
    int len2 = strlen(needle);

    for (int i = 0; i <= len1 - len2; i++) {
        int j = 0;
        while (j < len2 && haystack[i + j] == needle[j]) {
            j++;
        }

        if (j == len2) {
            return i;
        }
    }

    return -1;
}