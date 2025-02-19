#include <climits>
#include <vector>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int buy1 = std::numeric_limits<int>::max();
        int buy2 = std::numeric_limits<int>::max();
        int profit1 = 0;
        int profit2 = 0;

        for (size_t i = 0; i < prices.size(); i++) {
            buy1 = std::min(buy1, prices[i]);
            profit1 = std::max(profit1, prices[i] - buy1);
            buy2 = std::min(buy2, prices[i] - profit1);
            profit2 = std::max(profit2, prices[i] - buy2);
        }

        return profit2;
    }
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        size_t size = prices.size();
        vector<int> left(size);
        vector<int> right(size);
        int lowest = prices[0];

        for (size_t i = 1; i < size; i++) {
            left[i] = std::max(left[i - 1], prices[i] - lowest);
            lowest = std::min(lowest, prices[i]);
        }

        int highest = prices[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right[i] = std::max(right[i + 1], highest - prices[i]);
            highest = std::max(highest, prices[i]);
        }

        int max_profit = right[0];
        for (size_t i = 1; i < size; i++) {
            max_profit = std::max(max_profit, left[i - 1] + right[i]);
        }

        return max_profit;
    }
};