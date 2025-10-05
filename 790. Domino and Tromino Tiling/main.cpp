#include <vector>

using namespace std;

class Solution {
    static constexpr long long MOD = 1000000007LL;

public:
    int numTilings(int n) {
        if (n <= 2) {
            return n;
        }

        if (n == 3) {
            return 5;
        }

        vector<long long> dp(n, 0);

        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 5;

        for (int i = 3; i < n; i++) {
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % MOD;
        }

        return (int)dp[n - 1];
    }
};