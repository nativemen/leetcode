#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Trie {
    static constexpr size_t ALPHABET_SIZE = 26;

    Trie *children[ALPHABET_SIZE];
    bool isEndOfWord;

public:
    Trie() {
        for (size_t i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }

    void insert(string word) {
        Trie *node = this;

        for (const auto &c : word) {
            size_t index = c - 'a';

            if (!node->children[index]) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }

        node->isEndOfWord = true;
    }

    bool search(string word) {
        Trie *node = this;

        for (const auto &c : word) {
            size_t index = c - 'a';

            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }

        return node->isEndOfWord;
    }

    bool startsWith(string prefix) {
        Trie *node = this;

        for (const auto &c : prefix) {
            size_t index = c - 'a';

            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }

        return true;
    }
};

class Trie {
    static constexpr size_t ALPHABET_SIZE = 26;

    unordered_map<char, Trie *> children;
    bool isEndOfWord;

public:
    Trie() {
        isEndOfWord = false;
    }

    void insert(string word) {
        Trie *node = this;

        for (const auto &c : word) {
            if (!node->children.contains(c)) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }

        node->isEndOfWord = true;
    }

    bool search(string word) {
        Trie *node = this;

        for (const auto &c : word) {
            if (!node->children.contains(c)) {
                return false;
            }
            node = node->children[c];
        }

        return node->isEndOfWord;
    }

    bool startsWith(string prefix) {
        Trie *node = this;

        for (const auto &c : prefix) {
            if (!node->children.contains(c)) {
                return false;
            }
            node = node->children[c];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class TrieNode {
    static constexpr size_t ALPHABET_SIZE = 26;

public:
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() {
        for (size_t i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Trie {
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *node = root;

        for (const auto &c : word) {
            size_t index = c - 'a';

            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }

        node->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode *node = root;

        size_t wordLen = word.size();

        for (size_t i = 0; i < wordLen; i++) {
            size_t index = word[i] - 'a';

            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }

        return node->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode *node = root;

        size_t prefixLen = prefix.size();

        for (size_t i = 0; i < prefixLen; i++) {
            size_t index = prefix[i] - 'a';

            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class TrieNode {
    static constexpr size_t ALPHABET_SIZE = 26;

public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *node = root;

        for (const auto &c : word) {
            if (!node->children.contains(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }

        node->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode *node = root;

        for (const auto &c : word) {
            if (!node->children.contains(c)) {
                return false;
            }
            node = node->children[c];
        }

        return node->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode *node = root;

        for (const auto &c : prefix) {
            if (!node->children.contains(c)) {
                return false;
            }
            node = node->children[c];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */