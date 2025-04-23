#include <vector>

using namespace std;

class Solution {
    void makeIslandsZero(vector<vector<char>> &grid, int i, int j) {
        int rowSize = grid.size();
        int colSize = grid[0].size();

        if (i < 0 || i >= rowSize || j < 0 || j >= colSize || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        makeIslandsZero(grid, i - 1, j);
        makeIslandsZero(grid, i + 1, j);
        makeIslandsZero(grid, i, j - 1);
        makeIslandsZero(grid, i, j + 1);
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int count = 0;

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    makeIslandsZero(grid, i, j);
                }
            }
        }

        return count;
    }
};