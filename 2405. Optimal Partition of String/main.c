#include <limits.h>
#include <stdio.h>

#define ALPHABET_SIZE 26

int partitionString(char *s) {
    int count[ALPHABET_SIZE] = {0};
    int num = 1;

    for (int i = 0; i < strlen(s); i++) {
        int index = s[i] - 'a';
        if (count[index] == 1) {
            num++;
            memset(count, 0, ALPHABET_SIZE * sizeof(int));
        }

        count[index] = 1;
    }

    return num;
}

#define ALPHABET_SIZE 26

int partitionString(char *s) {
    int sLen = strlen(s);
    unsigned int mask = 0;
    int num = 1;

    for (int i = 0; i < sLen; i++) {
        unsigned int index = s[i] - 'a';

        if ((mask & (1 << index)) != 0) {
            mask = 0;
            num++;
        }

        mask |= (1 << index);
    }

    return num;
}