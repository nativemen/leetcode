#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        vector<vector<int>> dp = vector<vector<int>>(rowSize, vector<int>(colSize, 0));
        int maxSize = 0;

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    }

                    maxSize = max(maxSize, dp[i][j]);
                }
            }
        }

        return maxSize * maxSize;
    }
};