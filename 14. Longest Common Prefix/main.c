#include <limits.h>
#include <stdio.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    int minLen = INT_MAX;

    if (strsSize == 1) {
        return strs[0];
    }

    for (int i = 0; i < strsSize; i++) {
        minLen = minLen > strlen(strs[i]) ? strlen(strs[i]) : minLen;
    }

    int count = 0;
    while (count < minLen) {
        int i = 1;
        while (i < strsSize) {
            if (strncmp(strs[0], strs[i], count + 1) != 0) {
                break;
            }

            i++;
        }

        if (i != strsSize) {
            break;
        }

        count++;
    }

    strs[0][count] = '\0';

    return strs[0];
}

char *longestCommonPrefix(char **strs, int strsSize) {
    int minLen = INT_MAX;

    if (strsSize == 1) {
        return strs[0];
    }

    for (int i = 0; i < strsSize; i++) {
        minLen = minLen > strlen(strs[i]) ? strlen(strs[i]) : minLen;
    }

    int count = 0;
    while (count < minLen) {
        int i = 1;
        while (i < strsSize) {
            if (strncmp(strs[0], strs[i], count + 1) != 0) {
                break;
            }

            i++;
        }

        if (i != strsSize) {
            break;
        }

        count++;
    }

    strs[0][count] = '\0';

    return strs[0];
}

char *longestCommonPrefix(char **strs, int strsSize) {
    int prefixLen = strlen(strs[0]);

    for (int i = 1; i < strsSize; i++) {
        int j = 0;

        while (j < prefixLen && strs[0][j] == strs[i][j]) {
            j++;
        }

        prefixLen = j;
        if (prefixLen == 0) {
            break;
        }
    }

    strs[0][prefixLen] = '\0';

    return strs[0];
}