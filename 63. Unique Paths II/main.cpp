#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int obstacleGridSize = obstacleGrid.size();
        int obstacleGridColSize = obstacleGrid[0].size();

        obstacleGrid[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;

        for (int i = 1; i < obstacleGridSize; i++) {
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 1) ? 0 : obstacleGrid[i - 1][0];
        }

        for (int j = 1; j < obstacleGridColSize; j++) {
            obstacleGrid[0][j] = (obstacleGrid[0][j] == 1) ? 0 : obstacleGrid[0][j - 1];
        }

        for (int i = 1; i < obstacleGridSize; i++) {
            for (int j = 1; j < obstacleGridColSize; j++) {
                obstacleGrid[i][j] = (obstacleGrid[i][j] == 1) ? 0 : obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
        }

        return obstacleGrid[obstacleGridSize - 1][obstacleGridColSize - 1];
    }
};