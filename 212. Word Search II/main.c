#include <stdbool.h>
#include <stdio.h>

#define ALPHABET_SIZE 26
#define WORD_LEN 10

typedef struct Trie {
    struct Trie *children[ALPHABET_SIZE];
    bool isEndOfWord;
} Trie;

static Trie *createTrie(void) {
    return (Trie *)calloc(1, sizeof(Trie));
}

static void insertTrie(Trie *obj, const char *word) {
    if (obj == NULL) {
        return;
    }

    Trie *node = obj;
    size_t wordLen = strlen(word);

    for (size_t i = 0; i < wordLen; i++) {
        size_t index = word[i] - 'a';

        if (node->children[index] == NULL) {
            node->children[index] = createTrie();
        }

        node = node->children[index];
    }

    node->isEndOfWord = true;
}

static bool searchTrie(const Trie *obj, const char *word) {
    if (obj == NULL) {
        return false;
    }

    Trie *node = obj;
    size_t wordLen = strlen(word);

    for (size_t i = 0; i < wordLen; i++) {
        size_t index = word[i] - 'a';

        if (node->children[index] == NULL) {
            return false;
        }

        node = node->children[index];
    }

    if (node->isEndOfWord) {
        node->isEndOfWord = false;
        return true;
    }

    return false;
}

static bool startWithTrie(const Trie *obj, const char *prefix) {
    if (obj == NULL) {
        return false;
    }

    Trie *node = obj;
    size_t prefixLen = strlen(prefix);

    for (size_t i = 0; i < prefixLen; i++) {
        size_t index = prefix[i] - 'a';

        if (node->children[index] == NULL) {
            return false;
        }

        node = node->children[index];
    }

    return true;
}

static void freeTrie(Trie *obj) {
    if (obj == NULL) {
        return;
    }

    for (size_t i = 0; i < ALPHABET_SIZE; i++) {
        freeTrie(obj->children[i]);
    }

    free(obj);
}

static void
dfs(char **board, int rowSize, int colSize, int i, int j, char *word, int index, Trie *obj, char **result, int *count) {
    if (i < 0 || i >= rowSize || j < 0 || j >= colSize || index >= WORD_LEN || board[i][j] == '*') {
        return;
    }

    char original = word[index];
    word[index] = board[i][j];

    if (startWithTrie(obj, word)) {
        if (searchTrie(obj, word)) {
            result[*count] = strdup(word);
            *count += 1;
        }

        board[i][j] = '*';
        dfs(board, rowSize, colSize, i + 1, j, word, index + 1, obj, result, count);
        dfs(board, rowSize, colSize, i - 1, j, word, index + 1, obj, result, count);
        dfs(board, rowSize, colSize, i, j + 1, word, index + 1, obj, result, count);
        dfs(board, rowSize, colSize, i, j - 1, word, index + 1, obj, result, count);
        board[i][j] = word[index];
    }
    word[index] = original;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **findWords(char **board, int boardSize, int *boardColSize, char **words, int wordsSize, int *returnSize) {
    *returnSize = 0;
    char **result = (char **)calloc(wordsSize, sizeof(char *));
    if (result == NULL) {
        return NULL;
    }

    Trie *root = createTrie();
    for (int i = 0; i < wordsSize; i++) {
        insertTrie(root, words[i]);
    }

    char word[WORD_LEN + 1] = {'\0'};

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            dfs(board, boardSize, boardColSize[0], i, j, word, 0, root, result, returnSize);
        }
    }

    freeTrie(root);

    return result;
}

#define ALPHABET_SIZE 26
#define WORD_LEN 10

typedef struct Trie {
    struct Trie *children[ALPHABET_SIZE];
    bool isEndOfWord;
} Trie;

static Trie *createTrie(void) {
    return (Trie *)calloc(1, sizeof(Trie));
}

static void insertTrie(Trie *obj, const char *word) {
    if (obj == NULL) {
        return;
    }

    Trie *node = obj;
    size_t wordLen = strlen(word);

    for (size_t i = 0; i < wordLen; i++) {
        size_t index = word[i] - 'a';

        if (node->children[index] == NULL) {
            node->children[index] = createTrie();
        }

        node = node->children[index];
    }

    node->isEndOfWord = true;
}

static void freeTrie(Trie *obj) {
    if (obj == NULL) {
        return;
    }

    for (size_t i = 0; i < ALPHABET_SIZE; i++) {
        freeTrie(obj->children[i]);
    }

    free(obj);
}

static void dfs(char **board,
                int rowSize,
                int colSize,
                int i,
                int j,
                char *word,
                int index,
                Trie *root,
                char **result,
                int *count) {
    if (i < 0 || i >= rowSize || j < 0 || j >= colSize || index >= WORD_LEN || board[i][j] == '*' ||
        root->children[board[i][j] - 'a'] == NULL) {
        return;
    }

    char original = word[index];
    word[index] = board[i][j];
    root = root->children[board[i][j] - 'a'];

    if (root->isEndOfWord) {
        result[(*count)++] = strdup(word);
        root->isEndOfWord = false;
    }

    board[i][j] = '*';
    dfs(board, rowSize, colSize, i + 1, j, word, index + 1, root, result, count);
    dfs(board, rowSize, colSize, i - 1, j, word, index + 1, root, result, count);
    dfs(board, rowSize, colSize, i, j + 1, word, index + 1, root, result, count);
    dfs(board, rowSize, colSize, i, j - 1, word, index + 1, root, result, count);
    board[i][j] = word[index];

    word[index] = original;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **findWords(char **board, int boardSize, int *boardColSize, char **words, int wordsSize, int *returnSize) {
    *returnSize = 0;
    char **result = (char **)calloc(wordsSize, sizeof(char *));
    if (result == NULL) {
        return NULL;
    }

    Trie *root = createTrie();
    for (int i = 0; i < wordsSize; i++) {
        insertTrie(root, words[i]);
    }

    char word[WORD_LEN + 1] = {'\0'};

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            dfs(board, boardSize, boardColSize[0], i, j, word, 0, root, result, returnSize);
        }
    }

    freeTrie(root);

    return result;
}