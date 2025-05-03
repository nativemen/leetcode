from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        obstacleGridSize = len(obstacleGrid)
        obstacleGridColSize = len(obstacleGrid[0])

        obstacleGrid[0][0] = 0 if obstacleGrid[0][0] == 1 else 1

        for i in range(1, obstacleGridSize):
            obstacleGrid[i][0] = (
                0 if obstacleGrid[i][0] == 1 else obstacleGrid[i - 1][0]
            )

        for j in range(1, obstacleGridColSize):
            obstacleGrid[0][j] = (
                0 if obstacleGrid[0][j] == 1 else obstacleGrid[0][j - 1]
            )

        for i in range(1, obstacleGridSize):
            for j in range(1, obstacleGridColSize):
                obstacleGrid[i][j] = (
                    0
                    if obstacleGrid[i][j] == 1
                    else obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1]
                )

        return obstacleGrid[obstacleGridSize - 1][obstacleGridColSize - 1]
