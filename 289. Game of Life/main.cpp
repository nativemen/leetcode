#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        int rowSize = board.size();
        int colSize = board[0].size();

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                int count = 0;

                for (int m = max(0, i - 1); m <= min(rowSize - 1, i + 1); m++) {
                    for (int n = max(0, j - 1); n <= min(colSize - 1, j + 1); n++) {
                        if (m != i || n != j) {
                            count += board[m][n] & 1;
                        }
                    }
                }

                if (((board[i][j] & 1) == 1 && count == 2) || count == 3) {
                    board[i][j] |= 1 << 1;
                }
            }
        }

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};