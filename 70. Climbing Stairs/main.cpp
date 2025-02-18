#include <vector>

using std::vector;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }

        int a = 1;
        int b = 1;
        int temp;

        for (int i = 2; i <= n; i++) {
            temp = b;
            b = a + b;
            a = temp;
        }

        return b;
    }
};

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp;
        dp.reserve(VECTOR_SIZE);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (size_t i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

private:
    const size_t VECTOR_SIZE = 46;
};