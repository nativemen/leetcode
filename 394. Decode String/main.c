#include <stdbool.h>
#include <stdio.h>

#define STACK_SIZE 100000
#define ARRAY_SIZE 300

char *decodeString(char *s) {
    char *cStack = (char *)calloc(STACK_SIZE + 1, sizeof(char));
    if (cStack == NULL) {
        return NULL;
    }

    int cTop = -1;
    int nStack[ARRAY_SIZE] = {0};
    int nTop = -1;
    char str[ARRAY_SIZE] = {0};
    int num = 0;

    while (*s != '\0') {
        if (isdigit(*s)) {
            num = num * 10 + (*s - '0');
        } else if (*s == '[') {
            nStack[++nTop] = num;
            cStack[++cTop] = *s;
            num = 0;
        } else if (*s == ']') {
            int count = 0;
            while (cStack[cTop] != '[') {
                str[count++] = cStack[cTop--];
            }
            cTop--;
            int number = nStack[nTop--];
            for (int i = 0; i < number; i++) {
                for (int j = count - 1; j >= 0; j--) {
                    cStack[++cTop] = str[j];
                }
            }
        } else {
            cStack[++cTop] = *s;
        }
        s++;
    }

    cStack[++cTop] = '\0';

    return cStack;
}