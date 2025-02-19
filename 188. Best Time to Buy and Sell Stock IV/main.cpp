#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int maxsize = std::numeric_limits<int>::max();
        vector<int> buys(k, maxsize);
        vector<int> profits(k);

        for (const auto &price : prices) {
            int prev_profit = 0;
            for (int i = 0; i < k; i++) {
                if (i != 0) {
                    prev_profit = profits[i - 1];
                }
                buys[i] = std::min(buys[i], price - prev_profit);
                profits[i] = std::max(profits[i], price - buys[i]);
            }
        }

        return profits[k - 1];
    }
};