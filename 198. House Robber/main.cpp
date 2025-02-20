#include <vector>

using std::vector;

class Solution {
public:
    int rob(vector<int> &nums) {
        size_t size = nums.size();
        if (size == 1) {
            return nums[0];
        }

        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = std::max(dp[0], nums[1]);
        for (size_t i = 2; i < size; i++) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[size - 1];
    }
};

class Solution {
public:
    int rob(vector<int> &nums) {
        int a = 0;
        int b = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                a = std::max(a + nums[i], b);
            } else {
                b = std::max(a, b + nums[i]);
            }
        }

        return std::max(a, b);
    }
};
