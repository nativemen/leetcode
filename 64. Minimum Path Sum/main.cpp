#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();

        for (int row = 1; row < rowSize; row++) {
            grid[row][0] += grid[row - 1][0];
        }

        for (int col = 1; col < colSize; col++) {
            grid[0][col] += grid[0][col - 1];
        }

        for (int row = 1; row < rowSize; row++) {
            for (int col = 1; col < colSize; col++) {
                grid[row][col] += min(grid[row - 1][col], grid[row][col - 1]);
            }
        }

        return grid[rowSize - 1][colSize - 1];
    }
};