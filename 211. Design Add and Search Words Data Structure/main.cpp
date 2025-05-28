#include <string>
#include <unordered_map>

using namespace std;

class WordDictionary {
    static constexpr size_t ALPHABET_SIZE = 26;

    unordered_map<char, WordDictionary *> children;
    bool isEndOfWord;

public:
    WordDictionary() {
        isEndOfWord = false;
    }

    void addWord(string word) {
        WordDictionary *node = this;

        for (const auto &c : word) {
            if (!node->children.contains(c)) {
                node->children[c] = new WordDictionary();
            }
            node = node->children[c];
        }

        node->isEndOfWord = true;
    }

    bool search(string word) {
        WordDictionary *node = this;
        size_t wordLen = word.size();

        for (size_t i = 0; i < wordLen; i++) {
            if (word[i] == '.') {
                for (const auto &[c, wd] : node->children) {
                    if (wd->search(word.substr(i + 1, wordLen))) {
                        return true;
                    }
                }

                return false;
            }

            if (!node->children.contains(word[i])) {
                return false;
            }
            node = node->children[word[i]];
        }

        return node->isEndOfWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */