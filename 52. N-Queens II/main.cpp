#include <math.h>
#include <vector>

using namespace std;

class Solution {
    bool isValid(int *line, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (line[i] == col || abs(row - i) == abs(col - line[i])) {
                return false;
            }
        }

        return true;
    }

    int getCount(int *line, int size, int row) {
        if (row == size) {
            return 1;
        }

        int count = 0;

        for (int col = 0; col < size; col++) {
            if (isValid(line, row, col)) {
                line[row] = col;
                count += getCount(line, size, row + 1);
            }
        }

        return count;
    }

public:
    int totalNQueens(int n) {
        if (n <= 0) {
            return 0;
        }

        int line[n];
        return getCount(line, n, 0);
    }
};

class Solution {
    bool isValid(vector<vector<bool>> &board, int row, int col) {
        int size = board.size();

        for (int i = 0; i <= row; i++) {
            if (board[i][col] || (row - i >= 0 && col - i >= 0 && board[row - i][col - i]) ||
                (row - i >= 0 && col + i < size && board[row - i][col + i])) {
                return false;
            }
        }

        return true;
    }

    int getCount(vector<vector<bool>> &board, int row) {
        if (row == board.size()) {
            return 1;
        }

        int count = 0;

        for (int col = 0; col < board.size(); col++) {
            if (isValid(board, row, col)) {
                board[row][col] = true;
                count += getCount(board, row + 1);
                board[row][col] = false;
            }
        }

        return count;
    }

public:
    int totalNQueens(int n) {
        if (n <= 0) {
            return 0;
        }

        vector<vector<bool>> board(n, vector<bool>(n, false));
        return getCount(board, 0);
    }
};