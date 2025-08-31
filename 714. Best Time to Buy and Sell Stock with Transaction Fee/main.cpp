#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int buy = numeric_limits<int>::min();
        int profit = 0;

        for (const auto &price : prices) {
            buy = max(buy, profit - price);
            profit = max(profit, price + buy - fee);
        }

        return profit;
    }
};