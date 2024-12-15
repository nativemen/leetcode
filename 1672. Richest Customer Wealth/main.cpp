#include <algorithm>
#include <numeric>
#include <vector>

using std::accumulate;
using std::max;
using std::vector;

class Solution {
public:
    int maximumWealth(const vector<vector<int>> &accounts) {
        int max_wealth = 0;
        for (const auto &customer : accounts) {
            int sum = 0;
            for (int money : customer) {
                sum += money;
            }
            max_wealth = max(max_wealth, sum);
        }

        return max_wealth;
    }
};

class Solution {
public:
    int maximumWealth(const vector<vector<int>> &accounts) {
        int max_wealth = 0;
        for (const auto &customer : accounts) {
            int sum = accumulate(customer.begin(), customer.end(), 0);
            max_wealth = max(max_wealth, sum);
        }

        return max_wealth;
    }
};