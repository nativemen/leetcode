#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int turnCount = 0;
        int turn = 0;
        int turnTotal = 1;
        int total = rows * cols;
        int row = rStart;
        int col = cStart;
        int left = cStart;
        int right = cStart;
        int top = rStart;
        int bottom = rStart;
        int direction = 0;
        int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> result;

        while (result.size() < total) {
            if (row >= 0 && row < rows && col >= 0 && col < cols) {
                result.push_back({row, col});
            }

            turnCount++;
            if (turnCount == turnTotal) {
                turnCount = 0;
                turn++;
                turnTotal = 8 * turn;
                left = cStart - turn;
                right = cStart + turn;
                top = rStart - turn;
                bottom = rStart + turn;
            }

            int nextRow = row + dirs[direction][0];
            int nextCol = col + dirs[direction][1];

            if (nextRow < top || nextRow > bottom || nextCol < left || nextCol > right) {
                direction = (direction + 1) % 4;
                nextRow = row + dirs[direction][0];
                nextCol = col + dirs[direction][1];
            }

            row = nextRow;
            col = nextCol;
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int total = rows * cols;
        int row = rStart;
        int col = cStart;
        int step = 1;
        int direction = 0;
        int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> result;

        while (result.size() < total) {
            for (int repeat = 0; repeat < 2; repeat++) {
                for (int s = 0; s < step; s++) {
                    if (row >= 0 && row < rows && col >= 0 && col < cols) {
                        result.push_back({row, col});
                    }

                    row += dirs[direction][0];
                    col += dirs[direction][1];
                }
                direction = (direction + 1) % 4;
            }
            step++;
        }

        return result;
    }
};