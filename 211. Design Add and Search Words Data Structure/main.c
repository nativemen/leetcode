#include <stdbool.h>
#include <stdio.h>

#define ALPHABET_SIZE 26

typedef struct WordDictionary {
    struct WordDictionary *children[ALPHABET_SIZE];
    bool isEndOfWord;
} WordDictionary;

WordDictionary *wordDictionaryCreate(void) {
    return (WordDictionary *)calloc(1, sizeof(WordDictionary));
}

void wordDictionaryAddWord(WordDictionary *obj, char *word) {
    if (obj == NULL) {
        return;
    }

    WordDictionary *node = obj;
    size_t wordLen = strlen(word);

    for (size_t i = 0; i < wordLen; i++) {
        size_t index = word[i] - 'a';

        if (node->children[index] == NULL) {
            node->children[index] = wordDictionaryCreate();
        }
        node = node->children[index];
    }

    node->isEndOfWord = true;
}

bool wordDictionarySearch(WordDictionary *obj, char *word) {
    if (obj == NULL) {
        return false;
    }

    if (*word == '\0') {
        return obj->isEndOfWord;
    }

    WordDictionary *node = obj;
    size_t wordLen = strlen(word);

    for (size_t i = 0; i < wordLen; i++) {
        if (word[i] == '.') {
            for (size_t j = 0; j < ALPHABET_SIZE; j++) {
                if (node->children[j] && wordDictionarySearch(node->children[j], word + i + 1)) {
                    return true;
                }
            }

            return false;
        }

        size_t index = word[i] - 'a';

        if (node->children[index] == NULL) {
            return false;
        }
        node = node->children[index];
    }

    return node->isEndOfWord;
}

void wordDictionaryFree(WordDictionary *obj) {
    if (!obj) {
        return;
    }

    for (size_t i = 0; i < ALPHABET_SIZE; i++) {
        wordDictionaryFree(obj->children[i]);
        obj->children[i] = NULL;
    }

    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 * bool param_2 = wordDictionarySearch(obj, word);
 * wordDictionaryFree(obj);
 */