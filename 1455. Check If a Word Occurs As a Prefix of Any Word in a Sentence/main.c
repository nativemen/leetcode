#include <stdio.h>
#include <string.h>

int isPrefixOfWord(char* sentence, char* searchWord) {
    int totalLen = strlen(sentence);
    int searchLen = strlen(searchWord);
    int start = 0;
    int num = 0;
    for (int i = 0; i <= totalLen; i++) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            num++;
            if (i - start >= searchLen && strncmp(sentence + start, searchWord, searchLen) == 0) {
                return num;
            }
            start = i + 1;
        }
    }

    return -1;
}