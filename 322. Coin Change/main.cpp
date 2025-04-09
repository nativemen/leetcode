#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, numeric_limits<int>::max());
        dp[0] = 0;
        int coins_size = coins.size();

        for (int i = 0; i < amount; i++) {
            if (dp[i] == numeric_limits<int>::max()) {
                continue;
            }

            for (int j = 0; j < coins_size; j++) {
                if (coins[j] <= amount - i) {
                    if (dp[i + coins[j]] > dp[i] + coins[j]) {
                        dp[i + coins[j]] = dp[i] + coins[j];
                    }
                }
            }
        }

        if (dp[amount] == numeric_limits<int>::max()) {
            return -1;
        }

        return dp[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, numeric_limits<int>::max());
        dp[0] = 0;
        int coins_size = coins.size();

        for (const auto &coin : coins) {
            for (int i = coin; i <= amount; i++) {
                if (dp[i - coin] == numeric_limits<int>::max()) {
                    continue;
                }
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        if (dp[amount] == numeric_limits<int>::max()) {
            return -1;
        }

        return dp[amount];
    }
};