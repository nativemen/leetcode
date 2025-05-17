#include <string>
#include <vector>

using namespace std;

class Solution {
    bool dfs(vector<vector<char>> &board, string word, int index, int i, int j) {
        if (index == word.size()) {
            return true;
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[index]) {
            return false;
        }

        board[i][j] = '0';
        bool r1 = dfs(board, word, index + 1, i - 1, j);
        bool r2 = dfs(board, word, index + 1, i + 1, j);
        bool r3 = dfs(board, word, index + 1, i, j - 1);
        bool r4 = dfs(board, word, index + 1, i, j + 1);
        board[i][j] = word[index];

        return r1 || r2 || r3 || r4;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};

class Solution {
    bool result;

    void dfs(vector<vector<char>> &board, string word, int index, int i, int j) {
        if (index == word.size()) {
            result = true;
            return;
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size()) {
            return;
        }

        if (board[i][j] == word[index]) {
            board[i][j] = '0';
            dfs(board, word, index + 1, i - 1, j);
            dfs(board, word, index + 1, i + 1, j);
            dfs(board, word, index + 1, i, j - 1);
            dfs(board, word, index + 1, i, j + 1);
            board[i][j] = word[index];
        }
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                dfs(board, word, 0, i, j);
            }
        }

        return result;
    }
};