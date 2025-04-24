#include <vector>

using namespace std;

class Solution {
    void makeOtoY(vector<vector<char>> &board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == 'Y') {
            return;
        }

        board[i][j] = 'Y';

        makeOtoY(board, i - 1, j);
        makeOtoY(board, i + 1, j);
        makeOtoY(board, i, j - 1);
        makeOtoY(board, i, j + 1);
    }

public:
    void solve(vector<vector<char>> &board) {
        int rowSize = board.size();
        int colSize = board[0].size();

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (i == 0 || i == rowSize - 1 || j == 0 || j == colSize - 1) {
                    if (board[i][j] == 'O') {
                        makeOtoY(board, i, j);
                    }
                }
            }
        }

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }

                if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};