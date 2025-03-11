#include <stdbool.h>

bool isSubsequence(char *s, char *t) {
    int size1 = strlen(s);
    int size2 = strlen(t);
    if (size1 > size2) {
        return false;
    }

    int i = 0;
    int j = 0;

    for (; i < size1; i++) {
        for (; j < size2; j++) {
            if (s[i] == t[j]) {
                break;
            }
        }

        if (j == size2) {
            return false;
        }
        j++;
    }

    return true;
}

bool isSubsequence(char *s, char *t) {
    int size1 = strlen(s);
    int size2 = strlen(t);
    int si = 0;
    int ti = 0;

    for (ti = 0; ti < size2; ti++) {
        if (s[si] == t[ti] && si < size1) {
            si++;
        }
    }

    return si == size1;
}

bool isSubsequence(char *s, char *t) {
    int size1 = strlen(s);
    int size2 = strlen(t);
    int si = 0;
    int ti = 0;

    while (si < size1 && ti < size2) {
        if (s[si] == t[ti]) {
            si++;
        }

        ti++;
    }

    return si == size1;
}
