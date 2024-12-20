#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::unordered_map;
using std::unordered_set;
using std::vector;

const int ARRAY_SIZE = 9;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<int> rows(ARRAY_SIZE, 0);
        vector<int> cols(ARRAY_SIZE, 0);
        vector<int> boxes(ARRAY_SIZE, 0);

        for (int row = 0; row < ARRAY_SIZE; row++) {
            for (int col = 0; col < ARRAY_SIZE; col++) {
                if (board[row][col] == '.') {
                    continue;
                }

                int shift = board[row][col] - '1';
                int mask = 1 << shift;
                int box = ((int)(row / 3)) * 3 + (int)(col / 3);

                if ((rows[row] & mask) != 0 || (cols[col] & mask) != 0 || (boxes[box] & mask) != 0) {
                    return false;
                }

                rows[row] |= mask;
                cols[col] |= mask;
                boxes[box] |= mask;
            }
        }

        return true;
    }
};

const int ARRAY_SIZE = 9;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> boxes;

        for (int row = 0; row < ARRAY_SIZE; row++) {
            for (int col = 0; col < ARRAY_SIZE; col++) {
                if (board[row][col] == '.') {
                    continue;
                }

                int c = board[row][col];
                int box = ((int)(row / 3)) * 3 + (int)(col / 3);

                if (rows[row].contains(c) || cols[col].contains(c) || boxes[box].contains(c)) {
                    return false;
                }

                rows[row].insert(c);
                cols[col].insert(c);
                boxes[box].insert(c);
            }
        }

        return true;
    }
};