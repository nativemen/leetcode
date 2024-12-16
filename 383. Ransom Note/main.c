#include <stdbool.h>

#define LETTERS_NUM 26

bool canConstruct(char *ransomNote, char *magazine) {
    int count[LETTERS_NUM] = {0};

    for (int i = 0; i < strlen(magazine); i++) {
        count[magazine[i] - 'a']++;
    }

    for (int i = 0; i < strlen(ransomNote); i++) {
        count[ransomNote[i] - 'a']--;
        if (count[ransomNote[i] - 'a'] < 0) {
            return false;
        }
    }

    return true;
}

bool canConstruct(char *ransomNote, char *magazine) {
    int count[LETTERS_NUM] = {0};

    for (int i = 0; magazine[i] != '\0'; i++) {
        count[magazine[i] - 'a']++;
    }

    for (int i = 0; ransomNote[i] != '\0'; i++) {
        count[ransomNote[i] - 'a']--;
        if (count[ransomNote[i] - 'a'] < 0) {
            return false;
        }
    }

    return true;
}