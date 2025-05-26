#include <queue>
#include <vector>

using namespace std;

class Solution {
    static constexpr int ROLL_SIZE = 6;

    void convert(int rowSize, int colSize, int value, int &x, int &y) {
        int r = (value - 1) / colSize;
        int c = (value - 1) % colSize;
        x = rowSize - 1 - r;
        y = (r % 2 == 0) ? c : colSize - 1 - c;
    }

public:
    int snakesAndLadders(vector<vector<int>> &board) {
        queue<pair<int, int>> q;
        q.push({1, 0});
        int rowSize = board.size();
        int colSize = board[0].size();
        int size = rowSize * colSize;
        vector<bool> visited(size + 1, false);
        visited[1] = true;

        while (!q.empty()) {
            int value = q.front().first;
            int moves = q.front().second;
            q.pop();

            for (int i = 1; i <= ROLL_SIZE; i++) {
                int next = value + i;

                if (next > size) {
                    continue;
                }

                int x = 0;
                int y = 0;
                convert(rowSize, colSize, next, x, y);

                if (board[x][y] != -1) {
                    next = board[x][y];
                }

                if (next == size) {
                    return moves + 1;
                }

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1;
    }
};