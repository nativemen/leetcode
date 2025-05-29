#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Trie {
public:
    unordered_map<char, Trie *> children;
    bool isEndOfWord;

    Trie() {
        isEndOfWord = false;
    }

    void insertTrie(string word) {
        Trie *node = this;

        for (const auto &c : word) {
            if (!node->children.contains(c)) {
                node->children[c] = new Trie();
            }

            node = node->children[c];
        }

        node->isEndOfWord = true;
    }
};

class Solution {
    static constexpr size_t WORD_LEN = 10;

    vector<string> result;

    void dfs(vector<vector<char>> &board, int i, int j, string &word, Trie *root) {
        if (!root) {
            return;
        }

        if (root->isEndOfWord) {
            result.push_back(word);
            root->isEndOfWord = false;
        }

        int rowSize = board.size();
        int colSize = board[0].size();

        char original = board[i][j];
        board[i][j] = '*';
        if (i + 1 < rowSize && board[i + 1][j] != '*' && root->children.contains(board[i + 1][j])) {
            word.push_back(board[i + 1][j]);
            dfs(board, i + 1, j, word, root->children[board[i + 1][j]]);
            word.pop_back();
        }

        if (i - 1 >= 0 && board[i - 1][j] != '*' && root->children.contains(board[i - 1][j])) {
            word.push_back(board[i - 1][j]);
            dfs(board, i - 1, j, word, root->children[board[i - 1][j]]);
            word.pop_back();
        }

        if (j + 1 < colSize && board[i][j + 1] != '*' && root->children.contains(board[i][j + 1])) {
            word.push_back(board[i][j + 1]);
            dfs(board, i, j + 1, word, root->children[board[i][j + 1]]);
            word.pop_back();
        }

        if (j - 1 >= 0 && board[i][j - 1] != '*' && root->children.contains(board[i][j - 1])) {
            word.push_back(board[i][j - 1]);
            dfs(board, i, j - 1, word, root->children[board[i][j - 1]]);
            word.pop_back();
        }

        board[i][j] = original;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        Trie *root = new Trie();

        for (const auto &word : words) {
            root->insertTrie(word);
        }

        int rowSize = board.size();
        int colSize = board[0].size();

        string word;

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                char c = board[i][j];
                if (root->children.contains(c)) {
                    word = string(1, c);
                    dfs(board, i, j, word, root->children[c]);
                }
            }
        }

        return result;
    }
};

class Trie {
public:
    unordered_map<char, Trie *> children;
    bool isEndOfWord;

    Trie() {
        isEndOfWord = false;
    }

    void insertTrie(string word) {
        Trie *node = this;

        for (const auto &c : word) {
            if (!node->children.contains(c)) {
                node->children[c] = new Trie();
            }

            node = node->children[c];
        }

        node->isEndOfWord = true;
    }
};

class Solution {
    static constexpr size_t WORD_LEN = 10;

    vector<string> result;

    void dfs(vector<vector<char>> &board, int i, int j, string &word, Trie *root) {
        int rowSize = board.size();
        int colSize = board[0].size();

        if (i < 0 || i >= rowSize || j < 0 || j >= colSize || word.size() > WORD_LEN || board[i][j] == '*' ||
            !root->children.contains(board[i][j])) {
            return;
        }

        word.push_back(board[i][j]);
        char original = board[i][j];
        root = root->children[board[i][j]];

        if (root->isEndOfWord) {
            result.push_back(word);
            root->isEndOfWord = false;
        }

        board[i][j] = '*';
        dfs(board, i + 1, j, word, root);
        dfs(board, i - 1, j, word, root);
        dfs(board, i, j + 1, word, root);
        dfs(board, i, j - 1, word, root);
        board[i][j] = original;
        word.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        Trie *root = new Trie();

        for (const auto &word : words) {
            root->insertTrie(word);
        }

        int rowSize = board.size();
        int colSize = board[0].size();

        string word;

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                dfs(board, i, j, word, root);
            }
        }

        return result;
    }
};

class Trie {
public:
    unordered_map<char, Trie *> children;
    bool isEndOfWord;

    Trie() {
        isEndOfWord = false;
    }

    void insertTrie(string word) {
        Trie *node = this;

        for (const auto &c : word) {
            if (!node->children.contains(c)) {
                node->children[c] = new Trie();
            }

            node = node->children[c];
        }

        node->isEndOfWord = true;
    }
};

class Solution {
    static constexpr size_t WORD_LEN = 10;

    unordered_set<string> result;

    void dfs(vector<vector<char>> &board, int i, int j, string &word, Trie *root) {
        int rowSize = board.size();
        int colSize = board[0].size();

        if (i < 0 || i >= rowSize || j < 0 || j >= colSize || word.size() > WORD_LEN || board[i][j] == '*' ||
            !root->children.contains(board[i][j])) {
            return;
        }

        word.push_back(board[i][j]);
        char original = board[i][j];
        root = root->children[board[i][j]];

        if (root->isEndOfWord) {
            result.emplace(word);
        }

        board[i][j] = '*';
        dfs(board, i + 1, j, word, root);
        dfs(board, i - 1, j, word, root);
        dfs(board, i, j + 1, word, root);
        dfs(board, i, j - 1, word, root);
        board[i][j] = original;
        word.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        Trie *root = new Trie();

        for (const auto &word : words) {
            root->insertTrie(word);
        }

        int rowSize = board.size();
        int colSize = board[0].size();

        string word;

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                dfs(board, i, j, word, root);
            }
        }

        return vector<string>(result.begin(), result.end());
    }
};