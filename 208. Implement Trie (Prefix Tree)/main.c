#include <stdbool.h>
#include <stdio.h>

#define ALPHASET_SIZE 26

typedef struct Trie {
    struct Trie *children[ALPHASET_SIZE];
    bool isEndOfWord;
} Trie;

Trie *trieCreate(void) {
    return (Trie *)calloc(1, sizeof(Trie));
}

void trieInsert(Trie *obj, char *word) {
    if (obj == NULL) {
        return;
    }

    Trie *node = obj;
    size_t wordLen = strlen(word);

    for (size_t i = 0; i < wordLen; i++) {
        int index = word[i] - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = trieCreate();
        }
        node = node->children[index];
    }

    node->isEndOfWord = true;
}

bool trieSearch(Trie *obj, char *word) {
    if (obj == NULL) {
        return false;
    }

    Trie *node = obj;
    size_t wordLen = strlen(word);

    for (size_t i = 0; i < wordLen; i++) {
        int index = word[i] - 'a';
        if (node->children[index] == NULL) {
            return false;
        }
        node = node->children[index];
    }

    return node->isEndOfWord;
}

bool trieStartsWith(Trie *obj, char *prefix) {
    if (obj == NULL) {
        return false;
    }

    Trie *node = obj;
    size_t prefixLen = strlen(prefix);

    for (size_t i = 0; i < prefixLen; i++) {
        int index = prefix[i] - 'a';
        if (node->children[index] == NULL) {
            return false;
        }
        node = node->children[index];
    }

    return true;
}

void trieFree(Trie *obj) {
    if (obj == NULL) {
        return;
    }

    Trie *node = obj;

    for (size_t i = 0; i < ALPHASET_SIZE; i++) {
        if (node->children[i] != NULL) {
            trieFree(node->children[i]);
        }
    }
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 * bool param_2 = trieSearch(obj, word);
 * bool param_3 = trieStartsWith(obj, prefix);
 * trieFree(obj);
 */