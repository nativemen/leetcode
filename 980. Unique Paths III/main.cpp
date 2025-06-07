#include <vector>

using namespace std;

class Solution {
    int dfs(vector<vector<int>> &grid, int i, int j, int spaces) {
        int rowSize = grid.size();
        int colSize = grid[0].size();

        if (i < 0 || i >= rowSize || j < 0 || j >= colSize || grid[i][j] == -1) {
            return 0;
        }

        if (grid[i][j] == 2) {
            return (spaces == 0) ? 1 : 0;
        }

        int result = 0;

        grid[i][j] = -1;

        result += dfs(grid, i + 1, j, spaces - 1);
        result += dfs(grid, i - 1, j, spaces - 1);
        result += dfs(grid, i, j + 1, spaces - 1);
        result += dfs(grid, i, j - 1, spaces - 1);

        grid[i][j] = 0;

        return result;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int startX = -1;
        int startY = -1;
        int spaces = 1;

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                } else if (grid[i][j] == 0) {
                    spaces++;
                }
            }
        }

        return dfs(grid, startX, startY, spaces);
    }
};