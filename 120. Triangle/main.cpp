#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int rowSize = triangle.size();
        if (rowSize <= 0) {
            return 0;
        }

        vector<vector<int>> dp;
        dp.push_back({triangle[0][0]});

        for (int i = 1; i < rowSize; i++) {
            dp.push_back({});
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    dp[i].push_back(dp[i - 1][0] + triangle[i][0]);
                } else if (j == triangle[i].size() - 1) {
                    dp[i].push_back(dp[i - 1][triangle[i - 1].size() - 1] + triangle[i][triangle[i].size() - 1]);
                } else {
                    int val = (dp[i - 1][j - 1] < dp[i - 1][j]) ? dp[i - 1][j - 1] : dp[i - 1][j];
                    dp[i].push_back(val + triangle[i][j]);
                }
            }
        }

        int minVal = numeric_limits<int>::max();

        for (int i = 0; i < dp[rowSize - 1].size(); i++) {
            minVal = min(minVal, dp[rowSize - 1][i]);
        }

        return minVal;
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int rowSize = triangle.size();
        if (rowSize <= 0) {
            return 0;
        }

        for (int i = rowSize - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};