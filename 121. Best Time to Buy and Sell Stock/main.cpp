class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int max_profit = 0;
        int buy = prices[0];

        for (const auto &price : prices) {
            if (buy > price) {
                buy = price;
                continue;
            }

            int profit = price - buy;
            if (max_profit < profit) {
                max_profit = profit;
            }
        }

        return max_profit;
    }
};

#include <vector>

using std::max;
using std::vector;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int max_profit = 0;
        int buy = prices[0];

        for (const auto &price : prices) {
            if (buy > price) {
                buy = price;
                continue;
            }

            max_profit = max(max_profit, price - buy);
        }

        return max_profit;
    }
};