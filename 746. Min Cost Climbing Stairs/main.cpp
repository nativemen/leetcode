#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int costSize = cost.size();
        vector<int> dp(costSize + 1, 0);

        for (int i = 2; i <= costSize; i++) {
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }

        return dp[costSize];
    }
};